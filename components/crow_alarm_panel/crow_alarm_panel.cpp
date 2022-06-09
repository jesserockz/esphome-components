#include "crow_alarm_panel.h"
#include "esphome/core/helpers.h"
#include "esphome/core/log.h"

namespace esphome {
namespace crow_alarm_panel {

static const char *TAG = "crow_alarm_panel";

void CrowAlarmPanelStore::setup(InternalGPIOPin *clock_pin, InternalGPIOPin *data_pin) {
  clock_pin->setup();
  data_pin->setup();
  this->clock_pin_ = clock_pin->to_isr();
  this->data_pin_ = data_pin->to_isr();
  clock_pin->attach_interrupt(CrowAlarmPanelStore::interrupt, this, gpio::INTERRUPT_FALLING_EDGE);
}

std::string binary_indices(uint8_t byte) {
  std::string str;
  for (uint8_t i = 0; i < 8; i++) {
    if ((byte >> i) & 0x01) {
      if (str.length() > 0) {
        str += ",";
      }
      str += to_string(i + 1);
    }
  }
  return str;
}

void IRAM_ATTR HOT CrowAlarmPanelStore::interrupt(CrowAlarmPanelStore *arg) {
  // if (arg->tx_sending) {
  //   if (arg->tx_buffer_index < arg->tx_buffer_length) {
  //     if (arg->tx_buffer[arg->tx_buffer_index]) {
  //       arg->data_pin_.digital_write(true);
  //     } else {
  //       arg->data_pin_.digital_write(false);
  //     }
  //     arg->tx_buffer_index++;
  //     return;
  //   }
  //   arg->tx_sending = false;
  //   arg->data_pin_.pin_mode(gpio::FLAG_INPUT);
  // }

  bool data_bit = arg->data_pin_.digital_read();

  if (!arg->data && data_bit)
    return;

  arg->data = true;

  // Check for boundary
  arg->boundary_buffer_ = (uint8_t) ((arg->boundary_buffer_ << 1) | data_bit);

  if (arg->inside_) {
    uint8_t idx = arg->num_bits_ / 8;
    arg->buffer[idx] = (arg->buffer[idx] >> 1) | ((data_bit ? 1 : 0) << 7);
    arg->num_bits_++;

    if (arg->boundary_buffer_ == BOUNDARY) {
      //  Save data
      memcpy(arg->buffer2, arg->buffer, arg->num_bits_ / 8);
      arg->data_length = arg->num_bits_ / 8;
      //  Reset
      memset(arg->buffer, 0, BUFFER_LENGTH);
      arg->boundary_buffer_ = 0;
      arg->inside_ = false;
      arg->num_bits_ = 0;
      arg->data = false;
      return;
    } else if (arg->num_bits_ >= BUFFER_LENGTH * 8) {
      // Wrong side of boundary.
      arg->inside_ = false;
      arg->num_bits_ = 0;
      memset(arg->buffer, 0, BUFFER_LENGTH);
      arg->boundary_buffer_ = 0;
    }
  }

  if (arg->boundary_buffer_ == BOUNDARY) {
    arg->inside_ = true;
    return;
  }
  // if (arg->tx_buffer_index < arg->tx_buffer_length) {
  //   arg->tx_sending = true;

  //   // arg->data_pin_.digital_write(false);
  //   arg->data_pin_.pin_mode(gpio::FLAG_OUTPUT);
  //   arg->data_pin_.digital_write(false);
  // }
}

void CrowAlarmPanel::setup() {
  this->store_.setup(this->clock_pin_, this->data_pin_);
  if (this->armed_state_ != nullptr) {
    this->armed_state_->publish_state("disarmed");
  }
  // this->set_interval("crow_alarm_panel_update", 1000, [this]() {
  //   uint32_t now = millis();
  //   ESP_LOGD(TAG, "%d clocks in %dms", this->store_.clock_count, now - this->last_update_);
  //   this->last_update_ = now;
  //   this->store_.clock_count = 0;
  // });
};

void CrowAlarmPanel::dump_config() {
  ESP_LOGCONFIG(TAG, "Crow Alarm Panel:");
  LOG_PIN("  Clock Pin: ", this->clock_pin_);
  LOG_PIN("  Data Pin: ", this->data_pin_);
}

CrowAlarmPanelKeypad CrowAlarmPanel::find_keypad_(uint8_t address) {
  for (CrowAlarmPanelKeypad keypad : this->keypads_) {
    if (keypad.address == address) {
      return keypad;
    }
  }
  return {};
}

void CrowAlarmPanel::loop() {
  if (this->store_.data_length) {
    ets_intr_lock();
    uint8_t type = this->store_.buffer2[0];
    std::vector<uint8_t> data;
    data.insert(data.begin(), this->store_.buffer2 + 1, this->store_.buffer2 + this->store_.data_length - 1);
    memset(this->store_.buffer2, 0, BUFFER_LENGTH);
    this->store_.data_length = 0;
    ets_intr_unlock();

    ESP_LOGD(TAG, "Received data: [%02x.%s]", type, format_hex_pretty(data).c_str());

    switch (type) {
      case OUTPUT_STATE:
        ESP_LOGD(TAG, "Output state [%s]", format_hex_pretty(data).c_str());
        for (CrowAlarmPanelOutput output : this->outputs_) {
          bool on = ((data[0] >> (output.number - 1)) & 0x01);
          output.the_switch->publish_state(on);
        }
        break;
      case ZONE_STATE: {
        if (data.size() < 6) {
          ESP_LOGW(TAG, "Zone state invalid length, discarding");
          return;
        }
        ESP_LOGD(TAG, "Zone state received [%s]", format_hex_pretty(data).c_str());
        bool clear = true;
        for (CrowAlarmPanelZone zone : this->zones_) {
          bool triggered = ((data[1] >> (zone.zone - 1)) & 0x01);
          bool triggered_alarmed = ((data[2] >> (zone.zone - 1)) & 0x01);
          bool bypassed = ((data[3] >> (zone.zone - 1)) & 0x01);

          if (zone.motion_binary_sensor != nullptr) {
            zone.motion_binary_sensor->publish_state(triggered | triggered_alarmed);
          }
          if (zone.bypass_binary_sensor != nullptr) {
            zone.bypass_binary_sensor->publish_state(bypassed);
          }

          if (triggered) {
            ESP_LOGD(TAG, "Zone %d active", zone.zone);
            if (this->armed_state_->state != "arming")
              this->armed_state_->publish_state("disarmed");  // Assume disarmed if motion detected in this byte
            clear = false;
          }
          if (triggered_alarmed) {
            this->armed_state_->publish_state("pending");
            ESP_LOGD(TAG, "Alarm pending from zone %d", zone.zone);
            clear = false;
          }
        }
        if (clear) {
          ESP_LOGD(TAG, "All zones clear");
        }
        break;
      }
      case ARMED_STATE: {
        if (armed_state_ != nullptr) {
          if (data[0] == 0x00 && data[1] == 0x01) {
            this->armed_state_->publish_state("arming");
            ESP_LOGD(TAG, "Arming [%02x.%s]", type, format_hex_pretty(data).c_str());
          } else if (data[0] == 0x01 && data[1] == 0x00) {
            this->armed_state_->publish_state("armed_away");
            ESP_LOGD(TAG, "Armed Away [%02x.%s]", type, format_hex_pretty(data).c_str());
          } else if (data[0] == 0x00 && data[1] == 0x00) {
            this->armed_state_->publish_state("disarmed");
            ESP_LOGD(TAG, "Disarmed [%02x.%s]", type, format_hex_pretty(data).c_str());
          } else {
            ESP_LOGD(TAG, "Armed state unknown [%02x.%s]", type, format_hex_pretty(data).c_str());
          }
        }
        break;
      }
      case KEYPRESS: {
        uint8_t key = data[1];
        CrowAlarmPanelKeypad keypad = this->find_keypad_(data[0]);
        ESP_LOGD(TAG, "Key %s (%d) pressed on %s [%02x.%s]", KEYS[key], key, keypad.name.c_str(), type,
                 format_hex_pretty(data).c_str());
        break;
      }
      case CURRENT_TIME: {
        const char *day_of_week = DAYS[data[0] - 1];
        uint8_t mins = data[2];
        uint8_t hour = data[1];
        if (mins >= 60) {
          hour = hour + (mins / 60);
          mins = mins % 60;
        }
        ESP_LOGV(TAG, "Date/Time %s 20%02d-%02d-%02d %02d:%02d:%02d", day_of_week, data[6], data[5], data[4], hour,
                 mins, data[3]);
        // ESP_LOGD(TAG, "[%s]", format_hex_pretty(data).c_str());
        break;
      }
      case RESPONSE_TIME:
        ESP_LOGD(TAG, "Current time setting received [%d]", (data[1] << 8) | data[2]);
        break;
      case KEYPAD_COMMAND: {
        CrowAlarmPanelKeypad keypad = this->find_keypad_(data[0]);
        ESP_LOGD(TAG, "%s command [%02x.%s]", keypad.name.c_str(), type, format_hex_pretty(data).c_str());
        break;
      }
      case KEYPAD_STATE: {
        CrowAlarmPanelKeypad keypad = this->find_keypad_(data[0]);
        if (data[1] == 00) {
          ESP_LOGD(TAG, "%s in normal state [%02x.%s]", keypad.name.c_str(), type, format_hex_pretty(data).c_str());
        } else if (data[1] == 02) {
          ESP_LOGD(TAG, "%s in installer mode [%02x.%s]", keypad.name.c_str(), type, format_hex_pretty(data).c_str());
        } else if (data[1] == 03) {
          ESP_LOGD(TAG, "%s programming %d [%02x.%s]", keypad.name.c_str(), data[2], type,
                   format_hex_pretty(data).c_str());
        } else {
          ESP_LOGD(TAG, "%s state unknown [%02x.%s]", keypad.name.c_str(), type, format_hex_pretty(data).c_str());
        }
        break;
      }
      case SETTING_VALUE: {
        ESP_LOGD(TAG, "Address %d-%d has options: %s [%02x.%s]", data[3], data[4], binary_indices(data[2]).c_str(),
                 type, format_hex_pretty(data).c_str());
        break;
      }
      case SETTING_VALUE2: {
        // CrowAlarmPanelKeypad keypad = this->find_keypad_(data[0]);
        ESP_LOGD(TAG, "Address %d-%d has value %d [%02x.%s]", data[2], data[3], data[1], type,
                 format_hex_pretty(data).c_str());
        break;
      }
      case SETTING_VALUE3: {
        // CrowAlarmPanelKeypad keypad = this->find_keypad_(data[0]);
        ESP_LOGD(TAG, "Address %d-%d has value %d [%02x.%s]", data[3], data[4], (data[1] << 8) | data[2], type,
                 format_hex_pretty(data).c_str());
        break;
      }
      case MEMORY_EVENT: {
        // CrowAlarmPanelKeypad keypad = this->find_keypad_(data[0]);
        ESP_LOGD(TAG, "Memory event #%d ", data[1]);
        break;
      }
      default:
        ESP_LOGD(TAG, "Unknown [%02x.%s]", type, format_hex_pretty(data).c_str());
        break;
    }
    this->on_message_trigger_->trigger(type, data);
  } else if (!this->tx_buffer_.empty() && !this->store_.data) {
    InterruptLock lock;
    this->clock_pin_->pin_mode(gpio::FLAG_OUTPUT);
    this->data_pin_->pin_mode(gpio::FLAG_OUTPUT);
    std::vector<uint8_t> to_send = this->tx_buffer_[0];
    std::string s;
    this->tx_buffer_.erase(this->tx_buffer_.begin());
    for (uint8_t i = 0; i < to_send.size(); i++) {
      for (uint8_t j = 0; j < 8; j++) {
        this->clock_pin_->digital_write(true);
        this->data_pin_->digital_write(to_send[i] & (1 << j));
        this->clock_pin_->digital_write(false);
        s += (to_send[i] & (1 << j)) ? "1" : "0";
        delay(1);
      }
      s += " (";
      s += format_hex(to_send.data() + i, 1);
      s += ") ";
    }

    this->clock_pin_->pin_mode(gpio::FLAG_INPUT);
    this->data_pin_->pin_mode(gpio::FLAG_INPUT);

    ESP_LOGD(TAG, "Sending Bits: %s", s.c_str());

    // if (this->store_.tx_buffer_index == this->store_.tx_buffer_length) {
    //   std::vector<uint8_t> to_send = this->tx_buffer_[0];
    //   this->tx_buffer_.erase(this->tx_buffer_.begin());
    //   std::string s;
    //   for (uint8_t i = 0; i < to_send.size(); i++) {
    //     for (uint8_t j = 0; j < 8; j++) {
    //       this->store_.tx_buffer[i * 8 + j] = (to_send[i] & (1 << j)) ? 1 : 0;
    //       s += (to_send[i] & (1 << j)) ? "1" : "0";
    //     }
    //     s += " (";
    //     s += format_hex(to_send.data() + i, 1);
    //     s += ") ";
    //   }
    //   this->store_.tx_buffer_length = to_send.size() * 8;
    //   this->store_.tx_buffer_index = 0;
    //   ESP_LOGD(TAG, "Sending Bits: %s", s.c_str());
    // }
  }
}

void CrowAlarmPanel::arm_away() {}

void CrowAlarmPanel::arm_stay() {}

void CrowAlarmPanel::disarm(const std::string code) {}

void CrowAlarmPanel::set_output(uint8_t output, bool state) {}

void CrowAlarmPanel::send_packet(uint8_t type, const std::vector<uint8_t> &data) {
  std::vector<uint8_t> to_send;
  to_send.push_back(BOUNDARY);
  to_send.push_back(type);
  to_send.insert(to_send.end(), data.begin(), data.end());
  to_send.push_back(BOUNDARY);
  this->tx_buffer_.push_back(to_send);
  ESP_LOGD(TAG, "Queuing command %s", format_hex_pretty(to_send).c_str());
}

void CrowAlarmPanel::keypress(uint8_t key) {
  std::vector<uint8_t> data;
  data.push_back(this->keypad_address_);
  data.push_back(key);
  this->send_packet(KEYPRESS, data);
}

}  // namespace crow_alarm_panel
}  // namespace esphome

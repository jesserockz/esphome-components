#pragma once

#include "esphome/core/helpers.h"

#include "esphome/components/display/display_buffer.h"
#include "esphome/components/uart/uart.h"

#include <cinttypes>
#include <queue>
#include <vector>

namespace esphome {
namespace m5stack_printer {

enum BarcodeType {
  UPC_A = 0x41,
  UPC_E,
  EAN13,
  EAN8,
  CODE39,
  ITF,
  CODABAR,
  CODE93,
  CODE128,
};

class M5StackPrinterDisplay : public display::DisplayBuffer, public uart::UARTDevice {
 public:
  void setup() override;
  void loop() override;
  void update() override;
  bool can_proceed() override { return this->ready_; }

  void write_to_device_();

  // Display buffer
  int get_width_internal() override { return 8 * 58; };  // 58mm, 8 dots per mm
  int get_height_internal() override { return this->height_; };

  void set_height(int height) { this->height_ = height; }

  display::DisplayType get_display_type() override { return display::DisplayType::DISPLAY_TYPE_BINARY; }

  void print_text(std::string text, uint8_t font_size = 0);
  void new_line(uint8_t lines);
  void print_qrcode(std::string data);

  void print_barcode(std::string barcode, BarcodeType type);

  void set_send_wakeup(bool send_wakeup) { this->send_wakeup_ = send_wakeup; }

 protected:
  void draw_absolute_pixel_internal(int x, int y, Color color) override;
  size_t get_buffer_length_() { return size_t(this->get_width_internal()) * size_t(this->get_height_internal()) / 8; }
  void queue_data_(std::vector<uint8_t> data);
  void queue_data_(const uint8_t *data, size_t size);
  void init_();

  std::queue<std::vector<uint8_t>> queue_{};
  int height_{0};
  bool ready_{false};
  bool send_wakeup_{false};
};

template<typename... Ts>
class M5StackPrinterPrintTextAction : public Action<Ts...>, public Parented<M5StackPrinterDisplay> {
 public:
  TEMPLATABLE_VALUE(std::string, text)
  TEMPLATABLE_VALUE(uint8_t, font_size)

  void play(Ts... x) override { this->parent_->print_text(this->text_.value(x...), this->font_size_.value(x...)); }
};

}  // namespace m5stack_printer
}  // namespace esphome

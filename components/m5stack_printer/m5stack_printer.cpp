#include "m5stack_printer.h"

#include <cinttypes>

namespace esphome {
namespace m5stack_printer {

static const char *const TAG = "m5stack_printer";

static const uint8_t ESC = 0x1B;
static const uint8_t GS = 0x1D;

static const uint8_t INIT_PRINTER_CMD[] = {ESC, 0x40};
static const uint8_t BAUD_RATE_9600_CMD[] = {ESC, '#', '#', 'S', 'B', 'D', 'R', 0x80, 0x25, 0x00, 0x00};
static const uint8_t BAUD_RATE_115200_CMD[] = {ESC, '#', '#', 'S', 'B', 'D', 'R', 0x00, 0xC2, 0x01, 0x00};

static const uint8_t FONT_SIZE_CMD[] = {GS, '!'};
static const uint8_t FONT_SIZE_RESET_CMD[] = {ESC, 0x14};

static const uint8_t QR_CODE_SET_CMD[] = {GS, 0x28, 0x6B, 0x00, 0x00, 0x31, 0x50, 0x30};
static const uint8_t QR_CODE_PRINT_CMD[] = {GS, 0x28, 0x6B, 0x03, 0x00, 0x31, 0x51, 0x30, 0x00};

static const uint8_t BARCODE_ENABLE_CMD[] = {GS, 0x45, 0x43, 0x01};
static const uint8_t BARCODE_DISABLE_CMD[] = {GS, 0x45, 0x43, 0x00};
static const uint8_t BARCODE_PRINT_CMD[] = {GS, 0x6B};

static const uint8_t BYTES_PER_LOOP = 120;

void M5StackPrinterDisplay::setup() {
  this->init_internal_(this->get_buffer_length_());

  this->set_timeout(500, [this]() {
    this->init_();
    this->ready_ = true;
  });
  // this->write_array(BAUD_RATE_115200_CMD, sizeof(BAUD_RATE_115200_CMD));
  // delay(10);
  // this->parent_->set_baud_rate(115200);
  // this->parent_->load_settings();
  // delay(10);

  // this->write_array(INIT_PRINTER_CMD, sizeof(INIT_PRINTER_CMD));
}

void M5StackPrinterDisplay::init_() { this->write_array(INIT_PRINTER_CMD, sizeof(INIT_PRINTER_CMD)); }

void M5StackPrinterDisplay::print_text(std::string text, uint8_t font_size) {
  this->init_();
  font_size = clamp<uint8_t>(font_size, 0, 7);
  this->write_array(FONT_SIZE_CMD, sizeof(FONT_SIZE_CMD));
  this->write_byte(font_size | (font_size << 4));

  this->write_str(text.c_str());

  this->write_array(FONT_SIZE_RESET_CMD, sizeof(FONT_SIZE_RESET_CMD));
}

void M5StackPrinterDisplay::new_line(uint8_t lines) {
  for (uint8_t i = 0; i < lines; i++) {
    this->write_byte('\n');
  }
}

void M5StackPrinterDisplay::print_qrcode(std::string data) {
  this->init_();

  size_t len;
  uint8_t len_low, len_high;
  len = data.length() + 3;
  len_low = len & 0xFF;
  len_high = len >> 8;

  uint8_t qr_code_cmd[sizeof(QR_CODE_SET_CMD)];
  memcpy(qr_code_cmd, QR_CODE_SET_CMD, sizeof(QR_CODE_SET_CMD));
  qr_code_cmd[3] = len_low;
  qr_code_cmd[4] = len_high;
  this->write_array(qr_code_cmd, sizeof(qr_code_cmd));
  this->write_str(data.c_str());
  this->write_byte(0x00);

  this->write_array(QR_CODE_PRINT_CMD, sizeof(QR_CODE_PRINT_CMD));
}

void M5StackPrinterDisplay::print_barcode(std::string barcode, BarcodeType type) {
  this->init_();

  this->write_array(BARCODE_ENABLE_CMD, sizeof(BARCODE_ENABLE_CMD));

  this->write_array(BARCODE_PRINT_CMD, sizeof(BARCODE_PRINT_CMD));
  this->write_byte(type);
  this->write_byte(barcode.length());
  this->write_str(barcode.c_str());
  this->write_byte(0x00);

  this->write_array(BARCODE_DISABLE_CMD, sizeof(BARCODE_DISABLE_CMD));
}

void M5StackPrinterDisplay::queue_data_(std::vector<uint8_t> data) {
  for (size_t i = 0; i < data.size(); i += BYTES_PER_LOOP) {
    std::vector<uint8_t> chunk(data.begin() + i, data.begin() + std::min(i + BYTES_PER_LOOP, data.size()));
    this->queue_.push(chunk);
  }
}
void M5StackPrinterDisplay::queue_data_(const uint8_t *data, size_t size) {
  for (size_t i = 0; i < size; i += BYTES_PER_LOOP) {
    size_t chunk_size = std::min(i + BYTES_PER_LOOP, size) - i;
    std::vector<uint8_t> chunk(data + i, data + i + chunk_size);
    this->queue_.push(chunk);
  }
}

void M5StackPrinterDisplay::loop() {
  if (this->queue_.empty()) {
    return;
  }

  std::vector<uint8_t> data = this->queue_.front();
  this->queue_.pop();
  this->write_array(data.data(), data.size());
}

static uint16_t count = 0;

void M5StackPrinterDisplay::update() {
  this->do_update_();
  this->write_to_device_();
  ESP_LOGD(TAG, "count: %d;", count);
  count = 0;
}

void M5StackPrinterDisplay::write_to_device_() {
  if (this->buffer_ == nullptr) {
    return;
  }

  uint8_t header[] = {0x1D, 0x76, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00};

  uint16_t width = this->get_width() / 8;
  uint16_t height = this->get_height();

  header[3] = 0;  // Mode
  header[4] = width & 0xFF;
  header[5] = (width >> 8) & 0xFF;
  header[6] = height & 0xFF;
  header[7] = (height >> 8) & 0xFF;

  this->queue_data_(header, sizeof(header));
  this->queue_data_(this->buffer_, this->get_buffer_length_());
}

void M5StackPrinterDisplay::draw_absolute_pixel_internal(int x, int y, Color color) {
  if (this->buffer_ == nullptr) {
    ESP_LOGW(TAG, "Buffer is null");
    return;
  }
  if (x < 0 || y < 0 || x >= this->get_width_internal() || y >= this->get_height_internal()) {
    ESP_LOGW(TAG, "Invalid pixel: x=%d, y=%d", x, y);
    return;
  }
  uint8_t width = this->get_width_internal() / 8;
  uint16_t index = x / 8 + y * width;
  uint8_t bit = x % 8;
  if (color.is_on()) {
    this->buffer_[index] |= 1 << (7 - bit);
  } else {
    this->buffer_[index] &= ~(1 << (7 - bit));
  }
  count++;
}

}  // namespace m5stack_printer
}  // namespace esphome

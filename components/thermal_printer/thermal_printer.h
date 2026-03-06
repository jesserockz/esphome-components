#pragma once

#include "esphome/core/helpers.h"

#include "esphome/components/display/display_buffer.h"
#include "esphome/components/uart/uart.h"

#include <cinttypes>
#include <queue>
#include <vector>

namespace esphome {
namespace thermal_printer {

enum ThermalPrinterModel {
  M5STACK_THERMAL = 0,
  CSN_A2 = 1,
  GENERIC_58MM = 2,
  ADAFRUIT_597 = 3,
  SPARKFUN_10438 = 4,
};

// Barcode types according to CSN-A2 datasheet GS k command table
// These values correspond to format 1 (m=0-6) from the datasheet
enum BarcodeType {
  UPC_A = 0,     // 11-12 characters, digits only
  UPC_E = 1,     // 11-12 characters, digits only
  EAN13 = 2,     // 12-13 characters, digits only (was JAN13)
  EAN8 = 3,      // 7-8 characters, digits only (was JAN8)
  CODE39 = 4,    // Variable length, alphanumeric + special chars
  ITF = 5,       // Variable even length, digits only
  CODABAR = 6,   // Variable length, digits + A-D + special chars
  CODE93 = 7,    // Variable length, full ASCII (uses format 2, m=72)
  CODE128 = 8,   // Variable length, full ASCII (uses format 2, m=73)
};

/**
 * Thermal Printer Component
 *
 * This component provides ESC/POS compatible thermal printing functionality
 * for the thermal printer s (CSN-A2 based).
 *
 * Supported features:
 * - Text printing with font size control (0-7)
 * - QR code printing with error correction
 * - 1D barcode printing (UPC, EAN, CODE39, CODE128, etc.)
 * - Raster image printing via display buffer
 *
 * Communication: UART (TTL/RS232) at 9600 baud by default
 * Print width: 58mm (384 dots), 8 dots/mm resolution
 */
class ThermalPrinterDisplay : public display::DisplayBuffer, public uart::UARTDevice {
 public:
  void setup() override;
  void loop() override;
  void update() override;

  void write_to_device_();

  // Display buffer
  int get_width_internal() override { return 8 * 58; };  // 58mm, 8 dots per mm
  int get_height_internal() override { return this->height_; };

  void set_height(int height) { this->height_ = height; }
  void set_model(ThermalPrinterModel model) { this->model_ = model; }

  display::DisplayType get_display_type() override { return display::DisplayType::DISPLAY_TYPE_BINARY; }

  /**
   * Print text with specified font width and height
   * @param text Text string to print
   * @param font_width Font width multiplier (1-8), 1=normal width
   * @param font_height Font height multiplier (1-8), 1=normal height
   * @param font_type Font type (0=Font A 12x24, 1=Font B 9x17)
   */
  void print_text(std::string text, uint8_t font_width = 1, uint8_t font_height = 1, uint8_t font_type = 0);

  /**
   * Print text with comprehensive formatting options
   * This method handles all formatting parameters and character encoding correctly
   * @param text Text string to print
   * @param font_width Font width multiplier (1-8)
   * @param font_height Font height multiplier (1-8)
   * @param font_type Font type (0=Font A 12x24, 1=Font B 9x17)
   * @param bold Enable bold text
   * @param double_strike Enable double-strike mode (overlapping dots)
   * @param underline Underline mode (0=off, 1=1dot, 2=2dot)
   * @param upside_down Enable upside down text
   * @param rotation Enable 90-degree rotation
   * @param inverse Enable inverse printing
   * @param chinese_mode Enable Chinese/Kanji character mode
   * @param alignment Text alignment (0=left, 1=center, 2=right)
   * @param charset International character set (0=USA, 1=France, 2=Germany, etc. 0-15)
   * @param codepage Character code table (0=CP437, 1=Katakana, 2=CP850, etc. 0-47)
   * @param character_spacing Right-side character spacing (0-255, units of 0.125mm)
   */
  void thermal_print_text_with_formatting(
    const std::string &text, uint8_t font_width, uint8_t font_height, uint8_t font_type, bool bold, bool double_strike, uint8_t underline,
    bool upside_down, bool rotation,
    bool inverse, bool chinese_mode, uint8_t alignment, uint8_t charset = 0, uint8_t codepage = 0, uint8_t character_spacing = 0
  );

  /**
   * Set printer hardware settings
   * @param line_spacing Line spacing in dots (default: 30)
   * @param print_density Print density 0-31 (default: 10)
   * @param break_time Break time between dots 0-7 (default: 4)
   */
  void set_printer_settings(uint8_t line_spacing, uint8_t print_density, uint8_t break_time);

  /**
   * Reset printer settings to factory defaults
   */
  void reset_printer_settings();

  /**
   * Set whether to send wakeup/init commands to printer
   * @param send_wakeup If true, sends ESC @ command during initialization
   */
  void set_send_wakeup(bool send_wakeup) { this->send_wakeup_ = send_wakeup; }

  /**
   * Print newlines to advance paper
   * @param lines Number of lines to advance (1-255)
   */
  void new_line(uint8_t lines);

  /**
   * Print QR code with error correction level L
   * @param data String data to encode (max ~100 characters recommended)
   */
  void print_qrcode(std::string data);

  /**
   * Print 1D barcode with validation
   * @param barcode Barcode data string
   * @param type Barcode format (UPC_A, EAN13, CODE128, etc.)
   */
  void print_barcode(std::string barcode, BarcodeType type);

  /**
   * Cut paper (full cut)
   * Requires printer with cutting mechanism
   */
  void cut_paper();

  /**
   * Cut paper with specified mode
   * @param mode 0=full cut, 1=partial cut, 66=cut and feed
   * @param feed_lines Additional lines to feed before cutting (mode 66 only)
   */
  void cut_paper(uint8_t mode, uint8_t feed_lines = 0);

  /**
   * Set text alignment
   * @param alignment 0=left, 1=center, 2=right
   */
  void set_text_alignment(uint8_t alignment);

  /**
   * Set line spacing
   * @param spacing Line spacing in dots (0-255)
   */
  void set_line_spacing(uint8_t spacing);

  /**
   * Set print density and break time
   * @param density Print density (0-31, affects darkness)
   * @param break_time Break time between dots (0-7)
   */
  void set_print_density(uint8_t density, uint8_t break_time = 0);

  /**
   * Set text style modes
   * @param bold Enable bold/emphasized text
   * @param underline Underline mode (0=off, 1=1dot, 2=2dot)
   * @param upside_down Enable upside down text
   * @param font_type Font type (0=Font A 12x24, 1=Font B 9x17)
   */
  void set_text_style(bool bold = false, uint8_t underline = 0, bool upside_down = false, uint8_t font_type = 0);

  /**
   * Print test page
   * Useful for checking printer functionality
   */
  void print_test_page();

  /**
   * Set character set for regional character support
   * @param charset Character set (0-15), 0=USA default
   */
  void set_charset(uint8_t charset = 0);

  /**
   * Set code page for extended ASCII characters (0x80-0xFF)
   * @param codepage Code page (0-47), 0=CP437 default
   */
  void set_codepage(uint8_t codepage = 0);

  /**
   * Get current character set
   * @return Current character set (0-15)
   */
  uint8_t get_charset() const { return this->current_charset_; }

  /**
   * Get current code page
   * @return Current code page (0-47)
   */
  uint8_t get_codepage() const { return this->current_codepage_; }

  /**
   * Reset all formatting settings to defaults
   * Clears bold, underline, rotation, inverse, alignment, etc.
   * Sends hardware commands to ensure printer matches internal state
   */
  void reset_all_formatting();

  /**
   * Apply current formatting state to hardware
   * Internal helper for maintaining state consistency
   */
  void apply_current_formatting_state();

  /**
   * Set 90-degree clockwise rotation mode
   * @param enable True to enable rotation, false to disable
   */
  void set_90_degree_rotation(bool enable);

  /**
   * Set white/black inverse printing mode
   * @param enable True to enable inverse (white text on black), false for normal
   */
  void set_inverse_printing(bool enable);

  /**
   * Set upside-down printing mode (180-degree rotation)
   * @param enable True to enable upside-down printing
   */
  void set_upside_down_printing(bool enable);

  /**
   * Send raw ESC/POS command bytes
   * @param command Vector of bytes to send to the printer
   * Useful for debugging and testing specific ESC/POS sequences
   */
  void send_raw_command(const std::vector<uint8_t> &command);

  /**
   * Enable Chinese/Japanese character mode
   * When enabled, processes multi-byte characters for Asian text
   * @param enable True to enable Asian character mode, false for ASCII mode
   */
  void set_chinese_mode(bool enable);

  /**
   * Set printer sleep mode timeout
   * @param timeout_seconds Sleep timeout in seconds (0-65535), 0 disables sleep mode
   */
  void set_sleep_mode(uint16_t timeout_seconds);

  /**
   * Wake up printer from sleep mode
   * Sends any character to wake the printer, followed by initialization
   */
  void wake_up();

  /**
   * Run demo/debug function to showcase all printer capabilities
   * Features Hitchhiker's Guide to the Galaxy themed content
   * @param show_header Print themed header (default: false, true when no params)
   * @param show_intro Print introduction and formatting showcase (default: false, true when no params)
   * @param show_footer Print completion message footer (default: false, true when no params)
   * @param show_text_styles Print various text formatting demos (default: false, true when no params)
   * @param show_inverse Print inverse text demo (default: false, true when no params)
   * @param show_rotation Print 90-degree rotated text demo (default: false, true when no params)
   * @param show_qr_code Print QR code demo (default: false, true when no params)
   * @param show_barcode Print barcode demo (default: false, true when no params)
   */
  void run_demo(bool show_header=false, bool show_intro = false, bool show_footer = false, bool show_text_styles = false, bool show_inverse = false, bool show_rotation = false, bool show_upside_down = false, bool show_qr_code = false, bool show_barcode = false);

  /**
   * Set horizontal tab stop positions
   * @param positions Comma or space separated character positions (e.g., "8,16,24,32" or "10 20 30")
   * Maximum 32 tab stops, positions are in character widths from left margin
   */
  void set_tab_positions(const std::string &positions);

  /**
   * Jump to next horizontal tab position
   * Use after setting tab positions with set_tab_positions
   * If no tab positions set or past last tab, moves to next 8-character boundary
   */
  void horizontal_tab();

  /**
   * Set absolute horizontal print position from left margin
   * @param position Horizontal position in dots from left margin (0-383 for 58mm paper)
   * Useful for precise alignment, right-justifying text, or creating custom layouts
   */
  void set_horizontal_position(uint16_t position);

  /**
   * Set text indentation for subsequent prints
   * @param spaces Number of spaces to add at the beginning of each print (0-50)
   * This adds actual space characters, not printer spacing commands
   */
  void set_text_indentation(uint8_t spaces);

  /**
   * Feed paper by specified number of dots (ESC J n)
   * @param dots Number of dots to feed (0-255), where each dot = 0.125mm
   * Use for precise vertical positioning without printing
   */
  void feed_paper_dots(uint8_t dots);

  /**
   * Print buffer and feed lines (ESC d n) 
   * @param lines Number of lines to feed after printing buffer (0-255)
   * Prints any buffered content, then advances paper by specified lines
   */
  void print_and_feed_lines(uint8_t lines);

  /**
   * Reset text indentation to default (no indentation)
   * Clears text indentation setting
   */
  void reset_text_indentation();
  
  /**
   * Get cover status  
   * @return true if cover is open (problem), false if cover is closed
   */
  bool get_cover_problem();

 protected:
  void draw_absolute_pixel_internal(int x, int y, Color color) override;
  size_t get_buffer_length_() { return size_t(this->get_width_internal()) * size_t(this->get_height_internal()) / 8; }
  void queue_data_(std::vector<uint8_t> data);
  void queue_data_(const uint8_t *data, size_t size);
  void init_();
  void build_formatting_prefix_(std::vector<uint8_t> &prefix);
  void draw_simple_esphome_logo_();

  std::queue<std::vector<uint8_t>> queue_{};
  int height_{0};
  ThermalPrinterModel model_{M5STACK_THERMAL};

  // Formatting state variables (line-buffered printer requires bundled commands)
  bool bold_state_{false};
  uint8_t underline_state_{0};
  bool upside_down_state_{false};
  uint8_t font_type_state_{0};  // 0=Font A, 1=Font B
  uint8_t alignment_state_{0};  // 0=left, 1=center, 2=right
  bool inverse_state_{false};
  bool rotation_state_{false};
  bool chinese_mode_state_{false};  // Track Chinese/Kanji character mode state
  uint8_t current_charset_{0};  // Current international character set (0-15)
  uint8_t current_codepage_{0};  // Current character code table (0-47)
  bool send_wakeup_{false};
  uint8_t text_indentation_{0};  // Number of spaces to add for indentation
};

template<typename... Ts>
class ThermalPrinterPrintTextAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  TEMPLATABLE_VALUE(std::string, text)
  TEMPLATABLE_VALUE(uint8_t, font_width)
  TEMPLATABLE_VALUE(uint8_t, font_height)
  TEMPLATABLE_VALUE(uint8_t, font_type)

  void play(const Ts &...x) override { 
    this->parent_->print_text(
      this->text_.value(x...), 
      this->font_width_.value(x...), 
      this->font_height_.value(x...),
      this->font_type_.value(x...)
    ); 
  }
};

template<typename... Ts>
class ThermalPrinterThermalPrintTextAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  TEMPLATABLE_VALUE(std::string, text_to_print)
  TEMPLATABLE_VALUE(uint8_t, font_width)
  TEMPLATABLE_VALUE(uint8_t, font_height)
  TEMPLATABLE_VALUE(uint8_t, font_type)
  TEMPLATABLE_VALUE(bool, bold)
  TEMPLATABLE_VALUE(bool, double_strike)
  TEMPLATABLE_VALUE(uint8_t, underline)
  TEMPLATABLE_VALUE(bool, upside_down)
  TEMPLATABLE_VALUE(bool, rotation)
  TEMPLATABLE_VALUE(bool, inverse)
  TEMPLATABLE_VALUE(bool, chinese_mode)
  TEMPLATABLE_VALUE(uint8_t, alignment)
  TEMPLATABLE_VALUE(uint8_t, charset)
  TEMPLATABLE_VALUE(uint8_t, codepage)
  TEMPLATABLE_VALUE(uint8_t, character_spacing)

  void play(const Ts &...x) override { 
    this->parent_->thermal_print_text_with_formatting(
      this->text_to_print_.value(x...),
      this->font_width_.value(x...),
      this->font_height_.value(x...),
      this->font_type_.value(x...),
      this->bold_.value(x...),      this->double_strike_.value(x...),      this->underline_.value(x...),
      this->upside_down_.value(x...),
      this->rotation_.value(x...),
      this->inverse_.value(x...),
      this->chinese_mode_.value(x...),
      this->alignment_.value(x...),
      this->charset_.value(x...),
      this->codepage_.value(x...),
      this->character_spacing_.value(x...)
    ); 
  }
};

template<typename... Ts>
class ThermalPrinterSetSettingsAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  TEMPLATABLE_VALUE(uint8_t, line_spacing)
  TEMPLATABLE_VALUE(uint8_t, print_density)
  TEMPLATABLE_VALUE(uint8_t, break_time)

  void play(const Ts &...x) override {
    this->parent_->set_printer_settings(
      this->line_spacing_.value(x...),
      this->print_density_.value(x...),
      this->break_time_.value(x...)
    );
  }
};

template<typename... Ts>
class ThermalPrinterResetSettingsAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  void play(const Ts &...x) override {
    this->parent_->reset_printer_settings();
  }
};

template<typename... Ts>
class ThermalPrinterPrintQRCodeAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  TEMPLATABLE_VALUE(std::string, qrcode)

  void play(const Ts &...x) override { this->parent_->print_qrcode(this->qrcode_.value(x...)); }
};

template<typename... Ts>
class ThermalPrinterPrintBarcodeAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  TEMPLATABLE_VALUE(std::string, barcode)
  TEMPLATABLE_VALUE(std::string, type)

  void play(const Ts &...x) override {
    // Convert string type to BarcodeType enum
    std::string type_str = this->type_.value(x...);
    BarcodeType barcode_type = CODE128; // Default
    if (type_str == "UPC_A") barcode_type = UPC_A;
    else if (type_str == "UPC_E") barcode_type = UPC_E;
    else if (type_str == "EAN13") barcode_type = EAN13;
    else if (type_str == "EAN8") barcode_type = EAN8;
    else if (type_str == "CODE39") barcode_type = CODE39;
    else if (type_str == "ITF") barcode_type = ITF;
    else if (type_str == "CODABAR") barcode_type = CODABAR;
    else if (type_str == "CODE93") barcode_type = CODE93;
    else if (type_str == "CODE128") barcode_type = CODE128;

    this->parent_->print_barcode(this->barcode_.value(x...), barcode_type);
  }
};

template<typename... Ts>
class ThermalPrinterNewLineAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  TEMPLATABLE_VALUE(uint8_t, lines)

  void play(const Ts &...x) override { this->parent_->new_line(this->lines_.value(x...)); }
};

template<typename... Ts>
class ThermalPrinterCutPaperAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  TEMPLATABLE_VALUE(uint8_t, cut_mode)
  TEMPLATABLE_VALUE(uint8_t, feed_lines)

  void play(const Ts &...x) override {
    if (this->cut_mode_.value(x...) == 0 && this->feed_lines_.value(x...) == 0) {
      this->parent_->cut_paper();
    } else {
      this->parent_->cut_paper(this->cut_mode_.value(x...), this->feed_lines_.value(x...));
    }
  }
};

template<typename... Ts>
class ThermalPrinterSetAlignmentAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  TEMPLATABLE_VALUE(uint8_t, alignment)

  void play(const Ts &...x) override { this->parent_->set_text_alignment(this->alignment_.value(x...)); }
};

template<typename... Ts>
class ThermalPrinterSetStyleAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  TEMPLATABLE_VALUE(bool, bold)
  TEMPLATABLE_VALUE(uint8_t, underline)
  TEMPLATABLE_VALUE(bool, upside_down)
  TEMPLATABLE_VALUE(uint8_t, font_type)

  void play(const Ts &...x) override {
    this->parent_->set_text_style(
      this->bold_.value(x...),
      this->underline_.value(x...),
      this->upside_down_.value(x...),
      this->font_type_.value(x...)
    );
  }
};

template<typename... Ts>
class ThermalPrinterSet90DegreeRotationAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  TEMPLATABLE_VALUE(bool, enable)

  void play(const Ts &...x) override { this->parent_->set_90_degree_rotation(this->enable_.value(x...)); }
};

template<typename... Ts>
class ThermalPrinterSetInversePrintingAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  TEMPLATABLE_VALUE(bool, enable)

  void play(const Ts &...x) override { this->parent_->set_inverse_printing(this->enable_.value(x...)); }
};

template<typename... Ts>
class ThermalPrinterSetUpsideDownPrintingAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  TEMPLATABLE_VALUE(bool, enable)

  void play(const Ts &...x) override { this->parent_->set_upside_down_printing(this->enable_.value(x...)); }
};

template<typename... Ts>
class ThermalPrinterSetChineseModeAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  TEMPLATABLE_VALUE(bool, enable)

  void play(const Ts &...x) override { this->parent_->set_chinese_mode(this->enable_.value(x...)); }
};

template<typename... Ts>
class ThermalPrinterSetLineSpacingAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  TEMPLATABLE_VALUE(uint8_t, spacing)

  void play(const Ts &...x) override { this->parent_->set_line_spacing(this->spacing_.value(x...)); }
};

template<typename... Ts>
class ThermalPrinterSetPrintDensityAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  TEMPLATABLE_VALUE(uint8_t, density)
  TEMPLATABLE_VALUE(uint8_t, break_time)

  void play(const Ts &...x) override {
    this->parent_->set_print_density(this->density_.value(x...), this->break_time_.value(x...));
  }
};

template<typename... Ts>
class ThermalPrinterSetTabPositionsAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  TEMPLATABLE_VALUE(std::string, positions)

  void play(const Ts &...x) override {
    // Parse comma or space separated positions and call set_tab_positions
    // For now, just log - the actual implementation would parse the string
    ESP_LOGD("thermal_printer", "Set tab positions: %s", this->positions_.value(x...).c_str());
    // TODO: Implement tab position parsing and setting
  }
};

template<typename... Ts>
class ThermalPrinterHorizontalTabAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  void play(const Ts &...x) override {
    // Send horizontal tab character (0x09)
    this->parent_->write_byte(0x09);
  }
};

template<typename... Ts>
class ThermalPrinterSetHorizontalPositionAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  TEMPLATABLE_VALUE(uint16_t, position)

  void play(const Ts &...x) override {
    // Send ESC $ nL nH command to set absolute horizontal position
    uint16_t pos = this->position_.value(x...);
    uint8_t cmd[] = {0x1B, '$', static_cast<uint8_t>(pos & 0xFF), static_cast<uint8_t>(pos >> 8)};
    this->parent_->write_array(cmd, 4);
  }
};

template<typename... Ts>
class ThermalPrinterPrintTestPageAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  void play(const Ts &...x) override { this->parent_->print_test_page(); }
};

template<typename... Ts>
class ThermalPrinterRunDemoAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  TEMPLATABLE_VALUE(bool, show_qr_code)
  TEMPLATABLE_VALUE(bool, show_barcode)
  TEMPLATABLE_VALUE(bool, show_text_styles)
  TEMPLATABLE_VALUE(bool, show_inverse)
  TEMPLATABLE_VALUE(bool, show_rotation)
  TEMPLATABLE_VALUE(bool, show_upside_down)

  void play(const Ts &...x) override {
    bool qr = this->show_qr_code_.value(x...);
    bool bc = this->show_barcode_.value(x...);
    bool txt = this->show_text_styles_.value(x...);
    bool inv = this->show_inverse_.value(x...);
    bool rot = this->show_rotation_.value(x...);
    bool upside = this->show_upside_down_.value(x...);

    // If no specific flags set, run full demo
    if (!qr && !bc && !txt && !inv && !rot && !upside) {
      this->parent_->run_demo(true, true, true, true, true, true);
    } else {
      this->parent_->run_demo(qr, bc, txt, inv, rot, upside);
    }
  }
};

template<typename... Ts>
class ThermalPrinterSendRawCommandAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  TEMPLATABLE_VALUE(std::string, command)

  void play(const Ts &...x) override {
    // Parse comma-separated string into vector of bytes
    std::vector<uint8_t> command_bytes;
    std::string cmd = this->command_.value(x...);

    // Remove spaces and parse comma-separated values
    std::string::size_type pos = 0;
    while (pos < cmd.length()) {
      std::string::size_type comma_pos = cmd.find(',', pos);
      std::string byte_str;
      if (comma_pos == std::string::npos) {
        byte_str = cmd.substr(pos);
        pos = cmd.length();
      } else {
        byte_str = cmd.substr(pos, comma_pos - pos);
        pos = comma_pos + 1;
      }

      // Trim whitespace and convert to int
      byte_str.erase(0, byte_str.find_first_not_of(" \t"));
      byte_str.erase(byte_str.find_last_not_of(" \t") + 1);

      if (!byte_str.empty()) {
        int byte_val = std::stoi(byte_str);
        if (byte_val >= 0 && byte_val <= 255) {
          command_bytes.push_back(static_cast<uint8_t>(byte_val));
        }
      }
    }

    this->parent_->send_raw_command(command_bytes);
  }
};

template<typename... Ts>
class ThermalPrinterSetTextIndentationAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  TEMPLATABLE_VALUE(uint8_t, spaces)

  void play(const Ts &...x) override {
    this->parent_->set_text_indentation(this->spaces_.value(x...));
  }
};

template<typename... Ts>
class ThermalPrinterResetTextIndentationAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  void play(const Ts &...x) override {
    this->parent_->reset_text_indentation();
  }
};

template<typename... Ts>
class ThermalPrinterFeedPaperDotsAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  TEMPLATABLE_VALUE(uint8_t, dots)

  void play(const Ts &...x) override {
    this->parent_->feed_paper_dots(this->dots_.value(x...));
  }
};

template<typename... Ts>
class ThermalPrinterPrintAndFeedLinesAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  TEMPLATABLE_VALUE(uint8_t, lines)

  void play(const Ts &...x) override {
    this->parent_->print_and_feed_lines(this->lines_.value(x...));
  }
};

template<typename... Ts>
class ThermalPrinterSetSleepModeAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  TEMPLATABLE_VALUE(uint16_t, timeout_seconds)

  void play(const Ts &...x) override {
    this->parent_->set_sleep_mode(this->timeout_seconds_.value(x...));
  }
};

template<typename... Ts>
class ThermalPrinterWakeUpAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  void play(const Ts &...x) override {
    this->parent_->wake_up();
  }
};

template<typename... Ts>
class ThermalPrinterResetFormattingAction : public Action<Ts...>, public Parented<ThermalPrinterDisplay> {
 public:
  void play(const Ts &...x) override {
    this->parent_->reset_all_formatting();
  }
};




}  // namespace thermal_printer
}  // namespace esphome

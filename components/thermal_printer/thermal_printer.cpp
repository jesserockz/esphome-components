#include "thermal_printer.h"

#include <cinttypes>
#include <sstream>

namespace esphome {
namespace thermal_printer {

static const char *const TAG = "thermal_printer";

static const uint8_t ESC = 0x1B;
static const uint8_t GS = 0x1D;

static const uint8_t INIT_PRINTER_CMD[] = {ESC, 0x40};
static const uint8_t BAUD_RATE_9600_CMD[] = {ESC, '#', '#', 'S', 'B', 'D', 'R', 0x80, 0x25, 0x00, 0x00};
static const uint8_t BAUD_RATE_115200_CMD[] = {ESC, '#', '#', 'S', 'B', 'D', 'R', 0x00, 0xC2, 0x01, 0x00};

// Font size commands based on GS ! n format from datasheet
static const uint8_t FONT_SIZE_CMD[] = {GS, '!'};
// Reset to default print mode using ESC @ (initialization)
static const uint8_t PRINT_MODE_RESET_CMD[] = {ESC, '@'};

// QR Code commands based on datasheet GS (k pL pH cn fn m format
// Set QR code module size (3x3 points) - GS ( k 03 00 31 43 03
static const uint8_t QR_CODE_MODULE_SIZE_CMD[] = {GS, 0x28, 0x6B, 0x03, 0x00, 0x31, 0x43, 0x03};
// Set QR code error correction level L - GS ( k 03 00 31 45 30
static const uint8_t QR_CODE_ERROR_CORRECTION_CMD[] = {GS, 0x28, 0x6B, 0x03, 0x00, 0x31, 0x45, 0x30};
// Store QR code data prefix - GS ( k pL pH 31 50 30 [data]
static const uint8_t QR_CODE_STORE_PREFIX[] = {GS, 0x28, 0x6B}; // pL pH will be calculated
// Print QR code - GS ( k 03 00 31 51 30
static const uint8_t QR_CODE_PRINT_CMD[] = {GS, 0x28, 0x6B, 0x03, 0x00, 0x31, 0x51, 0x30};

// Barcode commands based on datasheet - GS k m format
static const uint8_t BARCODE_HEIGHT_CMD[] = {GS, 'h'}; // Set barcode height
static const uint8_t BARCODE_WIDTH_CMD[] = {GS, 'w'}; // Set barcode width
static const uint8_t BARCODE_HRI_POS_CMD[] = {GS, 'H'}; // Set HRI character position
static const uint8_t BARCODE_PRINT_CMD[] = {GS, 'k'}; // Print barcode command
// Default barcode settings
static const uint8_t DEFAULT_BARCODE_HEIGHT = 162; // Default height in dots
static const uint8_t DEFAULT_BARCODE_WIDTH = 3; // Default width multiplier
static const uint8_t DEFAULT_HRI_POSITION = 0; // No HRI characters

// Paper cutting commands based on datasheet
static const uint8_t PAPER_CUT_FULL_CMD[] = {ESC, 'i'}; // Full cut - ESC i
static const uint8_t PAPER_CUT_PARTIAL_CMD[] = {GS, 'V', 1}; // Partial cut - GS V 1
static const uint8_t PAPER_CUT_FEED_PREFIX[] = {GS, 'V'}; // GS V m [n] for cut with feed

// Text formatting commands
static const uint8_t TEXT_ALIGN_CMD[] = {ESC, 'a'}; // ESC a n - text alignment
static const uint8_t LINE_SPACING_CMD[] = {ESC, '3'}; // ESC 3 n - line spacing

// Character encoding commands
static const uint8_t DEFAULT_LINE_SPACING_CMD[] = {ESC, '2'}; // ESC 2 - default spacing
static const uint8_t PRINT_DENSITY_CMD[] = {0x12, '#'}; // DC2 # n - print density

// Text style commands
static const uint8_t BOLD_ON_CMD[] = {ESC, 'E', 1}; // ESC E 1 - bold on
static const uint8_t BOLD_OFF_CMD[] = {ESC, 'E', 0}; // ESC E 0 - bold off
static const uint8_t UNDERLINE_CMD[] = {ESC, '-'}; // ESC - n - underline
static const uint8_t UNDERLINE_OFF_CMD[] = {ESC, '-', 0}; // ESC - 0 - underline off
static const uint8_t UPSIDE_DOWN_ON_CMD[] = {ESC, '{',1 }; // ESC { n - upside down mode on
static const uint8_t UPSIDE_DOWN_OFF_CMD[] = {ESC, '{', 0}; // ESC { n - upside down mode off
static const uint8_t DOUBLE_STRIKE_ON_CMD[] = {ESC, 'G', 1}; // ESC G 1 - double strike on
static const uint8_t DOUBLE_STRIKE_OFF_CMD[] = {ESC, 'G', 0}; // ESC G 0 - double strike off
static const uint8_t INVERSE_ON_CMD[] = {GS, 'B', 1}; // GS B 1 - inverse on
static const uint8_t INVERSE_OFF_CMD[] = {GS, 'B', 0}; // GS B 0 - inverse off
static const uint8_t ROTATE_90_ON_CMD[] = {ESC, 'V', 1}; // ESC V n - rotation (n=1 for 90-degree clockwise)
static const uint8_t ROTATE_90_OFF_CMD[] = {ESC, 'V', 0}; // ESC V n - rotation (n=0 for normal orientation)

// Printer control commands
static const uint8_t TEST_PAGE_CMD[] = {0x12, 'T'}; // DC2 T - print test page
static const uint8_t SLEEP_MODE_CMD[] = {ESC, '8'}; // ESC 8 n1 n2 - sleep mode

// Chinese mode commands removed - they interfere with character encoding
// Use charset/codepage commands instead for proper character support

static const uint8_t BYTES_PER_LOOP = 120;

void ThermalPrinterDisplay::setup() {
  ESP_LOGD(TAG, "Setting up Thermal Printer Display");

  this->init_internal_(this->get_buffer_length_());
  ESP_LOGD(TAG, "Buffer length: %d bytes", this->get_buffer_length_());

  // Initialize printer with proper sequence
  this->init_();
  ESP_LOGD(TAG, "Thermal Printer initialized successfully");

  // Note: Commented baud rate change - keep default 9600 baud for stability
  // Some printer modules don't handle baud rate changes reliably
  // this->write_array(BAUD_RATE_115200_CMD, sizeof(BAUD_RATE_115200_CMD));
  // delay(10);
  // this->parent_->set_baud_rate(115200);
  // this->parent_->load_settings();
  // delay(10);
}

void ThermalPrinterDisplay::init_() {
  if (this->send_wakeup_) {
    ESP_LOGD(TAG, "Sending printer initialization command (ESC @)");
    this->write_array(INIT_PRINTER_CMD, sizeof(INIT_PRINTER_CMD));
    delay(100); // Give printer time to initialize
    ESP_LOGD(TAG, "Printer initialization command sent");
  } else {
    ESP_LOGD(TAG, "Skipping printer initialization (send_wakeup: false)");
  }
}

void ThermalPrinterDisplay::print_text(std::string text, uint8_t font_width, uint8_t font_height, uint8_t font_type) {
  ESP_LOGD(TAG, "Text printing: '%s' with font_width=%d, font_height=%d, font_type=%d", text.c_str(), font_width, font_height, font_type);
  
  // Apply current formatting state first
  if (this->bold_state_) {
    this->write_array(BOLD_ON_CMD, sizeof(BOLD_ON_CMD));
  }
  else {
    this->write_array(BOLD_OFF_CMD, sizeof(BOLD_OFF_CMD));
  }
  
  if (this->underline_state_ > 0) {
    uint8_t underline_cmd[] = {0x1B, 0x2D, this->underline_state_}; // ESC - n
    this->write_array(underline_cmd, sizeof(underline_cmd));
  }
  else {
    this->write_array(UNDERLINE_OFF_CMD, sizeof(UNDERLINE_OFF_CMD));
  }
  
  if (this->upside_down_state_) {
    this->write_array(UPSIDE_DOWN_ON_CMD, sizeof(UPSIDE_DOWN_ON_CMD));
  }
  else {
    this->write_array(UPSIDE_DOWN_OFF_CMD, sizeof(UPSIDE_DOWN_OFF_CMD));
  }
  
  if (this->font_type_state_ > 0) {
    uint8_t font_type_cmd[] = {0x1B, 0x4D, this->font_type_state_}; // ESC M n
    this->write_array(font_type_cmd, sizeof(font_type_cmd));
  }
  else {
    uint8_t font_type_cmd[] = {0x1B, 0x4D, 0x00}; // ESC M 0 (Font A)
    this->write_array(font_type_cmd, sizeof(font_type_cmd));
  }
  
  // Apply current alignment state
  if (this->alignment_state_ != 0) {
    uint8_t align_cmd[] = {0x1B, 0x61, this->alignment_state_}; // ESC a n
    this->write_array(align_cmd, sizeof(align_cmd));
  }
  else {
    uint8_t align_cmd[] = {0x1B, 0x61, 0x00}; // ESC a 0 (left align)
    this->write_array(align_cmd, sizeof(align_cmd));
  }
  
  // Apply font size if not default (1x1)
  if (font_width > 1 || font_height > 1) {
    // Clamp values to valid range (1-8)
    font_width = clamp<uint8_t>(font_width, 1, 8);
    font_height = clamp<uint8_t>(font_height, 1, 8);
    
    // Convert to ESC/POS format: width bits 0-2, height bits 4-6
    // Subtract 1 because ESC/POS uses 0-7 for 1x-8x
    uint8_t escpos_value = (font_width - 1) | ((font_height - 1) << 4);
    
    uint8_t size_cmd[] = {0x1D, 0x21, escpos_value};
    this->write_array(size_cmd, sizeof(size_cmd));
    ESP_LOGD(TAG, "Applied font size: %dx%d (ESC/POS value: %d)", font_width, font_height, escpos_value);
  }

  // Apply font type override if specified (overrides state)
  if (font_type > 0) {
    uint8_t clamped_font_type = clamp<uint8_t>(font_type, 0, 1);
    uint8_t font_type_cmd[] = {0x1B, 0x4D, clamped_font_type}; // ESC M n
    this->write_array(font_type_cmd, sizeof(font_type_cmd));
    ESP_LOGD(TAG, "Applied font type override: %s (%d)", (clamped_font_type == 0) ? "Font A (12x24)" : "Font B (9x17)", clamped_font_type);
  }
  
  // Add indentation spaces if configured
  for (uint8_t i = 0; i < this->text_indentation_; i++) {
    this->write_byte(' ');
  }
  
  // Send the text characters directly
  for (char c : text) {
    this->write_byte(c);
  }
  this->write_byte('\n');  // Simple newline
  
  // Reset font size to default after printing if it was changed
  if (font_width > 1 || font_height > 1) {
    uint8_t reset_cmd[] = {0x1D, 0x21, 0x00};
    this->write_array(reset_cmd, sizeof(reset_cmd));
    ESP_LOGD(TAG, "Reset font size to default (1x1)");
  }

  // Reset font type to Font A if it was changed
  if (font_type > 0) {
    uint8_t font_type_reset_cmd[] = {0x1B, 0x21, 0x00}; // ESC ! 0 (Font A)
    this->write_array(font_type_reset_cmd, sizeof(font_type_reset_cmd));
    ESP_LOGD(TAG, "Reset font type to Font A (12x24)");
  }
  
  ESP_LOGD(TAG, "Text printing complete");
}

void ThermalPrinterDisplay::thermal_print_text_with_formatting(
    const std::string &text, uint8_t font_width, uint8_t font_height, uint8_t font_type, bool bold, bool double_strike, uint8_t underline,
    bool upside_down, bool rotation,
    bool inverse, bool chinese_mode, uint8_t alignment, uint8_t charset, uint8_t codepage, uint8_t character_spacing) {
  ESP_LOGD(TAG, "thermal_print_text_with_formatting: text='%s'", text.c_str());
  ESP_LOGD(TAG, "Formatting: font=%dx%d, type=%d, bold=%d, double_strike=%d, underline=%d, align=%d, charset=%d, codepage=%d, spacing=%d", font_width, font_height, font_type, bold, double_strike, underline, alignment, charset, codepage, character_spacing);
  
  // Save current state to restore after scoped formatting
  bool saved_bold = this->bold_state_;
  uint8_t saved_underline = this->underline_state_;
  bool saved_upside_down = this->upside_down_state_;
  bool saved_inverse = this->inverse_state_;
  bool saved_rotation = this->rotation_state_;
  uint8_t saved_alignment = this->alignment_state_;
  uint8_t saved_charset = this->current_charset_;
  uint8_t saved_codepage = this->current_codepage_;
  
  // Check if any formatting is actually requested (non-default values)
  bool has_formatting = (font_width > 1 || font_height > 1 || font_type > 0 || bold || double_strike || underline > 0 || upside_down || 
                        rotation || inverse || chinese_mode ||
                        alignment > 0 || charset > 0 || codepage > 0 || character_spacing > 0);
  
  if (!has_formatting) {
    // No formatting needed - use simple text printing with default font size
    ESP_LOGD(TAG, "No formatting requested, using simple text printing");
    this->print_text(text, 1, 1);  // 1x1 = default font size
  } else {
    // Formatting requested - implement safe formatting features one by one
    ESP_LOGD(TAG, "Applying safe formatting features");
    
    // Apply font size first if specified
    if (font_width > 1 || font_height > 1) {
      // Clamp values to valid range (1-8)
      uint8_t clamped_width = clamp<uint8_t>(font_width, 1, 8);
      uint8_t clamped_height = clamp<uint8_t>(font_height, 1, 8);
      
      // Convert to ESC/POS format
      uint8_t escpos_value = (clamped_width - 1) | ((clamped_height - 1) << 4);
      
      uint8_t size_cmd[] = {0x1D, 0x21, escpos_value};
      this->write_array(size_cmd, sizeof(size_cmd));
      ESP_LOGD(TAG, "Applied font size: %dx%d (ESC/POS: %d)", clamped_width, clamped_height, escpos_value);
    }

    // Apply font type selection (Font A/B) if specified
    if (font_type > 0) {
      // Clamp to valid range (0=Font A, 1=Font B)
      uint8_t clamped_font_type = clamp<uint8_t>(font_type, 0, 1);
      
      // ESC ! n command - bit 0 controls font type
      // 0 = Font A (12x24), 1 = Font B (9x17)
      uint8_t font_type_cmd[] = {0x1B, 0x21, clamped_font_type};
      this->write_array(font_type_cmd, sizeof(font_type_cmd));
      ESP_LOGD(TAG, "Applied font type: %s (%d)", (clamped_font_type == 0) ? "Font A (12x24)" : "Font B (9x17)", clamped_font_type);
    }

    // Apply character set (ESC R n) if specified
    if (charset > 0) {
      uint8_t clamped_charset = clamp<uint8_t>(charset, 0, 15);
      uint8_t charset_cmd[] = {0x1B, 0x52, clamped_charset}; // ESC R n
      this->write_array(charset_cmd, sizeof(charset_cmd));
      ESP_LOGD(TAG, "Applied character set: %d (0=USA, 1=France, 2=Germany, etc.)", clamped_charset);
    }

    // Apply code page (ESC t n) if specified  
    if (codepage > 0) {
      uint8_t clamped_codepage = clamp<uint8_t>(codepage, 0, 47);
      uint8_t codepage_cmd[] = {0x1B, 0x74, clamped_codepage}; // ESC t n
      this->write_array(codepage_cmd, sizeof(codepage_cmd));
      ESP_LOGD(TAG, "Applied code page: %d (0=CP437, 1=Katakana, 2=CP850, etc.)", clamped_codepage);
    }

    // Apply character spacing (ESC SP n) if specified
    if (character_spacing > 0) {
      uint8_t clamped_spacing = clamp<uint8_t>(character_spacing, 0, 255);
      uint8_t spacing_cmd[] = {0x1B, 0x20, clamped_spacing}; // ESC SP n
      this->write_array(spacing_cmd, sizeof(spacing_cmd));
      ESP_LOGD(TAG, "Applied character spacing: %d (in 0.125mm units = %.2fmm)", clamped_spacing, clamped_spacing * 0.125f);
    }
    
    // Apply alignment if specified
    if (alignment > 0) {
      uint8_t align_cmd[] = {0x1B, 0x61, (uint8_t)alignment};
      this->write_array(align_cmd, sizeof(align_cmd));
      ESP_LOGD(TAG, "Applied text alignment: %d", alignment);
    }
    
    // Add bold formatting
    if (bold) {
      this->write_array(BOLD_ON_CMD, sizeof(BOLD_ON_CMD));
      ESP_LOGD(TAG, "Applied bold formatting");
    }
    
    // Add double-strike formatting (ESC G n) - overlapping dots for darker text
    if (double_strike) {
      this->write_array(DOUBLE_STRIKE_ON_CMD, sizeof(DOUBLE_STRIKE_ON_CMD));
      ESP_LOGD(TAG, "Applied double-strike formatting (overlapping dots)");
    }
    
    // Add underline formatting
    if (underline > 0) {
      uint8_t underline_cmd[] = {0x1B, 0x2D, underline};
      this->write_array(underline_cmd, sizeof(underline_cmd));
      ESP_LOGD(TAG, "Applied underline formatting: %d", underline);
    }
    
    // Add inverse printing formatting
    if (inverse) {
      this->write_array(INVERSE_ON_CMD, sizeof(INVERSE_ON_CMD));
      ESP_LOGD(TAG, "Applied inverse formatting");
    }
    
    // Add upside down formatting
    if (upside_down) {
      this->write_array(UPSIDE_DOWN_ON_CMD, sizeof(UPSIDE_DOWN_ON_CMD));
      ESP_LOGD(TAG, "Applied upside down formatting");
    }
    
    // Add 90-degree rotation formatting
    if (rotation) {
      this->write_array(ROTATE_90_ON_CMD, sizeof(ROTATE_90_ON_CMD));
      ESP_LOGD(TAG, "Applied 90-degree rotation formatting");
    }
    
    // Print the text directly (font size already applied above)
    for (char c : text) {
      this->write_byte(c);
    }
    this->write_byte('\n');  // Simple newline
    
    // Reset formatting after printing to avoid affecting subsequent prints
    if (font_width > 1 || font_height > 1) {
      uint8_t size_reset_cmd[] = {0x1D, 0x21, 0x00};
      this->write_array(size_reset_cmd, sizeof(size_reset_cmd));
      ESP_LOGD(TAG, "Reset font size to default (1x1)");
    }

    // Reset font type to Font A if it was changed
    if (font_type > 0) {
      uint8_t font_type_reset_cmd[] = {0x1B, 0x21, 0x00}; // ESC ! 0 (Font A)
      this->write_array(font_type_reset_cmd, sizeof(font_type_reset_cmd));
      ESP_LOGD(TAG, "Reset font type to Font A (12x24)");
    }

    // Reset character set to USA if it was changed
    if (charset > 0) {
      uint8_t charset_reset_cmd[] = {0x1B, 0x52, 0x00}; // ESC R 0 (USA)
      this->write_array(charset_reset_cmd, sizeof(charset_reset_cmd));
      ESP_LOGD(TAG, "Reset character set to USA");
    }

    // Reset code page to CP437 if it was changed
    if (codepage > 0) {
      uint8_t codepage_reset_cmd[] = {0x1B, 0x74, 0x00}; // ESC t 0 (CP437)
      this->write_array(codepage_reset_cmd, sizeof(codepage_reset_cmd));
      ESP_LOGD(TAG, "Reset code page to CP437");
    }

    // Reset character spacing to default if it was changed
    if (character_spacing > 0) {
      uint8_t spacing_reset_cmd[] = {0x1B, 0x20, 0x00}; // ESC SP 0
      this->write_array(spacing_reset_cmd, sizeof(spacing_reset_cmd));
      ESP_LOGD(TAG, "Reset character spacing to default (0)");
    }
    
    // Reset bold if it was applied
    if (bold) {
      this->write_array(BOLD_OFF_CMD, sizeof(BOLD_OFF_CMD));
      ESP_LOGD(TAG, "Reset bold formatting");
    }
    
    // Reset double-strike if it was applied
    if (double_strike) {
      this->write_array(DOUBLE_STRIKE_OFF_CMD, sizeof(DOUBLE_STRIKE_OFF_CMD));
      ESP_LOGD(TAG, "Reset double-strike formatting");
    }
    
    // Reset underline if it was applied
    if (underline > 0) {
      this->write_array(UNDERLINE_OFF_CMD, sizeof(UNDERLINE_OFF_CMD));
      ESP_LOGD(TAG, "Reset underline formatting");
    }
    
    // Reset inverse if it was applied
    if (inverse) {
      this->write_array(INVERSE_OFF_CMD, sizeof(INVERSE_OFF_CMD));
      ESP_LOGD(TAG, "Reset inverse formatting");
    }
    
    // Reset upside down if it was applied
    if (upside_down) {
      this->write_array(UPSIDE_DOWN_OFF_CMD, sizeof(UPSIDE_DOWN_OFF_CMD));
      ESP_LOGD(TAG, "Reset upside down formatting");
    }
    
    // Reset rotation if it was applied
    if (rotation) {
      this->write_array(ROTATE_90_OFF_CMD, sizeof(ROTATE_90_OFF_CMD));
      ESP_LOGD(TAG, "Reset rotation formatting");
    }
    
    if (bold) {
      this->write_array(BOLD_OFF_CMD, sizeof(BOLD_OFF_CMD));
      ESP_LOGD(TAG, "Reset bold formatting");
    }
    
    if (alignment > 0) {
      uint8_t align_reset_cmd[] = {0x1B, 0x61, 0x00};  // Reset to left align
      this->write_array(align_reset_cmd, sizeof(align_reset_cmd));
      ESP_LOGD(TAG, "Reset text alignment");
    }
  }
  
  ESP_LOGD(TAG, "thermal_print_text_with_formatting complete");
}

void ThermalPrinterDisplay::set_printer_settings(uint8_t line_spacing, uint8_t print_density, uint8_t break_time) {
  ESP_LOGD(TAG, "Setting printer settings: line_spacing=%d, density=%d, break_time=%d", 
           line_spacing, print_density, break_time);
  
  // Set line spacing (ESC 3 n)
  uint8_t spacing_cmd[] = {0x1B, 0x33, line_spacing};
  this->write_array(spacing_cmd, sizeof(spacing_cmd));
  
  // Set print density and break time (ESC 7 n1 n2)
  uint8_t density_cmd[] = {0x1B, 0x37, print_density, break_time};
  this->write_array(density_cmd, sizeof(density_cmd));
  
  ESP_LOGD(TAG, "Printer settings applied");
}

void ThermalPrinterDisplay::reset_printer_settings() {
  ESP_LOGD(TAG, "Resetting printer settings to defaults");
  
  // Reset to default values: line_spacing=30, density=10, break_time=4
  this->set_printer_settings(30, 10, 4);
  
  // Send ESC @ to reset printer to default state
  uint8_t reset_cmd[] = {0x1B, 0x40};
  this->write_array(reset_cmd, sizeof(reset_cmd));
  
  ESP_LOGD(TAG, "Printer settings reset complete");
}

void ThermalPrinterDisplay::build_formatting_prefix_(std::vector<uint8_t> &prefix) {
  // Build ESC/POS command sequence based on current formatting state

  ESP_LOGD(TAG, "Building format prefix - states: align=%d bold=%d underline=%d ud=%d inv=%d rot=%d",
           this->alignment_state_, this->bold_state_, this->underline_state_,
           this->upside_down_state_,
           this->inverse_state_, this->rotation_state_);

  // Text alignment (must come first)
  if (this->alignment_state_ != 0) {
    prefix.insert(prefix.end(), {0x1B, 0x61, this->alignment_state_}); // ESC a n
    ESP_LOGD(TAG, "Added alignment command: ESC a %d", this->alignment_state_);
  }

  // Bold/emphasized text
  if (this->bold_state_) {
    prefix.insert(prefix.end(), {0x1B, 0x45, 0x01}); // ESC E 1
    ESP_LOGD(TAG, "Added bold command: ESC E 1");
  }

  // Underline
  if (this->underline_state_ > 0) {
    prefix.insert(prefix.end(), {0x1B, 0x2D, this->underline_state_}); // ESC - n
    ESP_LOGD(TAG, "Added underline command: ESC - %d", this->underline_state_);
  }

  // Upside down (character rotation)
  if (this->upside_down_state_) {
    prefix.insert(prefix.end(), {0x1B, 0x7B, 0x01}); // ESC { 1
    ESP_LOGD(TAG, "Added upside down command: ESC { 1");
  }

  // Inverse printing
  if (this->inverse_state_) {
    prefix.insert(prefix.end(), {0x1D, 0x42, 0x01}); // GS B 1
    ESP_LOGD(TAG, "Added inverse command: GS B 1");
  }

  // 90-degree rotation
  if (this->rotation_state_) {
    prefix.insert(prefix.end(), {0x1B, 0x56, 0x01}); // ESC V 1
    ESP_LOGD(TAG, "Added rotation command: ESC V 1");
  }

  ESP_LOGD(TAG, "Format prefix complete, %d bytes added", prefix.size());
}

void ThermalPrinterDisplay::new_line(uint8_t lines) {
  if (lines == 0) {
    ESP_LOGW(TAG, "new_line called with 0 lines, ignoring");
    return;
  }

  if (lines > 10) {
    ESP_LOGW(TAG, "new_line called with %d lines (>10), clamping to 10", lines);
    lines = 10;
  }

  ESP_LOGD(TAG, "Adding %d new lines", lines);
  for (uint8_t i = 0; i < lines; i++) {
    this->write_byte('\n');
  }
}

void ThermalPrinterDisplay::print_qrcode(std::string data) {
  this->init_();

  // QR code sequence based on datasheet:
  // 1. Set QR code module size (3x3 dots)
  this->write_array(QR_CODE_MODULE_SIZE_CMD, sizeof(QR_CODE_MODULE_SIZE_CMD));

  // 2. Set error correction level L
  this->write_array(QR_CODE_ERROR_CORRECTION_CMD, sizeof(QR_CODE_ERROR_CORRECTION_CMD));

  // 3. Store QR code data - GS ( k pL pH 31 50 30 [data]
  size_t data_len = data.length() + 3; // +3 for (31 50 30) prefix
  uint8_t len_low = data_len & 0xFF;
  uint8_t len_high = (data_len >> 8) & 0xFF;

  this->write_array(QR_CODE_STORE_PREFIX, sizeof(QR_CODE_STORE_PREFIX));
  this->write_byte(len_low);
  this->write_byte(len_high);
  this->write_byte(0x31); // cn
  this->write_byte(0x50); // fn (Store data function)
  this->write_byte(0x30); // m (model)
  this->write_str(data.c_str());

  // 4. Print the QR code
  this->write_array(QR_CODE_PRINT_CMD, sizeof(QR_CODE_PRINT_CMD));
}

void ThermalPrinterDisplay::print_barcode(std::string barcode, BarcodeType type) {
  ESP_LOGD(TAG, "Printing barcode: type=%d, data='%s'", type, barcode.c_str());

  // Validate barcode data length based on type
  size_t data_len = barcode.length();
  bool valid_length = false;

  switch (type) {
    case UPC_A:
      valid_length = (data_len >= 11 && data_len <= 12);
      break;
    case UPC_E:
      valid_length = (data_len >= 11 && data_len <= 12);
      break;
    case EAN13:
      valid_length = (data_len >= 12 && data_len <= 13);
      break;
    case EAN8:
      valid_length = (data_len >= 7 && data_len <= 8);
      break;
    case CODE39:
    case CODE93:
    case CODE128:
    case CODABAR:
      valid_length = (data_len >= 1 && data_len <= 255);
      break;
    case ITF:
      valid_length = (data_len >= 1 && data_len <= 255 && (data_len % 2) == 0);
      break;
    default:
      ESP_LOGE(TAG, "Invalid barcode type: %d", type);
      return;
  }

  if (!valid_length) {
    ESP_LOGE(TAG, "Invalid barcode data length %d for type %d", data_len, type);
    return;
  }

  // Complete printer reset to clear any formatting issues
  uint8_t full_reset[] = {0x1B, 0x40}; // ESC @ - Initialize printer
  this->write_array(full_reset, sizeof(full_reset));
  delay(200); // Give printer time to reset
  
  // Map barcode types to format 1 command values (0-6) and format 2 for advanced types
  uint8_t barcode_type_cmd;
  bool use_format2 = false;
  
  switch (type) {
    case UPC_A:
      barcode_type_cmd = 0; // Format 1: GS k 0
      break;
    case UPC_E:
      barcode_type_cmd = 1; // Format 1: GS k 1
      break;
    case EAN13:
      barcode_type_cmd = 2; // Format 1: GS k 2
      break;
    case EAN8:
      barcode_type_cmd = 3; // Format 1: GS k 3
      break;
    case CODE39:
      barcode_type_cmd = 4; // Format 1: GS k 4
      break;
    case ITF:
      barcode_type_cmd = 5; // Format 1: GS k 5
      break;
    case CODABAR:
      barcode_type_cmd = 6; // Format 1: GS k 6
      break;
    case CODE93:
      barcode_type_cmd = 72; // Format 2: GS k 72
      use_format2 = true;
      break;
    case CODE128:
      barcode_type_cmd = 73; // Format 2: GS k 73
      use_format2 = true;
      break;
    default:
      ESP_LOGE(TAG, "Unsupported barcode type: %d", type);
      return;
  }

  // Send barcode command
  uint8_t barcode_cmd[] = {0x1D, 0x6B, barcode_type_cmd}; // GS k m
  this->write_array(barcode_cmd, sizeof(barcode_cmd));
  
  if (use_format2) {
    // Format 2: GS k m n data (length-prefixed)
    this->write_byte(data_len); // Send length first
    this->write_str(barcode.c_str());
  } else {
    // Format 1: GS k m data NUL (null-terminated)
    this->write_str(barcode.c_str());
    this->write_byte(0x00); // NULL terminator
  }

  ESP_LOGD(TAG, "Barcode sent: type=%d, format=%s, length=%d", 
           barcode_type_cmd, use_format2 ? "2" : "1", data_len);
}

void ThermalPrinterDisplay::cut_paper() {
  ESP_LOGD(TAG, "Cutting paper (full cut)");
  this->write_array(PAPER_CUT_FULL_CMD, sizeof(PAPER_CUT_FULL_CMD));
}

void ThermalPrinterDisplay::cut_paper(uint8_t mode, uint8_t feed_lines) {
  ESP_LOGD(TAG, "Cutting paper with mode %d, feed lines %d", mode, feed_lines);

  if (mode == 0) {
    // Full cut
    this->write_array(PAPER_CUT_FULL_CMD, sizeof(PAPER_CUT_FULL_CMD));
  } else if (mode == 1) {
    // Partial cut
    this->write_array(PAPER_CUT_PARTIAL_CMD, sizeof(PAPER_CUT_PARTIAL_CMD));
  } else if (mode == 66) {
    // Cut with feed - GS V 66 n
    this->write_array(PAPER_CUT_FEED_PREFIX, sizeof(PAPER_CUT_FEED_PREFIX));
    this->write_byte(66);
    this->write_byte(feed_lines);
  } else {
    ESP_LOGW(TAG, "Invalid cut mode: %d", mode);
  }
}

void ThermalPrinterDisplay::set_text_alignment(uint8_t alignment) {
  if (alignment > 2) {
    ESP_LOGW(TAG, "Invalid alignment %d, clamping to 2", alignment);
    alignment = 2;
  }

  // Track alignment state and send command immediately
  this->alignment_state_ = alignment;
  
  uint8_t align_cmd[] = {0x1B, 0x61, alignment}; // ESC a n
  this->write_array(align_cmd, sizeof(align_cmd));
  
  ESP_LOGD(TAG, "Set text alignment: %d (0=left, 1=center, 2=right)", alignment);
}

void ThermalPrinterDisplay::set_line_spacing(uint8_t spacing) {
  if (spacing == 0) {
    // Reset to default line spacing
    ESP_LOGD(TAG, "Resetting to default line spacing");
    this->write_array(DEFAULT_LINE_SPACING_CMD, sizeof(DEFAULT_LINE_SPACING_CMD));
  } else {
    ESP_LOGD(TAG, "Setting line spacing to %d dots", spacing);
    this->write_array(LINE_SPACING_CMD, sizeof(LINE_SPACING_CMD));
    this->write_byte(spacing);
  }
}

void ThermalPrinterDisplay::set_print_density(uint8_t density, uint8_t break_time) {
  // Validate ranges according to datasheet
  density = clamp<uint8_t>(density, 0, 31); // D4-D0 bits
  break_time = clamp<uint8_t>(break_time, 0, 7); // D7-D5 bits

  uint8_t density_byte = density | (break_time << 5);
  ESP_LOGD(TAG, "Setting print density %d, break time %d (combined byte: 0x%02X)",
           density, break_time, density_byte);

  this->write_array(PRINT_DENSITY_CMD, sizeof(PRINT_DENSITY_CMD));
  this->write_byte(density_byte);
}

void ThermalPrinterDisplay::queue_data_(std::vector<uint8_t> data) {
  for (size_t i = 0; i < data.size(); i += BYTES_PER_LOOP) {
    std::vector<uint8_t> chunk(data.begin() + i, data.begin() + std::min(i + BYTES_PER_LOOP, data.size()));
    this->queue_.push(chunk);
  }
}
void ThermalPrinterDisplay::queue_data_(const uint8_t *data, size_t size) {
  for (size_t i = 0; i < size; i += BYTES_PER_LOOP) {
    size_t chunk_size = std::min(i + BYTES_PER_LOOP, size) - i;
    std::vector<uint8_t> chunk(data + i, data + i + chunk_size);
    this->queue_.push(chunk);
  }
}

void ThermalPrinterDisplay::loop() {
  // Process print queue
  if (!this->queue_.empty()) {
    std::vector<uint8_t> data = this->queue_.front();
    this->queue_.pop();

    ESP_LOGV(TAG, "Writing %d bytes from queue (%d items remaining)",
             data.size(), this->queue_.size());
    this->write_array(data.data(), data.size());
  }
  
}

static uint16_t count = 0;

void ThermalPrinterDisplay::update() {
  ESP_LOGD(TAG, "Display update triggered");
  this->do_update_();
  this->write_to_device_();
  ESP_LOGD(TAG, "Display update complete, pixels drawn: %d", count);
  count = 0;
}

void ThermalPrinterDisplay::write_to_device_() {
  if (this->buffer_ == nullptr) {
    ESP_LOGW(TAG, "Buffer is null, cannot write to device");
    return;
  }

  ESP_LOGD(TAG, "Writing raster image to device: %dx%d pixels", this->get_width(), this->get_height());

  // Raster bit-image command: GS v 0 m xL xH yL yH [data]
  // Based on datasheet: GS v 30 00 xL xH yL yH data
  uint8_t header[] = {0x1D, 0x76, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00};

  uint16_t width_bytes = this->get_width() / 8;  // Convert pixels to bytes
  uint16_t height = this->get_height();

  // Validate dimensions
  if (width_bytes == 0 || height == 0) {
    ESP_LOGW(TAG, "Invalid image dimensions: %d bytes width, %d height", width_bytes, height);
    return;
  }

  header[3] = 0;  // Mode (0 = normal)
  header[4] = width_bytes & 0xFF;        // xL
  header[5] = (width_bytes >> 8) & 0xFF; // xH
  header[6] = height & 0xFF;             // yL
  header[7] = (height >> 8) & 0xFF;      // yH

  ESP_LOGD(TAG, "Raster header: mode=%d, width_bytes=%d, height=%d",
           header[3], width_bytes, height);

  this->queue_data_(header, sizeof(header));
  this->queue_data_(this->buffer_, this->get_buffer_length_());

  ESP_LOGD(TAG, "Queued %d bytes of raster data", this->get_buffer_length_());
}

void ThermalPrinterDisplay::draw_absolute_pixel_internal(int x, int y, Color color) {
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

void ThermalPrinterDisplay::set_90_degree_rotation(bool enable) {
  // Track rotation state and send command immediately
  this->rotation_state_ = enable;
  
  uint8_t rotation_cmd[] = {0x1B, 0x56, static_cast<uint8_t>(enable ? 0x01 : 0x00)}; // ESC V n
  this->write_array(rotation_cmd, sizeof(rotation_cmd));
  
  ESP_LOGD(TAG, "Set 90-degree rotation: %s", enable ? "enabled" : "disabled");
}

void ThermalPrinterDisplay::set_inverse_printing(bool enable) {
  // Track inverse state and send command immediately  
  this->inverse_state_ = enable;
  
  uint8_t inverse_cmd[] = {0x1D, 0x42, static_cast<uint8_t>(enable ? 0x01 : 0x00)}; // GS B n
  this->write_array(inverse_cmd, sizeof(inverse_cmd));
  
  ESP_LOGD(TAG, "Set inverse printing: %s", enable ? "enabled" : "disabled");
}

void ThermalPrinterDisplay::set_upside_down_printing(bool enable) {
  // Track upside down state and send command immediately  
  this->upside_down_state_ = enable;
  
  uint8_t upside_down_cmd[] = {0x1B, 0x7B, static_cast<uint8_t>(enable ? 0x01 : 0x00)}; // ESC { n
  this->write_array(upside_down_cmd, sizeof(upside_down_cmd));
  
  ESP_LOGD(TAG, "Set upside down printing: %s", enable ? "enabled" : "disabled");
}

void ThermalPrinterDisplay::set_chinese_mode(bool enable) {
  ESP_LOGD(TAG, "Chinese/Japanese character mode state: %s (no commands sent)", enable ? "enabled" : "disabled");
  
  // Only track the state - don't send FS commands that interfere with character encoding
  // Character encoding is handled by charset (ESC R n) and codepage (ESC t n) commands
  this->chinese_mode_state_ = enable;
}

void ThermalPrinterDisplay::set_charset(uint8_t charset) {
  if (charset > 15) {
    ESP_LOGW(TAG, "Invalid charset %d, clamping to 15", charset);
    charset = 15;
  }
  
  ESP_LOGD(TAG, "Setting character set to %d (0=USA, 1=France, 2=Germany, etc.)", charset);
  
  // Send ESC R n command to set international character set
  uint8_t charset_cmd[] = {ESC, 'R', charset};
  this->write_array(charset_cmd, sizeof(charset_cmd));
  
  // Store current charset for reference
  this->current_charset_ = charset;
}

void ThermalPrinterDisplay::set_codepage(uint8_t codepage) {
  if (codepage > 47) {
    ESP_LOGW(TAG, "Invalid codepage %d, clamping to 47", codepage);
    codepage = 47;
  }
  
  ESP_LOGD(TAG, "Setting code page to %d (0=CP437, 1=Katakana, 2=CP850, etc.)", codepage);
  
  // Send ESC t n command to set character code table
  uint8_t codepage_cmd[] = {ESC, 't', codepage};
  this->write_array(codepage_cmd, sizeof(codepage_cmd));
  
  // Store current codepage for reference
  this->current_codepage_ = codepage;
}

void ThermalPrinterDisplay::reset_all_formatting() {
  ESP_LOGD(TAG, "Resetting all formatting to defaults");
  
  // Reset all state variables to defaults
  this->bold_state_ = false;
  this->underline_state_ = 0;
  this->upside_down_state_ = false;
  this->font_type_state_ = 0;
  this->alignment_state_ = 0;
  this->inverse_state_ = false;
  this->rotation_state_ = false;
  this->chinese_mode_state_ = false;
  this->current_charset_ = 0;
  this->current_codepage_ = 0;
  this->text_indentation_ = 0;
  
  // Sync hardware to match the reset state
  this->apply_current_formatting_state();
  
  ESP_LOGD(TAG, "All formatting reset to defaults - state and hardware synchronized");
}

void ThermalPrinterDisplay::apply_current_formatting_state() {
  ESP_LOGD(TAG, "Applying current formatting state to hardware");
  
  // Send hardware reset first
  this->write_array(PRINT_MODE_RESET_CMD, sizeof(PRINT_MODE_RESET_CMD));
  delay(100);
  
  // Apply current state to hardware
  if (this->alignment_state_ != 0) {
    uint8_t align_cmd[] = {0x1B, 0x61, this->alignment_state_};
    this->write_array(align_cmd, sizeof(align_cmd));
  }
  
  if (this->bold_state_) {
    uint8_t bold_cmd[] = {0x1B, 0x45, 0x01};
    this->write_array(bold_cmd, sizeof(bold_cmd));
  }
  
  if (this->underline_state_ > 0) {
    uint8_t underline_cmd[] = {0x1B, 0x2D, this->underline_state_};
    this->write_array(underline_cmd, sizeof(underline_cmd));
  }
  
  if (this->upside_down_state_) {
    uint8_t upside_cmd[] = {0x1B, 0x7B, 0x01};
    this->write_array(upside_cmd, sizeof(upside_cmd));
  }
  
  if (this->inverse_state_) {
    uint8_t inverse_cmd[] = {0x1D, 0x42, 0x01};
    this->write_array(inverse_cmd, sizeof(inverse_cmd));
  }
  
  if (this->rotation_state_) {
    uint8_t rotation_cmd[] = {0x1B, 0x56, 0x01};
    this->write_array(rotation_cmd, sizeof(rotation_cmd));
  }
  
  if (this->current_charset_ != 0) {
    uint8_t charset_cmd[] = {0x1B, 0x52, this->current_charset_};
    this->write_array(charset_cmd, sizeof(charset_cmd));
  }
  
  if (this->current_codepage_ != 0) {
    uint8_t codepage_cmd[] = {0x1B, 0x74, this->current_codepage_};
    this->write_array(codepage_cmd, sizeof(codepage_cmd));
  }
  
  ESP_LOGD(TAG, "Current formatting state applied to hardware");
}

void ThermalPrinterDisplay::send_raw_command(const std::vector<uint8_t> &command) {
  if (!command.empty()) {
    this->write_array(command.data(), command.size());
    ESP_LOGD(TAG, "Sent raw command: %d bytes", command.size());

    // Log the command bytes for debugging
    std::string cmd_str = "Command bytes: ";
    for (size_t i = 0; i < command.size(); i++) {
      cmd_str += std::to_string(command[i]);
      if (i < command.size() - 1) cmd_str += ", ";
    }
    ESP_LOGD(TAG, "%s", cmd_str.c_str());
  } else {
    ESP_LOGW(TAG, "Attempted to send empty raw command");
  }
}
void ThermalPrinterDisplay::run_demo(bool show_header, bool show_intro, bool show_footer, bool show_text_styles, bool show_inverse, bool show_rotation, bool show_upside_down, bool show_qr_code, bool show_barcode) {
  ESP_LOGD(TAG, "Running comprehensive printer demo with flags: header=%s, intro=%s, footer=%s, formatting=%s, inverse=%s, rotation=%s, upside_down=%s QR=%s, barcode=%s, ",
           show_header ? "yes" : "no", show_intro ? "yes" : "no", show_footer ? "yes" : "no",
           show_text_styles ? "yes" : "no", show_inverse ? "yes" : "no", show_rotation ? "yes" : "no",
           show_upside_down ? "yes" : "no", show_qr_code ? "yes" : "no", show_barcode ? "yes" : "no");

  this->init_();

  // Reset printer to default state
  this->write_array(PRINT_MODE_RESET_CMD, sizeof(PRINT_MODE_RESET_CMD));
  this->reset_all_formatting();
  delay(200); // Allow printer to process reset
    
  // === HITCHHIKER'S GUIDE THEMED HEADER ===
  if (show_header) {
    ESP_LOGD(TAG, "Demo: Hitchhiker's Guide themed header");
    this->set_text_alignment(1); // Center
    this->new_line(1);
    this->set_text_style(true, 0, false); // Bold
    this->print_text("DON'T PANIC", 2, 2); // Large bold
    this->new_line(1);
    this->set_text_style(false, 0, false); // Reset to normal first
    this->set_text_style(false, 1, false); // Normal, underlined
    this->print_text("The Hitchhiker's Guide to", 1, 1);
    this->new_line(1);
    this->print_text("Thermal Printing", 1, 1);
    this->new_line(1);
    this->set_text_style(false, 0, false); // Reset all formatting including underline
    this->print_text("42nd Edition - for ESPHome");
    this->new_line(2);
  }

  if (show_intro) {
    ESP_LOGD(TAG, "Demo: Introduction and formatting showcase");
    this->reset_all_formatting(); // Reset formatting

    // Opening introduction
    this->print_text("Welcome, intergalactic traveler!");
    this->new_line(1);
    this->print_text("This thermal printer demo");
    this->print_text("will showcase the Answer to the");
    this->print_text("Ultimate Question of Printing:");
    this->new_line(1);
    
    this->set_text_alignment(1); // Center for the answer
    this->set_text_style(true, 0, false); // Bold
    this->print_text("42 printing features!", 2, 2);
    this->set_text_style(false, 0, false); // Reset
    this->set_text_alignment(0);
    this->new_line(2);
  }

  // === TEXT STYLES AND FORMATTING ===
  if (show_text_styles) {
    ESP_LOGD(TAG, "Demo: Text styles and formatting");

    // Explicit formatting reset at start of section
    this->reset_all_formatting();

    this->set_text_alignment(1); // Center
    this->set_text_style(true, 2, false); // Bold underline
    this->print_text("=== FORD PREFECT'S ===", 2, 1);
    this->print_text("=== STYLE GUIDE ===", 2, 1);
    this->set_text_style(false, 0, false); // Reset all formatting
    this->set_text_alignment(0); // Left
    this->new_line(1);

    // Font size progression
    this->print_text("Font sizes for towel labels:");
    this->print_text("Size 1x1: Compact towel tag", 1, 1);
    this->print_text("Size 2x1: Bath towel", 2, 1);
    this->print_text("Size 3x2: Beach towel", 3, 2);
    this->print_text("Size 4x3: Hoopy!", 4, 3);

    // Text alignment demonstration
    this->new_line(1);
    this->print_text("Text alignment test:");
    
    this->set_text_alignment(0); // Left
    this->print_text("Left: Earth (mostly harmless)");
    
    this->set_text_alignment(1); // Center
    this->print_text("Center: Milliways Restaurant");
    
    this->set_text_alignment(2); // Right
    this->print_text("Right: Magrathea Industries");
    
    this->set_text_alignment(0); // Reset to left

    // Text styling combinations
    this->new_line(1);
    this->print_text("Vogon Poetry Styles:");

    this->set_text_style(true, 0, false); // Bold
    this->print_text("Bold: Oh freddled gruntbuggly!");
    this->set_text_style(false, 0, false); // Reset bold

    this->set_text_style(false, 1, false); // Single underline
    this->print_text("Underline: Thy micturations");
    this->set_text_style(false, 0, false); // Reset underline

    this->set_text_style(false, 2, false); // Double underline
    this->print_text("Double: Are to me");
    this->set_text_style(false, 0, false); // Reset underline

    this->set_text_style(true, 1, false); // Bold + underline
    this->print_text("Bold+Under: As plurdled gabbleblotchits!");
    this->set_text_style(false, 0, false); // Reset all
  
    this->print_text("Normal: Thy micturations");
    
    this->set_text_style(false, 2, false); // Double underline
    this->print_text("Double underlined: are to me");

    this->set_text_style(true, 1, false); // Bold + underline
    this->print_text("Bold+underlined: As plurdled", 2, 1);

    this->set_text_style(false, 0, false); // Reset
    this->print_text("(Vogon poetry causes nausea)");
  }

  if (show_inverse) {
    ESP_LOGD(TAG, "Demo: Inverse printing");

    // Explicit formatting reset
    this->reset_all_formatting();

    this->set_text_alignment(1); // Center
    this->set_text_style(true, 0, false);
    this->print_text("=== INVERSE MODE ===", 0);  // Reduced from 1 to 0
    this->set_text_style(false, 0, false);
    this->set_text_alignment(0);
    this->new_line(1);

    this->print_text("Normal: So long and thanks");
    this->new_line(1);

    this->set_inverse_printing(true);
    this->print_text("Inverse: for all the fish!");
    this->new_line(1);
    this->print_text("Black background mode");
    this->new_line(1);
    this->set_inverse_printing(false);

    this->print_text("Back to normal printing");
    this->new_line(2);
  }

  if (show_rotation) {
    ESP_LOGD(TAG, "Demo: 90-degree rotation");

    // Explicit formatting reset
    this->reset_all_formatting();

    this->set_text_alignment(1); // Center
    this->set_text_style(true, 0, false);
    this->print_text("=== ROTATION ===", 0);  // Normal rotation for header
    this->set_text_style(false, 0, false);
    this->set_text_alignment(0);
    this->new_line(1);

    this->print_text("Normal orientation:");
    this->new_line(1);
    this->print_text("Hitchhiker's Guide");
    this->new_line(1);

    this->set_90_degree_rotation(true);
    this->print_text("90 deg: Mostly Harmless");
    this->new_line(1);
    this->print_text("Rotated text mode");
    this->new_line(1);
    this->set_90_degree_rotation(false);

    this->print_text("Rotation disabled");
    this->new_line(2);
  }

  if (show_upside_down) {
    ESP_LOGD(TAG, "Demo: Upside-down text");

    // Explicit formatting reset
    this->reset_all_formatting();

    this->set_text_alignment(1); // Center
    this->set_text_style(true, 0, false);
    this->print_text("=== UPSIDE DOWN ===", 0);
    this->set_text_style(false, 0, false);
    this->set_text_alignment(0);
    this->new_line(1);

    this->print_text("Normal orientation:");
    this->new_line(1);
    this->print_text("Don't Panic!");
    this->new_line(1);

    this->set_upside_down_printing(true);
    this->print_text("Upside down: Always know where");
    this->new_line(1);
    this->print_text("your towel is!");
    this->new_line(1);
    this->set_upside_down_printing(false);

    this->print_text("Back to normal text");
    this->new_line(2);
  }

  if (show_qr_code) {
    ESP_LOGD(TAG, "Demo: QR codes");

    this->reset_all_formatting();
    this->set_text_alignment(1); // Center
    this->set_text_style(true, 0, false);
    this->print_text("=== QR CODES ===", 0);  // Normal rotation for header
    this->set_text_style(false, 0, false);
    this->new_line(1);

    this->print_text("The Ultimate Answer:");
    this->new_line(1);

    // QR code with the answer to everything
    this->print_qrcode("42");
    this->new_line(1);

    this->print_text("Scan this for the Answer!");
    this->new_line(1);

    // QR with a longer message
    this->print_text("Hitchhiker's wisdom:");
    this->new_line(1);
    this->print_qrcode("Don't Panic! Always carry a towel.");
    this->new_line(1);

    this->print_text("Essential travel advice");
    this->new_line(2);
  }

  if (show_barcode) {
    ESP_LOGD(TAG, "Demo: Barcodes");

    this->reset_all_formatting();

    this->set_text_alignment(1); // Center
    this->set_text_style(true, 0, false);
    this->print_text("=== BARCODES ===", 0);  // Normal rotation for header
    this->set_text_style(false, 0, false);
    this->new_line(1);

    this->print_text("Universal Product Codes:");
    this->new_line(1);

    // CODE128 barcode - most versatile
    this->print_text("CODE128: Towel SKU");
    this->new_line(1);
    this->print_barcode("TOWEL42", CODE128);
    this->new_line(1);

    // CODE39 for alphanumeric
    this->print_text("CODE39: Babel Fish ID");
    this->new_line(1);
    this->print_barcode("BABEL42", CODE39);
    this->new_line(1);

    // EAN13 for numeric (needs 12-13 digits)
    this->print_text("EAN13: Guide Edition");
    this->new_line(1);
    this->print_barcode("424242424242", EAN13);
    this->new_line(2);
  }

  if (show_footer) {
    ESP_LOGD(TAG, "Demo: Footer and completion message");
    // Footer with completion message
    this->reset_all_formatting();
    this->set_text_alignment(1); // Center
    this->set_text_style(true, 0, false); // Bold
    this->print_text("Demo Complete!", 2, 1);  // Bold + wide using font_width
    this->new_line(1);
    this->set_text_style(false, 0, false);

    this->print_text("Thank you for printing");
    this->new_line(1);
    this->print_text("with Thermal Printer!");
    this->new_line(1);
    this->print_text("Remember: Always carry a towel");
    this->print_text("and a working thermal printer.");
    this->new_line(2);
    
    // Reset all settings to defaults
    this->reset_all_formatting();
  }
  ESP_LOGD(TAG, "Demo completed successfully");
}

void ThermalPrinterDisplay::set_text_style(bool bold, uint8_t underline, bool upside_down, uint8_t font_type) {
  // Track formatting state for next text print (line-buffered printer)
  this->bold_state_ = bold;
  this->underline_state_ = underline;
  this->upside_down_state_ = upside_down;
  this->font_type_state_ = font_type;

  ESP_LOGD(TAG, "Set text style - bold:%s, underline:%d, upside_down:%s, font_type:%d",
           bold ? "true" : "false", underline, upside_down ? "true" : "false", font_type);
}

void ThermalPrinterDisplay::print_test_page() {
  ESP_LOGD(TAG, "Printing test page");

  // Print header
  this->set_text_style(true, 0, false); // Bold
  this->print_text("=== TEST PAGE ===\n", 0);
  this->set_text_style(false, 0, false); // Reset

  // Test basic text
  this->print_text("Basic text printing test\n", 0);

  // Test font sizes
  for (uint8_t size = 0; size <= 7; size++) {
    this->print_text("Font size " + std::to_string(size) + "\n", size);
  }

  // Test text styles
  this->set_text_style(true, 0, false); // Bold
  this->print_text("Bold text\n", 0);

  this->set_text_style(false, 1, false); // Underline
  this->print_text("Underlined text\n", 0);

  this->print_text("Double width\n", 2, 1); // Use font_width instead

  this->set_text_style(true, 1, false); // Bold + underline
  this->print_text("Bold+Under+Wide\n", 2, 1); // Wide using font_width

  // Reset styles with explicit commands
  this->set_text_style(false, 0, false);
  uint8_t reset_cmds[] = {0x1B, 0x45, 0x00, 0x1B, 0x2D, 0x00}; // Bold off, underline off
  this->write_array(reset_cmds, sizeof(reset_cmds));
  // Reset font size to default (1x1)
  uint8_t font_size_reset[] = {0x1D, 0x21, 0x00}; // GS ! 0
  this->write_array(font_size_reset, sizeof(font_size_reset));

  // Test alignment
  this->set_text_alignment(0); // Left
  this->print_text("Left aligned\n", 0);

  this->set_text_alignment(1); // Center
  this->print_text("Center aligned\n", 0);

  this->set_text_alignment(2); // Right
  this->print_text("Right aligned\n", 0);

  this->set_text_alignment(0); // Reset to left

  // Test QR code (small)
  this->print_text("\nQR Test:\n", 0);
  this->print_qrcode("ESP32");

  // Test Barcode (Code39)
  this->print_text("\nBarcode Test:\n", 0);
  this->print_barcode("4242424242", CODE39);

  // End of test page
  this->print_text("\n=== END TEST ===\n", 0);
  this->new_line(3); // Feed paper for clean tear

  ESP_LOGD(TAG, "Test page completed");
}

// Status functions completely removed - hardware doesn't support reliable status reporting
// Both DLE EOT and ESC v commands return random/garbage values instead of actual status

void ThermalPrinterDisplay::set_sleep_mode(uint16_t timeout_seconds) {
  // ESC 8 n m - Set sleep mode timeout
  // Convert seconds to appropriate units for the printer
  uint8_t timeout_low = timeout_seconds & 0xFF;
  uint8_t timeout_high = (timeout_seconds >> 8) & 0xFF;

  uint8_t cmd[] = {0x1B, 0x38, timeout_low, timeout_high};
  this->write_array(cmd, sizeof(cmd));

  ESP_LOGD(TAG, "Sleep mode set to %d seconds", timeout_seconds);
}

void ThermalPrinterDisplay::wake_up() {
  ESP_LOGD(TAG, "Waking up printer from sleep mode");
  
  // Send any character to wake the printer (space character is common)
  this->write_byte(0x20);  // Space character
  delay(100);  // Give printer time to wake up
  
  // Send initialization command to ensure printer is ready
  this->write_array(INIT_PRINTER_CMD, sizeof(INIT_PRINTER_CMD));
  delay(100);  // Give printer time to initialize
  
  ESP_LOGD(TAG, "Printer wake-up complete");
}

void ThermalPrinterDisplay::set_tab_positions(const std::string &positions) {
  // ESC D n1 n2 ... nk NUL - Set horizontal tab positions
  std::vector<uint8_t> cmd;
  cmd.push_back(0x1B);  // ESC
  cmd.push_back(0x44);  // D

  // Simple parsing of comma or space separated positions
  std::string current_number;
  int position_count = 0;

  for (size_t i = 0; i < positions.length() && position_count < 32; i++) {
    char c = positions[i];

    if ((c >= '0' && c <= '9')) {
      current_number += c;
    } else if ((c == ',' || c == ' ' || c == '\t') && !current_number.empty()) {
      // Parse the number using simple conversion to avoid exceptions
      int pos = 0;
      bool valid = true;
      for (char digit : current_number) {
        if (digit >= '0' && digit <= '9') {
          pos = pos * 10 + (digit - '0');
        } else {
          valid = false;
          break;
        }
      }

      if (valid && pos >= 1 && pos <= 255) {
        cmd.push_back(static_cast<uint8_t>(pos));
        position_count++;
      }
      current_number.clear();
    }
  }

  // Handle the last number if exists
  if (!current_number.empty() && position_count < 32) {
    int pos = 0;
    bool valid = true;
    for (char digit : current_number) {
      if (digit >= '0' && digit <= '9') {
        pos = pos * 10 + (digit - '0');
      } else {
        valid = false;
        break;
      }
    }

    if (valid && pos >= 1 && pos <= 255) {
      cmd.push_back(static_cast<uint8_t>(pos));
      position_count++;
    }
  }

  cmd.push_back(0);  // NUL terminator

  this->write_array(cmd.data(), cmd.size());
  ESP_LOGD(TAG, "Set %d tab positions", position_count);
}

void ThermalPrinterDisplay::horizontal_tab() {
  // Send horizontal tab character (HT = 0x09)
  uint8_t cmd = 0x09;
  this->write_array(&cmd, 1);
}

void ThermalPrinterDisplay::set_horizontal_position(uint16_t position) {
  // ESC $ nL nH - Set absolute horizontal print position
  uint8_t pos_low = position & 0xFF;
  uint8_t pos_high = (position >> 8) & 0xFF;

  uint8_t cmd[] = {0x1B, 0x24, pos_low, pos_high};
  this->write_array(cmd, sizeof(cmd));

  ESP_LOGD(TAG, "Set horizontal position to %d", position);
}

void ThermalPrinterDisplay::set_text_indentation(uint8_t spaces) {
  // Store indentation as number of spaces to prepend to each print
  if (spaces > 50) {
    ESP_LOGE(TAG, "Invalid text indentation %d, must be 0-50 spaces", spaces);
    return;
  }
  
  this->text_indentation_ = spaces;
  ESP_LOGD(TAG, "Set text indentation to %d spaces", spaces);
}

void ThermalPrinterDisplay::reset_text_indentation() {
  // Reset indentation to default (0 spaces)
  this->text_indentation_ = 0;
  ESP_LOGD(TAG, "Reset text indentation to default");
}

void ThermalPrinterDisplay::feed_paper_dots(uint8_t dots) {
  // ESC J n - Feed paper n dots (0.125mm units)
  uint8_t cmd[] = {0x1B, 0x4A, dots};
  this->write_array(cmd, sizeof(cmd));
  
  ESP_LOGD(TAG, "Feed paper %d dots (%.2f mm)", dots, dots * 0.125f);
}

void ThermalPrinterDisplay::print_and_feed_lines(uint8_t lines) {
  // ESC d n - Print buffer data and feed n lines
  uint8_t cmd[] = {0x1B, 0x64, lines};
  this->write_array(cmd, sizeof(cmd));
  
  ESP_LOGD(TAG, "Print buffer and feed %d lines", lines);
}



bool ThermalPrinterDisplay::get_cover_problem() {
  // Send ESC v 3 command to check cover status
  uint8_t esc_v_cmd[] = {0x1B, 0x76, 3};
  
  // Clear any pending data
  while (this->available()) {
    this->read();
  }
  
  this->write_array(esc_v_cmd, sizeof(esc_v_cmd));
  this->flush();
  
  // Wait for response
  uint32_t start = millis();
  std::vector<uint8_t> response;
  
  while (millis() - start < 500) {
    if (this->available()) {
      uint8_t byte = this->read();
      response.push_back(byte);
      
      // Read additional bytes if available
      uint32_t read_start = millis();
      while (millis() - read_start < 50) {
        if (this->available()) {
          response.push_back(this->read());
          read_start = millis();
        }
      }
      break;
    }
  }
  
  // Cover closed: '00 00' or no response, Cover open: '08' 
  if (response.empty()) {
    return false; // No response = cover closed
  }
  
  // Check if any byte is 0x08 (cover open indicator)
  for (uint8_t byte : response) {
    if (byte == 0x08) {
      return true; // Cover open = problem
    }
  }
  
  return false; // Cover closed = no problem
}
} // namespace thermal_printer
}  // namespace esphome

# Thermal Printer ESPHome Component

This component provides thermal printing functionality for
thermal printer modules based on the CSN-A2 thermal printer mechanism.

## Features

- Text printing with font size control (0-7)
- QR code generation and printing
- 1D barcode printing (UPC, EAN, CODE39, CODE128, etc.)
- Raster image printing via display buffer
- Text styling (bold, underline, double width, upside down)
- Text alignment (left, center, right) 
- 90-degree rotation printing
- Inverse printing (white text on black background)
- Paper cutting control
- **Demo/Debug function with Hitchhiker's Guide to the Galaxy themed content**

## Demo Function

The `run_demo` service showcases all printer capabilities with nerdy, funny content themed around *The Hitchhiker's Guide to the Galaxy*. Perfect for testing functionality and impressing fellow nerds!

### Usage

```yaml
# Run full demo (all capabilities)
service: esphome.your_printer_run_demo

# Run specific capability demos
service: esphome.your_printer_run_demo
data:
  show_qr_code: true
  show_barcode: true
  show_text_styles: false
  show_inverse: false
  show_rotation: false
```

### Demo Features

- **Full Demo Mode**: When called without parameters, runs through all capabilities
- **QR Codes**: Prints "42" and "Don't Panic! Always carry a towel."
- **Barcodes**: Shows CODE128, CODE39, and EAN13 with themed data
- **Text Styles**: Demonstrates all font sizes, bold, underline, double width
- **Alignment**: Shows left, center, and right text alignment
- **Inverse Printing**: White text on black background demos
- **90° Rotation**: Rotated text examples
- **Themed Content**: References to towels, Babel fish, Vogon poetry, and more!

### Service Parameters

- `show_qr_code` (optional, boolean): Print QR code demonstrations
- `show_barcode` (optional, boolean): Print various barcode format demos
- `show_text_styles` (optional, boolean): Show font sizes, styles, and alignment
- `show_inverse` (optional, boolean): Demonstrate inverse printing mode
- `show_rotation` (optional, boolean): Show 90-degree rotated text

When no parameters are specified, all demo sections are enabled.

## Configuration

```yaml
display:
  - platform: thermal_printer
    uart_id: thermal_uart
    height: 200
    id: thermal_printer
    
uart:
  - id: thermal_uart
    tx_pin: GPIO17
    rx_pin: GPIO16
    baud_rate: 9600
```

## Available Actions

### Text Printing
```yaml
- thermal_printer.print_text:
    id: thermal_printer
    text: "Hello World!"
    font_size: 2
```

### Run Demo
```yaml
- thermal_printer.run_demo:
    id: thermal_printer
    show_qr_code: true
    show_barcode: true
    show_text_styles: true
    show_inverse: true
    show_rotation: true
```

### Cut Paper
```yaml
- thermal_printer.cut_paper:
    id: thermal_printer
    cut_mode: 0  # 0=full, 1=partial, 66=cut and feed
    feed_lines: 3
```

### Set Alignment
```yaml
- thermal_printer.set_alignment:
    id: thermal_printer
    alignment: 1  # 0=left, 1=center, 2=right
```

### Set Text Style
```yaml
- thermal_printer.set_text_style:
    id: thermal_printer
    bold: true
    underline: 2  # 0=off, 1=1dot, 2=2dot
    double_width: false
    upside_down: false
```

### Print Test Page
```yaml
- thermal_printer.print_test_page:
    id: thermal_printer
```

## Hardware Requirements

- thermal printer module
- CSN-A2 or compatible thermal printer mechanism
- UART connection (TTL/RS232)
- 5-9V power supply for printer

## Compatible Printers

- thermal printer module
- CSN-A2 thermal printer
- Other ESC/POS compatible thermal printers

## Communication

- Protocol: ESC/POS thermal printer command set
- Interface: UART (TTL/RS232)
- Default baud rate: 9600
- Print width: 58mm (384 dots), 8 dots/mm resolution
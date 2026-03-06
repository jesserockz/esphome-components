you are helping me write a esphome component and esphome yaml configuration for an esp32 to communicate with a thermal printer.
The datasheets folder contains markdown versions of datasheets that I think are for this printer.

Also, I found this library (https://github.com/adafruit/Adafruit-Thermal-Printer-Library) that contains Arduino code that seems to work for most functionalities with this printer, so make sure to review that as well.

Don't run compilations or uploads to the device, I'd like to run it myself.

In the end, I want to support all possible features that this printer offers, and I want to have services exposed to home assistant for easy interaction with the printer.

I think we should focus on:

## Testing Roadmap (Piecemeal Approach)

### Phase 1: Core Text Printing ✅
Test these basic features first to ensure the foundation works:
- [x] Basic text printing (`m5stack_printer.print_text`)
- [x] Font width/height (`font_width: 2, font_height: 1`)
- [x] Alignment (`alignment: 0/1/2`)
- [x] Bold text (`bold: true`)

### Phase 2: Text Formatting 🧪
Test each formatting feature individually:
- [x] Underline modes (`underline: 0/1/2`) ✅ **Tested working**
- [x] Inverse printing (`inverse: true`) ✅ **Tested working**
- [x] Upside down (`upside_down: true`) ✅ **Tested working**
- [x] 90-degree rotation (`rotation: true`) ✅ **Tested working**

### Phase 3: Advanced Features 📋
Test complex features after basics work:
- [X] QR codes
- [X] Barcodes
- [X] Print density/line spacing
- [ ] Paper cutting
- [ ] Demo functions

### Phase 4: Combined Features 🔄
Test feature combinations:
- [X] Bold + underline
- [X] Font size + alignment
- [X] Multiple formatting together

---

## Text Formatting Features

| Feature | Status | Notes |
|---------|--------|-------|
| Alignment (left, center, right) | ✅ **Working** | Tested and confirmed working |
| Bold | ✅ **Working** | Tested and confirmed working |
| Font size | ✅ **Working** | Separate font_width (1-8) and font_height (1-8) parameters |
| ~~Double width~~ | ❌ **Redundant** | Replaced by font_width parameter |
| ~~Double height~~ | ❌ **Redundant** | Replaced by font_height parameter |
| Font A / B | ✅ **Working** | Character font selection (0=Font A 12x24, 1=Font B 9x17) - tested working |
| Underline (all types) | ✅ **Working** | 0=off, 1=1-dot, 2=2-dot underline modes |
| Inverse | ✅ **Working** | White text on black background - tested working |
| Upside down | ✅ **Working** | 180-degree text rotation - tested working |
| 90 degrees | ✅ **Working** | 90-degree clockwise rotation - tested working |
| Character sets | ✅ **Working** | International character sets (0-15) and code pages (0-47) |
| Character spacing | ✅ **Working** | ESC SP command with 0-255 units (0.125mm each) - tested working |
| Emphasized/double-strike | ✅ **Working** | ESC G command for overlapping dots - tested working |

## Print Control Features

| Feature | Status | Notes |
|---------|--------|-------|
| Line spacing | ✅ **Working** | Already implemented |
| Print density | ✅ **Working** | Already implemented |
| Print speed (break time) | ✅ **Working** | Already implemented |
| **Text indentation** | ✅ **Working** | Space-based indentation (0-50 spaces) - universally compatible |
| **Tab stops** | ✅ **Working** | ESC D (set positions) and HT (horizontal tab) - tested working with precise column alignment |
| **Print position** | ✅ **Working** | Horizontal: ESC $ (absolute position), Paper feed: ESC J (dots), ESC d (lines) |
| **Print and feed** | ✅ **Working** | ESC J (feed dots), ESC d (print buffer + feed lines) - tested working |

## Other Features

| Feature | Status | Notes |
|---------|--------|-------|
| Bitmaps | ✅ **Working** | GS v command for raster images - ESPHome display interface with pixel drawing. **Important:** Colors inverted - use `fill(Color::BLACK)` to clear, `draw_pixel_at(x,y,Color::WHITE)` for visible pixels |
| QR codes | ✅ **Working** | Already implemented in existing code |
| Barcodes | ✅ **Working** | Already implemented in existing code |
| Cutting paper | ✅ **Working** | Already implemented |
| Printer settings | ✅ **Working** | Line spacing, density, break time |
| Send wakeup | ✅ **Working** | Configurable init command (not needed for this printer) |
| Sleep management | ✅ **Working** | Complete sleep/wake functionality with debug service |

## Polish & Final Steps

| Item | Status | Notes |
|------|--------|-------|
| introduce configuration flag for model so multiple models can be supported|Let's discuss! My model is QR204|
| check text printing and formatting methods so it's complete with all valid options represented in the various methods| Todo|
| Demo expansion | 🚧 **Planned** | Add Hitchhiker's Guide references for each working feature. Also call the print service for the ESPHOME logo at the start of the demo method. |
| Component rename | 🚧 **Final** | m5stack_printer → thermal_printer (after functionality complete) |

# Thermal Printer ESPHome Component
#
# This component provides thermal printing functionality for
# thermal printer modules based on the CSN-A2 thermal printer mechanism.
#
# Features:
# - Text printing with font size control
# - QR code generation and printing  
# - 1D barcode printing (UPC, EAN, CODE39, CODE128, etc.)
# - Raster image printing via display buffer
#
# Compatible with ESC/POS thermal printer command set
# Communication via UART (TTL/RS232) at 9600 baud default
# Print resolution: 384 dots/line (58mm width), 8 dots/mm

from esphome.const import CONF_ID
import esphome.config_validation as cv

def to_code(config):
    """Component code generation is handled by display.py"""
    pass

# Component schema is defined in display.py
CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.use_id("thermal_printer"),
})

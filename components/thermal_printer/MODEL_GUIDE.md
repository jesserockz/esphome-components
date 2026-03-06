# Thermal Printer - Model Configuration Examples

## Supported Models

The thermal printer component supports multiple printer models with different capabilities:

### M5STACK_THERMAL (Default)
- **Use for**: M5Stack Thermal Unit
- **Capabilities**: QR codes ✅, Barcodes ✅, Sleep mode ✅
- **Status monitoring**: ❌ (hardware limitation)
- **Recommended baud**: 9600
- **Paper cutting**: ❌

```yaml
uart:
  tx_pin: GPIO17
  rx_pin: GPIO16
  baud_rate: 9600  # Recommended for M5Stack units

display:
  platform: thermal_printer
  id: printer
  model: M5STACK_THERMAL  # Default - can be omitted
  height: 50
  auto_clear_enabled: false
```

### CSN_A2 Compatible
- **Use for**: Generic CSN-A2 thermal printer mechanisms
- **Capabilities**: QR codes ✅, Barcodes ✅, Sleep mode ✅
- **Status monitoring**: ✅
- **Recommended baud**: 9600
- **Paper cutting**: ❌

```yaml
uart:
  tx_pin: GPIO17
  rx_pin: GPIO16
  baud_rate: 9600  # Standard for CSN-A2

display:
  platform: thermal_printer
  id: printer
  model: CSN_A2
  height: 50
  auto_clear_enabled: false
```

### GENERIC_58MM
- **Use for**: Standard 58mm thermal printers
- **Capabilities**: Barcodes ✅, Sleep mode ✅
- **Status monitoring**: ✅
- **QR codes**: ❌ (may not be supported)
- **Recommended baud**: 9600
- **Paper cutting**: ❌

```yaml
uart:
  tx_pin: GPIO17
  rx_pin: GPIO16
  baud_rate: 9600  # Most 58mm printers use 9600

display:
  platform: thermal_printer
  id: printer
  model: GENERIC_58MM
  height: 50
  auto_clear_enabled: false
```

### ADAFRUIT_597
- **Use for**: Adafruit Mini Thermal Printer (#597)
- **Capabilities**: Barcodes ✅, Sleep mode ✅
- **Status monitoring**: ✅
- **QR codes**: ❌
- **Recommended baud**: 19200
- **Paper cutting**: ❌

```yaml
uart:
  tx_pin: GPIO17
  rx_pin: GPIO16
  baud_rate: 19200  # Note: Adafruit printers typically use 19200

display:
  platform: thermal_printer
  id: printer
  model: ADAFRUIT_597
  height: 50
  auto_clear_enabled: false
```

### SPARKFUN_10438
- **Use for**: SparkFun Thermal Printer (#10438)
- **Capabilities**: Barcodes ✅, Sleep mode ✅
- **Status monitoring**: ✅
- **QR codes**: ❌
- **Recommended baud**: 19200
- **Paper cutting**: ❌

```yaml
uart:
  tx_pin: GPIO17
  rx_pin: GPIO16
  baud_rate: 19200  # Note: SparkFun printers typically use 19200

display:
  platform: m5stacthermal_printerk_printer
  id: printer
  model: SPARKFUN_10438
  height: 50
  auto_clear_enabled: false
```

## Automatic Feature Enabling/Disabling

When you select a model, the component automatically:

1. **Enables/disables QR code services** based on model capability
2. **Enables/disables status monitoring** based on model capability  
3. **Shows model info in logs** during startup
4. **Validates commands** against model capabilities

For example, if you try to print a QR code on a `GENERIC_58MM` model, you'll see:
```
[W][thermal_printer:123]: QR code printing not supported on model: GENERIC_58MM
```

## Service Behavior

All services work the same way regardless of model, but unsupported features will log warnings:

```yaml
# This works on all models
service: esphome.quick_print
data:
  text_to_print: "Hello World"

# QR codes only work on M5STACK_THERMAL and CSN_A2
service: esphome.print_qrcode  
data:
  qrcode: "https://esphome.io"
```

## Configuration Validation

The component validates your model choice at configuration time:

```yaml
display:
  platform: thermal_printer
  model: INVALID_MODEL  # ❌ This will cause a validation error
```

Valid models: `M5STACK_THERMAL`, `CSN_A2`, `GENERIC_58MM`, `ADAFRUIT_597`, `SPARKFUN_10438`
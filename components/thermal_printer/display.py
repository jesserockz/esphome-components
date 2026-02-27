import esphome.config_validation as cv
import esphome.codegen as cg
from esphome.components import display, uart
from esphome.const import CONF_HEIGHT, CONF_ID, CONF_LAMBDA
from esphome import automation

DEPENDENCIES = ["uart"]

thermal_printer_ns = cg.esphome_ns.namespace("thermal_printer")

ThermalPrinterDisplay = thermal_printer_ns.class_(
    "ThermalPrinterDisplay", display.DisplayBuffer, uart.UARTDevice
)

ThermalPrinterPrintTextAction = thermal_printer_ns.class_(
    "ThermalPrinterPrintTextAction", automation.Action
)

ThermalPrinterPrintQRCodeAction = thermal_printer_ns.class_(
    "ThermalPrinterPrintQRCodeAction", automation.Action
)

ThermalPrinterPrintBarcodeAction = thermal_printer_ns.class_(
    "ThermalPrinterPrintBarcodeAction", automation.Action
)

ThermalPrinterNewLineAction = thermal_printer_ns.class_(
    "ThermalPrinterNewLineAction", automation.Action
)

# Additional action classes for new features
ThermalPrinterCutPaperAction = thermal_printer_ns.class_(
    "ThermalPrinterCutPaperAction", automation.Action
)

ThermalPrinterSetAlignmentAction = thermal_printer_ns.class_(
    "ThermalPrinterSetAlignmentAction", automation.Action
)

ThermalPrinterSetStyleAction = thermal_printer_ns.class_(
    "ThermalPrinterSetStyleAction", automation.Action
)

ThermalPrinterSet90DegreeRotationAction = thermal_printer_ns.class_(
    "ThermalPrinterSet90DegreeRotationAction", automation.Action
)

ThermalPrinterSetInversePrintingAction = thermal_printer_ns.class_(
    "ThermalPrinterSetInversePrintingAction", automation.Action
)

ThermalPrinterSetUpsideDownPrintingAction = thermal_printer_ns.class_(
    "ThermalPrinterSetUpsideDownPrintingAction", automation.Action
)

ThermalPrinterSetChineseModeAction = thermal_printer_ns.class_(
    "ThermalPrinterSetChineseModeAction", automation.Action
)

ThermalPrinterSetLineSpacingAction = thermal_printer_ns.class_(
    "ThermalPrinterSetLineSpacingAction", automation.Action
)

ThermalPrinterSetSleepModeAction = thermal_printer_ns.class_(
    "ThermalPrinterSetSleepModeAction", automation.Action
)

ThermalPrinterWakeUpAction = thermal_printer_ns.class_(
    "ThermalPrinterWakeUpAction", automation.Action
)

ThermalPrinterSetPrintDensityAction = thermal_printer_ns.class_(
    "ThermalPrinterSetPrintDensityAction", automation.Action
)

ThermalPrinterSetTabPositionsAction = thermal_printer_ns.class_(
    "ThermalPrinterSetTabPositionsAction", automation.Action
)

ThermalPrinterHorizontalTabAction = thermal_printer_ns.class_(
    "ThermalPrinterHorizontalTabAction", automation.Action
)

ThermalPrinterSetHorizontalPositionAction = thermal_printer_ns.class_(
    "ThermalPrinterSetHorizontalPositionAction", automation.Action
)

ThermalPrinterPrintTestPageAction = thermal_printer_ns.class_(
    "ThermalPrinterPrintTestPageAction", automation.Action
)

ThermalPrinterRunDemoAction = thermal_printer_ns.class_(
    "ThermalPrinterRunDemoAction", automation.Action
)

ThermalPrinterSendRawCommandAction = thermal_printer_ns.class_(
    "ThermalPrinterSendRawCommandAction", automation.Action
)

ThermalPrinterThermalPrintTextAction = thermal_printer_ns.class_(
    "ThermalPrinterThermalPrintTextAction", automation.Action
)

ThermalPrinterSetTextIndentationAction = thermal_printer_ns.class_(
    "ThermalPrinterSetTextIndentationAction", automation.Action
)

ThermalPrinterResetTextIndentationAction = thermal_printer_ns.class_(
    "ThermalPrinterResetTextIndentationAction", automation.Action
)

ThermalPrinterResetFormattingAction = thermal_printer_ns.class_(
    "ThermalPrinterResetFormattingAction", automation.Action
)

ThermalPrinterFeedPaperDotsAction = thermal_printer_ns.class_(
    "ThermalPrinterFeedPaperDotsAction", automation.Action
)

ThermalPrinterPrintAndFeedLinesAction = thermal_printer_ns.class_(
    "ThermalPrinterPrintAndFeedLinesAction", automation.Action
)

CONF_FONT_SIZE = "font_size"  # Deprecated, use font_width/font_height
CONF_FONT_WIDTH = "font_width"
CONF_FONT_HEIGHT = "font_height"
CONF_FONT_TYPE = "font_type"
CONF_CHARSET = "charset"
CONF_CODEPAGE = "codepage"
CONF_CHARACTER_SPACING = "character_spacing"
CONF_DOUBLE_STRIKE = "double_strike"
CONF_TEXT = "text"
CONF_TEXT_TO_PRINT = "text_to_print"
CONF_QRCODE = "qrcode"
CONF_BARCODE = "barcode"
CONF_TYPE = "type"
CONF_LINES = "lines"
CONF_CUT_MODE = "cut_mode"
CONF_FEED_LINES = "feed_lines"
CONF_ALIGNMENT = "alignment"
CONF_BOLD = "bold"
CONF_UNDERLINE = "underline"
CONF_UPSIDE_DOWN = "upside_down"
CONF_ROTATION = "rotation"
CONF_INVERSE = "inverse"
CONF_CHINESE_MODE = "chinese_mode"
CONF_LINE_SPACING = "line_spacing"
CONF_PRINT_DENSITY = "print_density"
CONF_ENABLE = "enable"
CONF_SPACING = "spacing"
CONF_DENSITY = "density"
CONF_BREAK_TIME = "break_time"
CONF_POSITIONS = "positions"
CONF_POSITION = "position"
CONF_DOTS = "dots" 
CONF_LINES = "lines"
CONF_SHOW_HEADER = "show_header"
CONF_SHOW_INTRODUCTION = "show_introduction"
CONF_SHOW_FOOTER = "show_footer"
CONF_SHOW_QR_CODE = "show_qr_code"
CONF_SHOW_BARCODE = "show_barcode"
CONF_SHOW_TEXT_STYLES = "show_text_styles"
CONF_SHOW_INVERSE = "show_inverse"
CONF_SHOW_ROTATION = "show_rotation"
CONF_SHOW_UPSIDE_DOWN = "show_upside_down"
CONF_SEND_WAKEUP = "send_wakeup"
CONF_TIMEOUT_SECONDS = "timeout_seconds"
CONF_COMMAND = "command"
CONF_SPACES = "spaces"
CONF_MODEL = "model"

# Model types for different printer hardware
ThermalPrinterModel = thermal_printer_ns.enum("ThermalPrinterModel")
MODELS = {
    "M5STACK_THERMAL": ThermalPrinterModel.M5STACK_THERMAL,
    "CSN_A2": ThermalPrinterModel.CSN_A2,
    "GENERIC_58MM": ThermalPrinterModel.GENERIC_58MM,
    "ADAFRUIT_597": ThermalPrinterModel.ADAFRUIT_597,
    "SPARKFUN_10438": ThermalPrinterModel.SPARKFUN_10438,
}

CONFIG_SCHEMA = (
    display.FULL_DISPLAY_SCHEMA.extend(
        {
            cv.GenerateID(): cv.declare_id(ThermalPrinterDisplay),
            cv.Required(CONF_HEIGHT): cv.uint16_t,
            cv.Optional(CONF_MODEL, default="M5STACK_THERMAL"): cv.enum(MODELS, upper=True),
            cv.Optional(CONF_SEND_WAKEUP, default=False): cv.boolean,
        }
    )
    .extend(
        cv.polling_component_schema("never")
    )  # This component should always be manually updated with actions
    .extend(uart.UART_DEVICE_SCHEMA)
)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await display.register_display(var, config)
    await uart.register_uart_device(var, config)

    cg.add(var.set_height(config[CONF_HEIGHT]))
    cg.add(var.set_model(config[CONF_MODEL]))
    cg.add(var.set_send_wakeup(config[CONF_SEND_WAKEUP]))

    if lambda_config := config.get(CONF_LAMBDA):
        lambda_ = await cg.process_lambda(
            lambda_config, [(display.DisplayRef, "it")], return_type=cg.void
        )
        cg.add(var.set_writer(lambda_))


@automation.register_action(
    "thermal_printer.print_text",
    ThermalPrinterPrintTextAction,
    cv.maybe_simple_value(
        cv.Schema(
            {
                cv.GenerateID(): cv.use_id(ThermalPrinterDisplay),
                cv.Required(CONF_TEXT): cv.templatable(cv.string),
                cv.Optional(CONF_FONT_WIDTH, default=1): cv.templatable(cv.int_),
                cv.Optional(CONF_FONT_HEIGHT, default=1): cv.templatable(cv.int_),
                cv.Optional(CONF_FONT_TYPE, default=0): cv.templatable(cv.int_range(min=0, max=1)),
            }
        ),
        key=CONF_TEXT,
    ),
)
async def thermal_printer_print_text_action_to_code(
    config, action_id, template_arg, args
):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])
    templ = await cg.templatable(config[CONF_TEXT], args, cg.std_string)
    cg.add(var.set_text(templ))
    templ = await cg.templatable(config[CONF_FONT_WIDTH], args, cg.uint8)
    cg.add(var.set_font_width(templ))
    templ = await cg.templatable(config[CONF_FONT_HEIGHT], args, cg.uint8)
    cg.add(var.set_font_height(templ))
    templ = await cg.templatable(config[CONF_FONT_TYPE], args, cg.uint8)
    cg.add(var.set_font_type(templ))
    return var


@automation.register_action(
    "esphome.thermalprinter_print_text",
    ThermalPrinterThermalPrintTextAction,
    cv.Schema(
        {
            cv.GenerateID(): cv.use_id(ThermalPrinterDisplay),
            cv.Required(CONF_TEXT_TO_PRINT): cv.templatable(cv.string),
            cv.Optional(CONF_FONT_WIDTH, default=1): cv.templatable(cv.int_),
            cv.Optional(CONF_FONT_HEIGHT, default=1): cv.templatable(cv.int_),
            cv.Optional(CONF_FONT_TYPE, default=0): cv.templatable(cv.int_range(min=0, max=1)),
            cv.Optional(CONF_BOLD, default=False): cv.templatable(cv.boolean),
            cv.Optional(CONF_DOUBLE_STRIKE, default=False): cv.templatable(cv.boolean),
            cv.Optional(CONF_UNDERLINE, default=0): cv.templatable(
                cv.int_range(min=0, max=2)
            ),
            cv.Optional(CONF_UPSIDE_DOWN, default=False): cv.templatable(cv.boolean),
            cv.Optional(CONF_ROTATION, default=False): cv.templatable(cv.boolean),
            cv.Optional(CONF_INVERSE, default=False): cv.templatable(cv.boolean),
            cv.Optional(CONF_CHINESE_MODE, default=False): cv.templatable(cv.boolean),
            cv.Optional(CONF_ALIGNMENT, default=0): cv.templatable(
                cv.int_range(min=0, max=2)
            ),
            cv.Optional(CONF_CHARSET, default=0): cv.templatable(cv.int_range(min=0, max=15)),
            cv.Optional(CONF_CODEPAGE, default=0): cv.templatable(cv.int_range(min=0, max=47)),
            cv.Optional(CONF_CHARACTER_SPACING, default=0): cv.templatable(cv.int_range(min=0, max=255)),
        }
    ),
)
async def thermalprinter_print_text_action_to_code(
    config, action_id, template_arg, args
):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])
    
    # Set all templatable values
    templ = await cg.templatable(config[CONF_TEXT_TO_PRINT], args, cg.std_string)
    cg.add(var.set_text_to_print(templ))
    templ = await cg.templatable(config[CONF_FONT_WIDTH], args, cg.uint8)
    cg.add(var.set_font_width(templ))
    templ = await cg.templatable(config[CONF_FONT_HEIGHT], args, cg.uint8)
    cg.add(var.set_font_height(templ))
    templ = await cg.templatable(config[CONF_FONT_TYPE], args, cg.uint8)
    cg.add(var.set_font_type(templ))
    templ = await cg.templatable(config[CONF_BOLD], args, cg.bool_)
    cg.add(var.set_bold(templ))
    templ = await cg.templatable(config[CONF_DOUBLE_STRIKE], args, cg.bool_)
    cg.add(var.set_double_strike(templ))
    templ = await cg.templatable(config[CONF_UNDERLINE], args, cg.uint8)
    cg.add(var.set_underline(templ))
    templ = await cg.templatable(config[CONF_UPSIDE_DOWN], args, cg.bool_)
    cg.add(var.set_upside_down(templ))
    templ = await cg.templatable(config[CONF_ROTATION], args, cg.bool_)
    cg.add(var.set_rotation(templ))
    templ = await cg.templatable(config[CONF_INVERSE], args, cg.bool_)
    cg.add(var.set_inverse(templ))
    templ = await cg.templatable(config[CONF_CHINESE_MODE], args, cg.bool_)
    cg.add(var.set_chinese_mode(templ))
    templ = await cg.templatable(config[CONF_ALIGNMENT], args, cg.uint8)
    cg.add(var.set_alignment(templ))
    templ = await cg.templatable(config[CONF_CHARSET], args, cg.uint8)
    cg.add(var.set_charset(templ))
    templ = await cg.templatable(config[CONF_CODEPAGE], args, cg.uint8)
    cg.add(var.set_codepage(templ))
    templ = await cg.templatable(config[CONF_CHARACTER_SPACING], args, cg.uint8)
    cg.add(var.set_character_spacing(templ))
    
    return var


@automation.register_action(
    "thermal_printer.print_qrcode",
    ThermalPrinterPrintQRCodeAction,
    cv.maybe_simple_value(
        cv.Schema(
            {
                cv.GenerateID(): cv.use_id(ThermalPrinterDisplay),
                cv.Required(CONF_QRCODE): cv.templatable(cv.string),
            }
        ),
        key=CONF_QRCODE,
    ),
)
async def thermal_printer_print_qrcode_action_to_code(
    config, action_id, template_arg, args
):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])
    templ = await cg.templatable(config[CONF_QRCODE], args, cg.std_string)
    cg.add(var.set_qrcode(templ))
    return var


@automation.register_action(
    "thermal_printer.print_barcode",
    ThermalPrinterPrintBarcodeAction,
    cv.Schema(
        {
            cv.GenerateID(): cv.use_id(ThermalPrinterDisplay),
            cv.Required(CONF_BARCODE): cv.templatable(cv.string),
            cv.Required(CONF_TYPE): cv.templatable(cv.string),
        }
    ),
)
async def thermal_printer_print_barcode_action_to_code(
    config, action_id, template_arg, args
):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])
    templ = await cg.templatable(config[CONF_BARCODE], args, cg.std_string)
    cg.add(var.set_barcode(templ))
    templ = await cg.templatable(config[CONF_TYPE], args, cg.std_string)
    cg.add(var.set_type(templ))
    return var


@automation.register_action(
    "thermal_printer.new_line",
    ThermalPrinterNewLineAction,
    cv.maybe_simple_value(
        cv.Schema(
            {
                cv.GenerateID(): cv.use_id(ThermalPrinterDisplay),
                cv.Required(CONF_LINES): cv.templatable(cv.int_range(min=1, max=255)),
            }
        ),
        key=CONF_LINES,
    ),
)
async def thermal_printer_new_line_action_to_code(
    config, action_id, template_arg, args
):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])
    templ = await cg.templatable(config[CONF_LINES], args, cg.uint8)
    cg.add(var.set_lines(templ))
    return var


@automation.register_action(
    "thermal_printer.set_90_degree_rotation",
    ThermalPrinterSet90DegreeRotationAction,
    cv.Schema(
        {
            cv.GenerateID(): cv.use_id(ThermalPrinterDisplay),
            cv.Required(CONF_ENABLE): cv.templatable(cv.boolean),
        }
    ),
)
async def thermal_printer_set_90_degree_rotation_action_to_code(
    config, action_id, template_arg, args
):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])
    templ = await cg.templatable(config[CONF_ENABLE], args, cg.bool_)
    cg.add(var.set_enable(templ))
    return var


@automation.register_action(
    "thermal_printer.set_inverse_printing",
    ThermalPrinterSetInversePrintingAction,
    cv.Schema(
        {
            cv.GenerateID(): cv.use_id(ThermalPrinterDisplay),
            cv.Required(CONF_ENABLE): cv.templatable(cv.boolean),
        }
    ),
)
async def thermal_printer_set_inverse_printing_action_to_code(
    config, action_id, template_arg, args
):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])
    templ = await cg.templatable(config[CONF_ENABLE], args, cg.bool_)
    cg.add(var.set_enable(templ))
    return var


@automation.register_action(
    "thermal_printer.set_upside_down_printing",
    ThermalPrinterSetUpsideDownPrintingAction,
    cv.Schema(
        {
            cv.GenerateID(): cv.use_id(ThermalPrinterDisplay),
            cv.Required(CONF_ENABLE): cv.templatable(cv.boolean),
        }
    ),
)
async def thermal_printer_set_upside_down_printing_action_to_code(
    config, action_id, template_arg, args
):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])
    templ = await cg.templatable(config[CONF_ENABLE], args, cg.bool_)
    cg.add(var.set_enable(templ))
    return var


# Raw command action
ThermalPrinterSendRawCommandAction = thermal_printer_ns.class_(
    "ThermalPrinterSendRawCommandAction", automation.Action
)


@automation.register_action(
    "thermal_printer.send_raw_command",
    ThermalPrinterSendRawCommandAction,
    cv.Schema(
        {
            cv.GenerateID(): cv.use_id(ThermalPrinterDisplay),
            cv.Required("command"): cv.templatable(cv.string),
        }
    ),
)
async def thermal_printer_send_raw_command_to_code(
    config, action_id, template_arg, args
):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])

    # Set the templatable command string
    command_template = await cg.templatable(config["command"], args, cg.std_string)
    cg.add(var.set_command(command_template))

    return var


@automation.register_action(
    "thermal_printer.set_chinese_mode",
    ThermalPrinterSetChineseModeAction,
    cv.Schema(
        {
            cv.GenerateID(): cv.use_id(ThermalPrinterDisplay),
            cv.Required(CONF_ENABLE): cv.templatable(cv.boolean),
        }
    ),
)
async def thermal_printer_set_chinese_mode_action_to_code(
    config, action_id, template_arg, args
):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])
    templ = await cg.templatable(config[CONF_ENABLE], args, cg.bool_)
    cg.add(var.set_enable(templ))
    return var


@automation.register_action(
    "thermal_printer.set_line_spacing",
    ThermalPrinterSetLineSpacingAction,
    cv.Schema(
        {
            cv.GenerateID(): cv.use_id(ThermalPrinterDisplay),
            cv.Required(CONF_SPACING): cv.templatable(cv.int_range(min=0, max=255)),
        }
    ),
)
async def thermal_printer_set_line_spacing_action_to_code(
    config, action_id, template_arg, args
):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])
    templ = await cg.templatable(config[CONF_SPACING], args, cg.uint8)
    cg.add(var.set_spacing(templ))
    return var


@automation.register_action(
    "thermal_printer.set_print_density",
    ThermalPrinterSetPrintDensityAction,
    cv.Schema(
        {
            cv.GenerateID(): cv.use_id(ThermalPrinterDisplay),
            cv.Required(CONF_DENSITY): cv.templatable(cv.int_range(min=0, max=31)),
            cv.Optional(CONF_BREAK_TIME, default=0): cv.templatable(
                cv.int_range(min=0, max=7)
            ),
        }
    ),
)
async def thermal_printer_set_print_density_action_to_code(
    config, action_id, template_arg, args
):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])
    templ = await cg.templatable(config[CONF_DENSITY], args, cg.uint8)
    cg.add(var.set_density(templ))
    templ = await cg.templatable(config[CONF_BREAK_TIME], args, cg.uint8)
    cg.add(var.set_break_time(templ))
    return var


@automation.register_action(
    "thermal_printer.set_tab_positions",
    ThermalPrinterSetTabPositionsAction,
    cv.Schema(
        {
            cv.GenerateID(): cv.use_id(ThermalPrinterDisplay),
            cv.Required(CONF_POSITIONS): cv.templatable(cv.string),
        }
    ),
)
async def thermal_printer_set_tab_positions_action_to_code(
    config, action_id, template_arg, args
):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])
    templ = await cg.templatable(config[CONF_POSITIONS], args, cg.std_string)
    cg.add(var.set_positions(templ))
    return var


@automation.register_action(
    "thermal_printer.horizontal_tab",
    ThermalPrinterHorizontalTabAction,
    cv.Schema(
        {
            cv.GenerateID(): cv.use_id(ThermalPrinterDisplay),
        }
    ),
)
async def thermal_printer_horizontal_tab_action_to_code(
    config, action_id, template_arg, args
):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])
    return var


@automation.register_action(
    "thermal_printer.set_horizontal_position",
    ThermalPrinterSetHorizontalPositionAction,
    cv.Schema(
        {
            cv.GenerateID(): cv.use_id(ThermalPrinterDisplay),
            cv.Required(CONF_POSITION): cv.templatable(cv.int_range(min=0, max=383)),
        }
    ),
)
async def thermal_printer_set_horizontal_position_action_to_code(
    config, action_id, template_arg, args
):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])
    templ = await cg.templatable(config[CONF_POSITION], args, cg.uint16)
    cg.add(var.set_position(templ))
    return var


@automation.register_action(
    "thermal_printer.cut_paper",
    ThermalPrinterCutPaperAction,
    cv.Schema(
        {
            cv.GenerateID(): cv.use_id(ThermalPrinterDisplay),
            cv.Optional(CONF_CUT_MODE, default=0): cv.templatable(
                cv.int_range(min=0, max=66)
            ),
            cv.Optional(CONF_FEED_LINES, default=0): cv.templatable(
                cv.int_range(min=0, max=255)
            ),
        }
    ),
)
async def thermal_printer_cut_paper_action_to_code(
    config, action_id, template_arg, args
):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])
    templ = await cg.templatable(config[CONF_CUT_MODE], args, cg.uint8)
    cg.add(var.set_cut_mode(templ))
    templ = await cg.templatable(config[CONF_FEED_LINES], args, cg.uint8)
    cg.add(var.set_feed_lines(templ))
    return var


@automation.register_action(
    "thermal_printer.set_alignment",
    ThermalPrinterSetAlignmentAction,
    cv.Schema(
        {
            cv.GenerateID(): cv.use_id(ThermalPrinterDisplay),
            cv.Required(CONF_ALIGNMENT): cv.templatable(
                cv.int_range(min=0, max=2)
            ),  # 0=left, 1=center, 2=right
        }
    ),
)
async def thermal_printer_set_alignment_action_to_code(
    config, action_id, template_arg, args
):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])
    templ = await cg.templatable(config[CONF_ALIGNMENT], args, cg.uint8)
    cg.add(var.set_alignment(templ))
    return var


@automation.register_action(
    "thermal_printer.set_text_style",
    ThermalPrinterSetStyleAction,
    cv.Schema(
        {
            cv.GenerateID(): cv.use_id(ThermalPrinterDisplay),
            cv.Optional(CONF_BOLD, default=False): cv.templatable(cv.boolean),
            cv.Optional(CONF_UNDERLINE, default=0): cv.templatable(
                cv.int_range(min=0, max=2)
            ),
            cv.Optional(CONF_UPSIDE_DOWN, default=False): cv.templatable(cv.boolean),
            cv.Optional(CONF_FONT_TYPE, default=0): cv.templatable(cv.int_range(min=0, max=1)),
        }
    ),
)
async def thermal_printer_set_style_action_to_code(
    config, action_id, template_arg, args
):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])
    templ = await cg.templatable(config[CONF_BOLD], args, cg.bool_)
    cg.add(var.set_bold(templ))
    templ = await cg.templatable(config[CONF_UNDERLINE], args, cg.uint8)
    cg.add(var.set_underline(templ))
    templ = await cg.templatable(config[CONF_UPSIDE_DOWN], args, cg.bool_)
    cg.add(var.set_upside_down(templ))
    templ = await cg.templatable(config[CONF_FONT_TYPE], args, cg.uint8)
    cg.add(var.set_font_type(templ))
    return var


@automation.register_action(
    "thermal_printer.print_test_page",
    ThermalPrinterPrintTestPageAction,
    cv.Schema(
        {
            cv.GenerateID(): cv.use_id(ThermalPrinterDisplay),
        }
    ),
)
async def thermal_printer_print_test_page_action_to_code(
    config, action_id, template_arg, args
):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])
    return var


@automation.register_action(
    "thermal_printer.run_demo",
    ThermalPrinterRunDemoAction,
    cv.Schema(
        {
            cv.GenerateID(): cv.use_id(ThermalPrinterDisplay),
            cv.Optional(CONF_SHOW_HEADER, default=True): cv.templatable(cv.boolean),
            cv.Optional(CONF_SHOW_INTRODUCTION, default=True): cv.templatable(cv.boolean),
            cv.Optional(CONF_SHOW_FOOTER, default=True): cv.templatable(cv.boolean),
            cv.Optional(CONF_SHOW_TEXT_STYLES, default=False): cv.templatable(
                cv.boolean
            ),
            cv.Optional(CONF_SHOW_INVERSE, default=False): cv.templatable(cv.boolean),
            cv.Optional(CONF_SHOW_ROTATION, default=False): cv.templatable(cv.boolean),
            cv.Optional(CONF_SHOW_UPSIDE_DOWN, default=False): cv.templatable(cv.boolean),
            cv.Optional(CONF_SHOW_QR_CODE, default=False): cv.templatable(cv.boolean),
            cv.Optional(CONF_SHOW_BARCODE, default=False): cv.templatable(cv.boolean),
        }
    ),
)
async def thermal_printer_run_demo_action_to_code(
    config, action_id, template_arg, args
):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])

    templ = await cg.templatable(config[CONF_SHOW_HEADER], args, cg.bool_)
    cg.add(var.set_show_text_styles(templ))
    templ = await cg.templatable(config[CONF_SHOW_INTRODUCTION], args, cg.bool_)
    cg.add(var.set_show_text_styles(templ))
    templ = await cg.templatable(config[CONF_SHOW_FOOTER], args, cg.bool_)
    cg.add(var.set_show_text_styles(templ))
    templ = await cg.templatable(config[CONF_SHOW_TEXT_STYLES], args, cg.bool_)
    cg.add(var.set_show_text_styles(templ))
    templ = await cg.templatable(config[CONF_SHOW_INVERSE], args, cg.bool_)
    cg.add(var.set_show_inverse(templ))
    templ = await cg.templatable(config[CONF_SHOW_ROTATION], args, cg.bool_)
    cg.add(var.set_show_rotation(templ))
    templ = await cg.templatable(config[CONF_SHOW_UPSIDE_DOWN], args, cg.bool_)
    cg.add(var.set_show_upside_down(templ))
    templ = await cg.templatable(config[CONF_SHOW_QR_CODE], args, cg.bool_)
    cg.add(var.set_show_qr_code(templ))
    templ = await cg.templatable(config[CONF_SHOW_BARCODE], args, cg.bool_)
    cg.add(var.set_show_barcode(templ))

    return var


# Printer Settings Actions
ThermalPrinterSetSettingsAction = thermal_printer_ns.class_(
    "ThermalPrinterSetSettingsAction", automation.Action
)

@automation.register_action(
    "esphome.set_printer_settings",
    ThermalPrinterSetSettingsAction,
    cv.Schema(
        {
            cv.Required(CONF_ID): cv.use_id(ThermalPrinterDisplay),
            cv.Optional(CONF_LINE_SPACING, default=30): cv.templatable(
                cv.int_range(min=0, max=255)
            ),
            cv.Optional(CONF_PRINT_DENSITY, default=10): cv.templatable(
                cv.int_range(min=0, max=31)
            ),
            cv.Optional(CONF_BREAK_TIME, default=4): cv.templatable(
                cv.int_range(min=0, max=7)
            ),
        }
    ),
)
async def set_printer_settings_action_to_code(config, action_id, template_arg, args):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])
    
    templ = await cg.templatable(config[CONF_LINE_SPACING], args, cg.uint8)
    cg.add(var.set_line_spacing(templ))
    templ = await cg.templatable(config[CONF_PRINT_DENSITY], args, cg.uint8)
    cg.add(var.set_print_density(templ))
    templ = await cg.templatable(config[CONF_BREAK_TIME], args, cg.uint8)
    cg.add(var.set_break_time(templ))
    
    return var


ThermalPrinterResetSettingsAction = thermal_printer_ns.class_(
    "ThermalPrinterResetSettingsAction", automation.Action
)

@automation.register_action(
    "esphome.reset_printer_settings",
    ThermalPrinterResetSettingsAction,
    cv.Schema(
        {
            cv.Required(CONF_ID): cv.use_id(ThermalPrinterDisplay),
        }
    ),
)
async def reset_printer_settings_action_to_code(config, action_id, template_arg, args):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])
    return var


# Text indentation control automation actions
@automation.register_action(
    "thermal_printer.set_text_indentation",
    ThermalPrinterSetTextIndentationAction,
    cv.Schema(
        {
            cv.GenerateID(): cv.use_id(ThermalPrinterDisplay),
            cv.Required(CONF_SPACES): cv.templatable(cv.int_range(min=0, max=50)),
        }
    ),
)
async def set_text_indentation_action_to_code(config, action_id, template_arg, args):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])
    
    templ = await cg.templatable(config[CONF_SPACES], args, cg.uint8)
    cg.add(var.set_spaces(templ))
    
    return var


@automation.register_action(
    "thermal_printer.reset_text_indentation",
    ThermalPrinterResetTextIndentationAction,
    cv.Schema(
        {
            cv.GenerateID(): cv.use_id(ThermalPrinterDisplay),
        }
    ),
)
async def reset_text_indentation_action_to_code(config, action_id, template_arg, args):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])
    
    return var


@automation.register_action(
    "thermal_printer.feed_paper_dots",
    ThermalPrinterFeedPaperDotsAction,
    cv.Schema(
        {
            cv.GenerateID(): cv.use_id(ThermalPrinterDisplay),
            cv.Required(CONF_DOTS): cv.templatable(cv.int_range(min=0, max=255)),
        }
    ),
)
async def feed_paper_dots_action_to_code(config, action_id, template_arg, args):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])
    
    templ = await cg.templatable(config[CONF_DOTS], args, cg.uint8)
    cg.add(var.set_dots(templ))
    
    return var


@automation.register_action(
    "thermal_printer.print_and_feed_lines",
    ThermalPrinterPrintAndFeedLinesAction,
    cv.Schema(
        {
            cv.GenerateID(): cv.use_id(ThermalPrinterDisplay),
            cv.Required(CONF_LINES): cv.templatable(cv.int_range(min=0, max=255)),
        }
    ),
)
async def print_and_feed_lines_action_to_code(config, action_id, template_arg, args):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])
    
    templ = await cg.templatable(config[CONF_LINES], args, cg.uint8)
    cg.add(var.set_lines(templ))
    
    return var


@automation.register_action(
    "thermal_printer.set_sleep_mode",
    ThermalPrinterSetSleepModeAction,
    cv.maybe_simple_value(
        cv.Schema(
            {
                cv.GenerateID(): cv.use_id(ThermalPrinterDisplay),
                cv.Required(CONF_TIMEOUT_SECONDS): cv.templatable(cv.int_range(min=0, max=65535)),
            }
        ),
        key=CONF_TIMEOUT_SECONDS,
    ),
)
async def thermal_printer_set_sleep_mode_action_to_code(
    config, action_id, template_arg, args
):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])
    templ = await cg.templatable(config[CONF_TIMEOUT_SECONDS], args, cg.uint16)
    cg.add(var.set_timeout_seconds(templ))
    return var


@automation.register_action(
    "thermal_printer.wake_up",
    ThermalPrinterWakeUpAction,
    cv.Schema(
        {
            cv.GenerateID(): cv.use_id(ThermalPrinterDisplay),
        }
    ),
)
async def thermal_printer_wake_up_action_to_code(
    config, action_id, template_arg, args
):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])
    return var


@automation.register_action(
    "thermal_printer.reset_all_formatting",
    ThermalPrinterResetFormattingAction,
    cv.Schema(
        {
            cv.GenerateID(): cv.use_id(ThermalPrinterDisplay),
        }
    ),
)
async def thermal_printer_reset_formatting_action_to_code(
    config, action_id, template_arg, args
):
    var = cg.new_Pvariable(action_id, template_arg)
    await cg.register_parented(var, config[CONF_ID])
    return var




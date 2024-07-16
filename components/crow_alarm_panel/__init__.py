from esphome import pins, automation
import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import text_sensor, switch
from esphome.const import (
    CONF_ADDRESS,
    CONF_ID,
    CONF_CLOCK_PIN,
    CONF_DATA_PIN,
    CONF_NAME,
    CONF_OUTPUTS,
)

AUTO_LOAD = ["binary_sensor", "text_sensor", "switch"]
MULTI_CONF = True

CONF_ARMED_STATE = "armed_state"
CONF_CROW_ALARM_PANEL_ID = "crow_alarm_panel_id"
CONF_NUM_ZONES = "number_of_zones"
CONF_KEYPADS = "keypads"
CONF_ON_MESSAGE = "on_message"

crow_alarm_panel_ns = cg.esphome_ns.namespace("crow_alarm_panel")

CrowAlarmPanel = crow_alarm_panel_ns.class_("CrowAlarmPanel", cg.Component)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(CrowAlarmPanel),
        cv.Required(CONF_CLOCK_PIN): pins.internal_gpio_input_pin_schema,
        cv.Required(CONF_DATA_PIN): pins.internal_gpio_input_pin_schema,
        cv.Optional(CONF_ADDRESS): cv.int_range(min=0, max=8),
        cv.Optional(CONF_KEYPADS, default=[]): cv.ensure_list(
            cv.Schema(
                {
                    cv.Required(CONF_NAME): cv.string,
                    cv.Required(CONF_ADDRESS): cv.int_range(min=0, max=8),
                }
            )
        ),
        cv.Optional(CONF_ON_MESSAGE): automation.validate_automation(single=True),
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)

    clock_pin = await cg.gpio_pin_expression(config[CONF_CLOCK_PIN])
    cg.add(var.set_clock_pin(clock_pin))

    data_pin = await cg.gpio_pin_expression(config[CONF_DATA_PIN])
    cg.add(var.set_data_pin(data_pin))

    if CONF_ADDRESS in config:
        cg.add(var.set_keypad_address(config[CONF_ADDRESS]))

    for keypad in config[CONF_KEYPADS]:
        cg.add(var.add_keypad(keypad[CONF_NAME], keypad[CONF_ADDRESS]))

    if CONF_ON_MESSAGE in config:
        await automation.build_automation(
            var.get_on_message_trigger(),
            [(cg.uint8, "type"), (cg.std_vector.template(cg.uint8), "data")],
            config[CONF_ON_MESSAGE],
        )

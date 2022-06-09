import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import text_sensor
from esphome.const import CONF_ID, CONF_TYPE
from .. import CrowAlarmPanel, CONF_CROW_ALARM_PANEL_ID

DEPENDENCIES = ["crow_alarm_panel"]

text_sensor_ns = cg.esphome_ns.namespace("text_sensor")
TextSensor = text_sensor_ns.class_("TextSensor", cg.EntityBase)

TYPES = ["armed_state"]

CONFIG_SCHEMA = text_sensor.TEXT_SENSOR_SCHEMA.extend(
    {
        cv.GenerateID(): cv.declare_id(TextSensor),
        cv.GenerateID(CONF_CROW_ALARM_PANEL_ID): cv.use_id(CrowAlarmPanel),
        cv.Required(CONF_TYPE): cv.one_of(*TYPES, lower=True),
    }
).extend(cv.COMPONENT_SCHEMA)


def to_code(config):
    paren = yield cg.get_variable(config[CONF_CROW_ALARM_PANEL_ID])
    var = cg.new_Pvariable(config[CONF_ID])

    yield text_sensor.register_text_sensor(var, config)

    if config[CONF_TYPE] == "armed_state":
        cg.add(paren.register_armed_state(var))

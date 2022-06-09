import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import binary_sensor
from esphome.const import CONF_ID, CONF_TYPE
from .. import CrowAlarmPanel, CONF_CROW_ALARM_PANEL_ID

DEPENDENCIES = ["crow_alarm_panel"]

binary_sensor_ns = cg.esphome_ns.namespace("binary_sensor")
BinarySensor = binary_sensor_ns.class_("BinarySensor", cg.EntityBase)

CONF_ZONE = "zone"
CONF_BYPASS = "bypass"

ZONE_SCHEMA = binary_sensor.BINARY_SENSOR_SCHEMA.extend(
    {
        cv.GenerateID(): cv.declare_id(BinarySensor),
        cv.GenerateID(CONF_CROW_ALARM_PANEL_ID): cv.use_id(CrowAlarmPanel),
        cv.Optional(CONF_ZONE): cv.positive_int,
    }
).extend(cv.COMPONENT_SCHEMA)

CONFIG_SCHEMA = cv.typed_schema(
    {
        CONF_ZONE: ZONE_SCHEMA,
        CONF_BYPASS: ZONE_SCHEMA,
    }
)


def to_code(config):
    paren = yield cg.get_variable(config[CONF_CROW_ALARM_PANEL_ID])
    type = config[CONF_TYPE]
    var = cg.new_Pvariable(config[CONF_ID])

    yield binary_sensor.register_binary_sensor(var, config)

    if type == "zone":
        cg.add(paren.register_zone(var, config[CONF_ZONE]))
    elif type == "bypass":
        cg.add(paren.register_zone_bypass(var, config[CONF_ZONE]))

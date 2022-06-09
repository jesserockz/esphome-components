import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import switch
from esphome.const import CONF_ID, CONF_TYPE, CONF_OUTPUT
from .. import crow_alarm_panel_ns, CrowAlarmPanel, CONF_CROW_ALARM_PANEL_ID

DEPENDENCIES = ["crow_alarm_panel"]

CrowAlarmPanelSwitch = crow_alarm_panel_ns.class_(
    "CrowAlarmPanelSwitch", switch.Switch, cg.Component
)
CrowAlarmPanelOutputSwitch = crow_alarm_panel_ns.class_(
    "CrowAlarmPanelOutputSwitch", CrowAlarmPanelSwitch
)


CROW_SWITCH_SCHEMA = switch.SWITCH_SCHEMA.extend(
    {
        cv.GenerateID(CONF_CROW_ALARM_PANEL_ID): cv.use_id(CrowAlarmPanel),
    }
).extend(cv.COMPONENT_SCHEMA)


CONFIG_SCHEMA = cv.typed_schema(
    {
        CONF_OUTPUT: CROW_SWITCH_SCHEMA.extend(
            {
                cv.GenerateID(): cv.declare_id(CrowAlarmPanelOutputSwitch),
                cv.Required(CONF_OUTPUT): cv.positive_int,
            }
        ),
    }
)


def to_code(config):
    paren = yield cg.get_variable(config[CONF_CROW_ALARM_PANEL_ID])
    type = config[CONF_TYPE]
    if type == "output":
        var = cg.new_Pvariable(config[CONF_ID])
        cg.add(var.set_output_number(config[CONF_OUTPUT]))
        cg.add(paren.register_output_switch(var, config[CONF_OUTPUT]))

    yield switch.register_switch(var, config)
    yield cg.register_component(var, config)

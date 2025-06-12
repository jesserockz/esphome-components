import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import microphone
from esphome.components.network import IPAddress
from esphome.const import CONF_ID, CONF_IP_ADDRESS, CONF_MICROPHONE, CONF_PORT

AUTO_LOAD = ["socket"]
DEPENDENCIES = ["microphone", "network"]

udp_audio_ns = cg.esphome_ns.namespace("udp_audio")
UDPAudioComponent = udp_audio_ns.class_("UDPAudioComponent", cg.Component)


CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(UDPAudioComponent),
        cv.Required(CONF_IP_ADDRESS): cv.ipv4address,
        cv.Required(CONF_PORT): cv.port,
        cv.GenerateID(CONF_MICROPHONE): cv.use_id(microphone.Microphone),
    }
)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    mic = await cg.get_variable(config[CONF_MICROPHONE])
    cg.add(var.set_microphone(mic))

    cg.add(var.set_address(IPAddress(str(config[CONF_IP_ADDRESS])), config[CONF_PORT]))

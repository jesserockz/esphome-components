import os

import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID, CONF_PATH

from esphome.core import HexInt, CORE

MULTI_CONF = True

CONFIG_SCHEMA = cv.Schema(
    {
        cv.Required(CONF_ID): cv.declare_id(cg.uint8),
        cv.Required(CONF_PATH): cv.file_,
    }
)


async def to_code(config):
    path = config[CONF_PATH]
    data = []
    with open(CORE.relative_config_path(path), "br") as f:
        if os.path.basename(path).endswith(".wav"):
            header = []
            while True:
                byte = f.read(1)
                if byte == b"":
                    raise ValueError("Could not find data in wav file")
                header.append(byte)
                if header[-4:] == [b"d", b"a", b"t", b"a"]:
                    break
            f.read(2)  # Skip the two content length bytes

        data = f.read()
    rhs = [HexInt(x) for x in data]
    cg.progmem_array(config[CONF_ID], rhs)

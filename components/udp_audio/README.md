# ESPHome UDP Audio sender

This component will attach to a microphones data callback and send the read audio via udp to the configured IP address and port.

## Configuration

```yaml
external_components:
  - source: github://jesserockz/esphome-components
    components: [udp_audio]

microphone:
  - platform: ...
    id: my_mic

udp_audio:
  ip_address: 10.10.10.10
  port: 6056

binary_sensor:
  - platform: ...
    ...
    on_press:
      - microphone.capture:
    on_release:
      - microphone.stop_capture:
```

## Example receiver

```shell
python ./server.py
```

The included `server.py` script will open the udp port 6056 and play any received audio out to the computer speakers.

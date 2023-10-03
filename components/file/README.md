# ESPHome File component

This component allows you to "inject" any raw file into the firmware as a progmem byte array.

## Configuration

```yaml
file:
  - id: my_file
    path: my_file.wav
```

## File types

### Wav files

The component will scrub the wav header and only include the raw audio data in the firmware.
This means that the wav file will be playable by the ESP32's [speaker](https://esphome.io/components/speaker) components.

#### Example

```yaml
speaker:
  - platform: ...
    id: my_speaker
    ...

file:
  - id: my_file
    path: my_file.wav

button:
  - platform: template
    name: Play my file
    on_press:
      - lambda: id(my_speaker).play(id(my_file), sizeof(id(my_file)));
```

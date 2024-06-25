# ESPHome File component

This component allows you to "inject" any raw file into the firmware as a progmem byte array.

## Configuration

```yaml
external_components:
  - source: github://jesserockz/esphome-components
    components: [file]

file:
  - id: my_file
    file: my_file.wav
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
    file: my_file.wav
  - id: my_remote_wav
    file: https://example.com/my_file.wav

button:
  - platform: template
    name: Play my file
    on_press:
      - lambda: id(my_speaker).play(id(my_file), sizeof(id(my_file)));
```

### Other files

Any other file type will be included as is as a raw byte array in the firmware.
If there are any certain filetypes that need to be manipulated first, please
make a pull request to add this.

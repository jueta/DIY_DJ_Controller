# DIY DJ Controller

Homemade CDJ-style DJ controller with a 3D-printed enclosure, hand-built electronics, and custom firmware.



This repository documents:
- the current stable Mixxx prototype
- the firmware and Mixxx mapping that make it work
- the next hardware direction for a cleaner v2 build

![Fusion 360 render](pics/fusion1.png)

![Prototype build](pics/overTable1.jpeg)

## Status

- `v1` is the stable Mixxx-focused version
- the controller has been built, flashed, and used successfully as a working prototype
- Rekordbox was tested, but the jog wheels never became usable enough for a real workflow
- because of that, Rekordbox is not a supported target for this hardware revision

## Current Version

- `MCU`: SparkFun Pro Micro / ATmega32U4
- `Firmware`: PlatformIO + Arduino + `MIDIUSB`
- `Inputs`: `PCF8575` for buttons, `74HC4067` for analog controls, 3 rotary encoders
- `Mechanical`: custom 3D-printed enclosure designed in Fusion 360
- `Software target`: Mixxx

The current prototype includes:
- two-deck transport and loop control
- EQ, filter, gain, volume, tempo, and crossfader control
- jog wheels
- music browsing and load controls

## V1 Hardware Summary

- `MCU`: SparkFun Pro Micro / ATmega32U4
- `Button expander`: `PCF8575` for 16 buttons
- `Analog mux`: `74HC4067` for 15 potentiometers
- `Encoders`: 3 total
  - 1 browse encoder
  - 2 jog wheel encoders
- `Direct buttons on MCU`: `A1`, `A2`, `A3`

## V1 Wiring Summary

These are the important firmware-defined connections for the current working Mixxx version.

### I2C / Button Expander

- `SDA` -> pin `2`
- `SCL` -> pin `3`
- `PCF8575` address is auto-detected on boot in the `0x20` to `0x27` range

### 74HC4067 Multiplexer

- `MUX signal` -> `A0`
- `S0` -> pin `15`
- `S1` -> pin `14`
- `S2` -> pin `16`
- `S3` -> pin `10`

### Rotary Encoders

- `Browse encoder` -> pins `4` and `5`
- `Jog wheel 1` -> pins `8` and `9`
- `Jog wheel 2` -> pins `6` and `7`

### Direct Buttons

- `A3` -> note `76`
- `A2` -> note `77`
- `A1` -> note `78`

## V1 Current Input Map

### PCF8575 Buttons

- `Button 0` -> Deck 1 Loop Out
- `Button 1` -> Deck 1 Loop In
- `Button 2` -> Deck 1 Hotcue 3
- `Button 3` -> Deck 1 Hotcue 4
- `Button 4` -> Deck 1 Hotcue 1
- `Button 5` -> Deck 1 Hotcue 2
- `Button 6` -> Deck 1 Cue
- `Button 7` -> Deck 1 Play/Pause
- `Button 8` -> Deck 2 Hotcue 4
- `Button 9` -> Deck 2 Hotcue 3
- `Button 10` -> Deck 2 Hotcue 1
- `Button 11` -> Deck 2 Hotcue 2
- `Button 12` -> Deck 2 Cue
- `Button 13` -> Deck 2 Play/Pause
- `Button 14` -> Deck 2 Loop In
- `Button 15` -> Deck 2 Loop Out

### Potentiometers

- `Pot 0 / CC 10` -> Deck 1 Gain
- `Pot 1 / CC 11` -> Deck 2 Gain
- `Pot 2 / CC 12` -> Deck 1 High EQ
- `Pot 3 / CC 13` -> Deck 2 High EQ
- `Pot 4 / CC 14` -> Deck 1 Mid EQ
- `Pot 5 / CC 15` -> Deck 2 Mid EQ
- `Pot 6 / CC 16` -> Deck 1 Low EQ
- `Pot 7 / CC 17` -> Deck 2 Low EQ
- `Pot 8 / CC 18` -> Deck 1 Filter
- `Pot 9 / CC 19` -> Deck 2 Filter
- `Pot 10 / CC 20` -> Deck 2 Volume
- `Pot 11 / CC 21` -> Deck 2 Tempo
- `Pot 12 / CC 22` -> Deck 1 Volume
- `Pot 13 / CC 23` -> Crossfader
- `Pot 14 / CC 24` -> Deck 1 Tempo

### Browser And Jog Controls

- `Browse encoder / CC 25` -> library scroll
- `A1 / note 78` -> Load selected track to Deck 1
- `A2 / note 77` -> Load selected track to Deck 2
- `A3 / note 76` -> Enter or expand selected folder
- `Jog wheel on pins 8/9 / CC 26` -> currently mapped to Deck 2
- `Jog wheel on pins 6/7 / CC 27` -> currently mapped to Deck 1

## V1 Firmware

The current firmware lives in `CDJ_firmware/src/main.cpp`.

### Current Behavior

- auto-detects the `PCF8575` on boot
- configures the expander pins as input pull-high
- reads 16 buttons through the `PCF8575`
- reads 15 analog controls through the `74HC4067`
- reads 3 rotary encoders
- reads direct top buttons on `A1`, `A2`, and `A3`
- sends MIDI note and CC messages through `MIDIUSB`
- uses an additional filter on the browse encoder to reduce event spam in Mixxx

### Build Target

`CDJ_firmware/platformio.ini` currently targets:

```ini
[env:sparkfun_promicro16]
platform = atmelavr
board = sparkfun_promicro16
framework = arduino
lib_deps =
  arduino-libraries/MIDIUSB @ ^1.0.5
```

## Repo Layout

- `CDJ_firmware/` - firmware source and PlatformIO config
- `controllers/mixx_Mapping/` - Mixxx XML and JS mapping
- `pics/` - renders and prototype photos
- `reference circuits/` - circuit reference images
- `CDJv2.f3z` - Fusion 360 model

## Source Of Truth

- `Firmware`: `CDJ_firmware/src/main.cpp`
- `Mixxx XML mapping`: `controllers/mixx_Mapping/DJC-DIY.midi.xml`
- `Mixxx JS mapping`: `controllers/mixx_Mapping/DJC-DIY-scripts.js`

For exact control behavior, use those files instead of this README.

## Getting Started

### Firmware

1. Install [PlatformIO](https://platformio.org/) in VS Code.
2. Open `CDJ_firmware/`.
3. Connect the SparkFun Pro Micro by USB.
4. Build or upload:

```bash
pio run
pio run --target upload
```

### Mixxx

Copy these files into your Mixxx controller mapping folder:

- `controllers/mixx_Mapping/DJC-DIY.midi.xml`
- `controllers/mixx_Mapping/DJC-DIY-scripts.js`

Then enable the mapping in Mixxx.

## Important Notes

- The stable path for this project is Mixxx, not Rekordbox.
- The prototype is still hand-wired and not PCB-based yet.
- The current jog wheel assignment is swapped between physical control and deck mapping.
- Rekordbox support should be treated as future hardware research, not a feature of this version.

## V2 Direction

V2 should be a hardware redesign, not a small firmware patch.

The new goal is:
- keep one `USB-C` cable from the controller to the computer
- add one `3.5 mm` headphone jack on the controller
- keep `Master` audio on the computer side
- send only `Headphones / Cue` audio through the controller
- keep the project Mixxx-first while moving to a cleaner electronics architecture

In practice, that means:
- `Master` can stay on MacBook speakers, a separate wired audio interface, or another host-selected output
- the controller only needs to provide the headphone cue path

## Exact V2 Hardware Stack

### Prototype

- `MCU board`: `ESP32-S3-DevKitC-1`
- `Audio module`: `Adafruit TLV320DAC3100`
- `Headphone output`: panel-mounted `3.5 mm TRS` jack
- `Main external connector`: panel-mounted `USB-C`

### Custom PCB Direction

- `MCU module`: `ESP32-S3-WROOM-1`
- `Audio path`: `TLV320DAC3100` or equivalent codec / DAC with headphone output
- `Existing control hardware to keep initially`: `PCF8575`, `74HC4067`, encoders, buttons, potentiometers

## Why This Stack

- no bulky external audio interface inside the enclosure
- no internal USB hub
- one USB device instead of separate controller and sound card devices
- dedicated headphone cue output without moving the master output into the controller
- better long-term platform than ATmega32U4 for future firmware and USB work

## V2 Signal Flow

```text
Computer / Mixxx
  |
  | USB-C
  |
ESP32-S3
  |- MIDI control data to Mixxx
  |- USB audio device for headphone cue
  |
  +-- I2S + I2C --> TLV320DAC3100 --> 3.5 mm headphone jack

Master audio stays on the computer-side output.
```

## V2 Firmware Goals

- present as a composite USB device with `MIDI + audio`
- port the current controller logic from ATmega32U4 to ESP32-S3
- keep the current control surface behavior as much as possible
- configure the headphone DAC over `I2C`
- stream cue audio to the DAC over `I2S`

## Rekordbox Note

Moving to `ESP32-S3` gives the project a much better platform for USB experiments, but it does not by itself guarantee Rekordbox compatibility.

It especially does not guarantee that the jog wheels will work correctly in Rekordbox. V2 should still be treated as a Mixxx-first design, with Rekordbox compatibility kept as future research.

## License

License not defined yet in the repository.
This project was inspired by my friend [@mandiclab](https://github.com/mandiclab) and the [djc-diy](https://github.com/mandiclab/djc-diy) project.

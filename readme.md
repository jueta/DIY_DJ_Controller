# CDJ Firmware

> **Note:** This README is a work in progress. Screenshots, pictures, references and wiring diagrams will be added soon.


## Introduction

This repository contains firmware for a DIY CDJ‑style DJ controller built around a Sparkfun Pro Micro (ATmega328p @16MHz). The goal is to provide an open‑source, customizable hardware interface that can be used with a computer running DJ software via USB‑MIDI.

The project started as an inspiration from Mandiclabs repo into a complete mapping for two decks with jog wheels, rotary encoders, potentiometers, and buttons.


## Features

- USB‑MIDI device using the `MIDIUSB` Arduino library
- Two-deck control with play/pause, cue, loops, tempo faders, EQ, gain, filter, and master volume
- Jog wheels with encoder inputs
- Music selection encoder with push button
- 16-button I²C expansion (PCF8575)
- 74HC4067 analog multiplexer for potentiometers
- Compatible with PlatformIO / Arduino framework

## Hardware Overview

### Required Components

- Sparkfun Pro Micro 16MHz (ATmega328)
- PCF8575 I²C GPIO expander
- 74HC4067 16‑channel analog multiplexer
- Rotary encoders (x3)
- Potentiometers for gain, EQ, filter, tempo, master, etc.
- Push buttons (≈20)
- Misc wiring, breadboard/PCB

### Wiring Details

For users building their own controller, here are the pin assignments used in the firmware:

- **PCF8575 I2C**  
  - SDA → Arduino pin 2  
  - SCL → Arduino pin 3  
  - 16 buttons connected with hardware pull‑ups; press shorts to input.

- **74HC4067 analog multiplexer**  
  - Signal → A0  
  - S0 → pin 15  
  - S1 → pin 14  
  - S2 → pin 16  
  - S3 → pin 10  
  - This IC reads 15 potentiometers (linear and rotary).

- **Rotary Encoders**  
  - Music selection encoder → pins 4 and 5  
  - Jog wheel 1 encoder → pins 8 & 9  
  - Jog wheel 2 encoder → pins 6 & 7

- **Top buttons (no hardware pull‑ups)**  
  - Buttons connected to A3, A2, A1 (use `INPUT_PULLUP` in software)

#### Button / Pot Mappings

- Button 1: Deck 1 loop in  
- Button 0: Deck 1 loop out  
- Button 7: Deck 1 play/pause  
- Button 6: Deck 1 cue  
- Pot 14: Deck 1 tempo fader  
- Pot 12: Deck 1 master  
- Buttons 4, 5, 2, 3: Deck 1 function buttons  
- *Jog wheel 2 is actually jog wheel 1*

- Button A1: Load music to deck 1  
- Button A2: Load music to deck 2  
- Music encoder: track selector  
- Button A3: music encoder push (navigate directories)

- Pot 0: Deck 1 gain  
- Pot 2: Deck 1 high  
- Pot 4: Deck 1 mid  
- Pot 6: Deck 1 low  
- Pot 8: Deck 1 filter  
- Pot 13: Mixer fader  

- Pot 1: Deck 2 gain  
- Pot 3: Deck 2 high  
- Pot 5: Deck 2 mid  
- Pot 7: Deck 2 low  
- Pot 9: Deck 2 filter  
- Pot 10: Deck 2 master  

- Button 14: Deck 2 loop in  
- Button 15: Deck 2 loop out  
- Button 13: Deck 2 play/pause  
- Button 12: Deck 2 cue  
- Buttons 10, 11, 9, 8: Deck 2 function buttons  
- Pot 11: Deck 2 tempo fader  
- *Jog wheel 1 is actually jog wheel 2*

## Building and Uploading

1. Install [PlatformIO](https://platformio.org) in VS Code.
2. Open the `CDJ_firmware` folder.
3. Connect the Pro Micro board via USB and select the correct port.
4. Use the PlatformIO toolbar or run:

   ```bash
   pio run --target upload
   ```

5. After uploading, the board will enumerate as a USB MIDI device.

## Usage

- Plug the controller into your computer.
- Launch your DJ software (e.g. Rekordbox, Serato, VirtualDJ, Mixxx).
- Map the MIDI controls if necessary.
- See the source code in `src/main.cpp` for details on MIDI messages and behavior.

## Contributing

Contributions are welcome! Feel free to submit issues or pull requests with improvements, new mappings, wiring diagrams, or documentation.

## License

[Specify your license here, e.g. MIT]

## Acknowledgments

Based on original hardware designs and code by [Your Name]. Thanks to the open‑source community for inspiration and libraries.

---

*This README will be updated with pictures, wiring diagrams, and usage examples soon.*

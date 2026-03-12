# Firmware Architecture

> DIY_DJ_Controller firmware docs | Agent: Volt ⚡

## Overview

The firmware is built with PlatformIO and Arduino framework, targeting the Sparkfun Pro Micro (ATmega328p @ 16MHz).

## Dependencies

- **Framework:** Arduino
- **MIDI Library:** [MIDIUSB](https://github.com/arduino-libraries/MIDIUSB) v1.0.5

## Build System

### platformio.ini

```ini
[env:sparkfun_promicro16]
platform = atmelavr
board = sparkfun_promicro16
framework = arduino
lib_deps = arduino-libraries/MIDIUSB @ ^1.0.5
```

## Key Modules

### main.cpp
- **Loop:** Reads all inputs (I²C GPIO, analog mux, encoders, direct buttons)
- **MIDI:** Sends USB-MIDI messages via MIDIUSB library

### Libraries Used
- `MIDIUSB` — USB-MIDI communication
- `Wire` — I²C communication (PCF8575)
- `Encoder` — Rotary encoder handling (or manual interrupt-based)

## Building

```bash
cd firmware/
pio run          # Build
pio run --target upload  # Upload
pio run --monitor  # Serial monitor
```

## File Structure

```
firmware/
├── src/main.cpp           # Main firmware
├── platformio.ini         # Build config
├── include/               # Header files (empty)
├── lib/                   # Local libraries (empty)
├── mixx_Mapping/          # Mixxx MIDI mapping
│   ├── DJC-DIY.midi.xml
│   └── DJC-DIY-scripts.js
├── backup/                # Previous versions
└── test/                  # Test files
```

## MIDI Messages

| Control | MIDI Channel | CC/Note | Value Range |
|---------|--------------|---------|-------------|
| Play/Pause | 1/2 | Note 0/1 | 0/127 |
| Cue | 1/2 | Note 2/3 | 0/127 |
| Tempo Fader | 1/2 | CC 14/15 | 0-127 |
| Master | 1/2 | CC 16/17 | 0-127 |
| Gain | 1/2 | CC 18/19 | 0-127 |
| EQ High | 1/2 | CC 20/21 | 0-127 |
| EQ Mid | 1/2 | CC 22/23 | 0-127 |
| EQ Low | 1/2 | CC 24/25 | 0-127 |
| Filter | 1/2 | CC 26/27 | 0-127 |

## Known Issues

- ⚠️ Jog wheel 1/2 labels swapped in firmware
- ⚠️ Button mappings need review in Mixxx

---

*Last updated: 2026-03-12*
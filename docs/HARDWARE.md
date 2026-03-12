# Hardware Specifications

> DIY_DJ_Controller component details | Agent: Volt ⚡

## Microcontroller

| Part | Spec |
|------|------|
| **MCU** | Sparkfun Pro Micro (ATmega328p @ 16MHz) |
| **Flash** | 32KB |
| **RAM** | 2KB |
| **EEPROM** | 1KB |
| **Voltage** | 5V (USB) |

## I²C Devices

### PCF8575 GPIO Expander
- **Address:** 0x20 (default)
- **Purpose:** 16-button matrix input
- **Pins:** SDA → Arduino pin 2, SCL → Arduino pin 3

### 74HC4067 Analog Multiplexer
- **Purpose:** Read 16 analog pots with only 1 ADC pin
- **Signal:** Arduino A0
- **Select pins:** 15, 14, 16, 10

## Input Devices

### Rotary Encoders (3x)
| Encoder | Pin A | Pin B |
|---------|-------|-------|
| Jog Wheel 1 | 8 | 9 |
| Jog Wheel 2 | 6 | 7 |
| Music Selector | 4 | 5 |

### Push Buttons (Direct Input)
| Button | Pin | Function |
|--------|-----|----------|
| Load Track D1 | A1 | INPUT_PULLUP |
| Load Track D2 | A2 | INPUT_PULLUP |
| Navigate | A3 | INPUT_PULLUP |

## Analog Inputs (via Mux)

| Mux Channel | Potentiometer |
|-------------|---------------|
| 0 | Deck 1 Gain |
| 1 | Deck 2 Gain |
| 2 | Deck 1 High EQ |
| 3 | Deck 2 High EQ |
| 4 | Deck 1 Mid EQ |
| 5 | Deck 2 Mid EQ |
| 6 | Deck 1 Low EQ |
| 7 | Deck 2 Low EQ |
| 8 | Deck 1 Filter |
| 9 | Deck 2 Filter |
| 10 | Deck 2 Master |
| 11 | Deck 2 Tempo |
| 12 | Deck 1 Master |
| 13 | Mixer (shared) |
| 14 | Deck 1 Tempo |
| 15 | (available) |

## Power

- **Source:** USB (5V)
- **External:** Not currently used

## Known Issues

⚠️ Jog wheel labels are swapped in firmware:
- Jog wheel 2 → controls Deck 1
- Jog wheel 1 → controls Deck 2

---

*Last updated: 2026-03-12*

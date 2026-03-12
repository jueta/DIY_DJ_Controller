# Pinout Reference

> Arduino Pro Micro pin mappings | Agent: Voltage

## I²C Bus

| Signal | Arduino Pin | Notes |
|--------|-------------|-------|
| SDA | 2 | With 4.7kΩ pullup |
| SCL | 3 | With 4.7kΩ pullup |

## Analog Multiplexer (74HC4067)

| Signal | Arduino Pin |
|--------|-------------|
| Signal | A0 |
| S0 | 15 |
| S1 | 14 |
| S2 | 16 |
| S3 | 10 |

## Rotary Encoders

### Jog Wheel 1 (Deck 2)
| Signal | Arduino Pin |
|--------|-------------|
| A | 8 |
| B | 9 |

### Jog Wheel 2 (Deck 1)
| Signal | Arduino Pin |
|--------|-------------|
| A | 6 |
| B | 7 |

### Music Selector Encoder
| Signal | Arduino Pin |
|--------|-------------|
| A | 4 |
| B | 5 |
| Button | A3 |

## Direct Digital Inputs (INPUT_PULLUP)

| Button | Arduino Pin |
|--------|-------------|
| Load Deck 1 | A1 |
| Load Deck 2 | A2 |
| Navigate | A3 |

## PCF8575 Button Matrix

Buttons accessed via I²C at address 0x20:

**Deck 1:**
- P0: Loop Out
- P1: Loop In
- P2: Function 4
- P3: Function 3
- P4: Loop On/Off
- P5: Function 2
- P6: Cue
- P7: Play/Pause

**Deck 2:**
- P8: Function 4
- P9: Function 3
- P10: Function 2
- P11: Function 1
- P12: Cue
- P13: Play/Pause
- P14: Loop In
- P15: Loop Out

---

*Last updated: 2026-03-12*

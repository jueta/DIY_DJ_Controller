# Mixxx Mapping

> DJC-DIY MIDI mapping for Mixxx | Agent: Volt ⚡

## Installation

1. Copy files to Mixxx mapping folder:
   - `firmware/mixx_Mapping/DJC-DIY.midi.xml`
   - `firmx_Mapping/DJC-DIY-scripts.js`

2. Windows: `%APPDATA%\Mixxx\mappings\`
3. macOS: `~/Library/Application Support/Mixxx/mappings/`
4. Linux: `~/.mixxx/mappings/`

## MIDI Channels

| Deck | MIDI Channel |
|------|--------------|
| Deck 1 | 1 |
| Deck 2 | 2 |

## Controls

### Transport
| Control | MIDI Note | Action |
|---------|-----------|--------|
| Play D1 | 0 | Play/Pause |
| Play D2 | 1 | Play/Pause |
| Cue D1 | 2 | Cue |
| Cue D2 | 3 | Cue |

### Loops
| Control | MIDI Note |
|---------|-----------|
| Loop In D1 | 1 |
| Loop Out D1 | 0 |
| Loop In D2 | 14 |
| Loop Out D2 | 15 |

### EQ & Filter
| Control | CC | Range |
|---------|-----|-------|
| High D1 | 20 | 0-127 |
| High D2 | 21 | 0-127 |
| Mid D1 | 22 | 0-127 |
| Mid D2 | 23 | 0-127 |
| Low D1 | 24 | 0-127 |
| Low D2 | 25 | 0-127 |
| Filter D1 | 26 | 0-127 |
| Filter D2 | 27 | 0-127 |

### Faders
| Control | CC | Range |
|---------|-----|-------|
| Tempo D1 | 14 | 0-127 |
| Tempo D2 | 15 | 0-127 |
| Master D1 | 16 | 0-127 |
| Master D2 | 17 | 0-127 |
| Gain D1 | 18 | 0-127 |
| Gain D2 | 19 | 0-127 |

## Known Issues

⚠️ Button mapping layout needs refinement in Mixxx software (see kanban)

---

*Last updated: 2026-03-12*
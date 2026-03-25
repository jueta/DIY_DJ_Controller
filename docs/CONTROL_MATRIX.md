# Control Matrix

> Working inventory of physical controls, firmware assignments, software mappings, and validation status.

Use this file to track the real behavior of the controller. If a control has not been tested on hardware, mark it clearly instead of assuming it works.

## Status Legend

- `Working`: verified on the real controller
- `Broken`: confirmed not working
- `Swapped`: works, but mapped to the wrong physical control or deck
- `Unverified`: present in repo evidence but not yet confirmed on hardware
- `Not mapped`: physical or firmware element exists but software mapping was not found in repo

## Direct Buttons

| Physical Control | Hardware Pin | Firmware MIDI | Software Mapping | Status | Notes |
|---|---|---|---|---|---|
| Load Deck 1 | A1 | Note 78 | Not found in repo | Unverified | Mentioned in README/PINOUT as load to deck 1 |
| Load Deck 2 | A2 | Note 77 | `DJCDIY.loadDeck2` exists in JS; XML binding not confirmed from current scan | Unverified | Needs full XML verification |
| Navigate / Music Encoder Push | A3 | Note 76 | Not found in repo | Unverified | README says navigate directories |

## Rotary Encoders

| Physical Control | Hardware Pins | Firmware MIDI | Software Mapping | Status | Notes |
|---|---|---|---|---|---|
| Music Selector Encoder | 4, 5 | CC 25 | `DJCDIY.playlistScroll` exists in JS; XML binding not confirmed from current scan | Unverified | Needs full XML verification |
| Jog Wheel 1 | 8, 9 | CC 26 | Mixxx jog binding on Channel 2 | Swapped | Docs indicate physical jog labeling is swapped |
| Jog Wheel 2 | 6, 7 | CC 27 | Mixxx jog binding on Channel 1 | Swapped | Docs indicate physical jog labeling is swapped |

## PCF8575 Buttons

| Control Group | Index / Pin | Firmware MIDI | Software Mapping | Status | Notes |
|---|---|---|---|---|---|
| Deck 1 Loop Out | P0 | Note 60 | `loop_out` on Channel 1 | Unverified | Present in XML |
| Deck 1 Loop In | P1 | Note 61 | `loop_in` on Channel 1 | Unverified | Present in XML |
| Deck 1 Function 3 | P2 | Note 62 | `hotcue_3_activate` on Channel 1 | Unverified | Present in XML |
| Deck 1 Function 4 | P3 | Note 63 | `hotcue_4_activate` on Channel 1 | Unverified | Present in XML |
| Deck 1 Function 1 | P4 | Note 64 | `hotcue_1_activate` on Channel 1 | Unverified | XML comment names differ from some docs |
| Deck 1 Function 2 | P5 | Note 65 | `hotcue_2_activate` on Channel 1 | Unverified | Present in XML |
| Deck 1 Cue | P6 | Note 66 | `cue_default` on Channel 1 | Unverified | Present in XML |
| Deck 1 Play/Pause | P7 | Note 67 | `play` on Channel 1 | Unverified | Present in XML |
| Deck 2 Function 4 | P8 | Note 68 | Not fully verified from current scan | Unverified | Needs complete XML audit |
| Deck 2 Function 3 | P9 | Note 69 | Not fully verified from current scan | Unverified | Needs complete XML audit |
| Deck 2 Function 2 | P10 | Note 70 | Not fully verified from current scan | Unverified | Needs complete XML audit |
| Deck 2 Function 1 | P11 | Note 71 | Not fully verified from current scan | Unverified | Needs complete XML audit |
| Deck 2 Cue | P12 | Note 72 | `cue_default` on Channel 2 | Unverified | Present in XML |
| Deck 2 Play/Pause | P13 | Note 73 | `play` on Channel 2 | Unverified | Present in XML |
| Deck 2 Loop In | P14 | Note 74 | `loop_in` on Channel 2 | Unverified | Present in XML |
| Deck 2 Loop Out | P15 | Note 75 | `loop_out` on Channel 2 | Unverified | Present in XML |

## Potentiometers Via 74HC4067

| Mux Channel | Documented Function | Firmware MIDI CC | Software Mapping | Status | Notes |
|---|---|---|---|---|---|
| 0 | Deck 1 Gain | CC 10 | Not fully verified from current scan | Unverified | README and docs list function |
| 1 | Deck 2 Gain | CC 11 | Not fully verified from current scan | Unverified | README and docs list function |
| 2 | Deck 1 High EQ | CC 12 | Not fully verified from current scan | Unverified | README and docs list function |
| 3 | Deck 2 High EQ | CC 13 | Not fully verified from current scan | Unverified | README and docs list function |
| 4 | Deck 1 Mid EQ | CC 14 | Not fully verified from current scan | Unverified | Docs and FIRMWARE.md naming are inconsistent with some summary tables |
| 5 | Deck 2 Mid EQ | CC 15 | Not fully verified from current scan | Unverified | Needs XML audit |
| 6 | Deck 1 Low EQ | CC 16 | Not fully verified from current scan | Unverified | Needs XML audit |
| 7 | Deck 2 Low EQ | CC 17 | Not fully verified from current scan | Unverified | Needs XML audit |
| 8 | Deck 1 Filter | CC 18 | Not fully verified from current scan | Unverified | Needs XML audit |
| 9 | Deck 2 Filter | CC 19 | Not fully verified from current scan | Unverified | Needs XML audit |
| 10 | Deck 2 Master | CC 20 | Not fully verified from current scan | Unverified | Needs XML audit |
| 11 | Deck 2 Tempo | CC 21 | Not fully verified from current scan | Unverified | Needs XML audit |
| 12 | Deck 1 Master | CC 22 | Not fully verified from current scan | Unverified | Needs XML audit |
| 13 | Mixer Fader | CC 23 | Not fully verified from current scan | Unverified | Shared mixer control in docs |
| 14 | Deck 1 Tempo | CC 24 | Not fully verified from current scan | Unverified | Needs XML audit |

## Next Validation Pass

The next agent or session should:

1. Complete a full XML and JS audit so every software mapping cell is explicit.
2. Compare firmware note and CC numbers against docs for consistency.
3. Validate the matrix against the real controller and replace `Unverified` with confirmed statuses.
4. Add issue notes for any control that is broken, swapped, noisy, or intermittent.

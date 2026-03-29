# Rekordbox Mapping

This folder contains a Rekordbox mapping reference for the DIY DJ controller.

## Important Limitation

Rekordbox supports MIDI Learn and can export/import MIDI mappings as CSV, but AlphaTheta does not publicly document the CSV schema. That means this folder provides:

- a complete mapping reference CSV for manual setup in Rekordbox
- a workflow for exporting your own Rekordbox CSV and adapting it later

If you export a sample MIDI CSV from your installed Rekordbox version, it can be converted into a true importable file using the same mapping in this folder.

## Intended Behavior

This mapping follows the current working controller behavior already used for Mixxx:

- Deck 1 and Deck 2 transport
- loop in / out
- four function buttons per deck
- gain, EQ, filter, volume, tempo
- crossfader
- library browse encoder
- load to Deck 1 / Deck 2
- enter / expand folder

## Recommended Rekordbox Setup Flow

1. Open Rekordbox in `PERFORMANCE` mode.
2. Connect the controller by USB.
3. Open the `MIDI` panel.
4. Use `LEARN` to assign controls one by one using `DJC-DIY-rekordbox-reference.csv`.
5. Export the finished mapping as a CSV from Rekordbox.
6. Save that exported CSV in this folder so it becomes the true import file for your exact Rekordbox version.

## Files

- `DJC-DIY-rekordbox-reference.csv` - manual mapping reference

## Notes

- Jog behavior in Rekordbox may require extra testing compared with Mixxx.
- The browse and load controls are included in the reference, but Rekordbox library mappings can vary slightly by version and focus state.
- If you export a Rekordbox MIDI CSV, the next step is to place it in this folder and use it as the canonical Rekordbox mapping file.

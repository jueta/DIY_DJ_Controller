# DIY DJ Controller

Custom homemade CDJ-style DJ controller with a 3D-printed enclosure, hand-built electronics, and USB-MIDI firmware for desktop DJ software.

This repository documents the project as it evolves from a working prototype into a more professional hardware, firmware, and documentation package.

This project was inspired by my friend [@mandiclab](https://github.com/mandiclab) and the [djc-diy](https://github.com/mandiclab/djc-diy) project.

## Project Overview

- **Type:** DIY USB-MIDI DJ controller
- **Core MCU:** Sparkfun Pro Micro (ATmega328p @ 16 MHz)
- **Firmware stack:** PlatformIO + Arduino + `MIDIUSB`
- **Current software path:** Mixxx mapping included in the repo
- **Design assets:** Fusion 360 model, build photos, firmware, and project docs

## Gallery

### Design Renders

<p align="center">
  <img src="pics/fusion1.png" alt="Fusion 360 render of the DIY DJ controller" width="80%" />
</p>

<table>
  <tr>
    <td align="center"><img src="pics/fusion2.png" alt="Fusion 360 angled render" width="100%" /><br /><sub>Fusion 360 render</sub></td>
    <td align="center"><img src="pics/fusion3.png" alt="Fusion 360 front-side render" width="100%" /><br /><sub>Fusion 360 render</sub></td>
  </tr>
</table>

### Prototype Build Photos

<table>
  <tr>
    <td align="center"><img src="pics/overTable1.jpeg" alt="Top view of the finished controller prototype" width="100%" /><br /><sub>Controller top view</sub></td>
    <td align="center"><img src="pics/overTable2.jpeg" alt="Additional top view of the controller prototype" width="100%" /><br /><sub>Controller top view</sub></td>
  </tr>
  <tr>
    <td align="center"><img src="pics/soldered.jpeg" alt="Hand-soldered electronics assembly" width="100%" /><br /><sub>Electronics assembly</sub></td>
    <td align="center"><img src="pics/soldered2.jpeg" alt="Additional hand-soldered electronics assembly view" width="100%" /><br /><sub>Electronics assembly</sub></td>
  </tr>
  <tr>
    <td align="center" colspan="2"><img src="pics/hands.jpeg" alt="Work-in-progress photo during assembly" width="65%" /><br /><sub>Work-in-progress assembly</sub></td>
  </tr>
</table>

## Current Status

This project is already past the idea stage: the controller has been designed, assembled, flashed, and used as a working prototype.

Current focus areas:

- Stabilize control mappings and firmware behavior
- Improve documentation and repo structure
- Prepare the electronics for a future PCB revision
- Improve the mechanical design for future iterations
- Explore broader software compatibility after the current setup is stabilized

See [docs/ROADMAP.md](docs/ROADMAP.md) and [docs/STATUS.md](docs/STATUS.md) for the current plan and project snapshot.

## What The Controller Does

- Sends USB-MIDI messages using the `MIDIUSB` library
- Supports two-deck transport and loop control
- Reads 15 analog controls through a `74HC4067` multiplexer
- Reads 16 additional buttons through a `PCF8575` I2C GPIO expander
- Uses three rotary encoders for jog wheels and music selection
- Includes a Mixxx mapping package in `CDJ_firmware/mixx_Mapping/`

## Hardware Summary

The current prototype is built around:

- Sparkfun Pro Micro 16 MHz
- PCF8575 I2C GPIO expander
- 74HC4067 16-channel analog multiplexer
- Rotary encoders for jog and browsing controls
- Multiple buttons and potentiometers for deck and mixer functions
- A custom 3D-printed enclosure designed in Fusion 360

For more detail, see:

- [docs/HARDWARE.md](docs/HARDWARE.md)
- [docs/PINOUT.md](docs/PINOUT.md)
- [CDJv2.f3z](CDJv2.f3z)

## Repository Structure

```text
.
|-- CDJ_firmware/          Firmware source, PlatformIO config, and Mixxx mapping
|-- docs/                  Project documentation and planning
|-- pics/                  Renders and build photos
|-- reference circuits/    Circuit reference screenshots
|-- kanban.md              Live task board
|-- AGENTS.md              Agent workflow instructions
`-- CDJv2.f3z              Fusion 360 model
```

## Getting Started

### Firmware

1. Install [PlatformIO](https://platformio.org/) in VS Code.
2. Open the [CDJ_firmware](CDJ_firmware) folder.
3. Connect the Sparkfun Pro Micro by USB.
4. Build or upload:

   ```bash
   pio run
   pio run --target upload
   ```

### Mixxx Mapping

Copy these files into your Mixxx mappings folder:

- `CDJ_firmware/mixx_Mapping/DJC-DIY.midi.xml`
- `CDJ_firmware/mixx_Mapping/DJC-DIY-scripts.js`

Then connect the controller and enable the mapping in Mixxx.

More details:

- [docs/FIRMWARE.md](docs/FIRMWARE.md)
- [docs/MIXXX.md](docs/MIXXX.md)

## Documentation

- [docs/README.md](docs/README.md) - documentation index
- [docs/ROADMAP.md](docs/ROADMAP.md) - phased development plan
- [docs/STATUS.md](docs/STATUS.md) - current project snapshot
- [docs/CONTROL_MATRIX.md](docs/CONTROL_MATRIX.md) - control validation tracker
- [kanban.md](kanban.md) - working task board

## Known Limitations

- Some button mappings still need fixing and verification
- The jog wheel labeling is currently swapped in the documented/firmware behavior
- The electronics are still based on hand wiring rather than a dedicated PCB
- Software compatibility beyond the current Mixxx path is still a future goal

## Development Direction

The current roadmap is:

1. Stabilize the existing prototype
2. Improve documentation and repo clarity
3. Prepare for PCB design
4. Refine the mechanical design
5. Refactor firmware for maintainability
6. Explore broader software support

## Inspiration

This controller project was inspired by [@mandiclab](https://github.com/mandiclab) and the open DIY controller work in [mandiclab/djc-diy](https://github.com/mandiclab/djc-diy).

## License

License not defined yet in the repository.

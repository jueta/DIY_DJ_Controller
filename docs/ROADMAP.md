# Project Roadmap

> DIY DJ Controller roadmap focused on turning a working prototype into a more robust, documented, and maintainable project.

## Vision

Build this homemade CDJ-style controller into a professional-quality open hardware project with:

- Reliable hardware and firmware
- Clear and reproducible documentation
- A cleaner mechanical design
- A migration path from hand wiring to PCB-based electronics
- Better software integration and mapping support

## Current State

Based on the repository, the project already has a strong prototype foundation:

- A working USB-MIDI firmware for a Sparkfun Pro Micro
- A custom physical controller with encoders, buttons, and analog controls
- Mixxx mapping files
- A Fusion 360 model and build photos
- Basic hardware, firmware, and pinout documentation

Current gaps visible in the repo:

- Button mapping issues are still open
- Documentation structure is improving but still incomplete
- No PCB design files are present yet
- No formal test or validation workflow is documented
- Mechanical iteration goals are not yet captured in a single plan

## Guiding Principles

- Stabilize the current prototype before expanding scope
- Prefer documented, reproducible progress over undocumented experimentation
- Separate short-term fixes from medium-term redesign work
- Keep firmware, hardware, and mechanical changes synchronized through documentation
- Define "done" for each phase to reduce overwhelm and avoid vague progress

## Roadmap Phases

## Phase 1 - Stabilize The Current Prototype

Goal: make the existing controller reliable enough that future redesign work starts from a known-good baseline.

Priority outcomes:

- Fix incorrect or incomplete button mappings
- Confirm the real hardware-to-firmware-to-software mapping
- Document known issues and workarounds
- Clean up core firmware comments and naming where it reduces confusion

Suggested deliverables:

- Verified control map for every button, pot, and encoder
- Updated Mixxx mapping notes
- Known-issues list with status and reproduction notes
- Firmware notes explaining swapped jog wheel labeling and other quirks

Definition of done:

- Every current control is classified as working, partially working, or broken
- The repo reflects the actual hardware behavior
- A new contributor or future-you can understand the current controller state quickly

## Phase 2 - Professionalize Documentation And Repo Structure

Goal: make the project understandable, presentable, and easier to continue.

Priority outcomes:

- Upgrade README into a stronger project overview
- Keep docs aligned with the real folder structure
- Add a roadmap, build status notes, and development workflow guidance
- Replace placeholder or inaccurate references

Suggested deliverables:

- Improved root README
- Updated `docs/README.md` index
- `docs/ROADMAP.md`
- A `docs/STATUS.md` or equivalent progress snapshot
- Consistent naming for folders, files, and docs references

Definition of done:

- The repository can be understood top-down from README and docs alone
- Broken or outdated path references are removed
- The project story, current status, and next steps are visible in one place

## Phase 3 - Prepare The Electronics For PCB Migration

Goal: convert the current hand-wired prototype into a design that can be captured as a repeatable electronic system.

Priority outcomes:

- Freeze the currently working signal map
- Turn informal wiring into a schematic-level representation
- Identify which parts stay and which parts should change for a PCB revision
- Reduce manual soldering complexity and wiring risk

Suggested deliverables:

- Complete schematic draft
- Connector and footprint decisions
- PCB requirements list
- Input/output matrix for buttons, encoders, and potentiometers
- Power and grounding review

Definition of done:

- The current electronics are documented clearly enough to begin PCB layout
- Key PCB constraints are written down before CAD work starts
- The board design can proceed without guessing signal ownership

## Phase 4 - Improve Mechanical Design

Goal: refine the controller enclosure and physical layout so the device is easier to assemble, sturdier, and nicer to use.

Priority outcomes:

- Improve fit, alignment, and access for controls
- Review ergonomics of button and encoder placement
- Design around PCB integration instead of point-to-point wiring
- Make the enclosure easier to print and assemble

Suggested deliverables:

- Revision list for the Fusion 360 model
- Assembly constraints for PCB, standoffs, mounting, and cable routing
- Notes on printability, tolerances, and maintenance access

Definition of done:

- The next mechanical revision is based on documented requirements
- Mechanical changes support the electronics plan instead of conflicting with it

## Phase 5 - Refactor Firmware For Maintainability

Goal: evolve the firmware from a functional prototype into a cleaner codebase that is easier to extend and debug.

Priority outcomes:

- Separate input scanning logic from MIDI output logic
- Improve naming and mapping clarity
- Make control definitions easier to update
- Add a basic validation strategy for regressions

Suggested deliverables:

- Refactored input/mapping structure
- Centralized control definitions
- Firmware behavior notes for each input group
- Manual test checklist for flashing and verification

Definition of done:

- Firmware changes are less risky to make
- The mapping between physical inputs and MIDI outputs is easier to audit
- Future software support work has a cleaner base

## Phase 6 - Expand Software Compatibility

Goal: make the controller easier to use with additional DJ software beyond the current Mixxx workflow.

Priority outcomes:

- Research what is possible through generic MIDI mappings versus software-specific integrations
- Document controller profiles or mappings for target software
- Prioritize the best-supported path before deeper custom work

Suggested targets:

- Mixxx: stabilize first
- Rekordbox: investigate mapping and device support path
- Other software: evaluate later based on real demand

Definition of done:

- A clear compatibility matrix exists
- The repo states what is supported, experimental, or not yet implemented

## Recommended Priority Order

1. Stabilize mappings and current controller behavior
2. Improve documentation and repo structure
3. Capture electronics for PCB planning
4. Revise mechanical design with PCB constraints in mind
5. Refactor firmware
6. Expand software compatibility

This order is recommended because it protects momentum. It avoids redesigning hardware or firmware before the current prototype is fully understood and documented.

## Immediate Next Steps

These are the highest-value tasks to tackle next:

1. Create a full control inventory from the current firmware and Mixxx mapping.
2. Mark each control as working, broken, swapped, or unverified.
3. Update documentation to reflect the actual current hardware state.
4. Capture PCB requirements from the existing hand-wired build.
5. Create a mechanical revision list based on assembly pain points.

## Proposed Working Milestones

### Milestone A - Prototype Baseline

- Verify all buttons, pots, and encoders
- Fix the most important mapping errors
- Update docs to reflect reality

### Milestone B - Repo Professionalization

- Improve README and docs navigation
- Add status, roadmap, and structured development notes
- Clean up outdated references and placeholders

### Milestone C - PCB Readiness

- Produce schematic capture inputs
- Define board requirements and constraints
- Align enclosure changes with electronics design

### Milestone D - Firmware And Compatibility Expansion

- Refactor firmware structure
- Improve maintainability
- Investigate Rekordbox and other software support paths

## Risks To Watch

- Expanding scope before the current prototype is fully documented
- Changing hardware and firmware at the same time without a stable baseline
- Letting folder names and docs drift out of sync
- Starting PCB design before the input map is verified
- Spending time on broad software compatibility before core controller behavior is stable

## How We Can Use This Roadmap

This roadmap is intended to guide repo work in small, manageable iterations.

A practical working pattern is:

1. Pick one phase or milestone
2. Define a small task list
3. Update docs as changes are made
4. Verify on hardware where needed
5. Move to the next bounded step

That keeps the project moving without requiring a full redesign all at once.

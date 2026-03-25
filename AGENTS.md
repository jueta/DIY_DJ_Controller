# AGENTS

This file tells any agent how to work effectively in this repository.

## Project Summary

This repository contains a homemade CDJ-style DJ controller project built by the owner from:

- A custom 3D-printed enclosure and physical layout
- Hand-soldered electronics around a Sparkfun Pro Micro
- USB-MIDI firmware built with PlatformIO and Arduino
- Mixxx mapping files for software integration

The controller is already functional as a prototype, but it is still under development. The project is now moving from "working prototype" toward a more professional and maintainable state.

## Project Goals

The current high-level goals are:

- Stabilize the current hardware and firmware behavior
- Improve documentation and repo structure
- Prepare the electronics for PCB design
- Improve the mechanical design
- Refactor firmware for maintainability
- Investigate broader software compatibility after stabilization

Read [docs/ROADMAP.md](/Users/jueta/Documents/Projects/CDJ/docs/ROADMAP.md) before starting larger work.

## Source Of Truth

Use these files as the current source of truth:

- [docs/ROADMAP.md](/Users/jueta/Documents/Projects/CDJ/docs/ROADMAP.md): project direction and phases
- [docs/STATUS.md](/Users/jueta/Documents/Projects/CDJ/docs/STATUS.md): current snapshot and active priorities
- [kanban.md](/Users/jueta/Documents/Projects/CDJ/kanban.md): active task workflow
- [docs/CONTROL_MATRIX.md](/Users/jueta/Documents/Projects/CDJ/docs/CONTROL_MATRIX.md): control inventory and validation status
- [readme.md](/Users/jueta/Documents/Projects/CDJ/readme.md): public project overview
- [CDJ_firmware/src/main.cpp](/Users/jueta/Documents/Projects/CDJ/CDJ_firmware/src/main.cpp): current firmware behavior
- [CDJ_firmware/mixx_Mapping/DJC-DIY.midi.xml](/Users/jueta/Documents/Projects/CDJ/CDJ_firmware/mixx_Mapping/DJC-DIY.midi.xml): Mixxx mapping definitions
- [CDJ_firmware/mixx_Mapping/DJC-DIY-scripts.js](/Users/jueta/Documents/Projects/CDJ/CDJ_firmware/mixx_Mapping/DJC-DIY-scripts.js): Mixxx script behavior

If documentation and code disagree, treat code and verified hardware behavior as higher priority, then update the docs.

## Working Rules

- Keep changes scoped and easy to review.
- Do not redesign hardware, firmware, and mappings all at once unless explicitly requested.
- Prefer small documented improvements over broad speculative refactors.
- When changing behavior, update the relevant docs in the same session.
- Do not assume hardware behavior if it has not been confirmed in the repo or by the owner.
- Mark unknowns clearly instead of inventing missing details.

## Kanban Workflow

Before starting work:

1. Read this file.
2. Read [docs/STATUS.md](/Users/jueta/Documents/Projects/CDJ/docs/STATUS.md).
3. Read [kanban.md](/Users/jueta/Documents/Projects/CDJ/kanban.md).
4. Pick one task from `Ready` if possible.

While working:

1. Move the chosen task to `In Progress`.
2. Keep notes brief and factual.
3. Update related docs if the understanding of the project changes.

When blocked:

1. Move the task to `Blocked`.
2. Add a short note explaining the blocker.
3. If possible, create a smaller unblocked follow-up task.

When implementation is complete:

1. Move the task to `Review`.
2. Summarize what changed.
3. Note any remaining risks or validation gaps.

When verified:

1. Move the task to `Done`.
2. Keep the board concise by removing stale duplicates.

## Task Selection Heuristics

Prefer this order:

1. Tasks that stabilize the current prototype
2. Tasks that improve clarity of documentation and project state
3. Tasks that prepare for PCB migration
4. Tasks that improve mechanical design planning
5. Firmware refactors after the input map is stable
6. Compatibility expansion after the core controller is reliable

Avoid spending time on future integrations before the current controller state is documented.

## Documentation Expectations

Agents should help the repo become easier for future-you to navigate.

When relevant, update:

- README when the public-facing project overview changes
- STATUS when current priorities or project health change
- CONTROL_MATRIX when an input is verified, renamed, or found broken
- ROADMAP when project direction changes materially
- Kanban when task state changes

## Good Session Outcomes

A productive session usually does one or more of these:

- Fixes a real bug
- Verifies one part of the control mapping
- Improves documentation accuracy
- Captures PCB or mechanical requirements from existing evidence
- Leaves behind a clearer next step than before

## What To Avoid

- Do not erase historical context that still helps explain the prototype.
- Do not present guesses as confirmed hardware facts.
- Do not mark work done if it still needs hardware validation.
- Do not leave doc links broken after moving or renaming files.

## Recommended Next Actions

The best next technical work is:

1. Build and verify the control matrix
2. Resolve button and mapping inconsistencies
3. Capture current-state hardware requirements for PCB planning
4. Improve README and status visibility

If there is uncertainty, choose the smallest task that improves clarity.

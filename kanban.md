# DIY DJ Controller - Kanban

> Live working board for the homemade CDJ-style MIDI controller project.

## How To Use This Board

- Move tasks between sections instead of rewriting the whole board each time.
- Keep tasks small enough to complete in one focused session where possible.
- When starting work, move one task to `In Progress`.
- If work cannot continue without hardware testing, user input, parts, or a design decision, move it to `Blocked`.
- When implementation is done but still needs validation, move it to `Review`.
- Only move a task to `Done` when the repo and docs reflect the final state.

## Backlog

- [ ] Improve root README project overview and polish
- [ ] Create and verify the full control matrix for all inputs
- [ ] Fix incorrect or incomplete Mixxx button mappings
- [ ] Document known issues and current firmware quirks
- [ ] Capture PCB requirements from the current hand-wired build
- [ ] Draft an electronics migration plan from wiring to PCB
- [ ] Create a mechanical revision list for the Fusion 360 model
- [ ] Review enclosure ergonomics and assembly constraints
- [ ] Refactor firmware structure after the input map is verified
- [ ] Research software compatibility strategy beyond Mixxx

## Ready

- [ ] Complete a full XML and JS audit for `docs/CONTROL_MATRIX.md`
- [ ] Audit documentation for outdated file paths and placeholders

## In Progress

- [ ] Improve root README project overview and polish

## Blocked

- [ ] Verify which physical buttons are failing on hardware and how they fail
- [ ] Confirm which controls are fully working versus partially working on the real device
- [ ] Decide the first target path for non-Mixxx software support

## Review

- [ ] Review roadmap and planning docs for completeness and tone
- [ ] Review new project operating docs for clarity and usefulness

## Done

- [x] Add a phased project roadmap in `docs/ROADMAP.md`
- [x] Fix broken documentation index links in `docs/README.md`
- [x] Create `docs/STATUS.md` current-state snapshot
- [x] Create `docs/CONTROL_MATRIX.md` baseline inventory
- [x] Create `AGENTS.md` operating instructions for future agents
- [x] Replace the old Kanban with a workflow-oriented board

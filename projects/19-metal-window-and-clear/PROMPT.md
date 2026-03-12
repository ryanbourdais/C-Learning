# Metal: Window And Clear

## Goal

Create a window and clear it to a solid color using Metal.

## Requirements

- Create a macOS window.
- Set up a Metal device and command queue.
- Create a drawable-backed layer or view.
- Encode commands that clear the current drawable.
- Present every frame.

## Concepts To Practice

- command queues
- command buffers
- drawable presentation
- platform integration
- resource lifetime basics

## Evaluation Focus

- How clean the API feels compared with Vulkan and DirectX
- How tied the workflow is to Apple platform tooling
- Whether the API design matches how you want to structure an engine

## Notes

- This project is Apple-platform-specific.

## Stretch Goals

- handle window resize correctly
- add frame timing
- separate platform and renderer setup

# DirectX 11: Window And Clear

## Goal

Create a Win32 window and clear it to a solid color using DirectX 11.

## Requirements

- Create a basic Win32 window.
- Initialize a Direct3D 11 device and swap chain.
- Create a render target view.
- Clear the render target every frame.
- Present the back buffer.

## Concepts To Practice

- Win32 window setup
- device and swap chain creation
- render target management
- frame presentation
- COM-style resource handling

## Evaluation Focus

- How much platform-specific work is required
- How ergonomic the D3D11 setup feels
- Whether the Windows-only tradeoff is acceptable for your goals

## Notes

- This project is Windows-specific.

## Stretch Goals

- handle window resizing
- add a frame timer
- wrap COM cleanup into helper functions

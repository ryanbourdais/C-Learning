# Vulkan: Window And Clear

## Goal

Create a window, initialize Vulkan, and clear the screen to a custom color every frame.

## Requirements

- Create a window with GLFW or SDL.
- Create a Vulkan instance and surface.
- Select a physical device and create a logical device.
- Create a swapchain.
- Record commands that clear the screen each frame.
- Present the result to the window.

## Concepts To Practice

- instance and device creation
- swapchains
- command buffers
- synchronization basics
- explicit resource management

## Evaluation Focus

- How much setup is required before first pixels
- How understandable the resource and lifetime model feels
- Whether the explicitness seems helpful or burdensome

## Stretch Goals

- handle window resize
- enable validation layers
- wrap setup steps into helper modules

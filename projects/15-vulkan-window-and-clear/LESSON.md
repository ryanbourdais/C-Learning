# Lesson: Explicit Graphics Setup And Resource Lifetimes

## What You Are Learning

Vulkan is designed around explicit control. This project teaches that modern graphics APIs often require substantial setup before a single frame can be drawn.

Key ideas:

- instance creation
- physical versus logical devices
- surfaces and swapchains
- command buffers
- synchronization

## Explicitness Is The Point

Unlike OpenGL, Vulkan does not try to hide much. You are expected to declare resources, choose devices, and manage lifetimes deliberately.

That is why the first Vulkan milestone is often just clearing the screen.

## Instance And Device

Vulkan separates concepts cleanly:

- the instance represents the application's connection to Vulkan
- the physical device is the actual GPU
- the logical device is your interface for submitting work to that GPU

This layered design reflects how close Vulkan is to the underlying platform.

## Presentation Requires A Swapchain

Rendering to a window involves a swapchain, which manages the images presented to the screen.

This is a major conceptual jump if you are coming from simpler APIs. It teaches that presenting a frame is itself a managed resource process.

## Commands Are Recorded

In Vulkan, you usually record commands into command buffers and submit them later. This is different from the immediate-feeling style of OpenGL.

That model is important for engine design because it encourages thinking in batches of work.

## Synchronization

Vulkan makes synchronization visible. Even a clear-screen app involves coordinating:

- image availability
- rendering completion
- presentation timing

This can feel heavy, but it exposes real GPU workflow details that simpler APIs abstract away.

## What To Pay Attention To

For evaluation, watch:

- how much of the code is pure setup
- whether the explicit model feels clarifying or exhausting
- whether the architecture seems like a good base for an engine

## Try These Before Starting

1. Learn the difference between a physical and logical device.
2. Read a short explanation of what a swapchain does.
3. Sketch the order of operations for one frame in Vulkan at a high level.

## C++ Notes

Vulkan itself is language-neutral, but many developers prefer C++ for managing Vulkan object lifetimes and setup structure. If you try both, compare whether C++ wrappers make the explicit model clearer or simply add another abstraction layer to debug.

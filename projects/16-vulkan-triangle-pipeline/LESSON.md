# Lesson: Pipelines, Recorded Draw Commands, And Reusability

## What You Are Learning

This project moves Vulkan from setup into actual rendering. The main lesson is that drawing in Vulkan revolves around explicitly created pipeline objects and recorded commands.

Key ideas:

- shader modules
- graphics pipeline creation
- render pass style rendering setup
- command recording
- reusable renderer architecture

## Pipelines Bundle Rendering State

Vulkan prefers large, explicit objects that describe how rendering works. A graphics pipeline may include:

- shader stages
- vertex input layout
- viewport rules
- rasterization state
- blending rules

This up-front declaration trades flexibility for predictability and performance.

## Shaders Become Modules

Shaders are typically compiled ahead of time and loaded into Vulkan as shader modules. This is different from APIs that often compile shader source at runtime.

That difference matters for tooling and iteration speed.

## Command Buffers Reflect Work Submission

The act of drawing is not just calling one function. You record steps into a command buffer:

- begin rendering commands
- bind the pipeline
- bind buffers
- issue a draw

This is a more engine-like mental model than immediate-mode style APIs.

## Separation Of Concerns

Vulkan quickly pushes you toward structure. You may naturally want separate areas of code for:

- device setup
- swapchain handling
- pipeline creation
- per-frame command recording

That pressure is informative. It tells you how the API wants to be organized.

## What To Pay Attention To

Compare this with OpenGL and DirectX:

- does Vulkan's explicit model make later scaling feel easier
- how painful is simple iteration
- can you imagine maintaining this API in a solo engine project

## Try These Before Starting

1. Read what a graphics pipeline object contains.
2. Look at the difference between shader source and compiled shader binaries.
3. Write down the minimum steps required to draw one triangle in Vulkan at a conceptual level.

## C++ Notes

This is one of the strongest examples of where C++ can help with Vulkan through RAII and builder-style setup helpers. The main concept to preserve is that pipeline creation and command recording remain explicit regardless of which host language you use.

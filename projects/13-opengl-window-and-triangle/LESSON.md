# Lesson: The Graphics Pipeline Starts With A Window

## What You Are Learning

This is your first rendering API project. The main lesson is that drawing to the screen requires more than issuing draw commands. You need a window, a graphics context, shader programs, GPU buffers, and a render loop.

Key ideas:

- window creation
- OpenGL context creation
- shader compilation
- vertex buffers
- the render loop

## Why A Helper Library Is Common

OpenGL itself does not create windows. It only defines rendering commands once a valid context exists. That is why beginner projects usually pair it with a library such as GLFW or SDL.

The helper library handles:

- opening a window
- creating the OpenGL context
- processing input and events

## The Render Loop

Graphics programs usually run in a loop:

1. process input and window events
2. clear the screen
3. issue draw commands
4. present the frame

This is very different from a terminal program that prints output once and exits.

## Shaders

Modern OpenGL rendering usually requires at least:

- a vertex shader
- a fragment shader

These small GPU programs define how vertex data is transformed and how pixels are colored.

Even a triangle project introduces the idea that some logic runs on the CPU and some on the GPU.

## Vertex Data

Your triangle is represented as vertex data in memory. That data must be uploaded to a GPU-managed buffer before OpenGL can use it efficiently.

This is one of the first important graphics concepts: CPU-side data is not automatically GPU-side data.

## API State

OpenGL is stateful. That means many commands affect global context state that later draw calls depend on.

This makes it approachable at first, but it also means bugs can come from doing the right step in the wrong order.

## What To Pay Attention To

For evaluation purposes, focus on:

- how much setup code is required before the first draw
- how understandable shader compilation errors are
- how easy it feels to connect CPU data to what appears on screen

## Try These Before Starting

1. Read about what an OpenGL context is.
2. Sketch the lifecycle of one frame from input to present.
3. Look at a minimal vertex and fragment shader and identify what each one is responsible for.

## C++ Notes

Most OpenGL learning material is written in C++, even when the API itself is C-style. If you revisit this project in C++, the biggest difference is usually wrapper structure and resource lifetime management, not the OpenGL calls themselves.

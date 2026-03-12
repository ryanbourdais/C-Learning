# Lesson: Metal Pipeline State And Basic Geometry Rendering

## What You Are Learning

This project adds actual drawing to the Metal setup. It is the point where you can compare Metal's pipeline model directly against OpenGL, Vulkan, and Direct3D 11.

Key ideas:

- shader functions
- pipeline state objects
- vertex buffers
- render command encoders
- frame submission

## Pipeline State Objects

Metal groups much of the draw configuration into a render pipeline state object. This is conceptually similar to Vulkan's pipeline approach, though usually with less setup friction.

That makes it a strong comparison point when thinking about engine architecture.

## Shader Functions

Metal uses Metal Shading Language, which is part of the Apple tooling ecosystem. This affects:

- how shaders are written
- how they are compiled
- how tightly they fit into the build process

Shader workflow is one of the most important long-term evaluation points for engine work.

## Command Encoders

Rendering commands are issued through encoders associated with a command buffer. This reflects a design that is explicit, but still comparatively streamlined.

It is useful to notice how much state is established:

- at pipeline creation time
- at per-frame encoding time
- at draw time

## Vertex Data

Like every other modern API, drawing a triangle means your vertex data must be stored in a GPU-usable buffer and described consistently to the shader stages.

This is one of the universal graphics lessons across APIs.

## What To Pay Attention To

Ask yourself:

- does Metal feel like the cleanest modern API
- how much does its platform lock-in matter
- would you want your engine abstraction to feel more like Metal or more like Vulkan

## Try These Before Starting

1. Read what information goes into a Metal render pipeline state.
2. Look at a tiny Metal shader pair and identify the vertex and fragment responsibilities.
3. Sketch the steps from vertex buffer creation to presenting a triangle on screen.

## C++ Notes

This project is best treated as a renderer-backend experiment rather than a pure C++ exercise, because Metal usually lives behind Objective-C or Objective-C++ integration. The architectural lesson still transfers directly: compare how your engine-facing abstraction would sit on top of Metal versus Vulkan or Direct3D.

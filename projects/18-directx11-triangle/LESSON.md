# Lesson: The D3D11 Pipeline And Shader Binding

## What You Are Learning

This project is the first real rendering step in Direct3D 11. It teaches how shader stages, vertex input layouts, and GPU buffers work together to produce an image.

Key ideas:

- vertex and pixel shaders
- input layouts
- vertex buffers
- pipeline state binding
- draw calls

## Shader Stages

For a simple triangle, the essential stages are:

- vertex shader
- pixel shader

The vertex shader processes per-vertex data. The pixel shader computes final pixel color. This is conceptually similar to OpenGL, even though the surrounding API is different.

## Input Layouts

D3D11 needs to know how your vertex buffer data maps onto the inputs expected by the vertex shader. That mapping is described by an input layout.

This is a useful lesson in API design: the GPU needs an exact agreement between memory format and shader expectations.

## Vertex Buffers

The triangle vertices are stored in a GPU-accessible buffer. Creating and binding that buffer is one of the core rendering tasks in every graphics API, even if the names differ.

## Binding State Before Drawing

In D3D11, rendering a triangle usually means binding several pieces of state before issuing a draw call:

- input layout
- vertex buffer
- shaders
- render target

This state-binding model is worth comparing to OpenGL's global state style and Vulkan's pipeline objects.

## What To Pay Attention To

For evaluation, ask:

- does the state model feel manageable
- are shaders easier to work with here than in OpenGL or Vulkan
- does this seem like a practical middle ground for an engine prototype

## Try These Before Starting

1. Learn what semantic names mean in D3D11 shader inputs.
2. Look at a small vertex structure and how its fields map to an input layout.
3. Sketch the order of binding calls needed before a `Draw`.

## C++ Notes

Direct3D 11 is commonly used from C++, so this project is a good place to evaluate whether the language makes pipeline setup and COM resource handling meaningfully more manageable. The graphics concepts themselves do not become simpler, but the host code often does.

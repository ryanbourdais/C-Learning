# Lesson: Textures, Coordinates, And Simple 2D Rendering

## What You Are Learning

This project extends basic OpenGL drawing into something closer to game rendering. A textured quad introduces images, coordinates, and a simple scene object that can move.

Key ideas:

- textured rendering
- texture coordinates
- uniforms
- input-driven motion
- 2D scene thinking

## A Quad Is Usually Two Triangles

Graphics hardware is built around triangles, so even a rectangle is typically drawn as two triangles.

That means your sprite is really:

- four vertices
- texture coordinates
- either six indexed vertices or two triangle definitions

## What A Texture Is

A texture is image data stored on the GPU. Rendering with a texture means:

- load image bytes on the CPU
- upload them into GPU memory
- sample that texture in a fragment shader

This is the first time your rendering depends on external asset data rather than only hardcoded vertices.

## Coordinates Matter

You now have at least two coordinate spaces to think about:

- vertex positions for where the quad appears
- texture coordinates for which part of the image is sampled

A common source of confusion is mixing these up.

## Uniforms

Uniforms are values sent to shaders that stay constant across a draw call. They are useful for things like:

- object position
- scale
- color tint

This is one of the first steps toward a reusable rendering model.

## Input And Motion

Moving the sprite with keyboard input means the render loop is now reacting to player actions every frame. That introduces the idea of updating state before drawing.

Many real-time programs follow this pattern:

1. read input
2. update world state
3. render the new frame

## What To Pay Attention To

Compare this project to the triangle project:

- does adding assets feel straightforward
- is the shader interface still understandable
- how much boilerplate is growing

These answers matter when choosing a long-term engine API.

## Try These Before Starting

1. Learn the difference between vertex position and texture coordinates.
2. Read a basic image-loading example and identify where CPU memory ends and GPU memory begins.
3. Sketch how keyboard input should change a sprite's position variable each frame.

## C++ Notes

This project maps very naturally to C++ because texture and buffer lifetimes benefit from RAII wrappers. The rendering concepts stay the same, so the value is in comparing plain C resource management with a cleaner C++ abstraction layer.

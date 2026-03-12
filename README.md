# C And C++ Learning Projects

This repository contains short C projects designed to be completed in less than a day each. The same projects also map well to beginner and intermediate C++ practice, especially if you want to compare procedural C design with C++ class and standard library patterns later.

## Structure

- `projects/`: one folder per project
- Each project contains a `PROMPT.md` file with scope, goals, and stretch ideas
- Each project contains a `LESSON.md` file with background concepts and examples
- `C_CHEATSHEET.md`: quick-reference guide for C syntax, pointers, memory, and common gotchas for C# or Python developers
- `SETUP.md`: how to set up a C or C++ development environment on macOS and Windows
- The final projects form a graphics API comparison track

## Language Approach

- Start with C first if your goal is systems programming or a C-based game engine
- Revisit the same projects in C++ if you want to compare language ergonomics
- The `PROMPT.md` files stay language-agnostic enough to support either
- The `LESSON.md` files now include a short `C++ Notes` section for translation of the core ideas

## Suggested Order

1. `01-hello-math-cli`
2. `02-number-guessing-game`
3. `03-unit-converter`
4. `04-tic-tac-toe`
5. `05-to-do-list`
6. `06-text-stats`
7. `07-contact-book`
8. `08-hangman`
9. `09-dynamic-array-library`
10. `10-student-gradebook`
11. `11-mini-shell`
12. `12-memory-game`
13. `12a-cmake-c-library`
14. `13-opengl-window-and-triangle`
15. `14-opengl-textured-sprite`
16. `15-vulkan-window-and-clear`
17. `16-vulkan-triangle-pipeline`
18. `17-directx11-window-and-clear`
19. `18-directx11-triangle`
20. `19-metal-window-and-clear`
21. `20-metal-triangle`

The `12a-cmake-c-library` project is the build-system bridge between the small terminal exercises and the graphics API track.

## Graphics Track Notes

- `OpenGL`: good for learning the classic graphics pipeline with less setup friction
- `Vulkan`: lower-level and more explicit; useful for understanding modern engine architecture
- `DirectX 11`: practical Windows API with a simpler learning curve than DirectX 12
- `Metal`: important if you want to understand Apple platform rendering

These graphics projects are intentionally small. The goal is to compare setup cost, rendering model, shader workflow, and debugging experience before committing to an engine direction.

# Lesson: Moving From One-File Programs To A Real Build

## What You Are Learning

This project is the bridge between small terminal exercises and larger systems work. The main lesson is that once code is split across multiple files and reused as a library, the build itself becomes part of the project.

Key ideas:

- separating declarations from implementation
- compiling multiple translation units
- linking your own library into an executable
- using CMake as a build description tool
- keeping builds repeatable as the project grows

## Why This Project Fits Before Graphics

Graphics API work usually involves:

- multiple source files
- platform setup code
- external libraries
- different build settings for debug and release

If you do not understand the build step before that point, graphics setup feels more confusing than it needs to.

This project gives you a smaller place to learn that workflow first.

## From One File To Multiple Files

Early projects can live entirely in `main.c`. That stops scaling once you want to reuse logic or keep responsibilities separate.

A common next step looks like this:

- `main.c` for command-line flow
- `stats.c` for implementation
- `stats.h` for declarations

The header exposes what other files are allowed to call. The `.c` file holds the actual implementation.

## Compilation Versus Linking

When you build a multi-file C program, two different phases matter:

1. compilation turns each `.c` file into an object file
2. linking combines object files and libraries into the final executable

That distinction matters because many beginner build errors are really link errors, not syntax errors.

For example, if `main.c` calls `sum_array` and you forgot to compile or link `stats.c`, the compiler may accept the header but the linker will fail because the implementation is missing from the final program.

## What A Library Target Means

In this project, your library is not something downloaded from the internet. It is your own reusable code packaged as a separate build target.

That matters because it teaches a cleaner engine-style habit:

- keep reusable logic in libraries
- keep app entry points thin
- link pieces together deliberately

Later, the same pattern applies to modules such as:

- math
- containers
- platform
- renderer
- asset loading

## What CMake Actually Does

CMake is not the compiler. It is a tool that describes the build and generates files for another build system.

You usually write a `CMakeLists.txt` that says things like:

- which source files belong to a library
- which source files belong to an executable
- which targets link to which libraries
- which include directories should be visible

Then CMake generates native build files for your platform, and those build files invoke the real compiler such as `cc`, `clang`, `gcc`, or MSVC `cl`.

## A Minimal CMake Shape

At a high level, a project like this often needs:

```cmake
cmake_minimum_required(VERSION 3.20)
project(toolkit C)

add_library(stats stats.c)
add_executable(tool main.c)
target_link_libraries(tool PRIVATE stats)
```

That is enough to express an important idea: the executable depends on your library.

## Why Out-Of-Source Builds Matter

Use a separate build directory such as `build/`:

```sh
cmake -S . -B build
cmake --build build
```

This keeps generated files out of your source tree.

That becomes more important as projects grow because build systems create many temporary and platform-specific files.

## What To Pay Attention To

For this project, focus on:

- whether your header file is clean and minimal
- whether your executable logic stays smaller after moving code into a library
- whether you understand the difference between editing source files and regenerating the build
- whether CMake feels clearer once you think in targets instead of raw compiler commands

## Try These Before Starting

1. Write one header with function declarations only.
2. Compile a two-file C program manually and notice the extra steps.
3. Read a tiny `CMakeLists.txt` and identify the library target and the executable target.

## C++ Notes

This project maps directly to C++ later. The build idea does not change. What changes is the compiler target language and often the library structure.

If you revisit it in C++, compare:

- `project(toolkit C)` versus `project(toolkit CXX)`
- `cc` or `clang` versus `c++` or `clang++`
- plain C helper functions versus small C++ utility classes

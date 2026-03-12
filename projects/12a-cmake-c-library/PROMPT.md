# CMake C Library Starter

## Goal

Build a small command-line program in C that uses your own library and is built with CMake instead of a single compiler command.

A good version of this project is a tiny toolkit app with commands such as:

- sum an array of integers
- find the max value
- compute an average
- print a small report

## Requirements

- Write the project in C first.
- Split the code into at least:
  - one executable source file
  - one library source file
  - one header file
- Create a `CMakeLists.txt` that builds:
  - a library target
  - an executable target
- Link the executable against your library.
- Build the project from a separate `build/` directory.
- Run the program from the terminal.

## Concepts To Practice

- multi-file C programs
- headers and source separation
- reusable library design
- build configuration with CMake
- linking your own code into an executable

## Evaluation Focus

- Whether you understand what CMake is generating for you
- Whether your code is cleaner once logic moves into a library
- Whether you can rebuild confidently after changing multiple files

## Stretch Goals

- add a second library source file
- support a few command-line modes
- add a simple test executable target
- build both a static library and a shared library version

# C And C++ Environment Setup

This guide covers a practical starter setup for learning C and C++ on macOS and Windows. The goal is not to build a perfect professional toolchain on day one. The goal is to get to the point where you can write a small source file, compile it, run it, and debug basic problems.

## What You Need

At minimum, you need:

- a compiler
- a terminal
- a text editor or IDE
- a way to build and run programs repeatedly

For this repo, a lightweight setup is enough.

## File Extensions

In this repo, you will likely use:

- `.c` for C source files
- `.cpp` for C++ source files
- `.h` for C or C++ headers in simple projects
- `.hpp` if you want to distinguish C++ headers explicitly

## macOS Setup

### 1. Install Apple's Command Line Tools

Open Terminal and run:

```sh
xcode-select --install
```

This installs tools such as:

- `cc` or `clang`
- `c++` or `clang++`
- `make`
- common headers and system libraries

After installation, verify:

```sh
cc --version
c++ --version
make --version
```

### 2. Pick An Editor

Common choices:

- VS Code
- Neovim
- CLion
- Xcode

If you want the least friction, VS Code is a reasonable default.

### 3. Compile A Test Program In C

Create a file named `hello.c`:

```c
#include <stdio.h>

int main(void) {
    printf("Hello, C!\n");
    return 0;
}
```

Compile it:

```sh
cc hello.c -o hello
```

Run it:

```sh
./hello
```

### 4. Compile A Test Program In C++

Create a file named `hello.cpp`:

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, C++!\n";
    return 0;
}
```

Compile it:

```sh
c++ hello.cpp -o hello-cpp
```

Do not use `cc` to build a `.cpp` file. `cc` is the C compiler driver, and it can fail at the link step with undefined `std::...` symbols because it does not link the C++ standard library the way `c++` or `clang++` does.

If you want to be explicit on macOS, this is also correct:

```sh
clang++ hello.cpp -o hello-cpp
```

Run it:

```sh
./hello-cpp
```

### 5. Optional: Install Homebrew

Homebrew is useful if you later want extra tools such as:

- `gcc`
- `cmake`
- `glfw`
- `sdl2`
- debugging utilities

If you already use Homebrew, that is enough. You do not need it just to start learning basic C.

### 6. Debugging On macOS

You can start with:

- compiler warnings
- `printf` debugging
- VS Code's debugger
- `lldb`

A good first compile command while learning C is:

```sh
cc -Wall -Wextra -pedantic hello.c -o hello
```

That enables helpful warnings and catches mistakes earlier.

A good first compile command while learning C++ is:

```sh
c++ -Wall -Wextra -pedantic -std=c++17 hello.cpp -o hello-cpp
```

If you prefer the explicit compiler name, use:

```sh
clang++ -Wall -Wextra -pedantic -std=c++17 hello.cpp -o hello-cpp
```

## Windows Setup

There are two practical beginner paths. The best one depends on whether you want the simplest C-learning setup or you specifically want the Microsoft toolchain for future DirectX work.

## Option 1: Visual Studio Community

This is the best default if you want a strong debugger and expect to evaluate DirectX later.

### 1. Install Visual Studio Community

During installation, include the workload:

- `Desktop development with C++`

Even though the name says C++, it includes the MSVC compiler and Windows development tools you need for C as well.

### 2. Use The Developer Command Prompt

After installation, open:

- `x64 Native Tools Command Prompt for VS`

Verify the compiler:

```bat
cl
```

### 3. Compile A Test Program In C

Create `hello.c`:

```c
#include <stdio.h>

int main(void) {
    printf("Hello, C!\n");
    return 0;
}
```

Compile:

```bat
cl /W4 hello.c
```

Run:

```bat
hello.exe
```

### 4. Compile A Test Program In C++

Create `hello.cpp`:

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, C++!" << std::endl;
    return 0;
}
```

Compile:

```bat
cl /EHsc /W4 hello.cpp
```

Run:

```bat
hello.exe
```

### Why Choose This Path

- best Windows debugger
- easiest path into Win32 and DirectX
- standard choice for native Windows development

## Option 2: MSYS2 With GCC Or Clang

This is a good choice if you want a Unix-like terminal workflow on Windows and simpler access to open-source libraries.

### 1. Install MSYS2

After installing it, open the `UCRT64` shell.

### 2. Install Toolchain Packages

Inside the MSYS2 shell, install a compiler and build tools:

```sh
pacman -S --needed base-devel mingw-w64-ucrt-x86_64-gcc
```

You can use Clang instead if you prefer, but GCC and G++ are fine for learning.

### 3. Verify The Compiler

```sh
gcc --version
make --version
```

### 4. Compile And Run C

```sh
gcc -Wall -Wextra -pedantic hello.c -o hello
./hello.exe
```

### 5. Compile And Run C++

```sh
g++ -Wall -Wextra -pedantic -std=c++17 hello.cpp -o hello-cpp
./hello-cpp.exe
```

### Why Choose This Path

- easier if you like a Unix-style workflow
- convenient for libraries like SDL and GLFW
- good for general C learning

## Editor And IDE Suggestions

### VS Code

Good default for both platforms. Useful extensions:

- `C/C++` by Microsoft
- `CodeLLDB` on macOS
- `CMake Tools` if you later adopt CMake

### Visual Studio

Best Windows-native IDE if you want debugger quality and eventual DirectX work.

### CLion

Strong if you already like JetBrains tools, though it is heavier than you need for basic exercises.

## Recommended Beginner Compile Flags

Use strict warnings early:

### macOS or GCC/Clang-style toolchains for C

```sh
cc -Wall -Wextra -pedantic -g main.c -o program
```

### macOS or GCC/Clang-style toolchains for C++

```sh
c++ -Wall -Wextra -pedantic -g -std=c++17 main.cpp -o program
```

### MSVC for C

```bat
cl /W4 /Zi main.c
```

### MSVC for C++

```bat
cl /W4 /Zi /EHsc /std:c++17 main.cpp
```

These do two things:

- warnings help catch mistakes
- debug info makes debugging easier later

## How To Work Through This Repo

For the early projects, you only need:

- one `.c` or `.cpp` file
- a compiler command
- the terminal

A typical loop is:

1. read the project's `PROMPT.md`
2. read the matching `LESSON.md`
3. write `main.c` or `main.cpp`
4. compile
5. run
6. fix warnings and errors
7. repeat

## C Versus C++ In This Repo

Use C if you want to practice:

- manual memory management with minimal abstraction
- explicit data layout
- procedural program structure
- language fundamentals that transfer directly to engine internals

Use C++ if you want to practice:

- the same low-level ideas with stronger abstraction tools
- `std::string`, `std::vector`, and streams
- classes and RAII
- writing tools or higher-level engine layers later

For the early projects, the fastest path is usually:

1. build it in C
2. if useful, rebuild it in C++ and compare what changed

## When You Reach The Graphics Projects

Your setup will depend on API choice:

- `OpenGL`: usually easiest to start with GLFW or SDL
- `Vulkan`: requires Vulkan SDK installation
- `DirectX 11`: Windows plus Visual Studio is the smoothest path
- `Metal`: requires macOS and Apple tooling

Do not install every graphics SDK immediately. Wait until you reach that part of the repo.

## Recommended Platform Strategy

If you are mainly on macOS:

- use Apple's command line tools now
- use OpenGL and Metal later
- use Vulkan only if you explicitly want to compare lower-level APIs

If you are mainly on Windows:

- use Visual Studio if DirectX matters to you
- use MSYS2 if you prefer a Unix-like shell workflow
- OpenGL and Vulkan are both reasonable later options

If your end goal is a C game engine:

- start with plain terminal C projects first
- then compare OpenGL and Vulkan for cross-platform graphics ideas
- evaluate DirectX and Metal as platform-specific backends, not necessarily your only abstraction

If your end goal is a C++ game engine:

- still benefit from doing the early projects in C first
- use the same project prompts to practice C++ containers and RAII later
- treat the graphics API track as renderer-backend research either way

## First Sanity Checklist

Before starting project 1, make sure you can:

- create a `.c` file
- compile it without errors
- run the resulting executable
- recompile after changing the code
- see warnings when you intentionally make a mistake

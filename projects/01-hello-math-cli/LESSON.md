# Lesson: Starting A Small C Program

## What You Are Learning

This project is a first pass at the basic shape of a C program. The goal is not just to make something that runs, but to understand how a small program is organized and how data moves through it.

For this project, the important ideas are:

- how a C project is usually laid out
- how compilation works at a high level
- what `main` does
- how to print output
- how to split work into functions
- how to accept simple user input

## Typical Small Project Structure

A very small C program can start as one file:

```c
int main(void) {
    return 0;
}
```

As projects grow, they are often split into:

- `main.c` for entry-point logic
- other `.c` files for implementation
- `.h` files for declarations shared between files

For a project this size, a single `main.c` is fine. If it starts feeling crowded, that is a signal to move math functions into another file later.

## The `main` Function

Every hosted C program starts in `main`.

```c
#include <stdio.h>

int main(void) {
    printf("Hello, world!\n");
    return 0;
}
```

Important details:

- `int` means `main` returns a status code to the operating system
- `return 0;` usually means success
- `#include <stdio.h>` is needed for `printf`

## Printing To The Console

The standard function for formatted output is `printf`.

```c
printf("Result: %d\n", 42);
printf("Pi-ish: %.2f\n", 3.14);
```

Common format specifiers:

- `%d` for `int`
- `%f` for `double`
- `%c` for `char`
- `%s` for strings

The `\n` moves to a new line.

## Functions Keep Code Manageable

Even in a tiny program, functions help separate responsibilities.

```c
int add(int a, int b) {
    return a + b;
}
```

Then call it from `main`:

```c
int result = add(2, 3);
printf("%d\n", result);
```

This is the core idea behind structuring your calculator: let `main` manage input and output, and let helper functions do the arithmetic.

## Reading Input

There are two common beginner-friendly approaches:

- command-line arguments with `argc` and `argv`
- interactive input with `scanf`

Example with command-line arguments:

```c
int main(int argc, char *argv[]) {
    printf("Argument count: %d\n", argc);
    return 0;
}
```

Example with interactive input:

```c
int a;
scanf("%d", &a);
```

Notice the `&a`. `scanf` needs the address of the variable so it can write into it.

## Basic Control Flow

A calculator needs to choose an operation based on user input. That means using `if` or `switch`.

```c
if (op == '+') {
    result = a + b;
}
```

Or:

```c
switch (op) {
    case '+':
        result = a + b;
        break;
    default:
        printf("Unknown operator\n");
        break;
}
```

## Errors Matter Early

Even simple programs should reject bad input. A classic example is division by zero.

```c
if (b == 0) {
    printf("Cannot divide by zero\n");
}
```

That habit becomes more important in every later project.

## Compilation Basics

If your file is named `main.c`, a simple compile command is:

```sh
cc main.c -o calculator
```

Then run it:

```sh
./calculator
```

## What To Focus On In This Project

- Keep `main` readable
- Put arithmetic in small helper functions
- Print clear error messages
- Get comfortable compiling, running, and changing the program repeatedly

## Try These Before Starting

1. Write a program that prints your name.
2. Write a function that multiplies two integers.
3. Use `scanf` to read two numbers and print their sum.

## C++ Notes

In C++, the same project can be structured with free functions just like C, but you would usually use `std::cout` and `std::cin` instead of `printf` and `scanf`. If you revisit this in C++, compare a plain procedural version against a small `Calculator` class only after the C version feels natural.

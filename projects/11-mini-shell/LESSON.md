# Lesson: Programs That Launch Other Programs

## What You Are Learning

This project is your first direct interaction with the operating system as a service provider. A shell reads commands, interprets them, and asks the OS to execute other programs.

Key ideas:

- reading full lines of input
- parsing command strings
- looping until exit
- launching commands
- distinguishing built-in commands from external commands

## What A Shell Does

A shell sits between the user and the OS. At a basic level it:

1. shows a prompt
2. reads a command
3. runs it
4. waits for the next command

This is a classic read-evaluate loop.

## Reading A Full Line

Unlike earlier projects that read numbers or single values, a shell usually needs an entire line of text.

That means thinking about:

- maximum line length
- trimming trailing newlines
- empty input

## The Simplest Execution Model

For an intro project, `system()` is a practical starting point. It sends a string to the host command processor.

This keeps the first version focused on shell behavior rather than process internals.

## Built-In Commands

Some commands cannot just be delegated. For example, a command like `cd` changes the shell's own working directory, so it must be implemented inside the shell process.

That introduces an important distinction:

- built-in commands handled by your code
- external commands run by the OS

## Parsing

Input parsing can be simple at first:

- split the line into a command and arguments
- ignore quoting and advanced syntax for now

The lesson here is that parsing complexity grows quickly, so a deliberately limited first version is the right choice.

## Loop Design

A shell runs until the user explicitly exits. That means:

- keep the main loop simple
- handle blank input gracefully
- avoid crashing on malformed commands

## Stretching Toward Systems Programming

If you later replace `system()` with `fork` and `exec`, you will learn much more about processes and program execution. That is a strong next step after the initial version works.

## Try These Before Starting

1. Write a loop that prints `mini-shell>` and reads one line.
2. Strip the trailing newline from the input.
3. Detect if the user typed `exit`.

## C++ Notes

In C++, input handling is usually easier with `std::getline` and `std::string`. The operating-system interaction concepts do not change, so this project is mostly about comparing C string parsing with C++ string manipulation.

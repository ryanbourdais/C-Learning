# Lesson: Control Flow, Loops, And Random Numbers

## What You Are Learning

This project teaches how a program maintains state over time. Unlike a one-shot calculator, a game keeps asking for input, compares it to hidden data, and updates the result of each turn.

Key ideas:

- loops
- conditionals
- variables that track game state
- pseudo-random numbers
- repeated user interaction

## Program State

State means the values your program is currently tracking. In this game, state might include:

- the secret number
- the player's current guess
- how many guesses have been made
- whether the game is over

Programs become easier to reason about when you can name the state clearly.

## Repetition With Loops

A guessing game keeps running until the user succeeds or quits. That usually means `while`.

```c
while (guess != secret) {
    /* ask for input */
}
```

You can also loop forever and break when the game ends:

```c
while (1) {
    if (guess == secret) {
        break;
    }
}
```

Use the version that keeps the condition easiest to read.

## Branching With `if`

Each guess needs a comparison:

```c
if (guess < secret) {
    printf("Too low\n");
} else if (guess > secret) {
    printf("Too high\n");
} else {
    printf("Correct\n");
}
```

This is one of the most common patterns in C: compare data, then branch into different behaviors.

## Random Numbers Are Pseudo-Random

In C, `rand()` generates pseudo-random numbers. That means the sequence is deterministic unless you seed it.

```c
#include <stdlib.h>
#include <time.h>

srand((unsigned int)time(NULL));
```

Then:

```c
int secret = rand() % 100 + 1;
```

This gives a number from `1` to `100`.

## Why Seeding Matters

If you do not call `srand`, many environments will produce the same sequence every run. For a game, that feels broken.

Seeding tells the random number generator to start from a different point.

## Validating Input

User input is rarely perfect. If you ask for a number, the user may enter something else. Even if you keep this project simple, you should still think about:

- what range is allowed
- what happens if the user enters invalid data
- how to recover and continue

This mindset prepares you for more complex input handling later.

## Counting Attempts

Any time something happens repeatedly, consider whether you should count it.

```c
attempts++;
```

This is a simple example of state mutation: one small update each time the loop runs.

## Breaking Work Into Functions

Even a small game benefits from helper functions. Possible responsibilities:

- create the secret number
- read one guess
- print feedback
- ask if the player wants to replay

Functions are not just for reuse. They help isolate ideas.

## Common Pitfalls

- forgetting to seed random numbers
- creating a loop that never changes state
- failing to reject guesses outside the allowed range
- printing success but forgetting to end the loop

## Try These Before Starting

1. Write a loop that prints numbers `1` through `10`.
2. Seed `rand()` and print five random numbers.
3. Read a guess and print whether it is less than, greater than, or equal to `50`.

## C++ Notes

The core logic is identical in C++, but you would typically prefer `std::mt19937` and distributions over `rand()`. This is also a good project for comparing C-style loop-and-state code with a cleaner C++ version that uses functions and `std::string` for replay prompts.

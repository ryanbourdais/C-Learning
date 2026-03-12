# Lesson: Arrays, Shuffling, And Multi-Step Turns

## What You Are Learning

This project is about managing a board whose state changes over many turns. The challenge is not advanced math. It is tracking visibility, matches, and user actions correctly.

Key ideas:

- representing a grid of cards
- generating pairs
- shuffling data
- handling turn phases
- recognizing completion conditions

## Modeling The Cards

Each card needs at least:

- an identity value
- whether it is currently revealed
- whether it has already been matched

You can represent this with a struct or with parallel arrays, though a struct is usually clearer.

## Building Pairs

The game begins by creating pairs of matching values. For example, in a 4x4 game you need 8 pairs.

That means:

- generate values in pairs
- place them into an array
- shuffle the array

## Shuffling

Shuffling is the key to replayability. A common pattern is the Fisher-Yates shuffle, which swaps each element with a random earlier position.

You do not need a complicated algorithm. You need a correct one.

## Turn Phases

Each turn has multiple steps:

1. choose the first card
2. choose the second card
3. compare them
4. either mark a match or hide them again

This is a useful design lesson: some programs are best understood as a sequence of phases rather than one loop body doing everything at once.

## Board Rendering

The display should show:

- hidden cards
- revealed cards
- matched cards

Clear rendering makes debugging much easier because the game state becomes visible.

## Input Validation

You need to reject:

- positions outside the board
- the same card chosen twice
- already matched cards

This project rewards careful checks before changing state.

## Try These Before Starting

1. Create an array containing pairs like `1 1 2 2 3 3 4 4`.
2. Shuffle the array and print the result.
3. Write logic that compares two selected positions and marks a match.

## C++ Notes

In C++, this project is a natural fit for `std::vector`, `std::shuffle`, and small structs or classes. That makes it a useful comparison for understanding how much boilerplate C requires around collections and state representation.

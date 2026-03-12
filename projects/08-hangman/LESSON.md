# Lesson: Strings, Word Lists, And Game State

## What You Are Learning

This project combines file loading, string handling, and game logic. It is a useful midpoint between simple terminal tools and more stateful interactive programs.

Key ideas:

- loading a word list
- choosing one entry at random
- tracking guessed letters
- revealing partial progress
- managing win and loss conditions

## Strings As Data

In this game, the word itself is central state. You will likely work with:

- the original hidden word
- a display version showing guessed letters and blanks
- the user's current guess

Managing multiple related strings cleanly is the main challenge.

## Loading Candidate Words

A text file is a simple source for the word list. That means:

- open the file
- read lines
- store them in memory

You may use a fixed-size array for a small project if you define reasonable limits.

## Picking A Word

Once you know how many words were loaded, you can pick a random index.

This is similar to the number guessing project, but now the random choice selects from a collection.

## Tracking Guesses

The program must remember:

- which letters have been guessed
- how many wrong guesses happened
- whether all letters have been revealed

This is another example of state evolving over a loop.

## Revealing Progress

A common beginner approach is to build a second string that starts with underscores and fills in letters when guesses are correct.

That keeps rendering simple because you always print the same display string.

## Duplicate Guesses

The user may guess the same letter twice. You should decide how the program responds:

- warn the user
- do not count it as a new mistake

Handling this well makes the game feel much more polished.

## Character Handling

This is a good project for paying attention to:

- uppercase versus lowercase
- validating that input is a single letter
- looping over each character in a word

## Try These Before Starting

1. Read ten words from a file into an array.
2. Create a masked word like `h _ n g m a n`.
3. Write a loop that reveals all matching letters after one guess.

## C++ Notes

In C++, `std::string` makes masking, comparison, and file-loaded word storage much less error-prone. This is a good project for comparing C-style character arrays against safer standard library string handling without changing the game design.

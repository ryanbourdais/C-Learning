# Lesson: Arrays, Board State, And Game Rules

## What You Are Learning

This project is the first one where the program needs to represent a structured world in memory. A tic-tac-toe board is small, but it introduces two-dimensional data, turn handling, and rule checking.

Key ideas:

- arrays
- representing a board
- validating moves
- alternating turns
- checking win conditions

## Representing A Board

The board is a grid, so a 2D array is a natural fit.

```c
char board[3][3];
```

Each element can store:

- `'X'`
- `'O'`
- a blank marker such as `' '`

This is a simple example of mapping real game state onto memory.

## Initializing Data

Before the game begins, every cell should be set to empty.

```c
for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
        board[row][col] = ' ';
    }
}
```

Initialization is easy to overlook, and uninitialized data leads to confusing bugs.

## Printing The Board

A game is only playable if the user can see the current state clearly. Rendering the board in text is just another form of output formatting.

Think about:

- row and column labels
- separators
- spacing that keeps the board readable

## Alternating Turns

You need a variable that tracks the current player.

```c
char current_player = 'X';
```

After a valid move, switch players.

```c
current_player = (current_player == 'X') ? 'O' : 'X';
```

This is a good example of state changing predictably after each action.

## Validating Moves

A legal move usually means:

- row and column are in range
- the target cell is empty

Never update the board before confirming the move is valid.

## Checking For A Win

The rules are fixed:

- three rows
- three columns
- two diagonals

This is a classic case for a helper function such as `check_winner`. The point is not to write clever code. The point is to write code that is obvious and correct.

## Detecting A Draw

If nobody has won and every square is filled, the game is a draw. That means you need to inspect the board after each move.

This is another example of deriving information from existing state rather than storing unnecessary extra variables.

## Decomposing The Program

Good candidate functions:

- initialize the board
- print the board
- validate a move
- place a move
- check for a winner
- check for a draw

This project becomes much easier if each function has a narrow role.

## Try These Before Starting

1. Create a 3x3 array and fill it with `'-'`.
2. Write a function that prints the array as a grid.
3. Write a function that returns true if all cells are full.

## C++ Notes

In C++, this board can still be a simple array, but `std::array` is often a better fixed-size choice. This project is also a good early comparison point for when a class improves clarity and when plain functions are still the better structure.

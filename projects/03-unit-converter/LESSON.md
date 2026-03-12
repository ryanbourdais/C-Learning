# Lesson: Menus, Functions, And Input Validation

## What You Are Learning

This project introduces menu-driven programs. Instead of doing one thing and exiting, the program presents options, runs one operation, then returns to the menu.

Key ideas:

- menu loops
- separating logic into functions
- validating numeric input
- organizing repeated program flow

## Menu-Driven Programs

A menu program usually follows this pattern:

1. print options
2. read the user's choice
3. run the selected action
4. repeat until the user chooses to exit

This means you will usually have a main loop around the menu.

```c
int choice = 0;

while (choice != 4) {
    /* print menu */
    /* read choice */
    /* run selected option */
}
```

## Small Functions Are A Good Fit

Each conversion should probably be its own function.

```c
double miles_to_km(double miles) {
    return miles * 1.60934;
}
```

That keeps the program modular:

- menu code chooses what to do
- conversion code performs the math

This separation becomes very important as projects get larger.

## Use Meaningful Types

Conversions often involve decimals, so `double` is usually a better fit than `int`.

```c
double celsius = 25.0;
double fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
```

Using integer types for decimal math leads to incorrect results.

## Input Validation

The user might select an invalid menu option or type a non-number. A robust program checks:

- whether input was read successfully
- whether the choice is within the expected range
- whether the input value makes sense

Even if your first pass is simple, write code with the expectation that input can be wrong.

## Control Flow Patterns

Menu code often uses `switch`:

```c
switch (choice) {
    case 1:
        /* conversion */
        break;
    case 2:
        /* conversion */
        break;
    default:
        printf("Invalid choice\n");
        break;
}
```

This is a clean fit when the user is choosing from a fixed list.

## Designing For Clarity

A useful rule is: one function, one job. For example:

- one function to print the menu
- one function to read a number
- one function per conversion

That makes it easier to test pieces mentally and later move them into separate files.

## Common Pitfalls

- mixing menu logic and conversion math in one long function
- using `int` when decimal precision is needed
- allowing invalid menu choices silently
- exiting the loop unexpectedly because input handling is messy

## Try These Before Starting

1. Write a function that converts pounds to kilograms.
2. Write a loop that keeps showing a menu until the user selects exit.
3. Use `switch` to print a different message for choices `1`, `2`, and `3`.

## C++ Notes

In C++, the same design works well with free functions, but input handling can use `std::cin` and formatted output can use `std::cout`. The main conceptual comparison here is whether C++ streams feel clearer than C's formatted I/O for menu-heavy programs.

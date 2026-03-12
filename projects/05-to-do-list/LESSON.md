# Lesson: Structs And Managing Collections Of Data

## What You Are Learning

This project moves beyond primitive variables into grouped data. A task is not just one value. It has multiple properties that belong together.

Key ideas:

- structs
- arrays of structs
- CRUD operations
- string handling
- menu-based state changes

## Why Structs Exist

Suppose a task has:

- a title
- a completion flag

Those two fields describe one thing, so a struct is a natural fit.

```c
struct Task {
    char title[100];
    int completed;
};
```

Structs are how C groups related data into one logical object.

## Arrays Of Structs

If one task is a struct, many tasks can be stored in an array.

```c
struct Task tasks[100];
int task_count = 0;
```

This pattern appears constantly in C:

- a fixed-size array for storage
- a separate variable that tracks how many entries are actually used

## CRUD Thinking

This app is a simple CRUD program:

- Create: add a task
- Read: list tasks
- Update: mark complete
- Delete: remove a task

Thinking in operations helps you design the functions you need.

## Deleting From An Array

Arrays in C do not automatically shrink and close gaps. If you remove an item from the middle, you usually shift later items left.

```c
for (int i = index; i < task_count - 1; i++) {
    tasks[i] = tasks[i + 1];
}
task_count--;
```

This is a fundamental array-management pattern.

## Strings In C

Task titles are strings, which in C means arrays of `char` ending with `'\0'`.

Be careful with:

- buffer sizes
- reading input without overflow
- trimming trailing newlines when needed

String handling is one of the areas where C demands attention.

## Program Design

A clear structure might include:

- a function to print the menu
- a function to add a task
- a function to list tasks
- a function to mark one complete
- a function to delete one task

The actual data can live in `main` or in a higher-level manager structure.

## Common Pitfalls

- forgetting to check array capacity before adding
- deleting an item without shifting the array
- mixing up task index and task count
- mishandling string input

## Try These Before Starting

1. Define a `struct Task` with a title and completion flag.
2. Store three tasks in an array and print them.
3. Remove one task by shifting later elements left.

## C++ Notes

This project changes significantly in C++ because `std::string` and `std::vector` remove much of the manual string and array management. That makes it a useful side-by-side exercise for understanding what C++ abstractions save you from handling directly.

# Lesson: Pointers, Heap Memory, And Reusable APIs

## What You Are Learning

This project is the transition from beginner C into the language's core systems model. You are no longer just using arrays. You are building a data structure that manages memory explicitly.

Key ideas:

- pointers
- heap allocation
- capacity versus length
- `malloc`, `realloc`, and `free`
- designing a small API

## Stack Versus Heap

So far, many arrays have likely been fixed-size local variables. Those usually live on the stack.

Dynamic data structures use the heap instead:

```c
int *data = malloc(10 * sizeof(int));
```

The heap lets you request memory at runtime.

## Pointer Basics

A pointer stores an address.

```c
int value = 5;
int *ptr = &value;
```

Important operations:

- `&value` gets an address
- `*ptr` accesses the value at that address

Pointers are essential for dynamic structures because the data often lives outside the function that created it.

## Length Versus Capacity

Dynamic arrays usually track two different numbers:

- length: how many elements are actually stored
- capacity: how many elements can fit before resizing

This distinction is fundamental.

## Growing The Array

When length reaches capacity, allocate a larger block and copy the existing data with `realloc`.

```c
data = realloc(data, new_capacity * sizeof(int));
```

Always think carefully about what happens if allocation fails.

## Structuring The Data Type

A dynamic array is usually represented by a struct:

```c
struct IntArray {
    int *data;
    size_t length;
    size_t capacity;
};
```

This struct becomes the handle through which all functions operate.

## API Design

Instead of writing one big demo, define a small interface:

- initialize
- append
- get
- set
- free

This project is less about one program and more about building a reusable component.

## Memory Ownership

If your code allocates memory, your code must also define who frees it and when. That is the heart of manual memory management.

Memory bugs often come from losing track of ownership.

## Common Pitfalls

- forgetting to free memory
- writing past capacity
- using a pointer after `free`
- confusing length with capacity

## Try These Before Starting

1. Allocate space for five integers with `malloc`.
2. Fill the array and print the values.
3. Free the memory and set the pointer to `NULL`.

## C++ Notes

This project is still valuable in C++ because it teaches the low-level mechanics that `std::vector` hides. If you revisit it in C++, treat it as an exercise in understanding ownership and allocation rather than as a recommendation to replace the standard library in normal application code.

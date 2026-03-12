# C Cheat Sheet For C# And Python Developers

This file is a quick reference for the C concepts that most often feel strange if you mostly write C# or Python.

It is not a full language guide. It is the set of things most likely to trip you up while working through this repo.

## Core Mindset

- C is small and explicit.
- The compiler does much less for you than C# or Python.
- Memory, lifetimes, and data layout are your responsibility.
- Many mistakes compile successfully and only fail at runtime.
- Undefined behavior is real. "It ran once" does not mean it is correct.

## What Feels Different Right Away

- There are no classes, properties, exceptions, or garbage collection in plain C.
- Strings are not a built-in safe type.
- Arrays do not know their own length.
- Function arguments are passed by value unless you pass a pointer.
- There is no bounds checking.
- Uninitialized local variables contain garbage values.

## `*` And `&`

These are two of the most important C symbols.

```c
int value = 42;
int *ptr = &value;
```

- `&value` means "address of `value`"
- `int *ptr` means "`ptr` is a pointer to int"
- `*ptr` means "the value stored at the address in `ptr`"

Example:

```c
int value = 42;
int *ptr = &value;

printf("%d\n", value);  // 42
printf("%p\n", (void *)ptr);  // address of value
printf("%d\n", *ptr);  // 42
```

Common beginner confusion:

- In a declaration, `*` is part of the type: `int *ptr;`
- In an expression, `*` dereferences: `*ptr = 10;`

## Why `scanf` Uses `&`

`scanf` needs a place to write the result.

```c
int x;
scanf("%d", &x);
```

You pass the address of `x`, not its current value.

Without `&x`, `scanf` would not know where to store the number.

## Pass By Value Versus "Modify The Caller"

C does not have C#-style `ref` or `out`.

Everything is passed by value. If you want a function to modify a caller's variable, pass a pointer.

```c
void set_to_zero(int *x) {
    *x = 0;
}

int main(void) {
    int value = 5;
    set_to_zero(&value);
}
```

## Arrays Are Bare Memory

```c
int numbers[3] = {10, 20, 30};
```

- The array does not carry its length at runtime.
- `numbers[5]` compiles even though it is out of bounds.
- Passing an array to a function usually becomes passing a pointer to its first element.

Typical function shape:

```c
int sum(const int *numbers, int count);
```

You nearly always pass the length separately.

## Strings Are Character Arrays

In C, a string is usually a `char` array ending with a null terminator `'\0'`.

```c
char name[] = "Ryan";
```

This is really:

```c
char name[] = {'R', 'y', 'a', 'n', '\0'};
```

Important consequences:

- String length is determined by scanning until `'\0'`
- You must leave room for the terminator
- Many string bugs are actually buffer-size bugs

## `char *` Versus `char[]`

These look similar but are not the same.

```c
char name[] = "Ryan";
char *label = "Ryan";
```

- `name` is a mutable array copy in local storage
- `label` points at string literal data, which should be treated as read-only

Do not write through a pointer to a string literal.

## Stack Versus Heap

Stack memory:

```c
int x = 5;
char buffer[128];
```

- usually automatic local storage
- cleaned up when the function returns

Heap memory:

```c
int *data = malloc(10 * sizeof(int));
```

- allocated at runtime
- stays alive until you call `free`

If you `malloc`, you must eventually `free`.

## `malloc`, `realloc`, And `free`

```c
int *data = malloc(10 * sizeof(int));
if (data == NULL) {
    return 1;
}

free(data);
data = NULL;
```

Rules:

- check allocation results
- never use memory after `free`
- do not `free` the same pointer twice
- `realloc` may move the memory block

## Uninitialized Variables

This is valid C:

```c
int x;
printf("%d\n", x);
```

It is also wrong.

Local variables are not automatically initialized. Always initialize them yourself.

## `==` Versus `=`

Same pitfall as C# in spirit, but easier to miss in C because many expressions are just integers.

```c
if (x = 5) {
}
```

This assigns `5` to `x`, then treats the result as true.

Use warnings:

```sh
cc -Wall -Wextra -pedantic file.c -o program
```

## Truthiness In C

C has historically used integers for truth values.

- `0` means false
- non-zero means true

Modern C also has `_Bool` and `bool` from `<stdbool.h>`:

```c
#include <stdbool.h>
bool done = false;
```

## `NULL` Is Not The Same As `0` Conceptually

You may see both compared against pointers, but use `NULL` for pointer intent:

```c
int *ptr = NULL;
```

This makes the code clearer.

## `const` Matters

`const` tells the compiler and the reader that something should not be modified.

```c
int sum(const int *numbers, int count);
```

That means the function will not modify the integers through that pointer.

This is one of the simplest ways to make C APIs safer.

## Header Files Versus Source Files

- `.h` files usually contain declarations
- `.c` files contain definitions

Example:

```c
// math_utils.h
int add(int a, int b);
```

```c
// math_utils.c
int add(int a, int b) {
    return a + b;
}
```

Think of headers as the interface and `.c` files as the implementation.

## Multiple Files Mean Compilation Plus Linking

Build errors are often one of two kinds:

- compile errors: syntax, types, missing declarations
- link errors: implementation exists nowhere in the final build

If the compiler accepts your function declaration but the linker says "undefined symbol", you probably forgot to compile or link the `.c` file containing the function definition.

## `struct` Is Your Main Data Modeling Tool

C does not have classes. Group related data with `struct`.

```c
struct Player {
    int health;
    int score;
};
```

Then:

```c
struct Player p = {100, 0};
```

If you pass a large struct often, pass a pointer instead of copying it every call.

## `->` Versus `.`

Use `.` with a struct value:

```c
player.health = 100;
```

Use `->` with a pointer to a struct:

```c
player_ptr->health = 100;
```

`a->b` is shorthand for `(*a).b`.

## Enums Are Named Integer Constants

```c
enum Direction {
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
};
```

They improve readability, but they are still integer-based underneath.

## C Does Not Protect You From Out-Of-Bounds Access

This compiles:

```c
int a[3] = {1, 2, 3};
printf("%d\n", a[10]);
```

That is undefined behavior.

This is one of the biggest differences from C# and Python.

## Input Handling Is More Fragile Than You Expect

`scanf` is usable for small exercises, but it is easy to misuse.

Common problems:

- leaving bad input in the buffer
- not checking the return value
- mixing numeric input and character input carelessly

Safer pattern:

```c
int x;
if (scanf("%d", &x) != 1) {
    printf("Invalid input\n");
}
```

## Recursion Is Usually Not A Menu Loop Replacement

If you want to repeat a prompt or replay a game, use a loop.

Do not keep calling `main()` or input functions recursively for normal control flow unless you have a very specific reason.

## `sizeof` Is Your Friend

Use `sizeof` instead of hardcoding byte counts.

```c
int *data = malloc(10 * sizeof(int));
```

Safer style:

```c
int *data = malloc(10 * sizeof(*data));
```

This avoids mistakes if the type changes later.

## Common C Gotchas For Managed-Language Developers

- forgetting to initialize locals
- forgetting to free heap memory
- using freed memory
- writing past array bounds
- assuming strings resize automatically
- assuming arrays know their length
- passing a value when you meant to pass an address
- dereferencing a null or invalid pointer
- mixing declaration knowledge with actual storage lifetime
- assuming the compiler will stop all dangerous code

## Practical Habits For This Repo

- compile with warnings every time
- keep functions small
- initialize variables immediately
- check `scanf` return values
- prefer loops over recursive menu flow
- comment pointer-heavy code if the intent is not obvious
- move repeated logic into helper functions
- when you allocate, decide immediately who frees

## Good Compile Commands

For C:

```sh
cc -Wall -Wextra -pedantic -g file.c -o program
```

For C++:

```sh
c++ -Wall -Wextra -pedantic -std=c++17 -g file.cpp -o program
```

## Suggested Time To Read This Again

Revisit this cheat sheet:

- before `04-tic-tac-toe` for pointer basics
- before `09-dynamic-array-library` for heap memory
- before `12a-cmake-c-library` for build and linking concepts

# Lesson: File I/O And Character Processing

## What You Are Learning

This project introduces files as an input source. Instead of only reacting to the keyboard, your program reads data from disk and analyzes it.

Key ideas:

- opening and closing files
- reading text one character at a time
- counting patterns in data
- handling file errors

## Opening A File

The standard library uses `FILE *` to represent an open file.

```c
FILE *file = fopen("example.txt", "r");
```

The `"r"` means read mode.

Always check whether the file opened successfully.

```c
if (file == NULL) {
    printf("Could not open file\n");
}
```

## Closing A File

When you are done, close it:

```c
fclose(file);
```

Resource cleanup matters. This habit carries directly into graphics and systems programming later.

## Character-By-Character Reading

One simple approach is `fgetc`.

```c
int ch;
while ((ch = fgetc(file)) != EOF) {
    /* process ch */
}
```

`ch` is usually an `int` rather than a `char` so it can represent `EOF`.

## Counting Lines, Words, And Characters

Each statistic depends on a rule:

- characters: count every character read
- lines: count newline characters
- words: count transitions from whitespace to non-whitespace

Word counting is more subtle than it looks. You often need a variable that remembers whether you are currently inside a word.

## Whitespace Detection

The `ctype.h` library provides helpers such as `isspace`.

```c
#include <ctype.h>

if (isspace(ch)) {
    /* whitespace */
}
```

This is often clearer than manually checking every whitespace character.

## Error Handling

A file path may be wrong, permissions may fail, or the file may not exist. This is a good project for getting comfortable with error paths.

Good programs do not crash or behave mysteriously when file access fails.

## Thinking In Passes

You can solve this project in one pass over the file. That is more efficient and also simpler than reopening the file repeatedly for each statistic.

This is a useful general lesson: if you already have the data in front of you, update all relevant counters in the same loop.

## Try These Before Starting

1. Open a text file and print each character.
2. Count only newline characters.
3. Use `isspace` to tell whether each character is whitespace.

## C++ Notes

In C++, you can solve this either with C file APIs or with `std::ifstream`. The important comparison is not syntax alone, but how stream-based I/O changes the structure of the code and how much manual error handling still remains.

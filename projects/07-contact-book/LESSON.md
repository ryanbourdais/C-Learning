# Lesson: Persistent Data And Simple Serialization

## What You Are Learning

This project extends struct-based data into persistent storage. The key change is that your program should remember information between runs.

Key ideas:

- storing records in structs
- saving data to a file
- loading data from a file
- simple search logic
- thinking about file format design

## Records In Memory

A contact is a record with multiple fields:

- name
- phone number
- email

That makes a struct the obvious representation.

```c
struct Contact {
    char name[100];
    char phone[30];
    char email[100];
};
```

## Persistence

Persistence means data survives after the program exits. In this project, that means writing your contact list to disk and rebuilding it later.

Without persistence, the program behaves like the to-do list project. With persistence, it starts feeling like a real tool.

## Choosing A File Format

You need a representation on disk. For a beginner project, keep it simple and predictable. Good file formats are:

- easy to write
- easy to read back
- easy to debug by opening the file manually

Plain text is often the best starting point.

## Writing Data

Functions like `fprintf` write formatted text to a file.

```c
fprintf(file, "%s,%s,%s\n", contact.name, contact.phone, contact.email);
```

This kind of plain-text serialization is enough for many beginner tools.

## Reading Data Back

Loading means parsing your chosen format back into structs. That requires careful string handling.

When reading from files, think about:

- one record per line
- how fields are separated
- what happens if a line is malformed

## Searching

Search can start very simply:

- loop through all contacts
- compare the query to each name

A linear scan is completely fine for a small collection.

## Program Design

Likely responsibilities:

- load contacts at startup
- save contacts before exit or after changes
- add a contact
- list contacts
- search by name

This is a good project for practicing the flow between in-memory data and external storage.

## Common Pitfalls

- choosing a file format that is hard to parse
- forgetting to load existing contacts before adding new ones
- overwriting data accidentally
- not checking file open failures

## Try These Before Starting

1. Write one contact to a text file.
2. Read a line from a file and print it.
3. Compare two strings with `strcmp`.

## C++ Notes

This project becomes much simpler in C++ with `std::string`, `std::vector`, and stream I/O. That makes it a strong example of where C demands explicit data handling while C++ lets you focus more directly on program behavior and file format design.

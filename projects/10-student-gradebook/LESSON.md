# Lesson: Nested Data And Aggregation

## What You Are Learning

This project is about managing more complex relationships in memory. A student has multiple grades, and the program must compute derived values such as averages and summaries.

Key ideas:

- nested structs
- fixed collections inside larger records
- aggregate calculations
- reporting
- persistence for more structured data

## Nested Structs

When data has layers, structs can contain other structs or arrays.

A gradebook may include:

- student identity data
- a collection of grades
- a calculated average

The program becomes easier to reason about when the shape of the data mirrors the real-world concept.

## Aggregation

An average is derived from multiple stored values. That means:

- sum the grades
- divide by the number of grades

This pattern appears all over programming: compute a result from a collection rather than storing everything separately by hand.

## Fixed-Size Limits

At this stage, it is perfectly reasonable to use fixed-size arrays with explicit limits, such as:

- up to 50 students
- up to 10 assignments per student

That lets you focus on structure before introducing dynamic allocation.

## Reporting

A gradebook is not only about storage. It also needs useful output:

- student averages
- class summaries
- highest and lowest scores

This is a good project for learning that data processing and display are different responsibilities.

## Persistence Revisited

Saving and loading more structured data requires planning. Decide early:

- what the file format looks like
- how one student record is represented
- how assignment counts are stored

A clear file format simplifies the rest of the project.

## Decomposing The Work

Good candidate functions:

- add a student
- record a grade
- compute one student's average
- print the report
- save and load the gradebook

Projects with richer data stay manageable only when decomposition is deliberate.

## Try These Before Starting

1. Define a struct for one student with a name and an array of grades.
2. Write a function that computes the average of an integer array.
3. Print a formatted table of three students and their averages.

## C++ Notes

In C++, nested records often become more expressive with `std::string` and `std::vector`. This project is a good place to compare fixed-size C-style limits against a more flexible C++ design while keeping the same reporting and aggregation logic.

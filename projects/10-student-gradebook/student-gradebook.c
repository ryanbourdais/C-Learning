#include <stdio.h>

#include "assignment.h"
#include "gradebook.h"
#include "student.h"

int main(void) {
    struct gradebook gradebook;
    struct student alice;
    struct student bob;
    struct assignment algebra;
    struct assignment history;
    struct assignment biology;
    struct assignment literature;
    const struct student *stored_student;
    const struct assignment *stored_assignment;
    double class_average;

    gradebook_init(&gradebook);

    student_init(&alice, "Alice");
    assignment_init(&algebra, "Algebra", 92);
    assignment_init(&history, "History", 88);
    student_set_assignment(&alice, 0, &algebra);
    student_set_assignment(&alice, 1, &history);
    student_set_average_grade(
        &alice,
        (assignment_get_score(&algebra) + assignment_get_score(&history)) / 2.0
    );

    student_init(&bob, "Bob");
    assignment_init(&biology, "Biology", 85);
    assignment_init(&literature, "Literature", 91);
    student_set_assignment(&bob, 0, &biology);
    student_set_assignment(&bob, 1, &literature);
    student_set_average_grade(
        &bob,
        (assignment_get_score(&biology) + assignment_get_score(&literature)) / 2.0
    );

    gradebook_set_student(&gradebook, 0, &alice);
    gradebook_set_student(&gradebook, 1, &bob);

    class_average = (student_get_average_grade(&alice) + student_get_average_grade(&bob)) / 2.0;
    gradebook_set_average_class_grade(&gradebook, class_average);

    stored_student = gradebook_get_student_const(&gradebook, 0);
    if (stored_student != 0) {
        printf("Student: %s\n", student_get_name(stored_student));
        stored_assignment = student_get_assignment_const(stored_student, 0);
        if (stored_assignment != 0) {
            printf(
                "  Assignment 1: %s (%d)\n",
                assignment_get_name(stored_assignment),
                assignment_get_score(stored_assignment)
            );
        }
        stored_assignment = student_get_assignment_const(stored_student, 1);
        if (stored_assignment != 0) {
            printf(
                "  Assignment 2: %s (%d)\n",
                assignment_get_name(stored_assignment),
                assignment_get_score(stored_assignment)
            );
        }
        printf("  Average: %.2f\n", student_get_average_grade(stored_student));
    }

    stored_student = gradebook_get_student_const(&gradebook, 1);
    if (stored_student != 0) {
        printf("Student: %s\n", student_get_name(stored_student));
        stored_assignment = student_get_assignment_const(stored_student, 0);
        if (stored_assignment != 0) {
            printf(
                "  Assignment 1: %s (%d)\n",
                assignment_get_name(stored_assignment),
                assignment_get_score(stored_assignment)
            );
        }
        stored_assignment = student_get_assignment_const(stored_student, 1);
        if (stored_assignment != 0) {
            printf(
                "  Assignment 2: %s (%d)\n",
                assignment_get_name(stored_assignment),
                assignment_get_score(stored_assignment)
            );
        }
        printf("  Average: %.2f\n", student_get_average_grade(stored_student));
    }

    printf("Class Average: %.2f\n", gradebook_get_average_class_grade(&gradebook));

    return 0;
}

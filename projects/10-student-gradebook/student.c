#include "student.h"

#include <string.h>

void student_set_name(struct student *student, const char *name) {
    if (name == 0) {
        student->name[0] = '\0';
        return;
    }

    strncpy(student->name, name, sizeof(student->name) - 1);
    student->name[sizeof(student->name) - 1] = '\0';
}

void student_init(struct student *student, const char *name) {
    size_t i;

    student_set_name(student, name);
    student->average_grade = 0.0;

    for (i = 0; i < 10; i++) {
        assignment_init(&student->assignments[i], "", 0);
    }
}

const char *student_get_name(const struct student *student) {
    return student->name;
}

void student_set_average_grade(struct student *student, double average_grade) {
    student->average_grade = average_grade;
}

double student_get_average_grade(const struct student *student) {
    return student->average_grade;
}

void student_set_assignment(struct student *student, size_t index, const struct assignment *assignment) {
    if (index >= 10 || assignment == 0) {
        return;
    }

    student->assignments[index] = *assignment;
}

struct assignment *student_get_assignment(struct student *student, size_t index) {
    if (index >= 10) {
        return 0;
    }

    return &student->assignments[index];
}

const struct assignment *student_get_assignment_const(const struct student *student, size_t index) {
    if (index >= 10) {
        return 0;
    }

    return &student->assignments[index];
}

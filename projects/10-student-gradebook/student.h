#ifndef STUDENT_H
#define STUDENT_H

#include <stddef.h>

#include "assignment.h"

struct student {
    char name[50];
    struct assignment assignments[10];
    double average_grade;
};

void student_init(struct student *student, const char *name);
void student_set_name(struct student *student, const char *name);
const char *student_get_name(const struct student *student);
void student_set_average_grade(struct student *student, double average_grade);
double student_get_average_grade(const struct student *student);
void student_set_assignment(struct student *student, size_t index, const struct assignment *assignment);
struct assignment *student_get_assignment(struct student *student, size_t index);
const struct assignment *student_get_assignment_const(const struct student *student, size_t index);

#endif

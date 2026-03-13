#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <stddef.h>

#include "student.h"

struct gradebook {
    struct student students[100];
    double average_class_grade;
};

void gradebook_init(struct gradebook *gradebook);
void gradebook_set_average_class_grade(struct gradebook *gradebook, double average_class_grade);
double gradebook_get_average_class_grade(const struct gradebook *gradebook);
void gradebook_set_student(struct gradebook *gradebook, size_t index, const struct student *student);
struct student *gradebook_get_student(struct gradebook *gradebook, size_t index);
const struct student *gradebook_get_student_const(const struct gradebook *gradebook, size_t index);

#endif

#include "gradebook.h"

void gradebook_init(struct gradebook *gradebook) {
    size_t i;

    gradebook->average_class_grade = 0.0;

    for (i = 0; i < 100; i++) {
        student_init(&gradebook->students[i], "");
    }
}

void gradebook_set_average_class_grade(struct gradebook *gradebook, double average_class_grade) {
    gradebook->average_class_grade = average_class_grade;
}

double gradebook_get_average_class_grade(const struct gradebook *gradebook) {
    return gradebook->average_class_grade;
}

void gradebook_set_student(struct gradebook *gradebook, size_t index, const struct student *student) {
    if (index >= 100 || student == 0) {
        return;
    }

    gradebook->students[index] = *student;
}

struct student *gradebook_get_student(struct gradebook *gradebook, size_t index) {
    if (index >= 100) {
        return 0;
    }

    return &gradebook->students[index];
}

const struct student *gradebook_get_student_const(const struct gradebook *gradebook, size_t index) {
    if (index >= 100) {
        return 0;
    }

    return &gradebook->students[index];
}

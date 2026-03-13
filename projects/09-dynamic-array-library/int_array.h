#ifndef INT_ARRAY_H
#define INT_ARRAY_H

#include <stddef.h>

struct IntArray {
    int *data;
    size_t length;
    size_t capacity;
};

void int_array_append(struct IntArray *arr, int value);
void int_array_pop(struct IntArray *arr);
void int_array_initialize(struct IntArray *arr);
int int_get_by_index(struct IntArray arr, size_t index, int *out_value);
void int_set_by_index(struct IntArray *arr, size_t index, int value);
void free_int_array(struct IntArray *arr);
void read_int_array(struct IntArray arr);

#endif

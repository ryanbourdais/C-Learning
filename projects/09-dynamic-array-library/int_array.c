#include <stdio.h>
#include <stdlib.h>
#include "int_array.h"

void int_array_append(struct IntArray *arr, int value) {
    if(arr->length == arr->capacity) {
        arr->capacity *= 2;
        arr->data = realloc(arr->data, arr->capacity * sizeof(int));
        if(arr->data == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
    }
    if(arr->capacity == 0) {
        arr->capacity = 4; // Initial capacity
        arr->data = malloc(arr->capacity * sizeof(int));
        if(arr->data == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
    }
    arr->data[arr->length] = value;
    arr->length++;
}

void int_array_pop(struct IntArray *arr) {
    if(arr->length > 0) {
        arr->length--;
    }
}

void int_array_initialize(struct IntArray *arr) {
    arr->data = malloc(4 * sizeof(int)); // Initial capacity of 4
    if(arr->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    arr->length = 0;
    arr->capacity = 4;
}

int int_get_by_index(struct IntArray arr, size_t index, int *out_value) {
    if(index < arr.length) {
        *out_value = arr.data[index];
        return 0; // Success
    } else {
        return -1; // Error
    }
}

void int_set_by_index(struct IntArray *arr, size_t index, int value) {
    if (index >= arr->length) {
        fprintf(stderr, "Index out of bounds\n");
        return;
    }
    arr->data[index] = value;
    return;
}

void free_int_array(struct IntArray *arr) {
    free(arr->data);
    arr->data = NULL;
    arr->length = 0;
    arr->capacity = 0;
}

void read_int_array(struct IntArray arr) {
    printf("Current Array Length: %zu, Capacity: %zu\n", arr.length, arr.capacity);
    for(size_t i = 0; i < arr.length; i++) {
        printf("%d\n", arr.data[i]);
    }
}

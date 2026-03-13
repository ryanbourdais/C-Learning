
#include "int_array.h"
#include <stdio.h>



int main(void) {
    struct IntArray arr;
    int_array_initialize(&arr);
    int_array_append(&arr, 10);

    read_int_array(arr);

    free_int_array(&arr);

    read_int_array(arr);
    struct IntArray newArr;
    int_array_initialize(&newArr); 
    int_array_append(&newArr, 10);
    int_array_append(&newArr, 20);
    int_array_append(&newArr, 30);
    int_array_append(&newArr, 40);
    int_array_append(&newArr, 50);
    int_array_append(&newArr, 60);
    int_array_append(&newArr, 70);
    int_array_append(&newArr, 80);
    int_array_append(&newArr, 90);
    int_array_append(&newArr, 100);

    read_int_array(newArr);

    int_array_pop(&newArr);
    int_array_pop(&newArr);

    read_int_array(newArr);
    int value1, value2;
    if(int_get_by_index(newArr, 3, &value1) == 0) {
        fprintf(stdout, "Retrieved int1: %d\n", value1);
    } else {
        fprintf(stdout, "Failed to retrieve int1\n");
    }
    if(int_get_by_index(newArr, 10, &value2) == 0) {
        fprintf(stdout, "Retrieved int2: %d\n", value2);
    } else {
        fprintf(stdout, "Failed to retrieve int2\n");
    }

    int_set_by_index(&newArr, 2, 999);
    int_set_by_index(&newArr, 10, 999);

    read_int_array(newArr);
    return 1;
}

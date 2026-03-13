#include "stats.h"

#include <stdio.h>

int sum_array(const int *values, size_t count) {
    size_t i;
    int sum;

    sum = 0;
    for (i = 0; i < count; i++) {
        sum += values[i];
    }

    return sum;
}

int max_array(const int *values, size_t count) {
    size_t i;
    int max_value;

    if (count == 0) {
        return 0;
    }

    max_value = values[0];
    for (i = 1; i < count; i++) {
        if (values[i] > max_value) {
            max_value = values[i];
        }
    }

    return max_value;
}

double average_array(const int *values, size_t count) {
    if (count == 0) {
        return 0.0;
    }

    return (double)sum_array(values, count) / (double)count;
}

void print_stats_report(const int *values, size_t count) {
    size_t i;

    printf("Values:");
    for (i = 0; i < count; i++) {
        printf(" %d", values[i]);
    }
    printf("\n");

    printf("Count: %zu\n", count);
    printf("Sum: %d\n", sum_array(values, count));
    printf("Max: %d\n", max_array(values, count));
    printf("Average: %.2f\n", average_array(values, count));
}

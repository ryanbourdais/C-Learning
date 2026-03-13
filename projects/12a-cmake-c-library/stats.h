#ifndef STATS_H
#define STATS_H

#include <stddef.h>

int sum_array(const int *values, size_t count);
int max_array(const int *values, size_t count);
double average_array(const int *values, size_t count);
void print_stats_report(const int *values, size_t count);

#endif

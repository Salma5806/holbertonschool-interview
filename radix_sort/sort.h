#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>

/* Provided helper function */
void print_array(const int *array, size_t size);

/* Prototype for radix sort */
void radix_sort(int *array, size_t size);

#endif /* SORT_H */
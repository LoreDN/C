/* library definition */
#ifndef MYARRAY_FLOAT_H
#define MYARRAT_FLOAT_H

/* library type definition */
#define TYPE float


/* including external libraries */
#include <stddef.h>


/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*
*  This header file is part of the myArray library, it is designed as the file to include in order to use the libary with type float.
*
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */





/* -------------------------------------------------------------------------------- 1. SCAN AN ARRAY -------------------------------------------------------------------------------- */

void array_scan_float(TYPE *array, size_t const size);
TYPE *array_scan_file_float(size_t *DIM, char const *path);

/* -------------------------------------------------------------------------------- 2. PRINT AN ARRAY ------------------------------------------------------------------------------- */

void array_print_float(TYPE *array, size_t const size, int const flag_user_interface);
void array_print_file_float(TYPE *array, size_t const size, char const *path, int const flag_user_interface);

/* -------------------------------------------------------------------------------- 3. SORT AN ARRAY -------------------------------------------------------------------------------- */

extern void array_swap_float(TYPE *a, TYPE *b);
size_t array_partition_float(TYPE *array, size_t const start, size_t const end);
void array_heapify_float(TYPE *array, size_t const start, size_t const size, size_t const root);
void array_merge_float(TYPE *array, size_t const start, size_t const middle , size_t const end);

void array_insertion_sort_float(TYPE *array, size_t const start, size_t const end);
void array_selection_sort_float(TYPE *array, size_t const start, size_t const end);
void array_bubble_sort_float(TYPE *array, size_t const start, size_t const end);
void array_quick_sort_float(TYPE *array, size_t const start, size_t const end);
void array_heap_sort_float(TYPE *array, size_t const start, size_t const end);
void array_merge_sort_float(TYPE *array, size_t const start, size_t const end);
void array_block_sort_float(TYPE *array, size_t const start, size_t const end);
void array_counting_sort_float(TYPE *array, size_t const start, size_t const end, int const flag_stable);

extern int array_is_sorted_float(TYPE *array, size_t const start, size_t const end);

extern void array_reverse_float(TYPE *array, size_t const start, size_t const end);

/* -------------------------------------------------------------------------- 4. STATISTICS ON THE ELEMENTS ------------------------------------------------------------------------- */

TYPE array_max_float(TYPE *array, size_t const start, size_t const end);
TYPE array_min_float(TYPE *array, size_t const start, size_t const end);
TYPE array_sum_float(TYPE *array, size_t const start, size_t const end);
float array_average_float(TYPE *array, size_t const start, size_t const end);
int *array_histogram_float(TYPE *array, size_t const start, size_t const end, size_t const min, size_t const max);


/* end of library */
#undef TYPE

#endif // MYARRAY_FLOAT_H
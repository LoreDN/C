/* library definition */
#ifndef MYARRAY_INT_H
#define MYARRAT_INT_H

/* library type definition */
#define TYPE int


/* including external libraries */
#include <stddef.h>


/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*
*  This header file is part of the myArray library, it is designed as the file to include in order to use the libary with type int.
*
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */





/* -------------------------------------------------------------------------------- 1. SCAN AN ARRAY -------------------------------------------------------------------------------- */

void array_scan_int(TYPE *array, size_t const size);
TYPE *array_scan_file_int(size_t *DIM, char const *path);

/* -------------------------------------------------------------------------------- 2. PRINT AN ARRAY ------------------------------------------------------------------------------- */

void array_print_int(TYPE *array, size_t const size, int const flag_user_interface);
void array_print_file_int(TYPE *array, size_t const size, char const *path, int const flag_user_interface);

/* -------------------------------------------------------------------------------- 3. SORT AN ARRAY -------------------------------------------------------------------------------- */

extern void array_swap_int(TYPE *a, TYPE *b);
size_t array_partition_int(TYPE *array, size_t const start, size_t const end);
void array_heapify_int(TYPE *array, size_t const start, size_t const size, size_t const root);
void array_merge_int(TYPE *array, size_t const start, size_t const middle , size_t const end);

void array_insertion_sort_int(TYPE *array, size_t const start, size_t const end);
void array_selection_sort_int(TYPE *array, size_t const start, size_t const end);
void array_bubble_sort_int(TYPE *array, size_t const start, size_t const end);
void array_quick_sort_int(TYPE *array, size_t const start, size_t const end);
void array_heap_sort_int(TYPE *array, size_t const start, size_t const end);
void array_merge_sort_int(TYPE *array, size_t const start, size_t const end);
void array_block_sort_int(TYPE *array, size_t const start, size_t const end);

extern int array_is_sorted_int(TYPE *array, size_t const start, size_t const end);

extern void array_reverse_int(TYPE *array, size_t const start, size_t const end);

/* -------------------------------------------------------------------------- 4. STATISTICS ON THE ELEMENTS ------------------------------------------------------------------------- */

TYPE array_max_int(TYPE *array, size_t const start, size_t const end);
TYPE array_min_int(TYPE *array, size_t const start, size_t const end);
TYPE array_sum_int(TYPE *array, size_t const start, size_t const end);
float array_average_int(TYPE *array, size_t const start, size_t const end);


/* end of library */
#undef TYPE

#endif // MYARRAY_INT_H
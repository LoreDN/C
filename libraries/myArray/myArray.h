/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*
*  This library contains some useful functions to work with arrays; it is designed to be used with all numeric types ( int, float, ecc... ).
*  In order to use a specific type, it is necessary to add the right 'myArray_type.c' files when compiling.
*  For max optimization, some functions have been implemented directly in assembly ( the functions with the 'extern' prefix ).
*  Since the library cointains external files, is raccomended to use the 'Makefile' given with the library.
*
*  The functions included in this library are divided in three groups:
*     1. SCAN AN ARRAY: used to scan an array from user input or from a file.
*     2. PRINT AN ARRAY: used to print an array to the user or to a file.
*     3. SORT AN ARRAY: used to sort an array using different sorting algorithms.
*     4. STATISTICS ON THE ELEMENTS: used to calculate some statistics on the elements of an array (such as max/min values).
*
*
*  |-----** IMPORTANT!!! **-----|
*  Since this library is designed to be used with different types of arrays, there are two ways of using it:
*     - Single Usage: use the library a single time (use with a single type of array).
*     - Multiple Usage: use the library multiple times (use with different types of arrays).
*  In order to use a type, all you have to do is only to include the corrispective 'myArray_type.h' file in the project.
*
*  Example of Single Usage:
*     #include "myArray_int.h"
*     array_scan_int(array, size);
*
*  Example of Multiple Usage:
*     #include "myArray_int.h"
*     #include "myArray_float.h"
*     array_scan_int(array, size);
*     array_scan_float(array, size);
*
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */





/* -------------------------------------------------------------------------------- 1. SCAN AN ARRAY -------------------------------------------------------------------------------- */

void array_scan(TYPE *array, size_t const size);
TYPE *array_scan_file(size_t *DIM, char const *path);

/* -------------------------------------------------------------------------------- 2. PRINT AN ARRAY ------------------------------------------------------------------------------- */

void array_print(TYPE *array, size_t const size, int const flag_user_interface);
void array_print_file(TYPE *array, size_t const size, char const *path, int const flag_user_interface);

/* -------------------------------------------------------------------------------- 3. SORT AN ARRAY -------------------------------------------------------------------------------- */

extern void array_swap(TYPE *a, TYPE *b);
size_t array_partition(TYPE *array, size_t const start, size_t const end);
void array_heapify(TYPE *array, size_t const start, size_t const size, size_t const root);
void array_merge(TYPE *array, size_t const start, size_t const middle , size_t const end);

void array_insertion_sort(TYPE *array, size_t const start, size_t const end);
void array_selection_sort(TYPE *array, size_t const start, size_t const end);
void array_bubble_sort(TYPE *array, size_t const start, size_t const end);
void array_quick_sort(TYPE *array, size_t const start, size_t const end);
void array_heap_sort(TYPE *array, size_t const start, size_t const end);
void array_merge_sort(TYPE *array, size_t const start, size_t const end);
void array_block_sort(TYPE *array, size_t const start, size_t const end);

extern int array_is_sorted(TYPE *array, size_t const start, size_t const end);

extern void array_reverse(TYPE *array, size_t const start, size_t const end);

/* -------------------------------------------------------------------------- 4. STATISTICS ON THE ELEMENTS ------------------------------------------------------------------------- */

TYPE array_max(TYPE *array, size_t const start, size_t const end);
TYPE array_min(TYPE *array, size_t const start, size_t const end);
TYPE array_sum(TYPE *array, size_t const start, size_t const end);
float array_average(TYPE *array, size_t const start, size_t const end);
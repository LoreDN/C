/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*
*  This library contains some useful functions to work with arrays, and it is designed to be used with all numeric types (int, float, ecc...).
*  In order to use a specific type, it is necessary to add the right 'myArray<type>.c' files when compiling.
*
*  The functions included in this library are divided in four groups:
*     1. SCAN AN ARRAY: used to scan an array from user input or from a file.
*     2. PRINT AN ARRAY: used to print an array to the user or to a file.
*     3. SORT AN ARRAY: used to sort an array using different sorting algorithms.
*
*
*  |-----** IMPORTANT!!! **-----|
*  Since this library is designed to be used with different types of arrays, there are two ways of using it:
*     - Single Usage: use the library a single time (use with a single type of array).
*     - Multiple Usage: use the library multiple times (use with different types of arrays).
*  In each case, it is not needed to include directly the library (doing this can be very awful in case of simple usage, even worse in case of multiple usage).
*  In order to use correctly the library, you only need to write the prototypes of the functions you want to use (this makes the inclusion less difficult in case of multiple usage).
*
*  Example of Single Usage:
*     void array_scan_int(int *array, size_t const size);
*     array_scan_int(array, size);
*
*  Example of Multiple Usage:
*     void array_scan_int(int *array, size_t const size);
*     void array_scan_float(float *array, size_t const size);
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

void array_swap(TYPE *a, TYPE *b);
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

int array_is_sorted(TYPE *array, size_t const start, size_t const end);

void array_reverse(TYPE *array, size_t const start, size_t const end);
/* including external libraries */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* library type definition */
#define TYPE float
#define TYPE_SPECIFIER "%f"

/* multiple usage definition */
#define array_scan array_scan_float
#define array_scan_file array_scan_file_float
#define array_print array_print_float
#define array_print_file array_print_file_float
#define array_swap array_swap_float
#define array_partition array_partition_float
#define array_heapify array_heapify_float
#define array_merge array_merge_float
#define array_insertion_sort array_insertion_sort_float
#define array_selection_sort array_selection_sort_float
#define array_bubble_sort array_bubble_sort_float
#define array_quick_sort array_quick_sort_float
#define array_heap_sort array_heap_sort_float
#define array_merge_sort array_merge_sort_float
#define array_block_sort array_block_sort_float
#define array_is_sorted array_is_sorted_float
#define array_reverse array_reverse_float

/* library definition */
#include "myArray.h"


/* -------------------------------------------------------------------------------- 1. SCAN AN ARRAY -------------------------------------------------------------------------------- */

/* scan an array from user input */
void array_scan(TYPE *array, size_t const size) {

    /* scan the array */
    for (size_t i = 0; i < size; i++) {

        printf("Element %zu: ", i+1);
        scanf(TYPE_SPECIFIER, &array[i]);

    }

    /* exit */
    return;

}


/* scan an array from a file */
TYPE *array_scan_file(size_t *DIM, char const *path) {

    /* open the file */
    FILE *file = fopen(path, "r");
    if (file == NULL) {

        printf("\n\nError: could not open file %s!!!\n\n", path);
        
        /* exit */
        exit(-1);

    }

    /* get the size */
    size_t size;
    fscanf(file, "%zu", &size);
    *DIM = size;

    /* allocate the array */
    TYPE *array = (TYPE *) malloc(size * sizeof(TYPE));

    /* scan the array */
    for (size_t i = 0; i < size; i++) {

        fscanf(file, TYPE_SPECIFIER, &array[i]);

    }

    /* close the file */
    fclose(file);

    /* exit */
    return array;

}


/* -------------------------------------------------------------------------------- 2. PRINT AN ARRAY -------------------------------------------------------------------------------- */

/* print an array to the user */
void array_print(TYPE *array, size_t const size, int const flag_user_interface) {

    /* print the array */
    for (size_t i = 0; i < size; i++) {

        /* if flag is set to 1, print the user interface */
        if (flag_user_interface == 1) {

            printf("\nElement %zu: ", i+1);
            printf(TYPE_SPECIFIER, array[i]);

        } else {

            printf(TYPE_SPECIFIER, array[i]);
            printf("\t");

        }

    }
    printf("\n");

    /* exit */
    return;

}


/* print an array to a file */
void array_print_file(TYPE *array, size_t const size, char const *path, int const flag_user_interface) {

    /* open the file */
    FILE *file = fopen(path, "w");
    if (file == NULL) {

        printf("\n\nError: could not open file %s!!!\n\n", path);
        
        /* exit */
        exit(-1);

    }

    /* if flag is set to 1, print the user interface */
    if (flag_user_interface == 1){

        /* print the array */
        fprintf(file, "Size of the Array: %zu", size);
        for (size_t i = 0; i < size; i++) {

            fprintf(file, "\nElement %zu: ", i+1);
            fprintf(file, TYPE_SPECIFIER, array[i]);
        }
    
    } else {

        /* print the array */
        fprintf(file, "%zu", size);
        for (size_t i = 0; i < size; i++) {
    
            fprintf(file, "\n");
            fprintf(file, TYPE_SPECIFIER, array[i]);

        }

    }
    printf("\nArray printed successfully to file %s\n!!!", path);

    /* close the file */
    fclose(file);

    /* exit */
    return;

}


/* -------------------------------------------------------------------------------- 3. SORT AN ARRAY -------------------------------------------------------------------------------- */

/* swap two elements of the array */
extern void array_swap(TYPE *a, TYPE *b);


/* partition an array from a pivot */
size_t array_partition(TYPE *array, size_t const start, size_t const end) {

    /* pivot initialization */
    TYPE pivot_value = array[end];

    /* partition the array */
    size_t i = start;
    for (size_t j = start; j < end; j++) {

        if (array[j] <= pivot_value) {

            array_swap(&array[i], &array[j]);
            i++;

        }

    }
    array_swap(&array[i], &array[end]);

    /* exit */
    return i;

}


/* heapify an array */
void array_heapify(TYPE *array, size_t const start, size_t const size, size_t const root) {

    /* get the children of the root */
    size_t left = (root << 1) + 1;
    size_t right = (root << 1) + 2;
    size_t largest = root;

    /* find the largest element */
    if (left < size && array[start + left] > array[start + largest]) {

        largest = left;

    }
    if (right < size && array[start + right] > array[start + largest]) {

        largest = right;

    }

    /* swap the root with the largest element */
    if (largest != root) {

        array_swap(&array[start + root], &array[start + largest]);

        /* heapify the largest element */
        array_heapify(array, start, size, largest);

    }

    /* exit */
    return;

}


/* merge two parts of an array */
void array_merge(TYPE *array, size_t const start, size_t const middle , size_t const end) {

    /* check the indexes */
    if (start > middle || middle > end) {

        /* exit */
        return;

    }

    /* allocate the merged array */
    size_t size = end - start + 1;
    TYPE *temp = (TYPE *) malloc(size * sizeof(TYPE));

    /* merge the left and right arrays */
    size_t i = start, j = middle + 1, k = 0;
    while (i <= middle && j <= end) {

        /* sort */
        if (array[i] <= array[j]) {

            temp[k++] = array[i++];

        } else {

            temp[k++] = array[j++];

        }

    }

    /* copy the remaining elements from left */
    while (i <= middle) {

        temp[k++] = array[i++];

    }
    /* copy the remaining elements from right */
    while (j <= end) {

        temp[k++] = array[j++];

    }

    /* copy the merged array to the original array */
    for (size_t c = start; c <= end; c++) {

        array[c] = temp[c - start];

    }

    /* free the memory */
    free(temp);

    /* exit */
    return;

}


/* Insertion Sort */
void array_insertion_sort(TYPE *array, size_t const start, size_t const end) {

    /* sort */
    for (size_t i = start + 1; i <= end; i++) {

        /* get the current element */
        TYPE current = array[i];

        /* find the position to insert the current element */
        size_t j = i - 1;
        while (j >= start && array[j] > current) {

            array[j + 1] = array[j];
            j--;

        }
        /* insert the current element */
        array[j + 1] = current;

    }

    /* exit */
    return;

}


/* Selection Sort */
void array_selection_sort(TYPE *array, size_t const start, size_t const end) {

    /* sort */
    for (size_t i = start; i < end; i++) {

        /* find the minimum element */
        size_t min_index = i;
        for (size_t j = i + 1; j <= end; j++) {

            if (array[j] < array[min_index]) {

                min_index = j;

            }

        }
        /* swap the minimum element with the current element */
        array_swap(&array[i], &array[min_index]);

    }

    /* exit */
    return;

}


/* Bubble Sort */
void array_bubble_sort(TYPE *array, size_t const start, size_t const end) {

    /* sort */
    for (size_t i = 0; i < end - start; i++) {

        /* insert the maximum element at the end */
        for (size_t j = start; j < end - i; j++) {

            if (array[j] > array[j+1]) {

                /* swap the element with a bigger one */
                array_swap(&array[j],&array[j+1]);

            }

        }

    }

    /* exit */
    return;

}


/* Quick Sort */
void array_quick_sort(TYPE *array, size_t const start, size_t const end) {

    /* empty array || one element array */
    if (start >= end) {

        /* exit */
        return;

    }

    /* partition the array */
    size_t pivot = array_partition(array, start, end);

    /* sort the left and right partitions */
    array_quick_sort(array, start, pivot - 1);
    array_quick_sort(array, pivot + 1, end);

    /* exit */
    return;

}


/* Heap Sort */
void array_heap_sort(TYPE *array, size_t const start, size_t const end) {

    /* get the indexes */
    size_t size = end - start + 1;
    size_t middle = (size >> 1) - 1;

    /* check the indexes */
    if (start > end || size  == 0) {

        /* exit */
        return;

    }

    /* build the heap */
    for (size_t i = middle + 1; i > 0; i--) {

        /* heapify */
        array_heapify(array, start, size, i - 1);

    }

    /* sort */
    for (size_t i = size - 1; i > 0; i--) {

        /* swap the root with the last element */
        array_swap(&array[start], &array[start + i]);

        /* heapify the root */
        array_heapify(array, start, i, 0);

    }

    /* exit */
    return;

}


/* Merge Sort */
void array_merge_sort(TYPE *array, size_t const start, size_t const end) {

    /* empty array || one element array */
    if (start >= end) {

        /* exit */
        return;

    }

    /* get the middle of the array */
    size_t middle = (start + end) >> 1;

    /* sort the left and right arrays */
    array_merge_sort(array, start, middle);
    array_merge_sort(array,  middle + 1, end);

    /* merge the left and right arrays */
    array_merge(array, start, middle, end);

    /* exit */
    return;
    
}


/* Block Sort */
void array_block_sort(TYPE *array, size_t const start, size_t const end) {

    /*  get the size of a block */
    size_t size = end - start + 1;
    size_t block_size = (size_t) sqrt(size);
    if (block_size == 0) {

        /* exit */
        return;

    }

    /* sort the blocks */
    for (size_t i = start; i <= end; i += block_size) {

        size_t block_end = i + block_size - 1;
        if (block_end > end) {
            
            block_end = end;
        
        }

        array_insertion_sort(array, i, block_end);
    }

    /* merge the blocks */
    for (size_t step = block_size; step < size; step <<= 1) {

        /* merge blocks of size step */
        for (size_t i = start; i + step <= end; i += (step << 1)) {

            size_t middle = i + step - 1;
            size_t right_end = i + (step << 1) - 1;
            if (right_end > end) {
                
                right_end = end;
            
            }
            
            array_merge(array, i, middle, right_end);

        }

    }

    /* exit */
    return;
    
}


/* check if the array is sorted */
extern int array_is_sorted(TYPE *array, size_t const start, size_t end);


/* reverse an array */
extern void array_reverse(TYPE *array, size_t const start, size_t const end);


/* library end definition */
#undef array_scan
#undef array_scan_file
#undef array_print
#undef array_print_file
#undef array_swap
#undef array_partition
#undef array_heapify
#undef array_merge
#undef array_insertion_sort
#undef array_selection_sort
#undef array_bubble_sort
#undef array_quick_sort
#undef array_heap_sort
#undef array_merge_sort
#undef array_block_sort
#undef array_is_sorted
#undef array_reverse


#undef TYPE
#undef TYPE_SPECIFIER
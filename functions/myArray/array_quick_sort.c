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
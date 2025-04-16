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
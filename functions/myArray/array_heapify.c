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
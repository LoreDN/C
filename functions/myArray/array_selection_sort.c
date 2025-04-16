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
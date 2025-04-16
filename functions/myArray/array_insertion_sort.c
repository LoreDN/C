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
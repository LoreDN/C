/* reverse an array */
void array_reverse(TYPE *array, size_t const start, size_t const end) {

    /* reverse */
    size_t middle = (start + end) >> 1;
    for (size_t i = start; i <= middle; i++) {

        /* swap the elements */
        array_swap(&array[i], &array[end - i + start]);

    }

    /* exit */
    return;

}
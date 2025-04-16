/* check if the array is sorted */
int array_is_sorted(TYPE *array, size_t const start, size_t end) {

    /* check the indexes */
    if (start > end) {

        /* exit */
        return 0;

    }

    /* check if the array is sorted */
    for (size_t i = start; i < end; i++) {

        if (array[i] > array[i + 1]) {

            return 0;

        }

    }

    /* exit */
    return 1;

}
/* get the maximum value of an array */
TYPE array_max(TYPE *array, size_t const start, size_t const end) {

    /* check the indexes */
    if (start > end) {

        /* exit */
        return 0;

    }

    /* check if array is sorted */
    if (array_is_sorted(array, start, end) == 1) {

        /* exit */
        return array[end];

    }

    /* get the maximum value */
    TYPE max = array[start];
    for (size_t i = start + 1; i <= end; i++) {

        /* check the elements */
        if (array[i] > max) {

            max = array[i];

        }

    }

    /* exit */
    return max;

}
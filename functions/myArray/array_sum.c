/* get the sum of the elements of an array */
TYPE array_sum(TYPE *array, size_t const start, size_t const end) {

    /* check the indexes */
    if (start > end) {

        /* exit */
        return 0;

    }

    /* get the sum of the elements */
    TYPE sum = 0;
    for (size_t i = start; i <= end; i++) {

        sum += array[i];

    }

    /* exit */
    return sum;

}
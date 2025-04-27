/* build the hiostogram of the array */
int *array_histogram(TYPE *array, size_t const start, size_t const end, size_t const min, size_t const max) {

    /* allocate the histogram */
    size_t size = max - min + 1;
    int *histogram = calloc(size, sizeof(int));

    /* build the histogram */
    for (size_t i = start; i <= end; i++) {

        /* check the value */
        if (array[i] < min || array[i] > max) {

            /* exit */
            free(histogram);
            return NULL;

        }
        histogram[(size_t)array[i] - min] ++;

    }

    /* exit */
    return histogram;

}
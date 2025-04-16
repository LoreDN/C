/* partition an array from a pivot */
size_t array_partition(TYPE *array, size_t const start, size_t const end) {

    /* pivot initialization */
    TYPE pivot_value = array[end];

    /* partition the array */
    size_t i = start;
    for (size_t j = start; j < end; j++) {

        if (array[j] <= pivot_value) {

            array_swap(&array[i], &array[j]);
            i++;

        }

    }
    array_swap(&array[i], &array[end]);

    /* exit */
    return i;

}
/* merge two parts of an array */
void array_merge(TYPE *array, size_t const start, size_t const middle , size_t const end) {

    /* check the indexes */
    if (start > middle || middle > end) {

        /* exit */
        return;

    }

    /* allocate the merged array */
    size_t size = end - start + 1;
    TYPE *temp = (TYPE *) malloc(size * sizeof(TYPE));

    /* merge the left and right arrays */
    size_t i = start, j = middle + 1, k = 0;
    while (i <= middle && j <= end) {

        /* sort */
        if (array[i] <= array[j]) {

            temp[k++] = array[i++];

        } else {

            temp[k++] = array[j++];

        }

    }

    /* copy the remaining elements from left */
    while (i <= middle) {

        temp[k++] = array[i++];

    }
    /* copy the remaining elements from right */
    while (j <= end) {

        temp[k++] = array[j++];

    }

    /* copy the merged array to the original array */
    for (size_t c = start; c <= end; c++) {

        array[c] = temp[c - start];

    }

    /* free the memory */
    free(temp);

    /* exit */
    return;

}
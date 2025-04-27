/* Counting Sort */
void array_counting_sort(TYPE *array, size_t const start, size_t const end, int const flag_stable) {

    /* check the indexes */
    if (start >= end) {

        /* exit */
        return;

    }

    /* get the maximum and minimun values */
    size_t max = array_max(array,start,end);
    size_t min = array_min(array, start, end);
    size_t size = max - min + 1;
    
    /* get the histogram */
    int *histogram = array_histogram(array, start, end, min, max);
    if (histogram == NULL) {

        /* exit */
        return;

    }

    /* if flag is set to 1, use stable Counting Sort */
    if (flag_stable == 1) {

        /* stabilize the histogram */
        int sum = 0;
        for (size_t i = 0; i < size; i++) {

            sum += histogram[i];
            histogram[i] = sum;
        }

        /* copy the array */
        TYPE *temp = malloc((end - start + 1) * sizeof(TYPE));
        for (size_t i = start; i <= end; i++) {

            temp[i - start] = array[i];

        }

        /* sort the array */
        for (size_t i = end; i > start; i--) {

            array[histogram[(size_t)temp[i - start] - min] - 1 + start] = (int)temp[i - start];
            histogram[(size_t)temp[i - start] - min]--;

        }
        /* copy the last element */
        array[histogram[(size_t)temp[0] - min] - 1 + start] = (int)temp[0];

        /* free the memory */
        free(temp);
        temp = NULL;

    } else {

        for (size_t i = 0, j = start; i < size; i++) {

            /* check the value */
            if (histogram[i] > 0) {

                /* insert the value */
                for (size_t k = 0; k < histogram[i]; k++) {

                    array[j++] = i + min;

                }

            }

        }

    }

    /* free the memory */
    free(histogram);
    histogram = NULL;

    /* exit */
    return;

}
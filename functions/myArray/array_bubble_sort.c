/* Bubble Sort */
void array_bubble_sort(TYPE *array, size_t const start, size_t const end) {

    /* sort */
    for (size_t i = 0; i < end - start; i++) {

        /* insert the maximum element at the end */
        for (size_t j = start; j < end - i; j++) {

            if (array[j] > array[j+1]) {

                /* swap the element with a bigger one */
                array_swap(&array[j],&array[j+1]);

            }

        }

    }

    /* exit */
    return;

}
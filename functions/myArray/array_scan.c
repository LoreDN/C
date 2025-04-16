/* scan an array from user input */
void array_scan(TYPE *array, size_t const size) {

    /* scan the array */
    for (size_t i = 0; i < size; i++) {

        printf("Element %zu: ", i+1);
        scanf(TYPE_SPECIFIER, &array[i]);

    }

    /* exit */
    return;

}
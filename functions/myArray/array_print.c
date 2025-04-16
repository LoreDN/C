/* print an array to the user */
void array_print(TYPE *array, size_t const size, int const flag_user_interface) {

    /* print the array */
    for (size_t i = 0; i < size; i++) {

        /* if flag is set to 1, print the user interface */
        if (flag_user_interface == 1) {

            printf("\nElement %zu: ", i+1);
            printf(TYPE_SPECIFIER, array[i]);

        } else {

            printf(TYPE_SPECIFIER, array[i]);
            printf("\t");

        }

    }
    printf("\n");

    /* exit */
    return;

}
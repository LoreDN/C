/* print an array to a file */
void array_print_file(TYPE *array, size_t const size, char const *path, int const flag_user_interface) {

    /* open the file */
    FILE *file = fopen(path, "w");
    if (file == NULL) {

        printf("\n\nError: could not open file %s!!!\n\n", path);
        
        /* exit */
        exit(-1);

    }

    /* if flag is set to 1, print the user interface */
    if (flag_user_interface == 1){

        /* print the array */
        fprintf(file, "Size of the Array: %zu", size);
        for (size_t i = 0; i < size; i++) {

            fprintf(file, "\nElement %zu: ", i+1);
            fprintf(file, TYPE_SPECIFIER, array[i]);
        }
    
    } else {

        /* print the array */
        fprintf(file, "%zu", size);
        for (size_t i = 0; i < size; i++) {
    
            fprintf(file, "\n");
            fprintf(file, TYPE_SPECIFIER, array[i]);

        }

    }
    printf("\nArray printed successfully to file %s\n!!!", path);

    /* close the file */
    fclose(file);

    /* exit */
    return;

}
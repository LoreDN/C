/* scan an array from a file */
TYPE *array_scan_file(size_t *DIM, char const *path) {

    /* open the file */
    FILE *file = fopen(path, "r");
    if (file == NULL) {

        printf("\n\nError: could not open file %s!!!\n\n", path);
        
        /* exit */
        exit(-1);

    }

    /* get the size */
    size_t size;
    fscanf(file, "%zu", &size);
    *DIM = size;

    /* allocate the array */
    TYPE *array = (TYPE *) malloc(size * sizeof(TYPE));

    /* scan the array */
    for (size_t i = 0; i < size; i++) {

        fscanf(file, TYPE_SPECIFIER, &array[i]);

    }

    /* close the file */
    fclose(file);

    /* exit */
    return array;

}
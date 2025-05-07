/* print the List to a file */
void list_print_file(LIST *list, char const *path, int const flag_user_interface) {

    /* open the file */
    FILE *fp = fopen(path, "w");
    if (fp == NULL) {

        fprintf(stderr, "File opening failed\n");

        /* exit */
        exit(-1);
        
    }

    /* if flag is set to 1, print the user interface */
    if (flag_user_interface == 1) {

        size_t index = 1;
        for (LIST *current = list; current != NULL; current = current->next) {

            fprintf(fp, "Element %zu: ", index++);
            fprintf(fp, TYPE_SPECIFIER, current->value);
            fprintf(fp, "\n");

        }
    
    } else {

        for (LIST *current = list; current != NULL; current = current->next) {

            fprintf(fp, TYPE_SPECIFIER "\t", current->value);

        }

    }

    /* close the file */
    fclose(fp);

    /* exit */
    return;

}
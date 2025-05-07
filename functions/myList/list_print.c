/* print the List to the user */
void list_print(LIST *list, int const flag_user_interface) {

    /* if flag is set to 1, print the user interface */
    if (flag_user_interface == 1) {

        size_t index = 1;
        for (LIST *current = list; current != NULL; current = current->next) {

            printf("\nElement %zu: ", index++);
            printf(TYPE_SPECIFIER, current->value);

        }
    
    } else {

        for (LIST *current = list; current != NULL; current = current->next) {

            printf(TYPE_SPECIFIER "\t", current->value);

        }

    }

    /* exit */
    return;

}
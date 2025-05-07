/* scan a List from user input */
LIST *list_scan(size_t const size) {

    /* go to the end of the List */
    LIST *list = NULL;
    LIST *current = NULL;

    /* scan the List */
    for (size_t i = 0; i < size; i++) {

        /* get the value */
        TYPE value;
        printf("Enter the value %zu: ", i + 1);
        scanf(TYPE_SPECIFIER, &value);

        /* add a new Node */
        if (i == 0) {

            /* create the first Node */
            list = list_add_Node(value);
            current = list;

        } else {
            
            /* new Node */
            current->next = list_add_Node(value);
            current = current->next;

        }

    }

    /* exit */
    return list;

}
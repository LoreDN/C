/* concatenate two Lists */
void list_concatenate(LIST *list, LIST *src) {

    /* check the Lists */
    if (list == NULL || src == NULL) {

        /* exit */
        return;

    }

    /* go to the end of the List */
    LIST *current = list;
    while (current->next != NULL) {

        current = current->next;

    }

    /* concatenate the Lists */
    current->next = src;

    /* exit */
    return;

}
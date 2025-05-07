/* free the List */
LIST *list_free(LIST *list) {

    /* check the List */
    if (list == NULL) {

        /* exit */
        return list;

    }

    /* free the List */
    while (list != NULL) {

        LIST *next = list->next;
        free(list);
        list = next;

    }

    /* exit */
    return list;

}
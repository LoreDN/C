/* get a pointer to the given node */
LIST *list_Node(LIST *list, size_t const node) {

    /* check the indexes */
    size_t length = list_length(list);
    if (node < 1 || node > length) {

        /* exit */
        return NULL;

    }

    /* go to the Node */
    for (size_t i = 1; i < node; i++) {

        list = list->next;

    }

    /* exit */
    return list;

}
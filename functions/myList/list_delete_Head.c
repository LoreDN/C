/* delete the head of the List */
LIST *list_delete_Head(LIST *list) {

    /* check the List */
    if (list == NULL) {

        /* exit */
        return NULL;

    }

    /* delete the head of the List */
    LIST *newHead = list->next;
    free(list);

    /* exit */
    return newHead;

}
/* insert a new Node as head of the List */
LIST *list_insert_Head(LIST *list, TYPE value) {

    /* check the List */
    if (list == NULL) {

        /* exit */
        return NULL;

    }

    /* insert the new Head to the List*/
    LIST *newHead = list_add_Node(value);
    newHead->next = list;

    /* exit */
    return newHead;
}
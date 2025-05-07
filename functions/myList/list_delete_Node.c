/* delete a Node from the List */
void list_delete_Node(LIST *list, LIST *node) {

    /* check the Node */
    if (list == NULL || node == NULL) {

        /* exit */
        return;

    }

    /* go to the previous Node */
    LIST *previous = list;
    while (previous != NULL && previous->next != node) {

        previous = previous->next;

    }

    /* delete the Node */
    previous->next = node->next;
    free(node);

    /* exit */
    return;

}
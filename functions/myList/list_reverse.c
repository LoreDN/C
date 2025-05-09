/* reverse the List */
void list_reverse(LIST *list, size_t const start, size_t const end) {

    /* get the length of the list */
    size_t length = list_length(list);
    
    /* check the indexes */
    if (end > length || start >= end || list == NULL) {

        /* exit */
        return;

    }

    /* go to the starting Node */
    LIST *node_sx = list_Node(list, start);

    /* reverse the List */
    size_t size = end - start + 1;
    size_t middle = size >> 1;
    for (size_t i = 0; i < middle; i++) {

        LIST *node_dx = list_Node(node_sx, size - (i << 1));
        list_swap(&(node_sx->value), &(node_dx->value));
        node_sx = node_sx->next;

    }

    /* exit */
    return;

}
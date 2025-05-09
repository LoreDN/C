/* fill the List with a value */
void list_fill(LIST *list, size_t const start, size_t const end, TYPE const value) {

    /* check the indexes */
    if (start > end || list == NULL) {

        /* exit */
        return;

    }
    
    /* go to the starting Node */
    LIST *temp = list_Node(list,start);

    /* fill the List */
    for (size_t i = start; temp != NULL && i <= end; i++) {

        temp->value = value;
        temp = temp->next;

    }

    /* exit */
    return;

}
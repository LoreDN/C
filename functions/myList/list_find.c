/* find the first occurrence of a value in the List */
LIST *list_find(LIST *list, TYPE const value) {

    /* search the value in the List */
    for (; list != NULL && list->value != value; list = list->next);

    /* exit */
    return list;

}
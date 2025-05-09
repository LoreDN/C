/* sort the List using Bubble Sort */
void list_sort(LIST *list, size_t const start, size_t const end) {

    /* get the length of the list */
    size_t length = list_length(list);
    
    /* check the indexes */
    if (end > length || start >= end || list == NULL) {

        /* exit */
        return;

    }
    
    /* go to the starting Node */
    list = list_Node(list, start);

    /* Bubble Sort */
    size_t size = end - start + 1;
    for (size_t i = 1; i <= size; i++) {  

        /* insert the maximum element at the end */
        LIST *temp = list;
        for (size_t j = 1; j <= size - i; j++) {

            if (temp->value > temp->next->value) {

                /* swap the element with a bigger one */
                list_swap(&(temp->value), &(temp->next->value));

            }
            temp = temp->next;

        }

    }

    /* exit */
    return;
   
}
/* insert a new Node into the List */
void list_insert_Node(LIST *node, TYPE value) {

    /* check the Node */
    if (node == NULL) {

        /* exit */
        return;

    }

    /* insert the new Node into the List */
    LIST *newNode = list_add_Node(value);
    newNode->next = node->next;
    node->next = newNode;

    /* exit */
    return;

}
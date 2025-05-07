/* add a new Node to the List */
LIST *list_add_Node(TYPE value) {

    /* create the new Node */
    LIST *newNode = (LIST *)malloc(sizeof(LIST));
    if (newNode == NULL) {

        fprintf(stderr, "Memory allocation failed\n");

        /* exit */
        exit(-1);
        
    }

    /* set the Node values */
    newNode->value = value;
    newNode->next = NULL;

    /* exit */
    return newNode;

}
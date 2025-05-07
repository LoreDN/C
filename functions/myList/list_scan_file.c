/* scan a List from a file */
LIST *list_scan_file(char const *path) {

    /* open the file */
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {

        fprintf(stderr, "File opening failed\n");

        /* exit */
        exit(-1);
        
    }

    /* go to the end of the List */
    LIST *list = NULL;
    LIST *current = NULL;

    /* scan the List */
    while (!feof(fp)) {

        /* get the value */
        TYPE value;
        fscanf(fp, TYPE_SPECIFIER, &value);

        /* add a new Node */
        if (list == NULL) {

            /* create the first Node */
            list = list_add_Node(value);
            current = list;

        } else {
            
            /* new Node */
            current->next = list_add_Node(value);
            current = current->next;

        }

    }

    /* close the file */
    fclose(fp);

    /* exit */
    return list;

}
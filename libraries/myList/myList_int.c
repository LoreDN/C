/* including external libraries */
#include <stdio.h>
#include <stdlib.h>

/* library type definition */
#define TYPE int
#define TYPE_SPECIFIER "%d"
#define NODE myNode_int
#define LIST myList_int

/* library List definition */
typedef struct NODE {

    TYPE value;
    struct NODE *next;

}LIST;


/* multiple usage definition */
#define list_add_Node list_add_Node_int
#define list_scan list_scan_int
#define list_scan_file list_scan_file_int
#define list_print list_print_int
#define list_print_file list_print_file_int
#define list_insert_Head list_insert_Head_int
#define list_insert_Node list_insert_Node_int
#define list_delete_Head list_delete_Head_int
#define list_delete_Node list_delete_Node_int
#define list_copy list_copy_int
#define list_concatenate list_concatenate_int
#define list_free list_free_int

/* library definition */
#include "myList.h"


/* --------------------------------------------------------------------------------- 1. SCAN A LIST --------------------------------------------------------------------------------- */


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


/* scan a List from user input */
LIST *list_scan(size_t const size) {

    /* go to the end of the List */
    LIST *list = NULL;
    LIST *current = NULL;

    /* scan the List */
    for (size_t i = 0; i < size; i++) {

        /* get the value */
        TYPE value;
        printf("Enter the value %zu: ", i + 1);
        scanf(TYPE_SPECIFIER, &value);

        /* add a new Node */
        if (i == 0) {

            /* create the first Node */
            list = list_add_Node(value);
            current = list;

        } else {
            
            /* new Node */
            current->next = list_add_Node(value);
            current = current->next;

        }

    }

    /* exit */
    return list;

}


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


/* -------------------------------------------------------------------------------- 2. PRINT A LIST --------------------------------------------------------------------------------- */


/* print the List to the user */
void list_print(LIST *list, int const flag_user_interface) {

    /* if flag is set to 1, print the user interface */
    if (flag_user_interface == 1) {

        size_t index = 1;
        for (LIST *current = list; current != NULL; current = current->next) {

            printf("\nElement %zu: ", index++);
            printf(TYPE_SPECIFIER, current->value);

        }
    
    } else {

        for (LIST *current = list; current != NULL; current = current->next) {

            printf(TYPE_SPECIFIER "\t", current->value);

        }

    }

    /* exit */
    return;

}


/* print the List to a file */
void list_print_file(LIST *list, char const *path, int const flag_user_interface) {

    /* open the file */
    FILE *fp = fopen(path, "w");
    if (fp == NULL) {

        fprintf(stderr, "File opening failed\n");

        /* exit */
        exit(-1);
        
    }

    /* if flag is set to 1, print the user interface */
    if (flag_user_interface == 1) {

        size_t index = 1;
        for (LIST *current = list; current != NULL; current = current->next) {

            fprintf(fp, "Element %zu: ", index++);
            fprintf(fp, TYPE_SPECIFIER, current->value);
            fprintf(fp, "\n");

        }
    
    } else {

        for (LIST *current = list; current != NULL; current = current->next) {

            fprintf(fp, TYPE_SPECIFIER "\t", current->value);

        }

    }

    /* close the file */
    fclose(fp);

    /* exit */
    return;

}


/* ---------------------------------------------------------------------------- 3. OPERATIONS ON A LIST ----------------------------------------------------------------------------- */


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


/* copy the List from a src */
extern LIST *list_copy(LIST *src);

/* concatenate two Lists */
void list_concatenate(LIST *list, LIST *src) {

    /* check the Lists */
    if (list == NULL || src == NULL) {

        /* exit */
        return;

    }

    /* go to the end of the List */
    LIST *current = list;
    while (current->next != NULL) {

        current = current->next;

    }

    /* concatenate the Lists */
    current->next = src;

    /* exit */
    return;

}


/* free the List */
LIST *list_free(LIST *list) {

    /* check the List */
    if (list == NULL) {

        /* exit */
        return list;

    }

    /* free the List */
    while (list != NULL) {

        LIST *next = list->next;
        free(list);
        list = next;

    }

    /* exit */
    return list;

}


/* library end definition */
#undef list_add_Node
#undef list_scan
#undef list_scan_file
#undef list_print
#undef list_print_file
#undef list_insert_Head
#undef list_insert_Node
#undef list_delete_Head
#undef list_delete_Node
#undef list_copy
#undef list_concatenate
#undef list_free

#undef TYPE
#undef TYPE_SPECIFIER
#undef NODE
#undef LIST
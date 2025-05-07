/* library definition */
#ifndef MYLIST_INT_H
#define MYLIST_INT_H

/* library type definition */
#define TYPE int
#define NODE myNode_int
#define LIST myList_int

/* library List definition */
typedef struct NODE {

    TYPE value;
    struct NODE *next;

}LIST;

/* including external libraries */
#include <stddef.h>


/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*
*  This header file is part of the myList library, it is designed as the file to include in order to use the library with type int.
*
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */





/* --------------------------------------------------------------------------------- 1. SCAN A LIST --------------------------------------------------------------------------------- */

LIST *list_add_Node_int(TYPE value);
LIST *list_scan_int(size_t const size);
LIST *list_scan_file_int(char const *path);

/* -------------------------------------------------------------------------------- 2. PRINT A LIST --------------------------------------------------------------------------------- */

void list_print_int(LIST *list, int const flag_user_interface);
void list_print_file_int(LIST *list, char const *path, int const flag_user_interface);

/* ---------------------------------------------------------------------------- 3. OPERATIONS ON A LIST ----------------------------------------------------------------------------- */

LIST *list_insert_Head_int(LIST *list, TYPE value);
void list_insert_Node_int(LIST *node, TYPE value);
LIST *list_delete_Head_int(LIST *list);
void list_delete_Node_int(LIST *list, LIST *node);

extern LIST *list_copy_int(LIST *src);
void list_concatenate_int(LIST *list, LIST *src);

LIST *list_free_int(LIST *list);


/* end of library */
#undef TYPE
#undef NODE
#undef LIST

#endif // MYLIST_INT_H
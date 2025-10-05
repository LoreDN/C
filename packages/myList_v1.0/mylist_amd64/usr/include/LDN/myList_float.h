/* library definition */
#ifndef MYLIST_FLOAT_H
#define MYLIST_FLOAT_H

/* library type definition */
#define TYPE float
#define NODE myNode_float
#define LIST myList_float

/* library List definition */
typedef struct NODE {

    TYPE value;
    struct NODE *next;

}LIST;

/* including external libraries */
#include <stddef.h>


/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*
*  This header file is part of the myList library, it is designed as the file to include in order to use the library with type float.
*
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */





/* --------------------------------------------------------------------------------- 1. SCAN A LIST --------------------------------------------------------------------------------- */

LIST *list_add_Node_float(TYPE const value);
LIST *list_scan_float(size_t const size);
LIST *list_scan_file_float(char const *path);

/* -------------------------------------------------------------------------------- 2. PRINT A LIST --------------------------------------------------------------------------------- */

void list_print_float(LIST *list, int const flag_user_interface);
void list_print_file_float(LIST *list, char const *path, int const flag_user_interface);

/* ---------------------------------------------------------------------------- 3. OPERATIONS ON A LIST ----------------------------------------------------------------------------- */

LIST *list_insert_Head_float(LIST *list, TYPE const value);
void list_insert_Node_float(LIST *node, TYPE const value);
LIST *list_delete_Head_float(LIST *list);
void list_delete_Node_float(LIST *list, LIST *node);

extern void list_swap_float(TYPE *a, TYPE *b);
void list_sort_float(LIST *list, size_t const start, size_t const end);
void list_reverse_float(LIST *list, size_t const start, size_t const end);

extern LIST *list_copy_float(LIST *src);
LIST *list_concatenate_float(LIST *list, LIST *src);

LIST *list_free_float(LIST *list);

/* ----------------------------------------------------------------------------------- 4. UTILITY ----------------------------------------------------------------------------------- */

extern size_t list_length_float(LIST *list);
LIST *list_find_float(LIST *list, TYPE const value);
LIST *list_Node_float(LIST *list, size_t const node);
void list_fill_float(LIST *list, size_t const start, size_t const end, TYPE const value);

/* end of library */
#undef TYPE
#undef NODE
#undef LIST

#endif // MYLIST_FLOAT_H
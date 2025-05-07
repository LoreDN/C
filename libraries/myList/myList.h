/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*
*  This library contains some usefull functions to work with Lists.
*  Since each node in a List can be a custom struct, the library has been designed to work with a precise type myList_type.
*  For each type, has been already given a definition for the LIST, however it consist in a struct of one element and a Node pointer to the next struct LIST.
*  Despite this limitation, the library is designed to be used with all numeric types ( int, float, ecc... ).
*  In order to use a specific type, it is necessary to add the right 'myArray_type.c' files when compiling.
*
*  The functions included in this library are divided in three groups:
*     1. SCAN A LIST: used to scan a LIST from user input or from a file.
*     2. PRINT A LIST: used to print a LIST to the user or to a file.
*     3. OPERATIONS ON A LIST: used to perform more specific operations on a LIST (such as insert/delete a nodes).
*
*
*  |-----** IMPORTANT!!! **-----|
*  Since this library is designed to be used with different types of elements, there are two ways of using it:
*     - Single Usage: use the library a single time (use with a single type of array).
*     - Multiple Usage: use the library multiple times (use with different types of arrays).
*  In order to use a type, all you have to do is only to include the corrispective 'myArray_type.h' file in the project.
*
*  Example of Single Usage:
*     #include "myLIST_int.h"
*     list = list_scan_int(size);
*
*  Example of Multiple Usage:
*     #include "myList_int.h"
*     #include "myList_float.h"
*     list = list_scan_int(size);
*     list = list_scan_float(size);
*
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */





/* --------------------------------------------------------------------------------- 1. SCAN A LIST --------------------------------------------------------------------------------- */

LIST *list_add_Node(TYPE value);
LIST *list_scan(size_t const size);
LIST *list_scan_file(char const *path);

/* -------------------------------------------------------------------------------- 2. PRINT A LIST --------------------------------------------------------------------------------- */

void list_print(LIST *list, int const flag_user_interface);
void list_print_file(LIST *list, char const *path, int const flag_user_interface);

/* ---------------------------------------------------------------------------- 3. OPERATIONS ON A LIST ----------------------------------------------------------------------------- */

LIST *list_insert_Head(LIST *list, TYPE value);
void list_insert_Node(LIST *node, TYPE value);
LIST *list_delete_Head(LIST *list);
void list_delete_Node(LIST *list, LIST *node);

extern LIST *list_copy(LIST *src);
void list_concatenate(LIST *list, LIST *src);

LIST *list_free(LIST *list);
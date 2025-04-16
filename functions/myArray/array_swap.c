/* swap two elements of the array */
void array_swap(TYPE *a, TYPE *b) {

    /* swap */
    TYPE temp = *a;
    *a = *b;
    *b = temp;

    /* exit */
    return;

}
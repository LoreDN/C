/* Merge Sort */
void array_merge_sort(TYPE *array, size_t const start, size_t const end) {

    /* empty array || one element array */
    if (start >= end) {

        /* exit */
        return;

    }

    /* get the middle of the array */
    size_t middle = (start + end) >> 1;

    /* sort the left and right arrays */
    array_merge_sort(array, start, middle);
    array_merge_sort(array,  middle + 1, end);

    /* merge the left and right arrays */
    array_merge(array, start, middle, end);

    /* exit */
    return;
    
}
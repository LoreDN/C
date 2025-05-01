/* find the first occurrence of a value in the array by binary search */
int array_binary_search(TYPE *array, size_t const start, size_t const end, TYPE const value) {

    /* check the indexes */
    if (start > end) {

        /* exit */
        return -1;

    } else if (start == end) {

        /* check the value */
        if (array[start] == value) {

            /* exit */
            return start;

        } else {

            /* exit */
            return -1;

        }

    }

    /* check if the array is sorted */
    if (array_is_sorted(array, start, end) == 0) {

        /* exit */
        return -2;

    }

    /* get the middle of the array */
    size_t middle = (start + end) >> 1;

    /* search the value */
    if (array[middle] == value) {

        /* exit */
        return middle;

    } else if (array[middle] < value) {
        
        middle = array_binary_search(array, middle + 1, end, value);

    } else if (array[middle] > value) {

        middle = array_binary_search(array, start, middle - 1, value);

    } else {

        /* exit */
        return -1;

    }

    /* exit */
    return middle;

}
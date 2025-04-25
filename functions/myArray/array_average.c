/* get the average of the elements of the array */
float array_average(TYPE *array, size_t const start, size_t const end) {

    /* check the indexes */
    if (start > end) {

        /* exit */
        return 0;

    }

    /* get the average of the elements */
    size_t size = end - start + 1;
    float average = array_sum(array, start, end);
    average /= size;    

    /* exit */
    return average;    

}
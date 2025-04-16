/* Block Sort */
void array_block_sort(TYPE *array, size_t const start, size_t const end) {

    /*  get the size of a block */
    size_t size = end - start + 1;
    size_t block_size = (size_t) sqrt(size);
    if (block_size == 0) {

        /* exit */
        return;

    }

    /* sort the blocks */
    for (size_t i = start; i <= end; i += block_size) {

        size_t block_end = i + block_size - 1;
        if (block_end > end) {
            
            block_end = end;
        
        }

        array_insertion_sort(array, i, block_end);
    }

    /* merge the blocks */
    for (size_t step = block_size; step < size; step <<= 1) {

        /* merge blocks of size step */
        for (size_t i = start; i + step <= end; i += (step << 1)) {

            size_t middle = i + step - 1;
            size_t right_end = i + (step << 1) - 1;
            if (right_end > end) {
                
                right_end = end;
            
            }
            
            array_merge(array, i, middle, right_end);

        }

    }

    /* exit */
    return;
    
}
/* ---------------------------------------------------------------------------------------------------------------
*
*  void list_swap(TYPE *a, TYPE *b);
*
*  swap the values of two Nodes of the List
*
--------------------------------------------------------------------------------------------------------------- */


# list_swap_int()
/* ========================== INT ========================== */
#ifdef INT_TYPE

    /* ------ x86_64 Architecture ------ */
    #ifdef __x86_64__

        .global list_swap_int
        .type list_swap_int, @function
        .text


        list_swap_int:

            # swap the elements
            movl    (%rdi), %eax
            movl    (%rsi), %ebx
            movl    %ebx, (%rdi)
            movl    %eax, (%rsi)

            # exit
            ret     

    #endif // x86_64 Architecture

    /* ------ RISC-V Architecture ------ */
    #ifdef __riscv

        .global list_swap_int
        .type list_swap_int, @function
        .text


        list_swap_int:

            # swap the elements
            lw      t0, 0(a0)
            lw      t1, 0(a1)
            sw      t1, 0(a0)
            sw      t0, 0(a1)

            # exit
            ret

    #endif // RISC-V Architecture

#endif // INT_TYPE


# list_swap_float()
/* ========================= FLOAT ========================= */
#ifdef FLOAT_TYPE

    /* ------ x86_64 Architecture ------ */
    #ifdef __x86_64__

        .global list_swap_float
        .type list_swap_float, @function
        .text


        list_swap_float:

            # swap the elements
            movss   (%rdi), %xmm0
            movss   (%rsi), %xmm1
            movss   %xmm1, (%rdi)
            movss   %xmm0, (%rsi)

            # exit
            ret

    #endif // x86_64 Architecture

    /* ------ RISC-V Architecture ------ */
    #ifdef __riscv

        .global list_swap_float
        .type list_swap_float, @function
        .text


        list_swap_float:

            # swap the elements
            flw     ft0, 0(a0)
            flw     ft1, 0(a1)
            fsw     ft1, 0(a0)
            fsw     ft0, 0(a1)

            # exit
            ret

    #endif // RISC-V Architecture

#endif // FLOAT_TYPE
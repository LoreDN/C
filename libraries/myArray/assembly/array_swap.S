# array_swap(): function to swap two elements of the array

# array_swap_int()
/* ========================== INT ========================== */

#ifdef INT_TYPE

    /* ------ x86_64 Architecture ------ */
    #ifdef __x86_64__

        .global array_swap_int
        .type array_swap_int, @function


        array_swap_int:

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

        .global array_swap_int
        .type array_swap_int, @function


        array_swap_int:

            # swap the elements
            lw      t0, 0(a0)
            lw      t1, 0(a1)
            sw      t1, 0(a0)
            sw      t0, 0(a1)

            # exit
            ret

    #endif // RISC-V Architecture

#endif // INT_TYPE


# array_swap_float()
/* ========================= FLOAT ========================= */

#ifdef FLOAT_TYPE

    /* ------ x86_64 Architecture ------ */
    #ifdef __x86_64__

        .global array_swap_float
        .type array_swap_float, @function


        array_swap_float:

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

        .global array_swap_float
        .type array_swap_float, @function


        array_swap_float:

            # swap the elements
            flw     ft0, 0(a0)
            flw     ft1, 0(a1)
            fsw     ft1, 0(a0)
            fsw     ft0, 0(a1)

            # exit
            ret

    #endif // RISC-V Architecture

#endif // FLOAT_TYPE
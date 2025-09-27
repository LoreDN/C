/* ---------------------------------------------------------------------------------------------------------------
*
*  void array_copy(TYPE *array, size_t const start, size_t const end, TYPE *src, size_t const src_idx);
*
*  copy the array from a src
*
--------------------------------------------------------------------------------------------------------------- */


# array_copy_int()
/* ========================== INT ========================== */
#ifdef INT_TYPE

    /* ------ x86_64 Architecture ------ */
    #ifdef __x86_64__

        .global array_copy_int
        .type array_copy_int, @function
        .text


        array_copy_int:

            # check the indexes
            cmp     %rsi, %rdx
            jl      end_array_copy_int

            # load start
            shlq    $2, %rsi

            # load end
            shlq    $2, %rdx

            # load src_idx
            shlq    $2, %r8

            # go to the loop
            jmp     loop_array_copy_int

        
        loop_array_copy_int:

            # load src[src_idx]
            mov     (%rcx, %r8), %r9d

            # copy src[src_idx] to array[i]
            mov     %r9d, (%rdi, %rsi)

            # src_idx++
            addq    $4, %r8

            # i++
            addq    $4, %rsi

            # while (i <= end)
            cmp     %rsi, %rdx
            jge     loop_array_copy_int
            ret
        

        end_array_copy_int:

            # exit
            ret

    #endif // x86_64 Architecture

    /* ------ RISC-V Architecture ------ */
    #ifdef __riscv

        .global array_copy_int
        .type array_copy_int, @function
        .text


        array_copy_int:

            # check the indexes
            bgt    a1, a2, end_array_copy_int

            # load start
            slli    a1, a1, 2

            # load end
            slli    a2, a2, 2

            # load &array[start]
            add     t0, a0, a1

            # load src_idx
            slli    a4, a4, 2

            # load &src[src_idx]
            add     t1, a3, a4

            # go to the loop
            j     loop_array_copy_int


        loop_array_copy_int:

            # load src[src_idx]
            lw      t2, 0(t1)

            # copy src[src_idx] to array[i]
            sw      t2, 0(t0)
            addi    t0, t0, 4
            addi    t1, t1, 4

            # i++
            addi    a1, a1, 4

            # while (i <= end)
            ble     a1, a2, loop_array_copy_int
            ret
        

        end_array_copy_int:

            # exit
            ret

    #endif // RISC-V Architecture

#endif // INT_TYPE


# array_copy_float()
 /* ========================= FLOAT ========================= */
#ifdef FLOAT_TYPE

    /* ------ x86_64 Architecture ------ */
    #ifdef __x86_64__

        .global array_copy_float
        .type array_copy_float, @function
        .text


        array_copy_float:

            # check the indexes
            cmp     %rsi, %rdx
            jl      end_array_copy_float

            # load start
            shlq    $2, %rsi

            # load end
            shlq    $2, %rdx

            # load src_idx
            shlq    $2, %r8

            # go to the loop
            jmp     loop_array_copy_float
        

        loop_array_copy_float:

            # load src[src_idx]
            mov     (%rcx, %r8), %r9d

            # copy src[src_idx] to array[i]
            mov     %r9d, (%rdi, %rsi)

            # src_idx++
            addq    $4, %r8

            # i++
            addq    $4, %rsi

            # while (i <= end)
            cmp     %rsi, %rdx
            jge     loop_array_copy_float
            ret
        

        end_array_copy_float:

            # exit
            ret
        
    #endif // x86_64 Architecture

    /* ------ RISC-V Architecture ------ */
    #ifdef __riscv

        .global array_copy_float
        .type array_copy_float, @function
        .text


        array_copy_float:

            # check the indexes
            bgt    a1, a2, end_array_copy_float

            # load start
            slli    a1, a1, 2

            # load end
            slli    a2, a2, 2

            # load &array[start]
            add     t0, a0, a1

            # load src_idx
            slli    a4, a4, 2

            # load &src[src_idx]
            add     t1, a3, a4

            # go to the loop
            j     loop_array_copy_float
        

        loop_array_copy_float:

            # load src[src_idx]
            flw     ft0, 0(t1)

            # copy src[src_idx] to array[i]
            fsw     ft0, 0(t0)
            addi    t0, t0, 4
            addi    t1, t1, 4

            # i++
            addi    a1, a1, 4

            # while (i <= end)
            ble     a1, a2, loop_array_copy_float
            ret
        

        end_array_copy_float:

            # exit
            ret
        
    #endif // RISC-V Architecture

#endif // FLOAT_TYPE
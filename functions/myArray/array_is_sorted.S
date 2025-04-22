# array_is_sorted(): check if the array is sorted

# array_is_sorted_int()
/* ========================== INT ========================== */

#ifdef INT_TYPE

    /* ------ x86_64 Architecture ------ */
    #ifdef __x86_64__

        .global array_is_sorted_int
        .type array_is_sorted_int, @function


        array_is_sorted_int:

            # load start
            shlq    $2, %rsi

            # load end
            shlq    $2, %rdx

            # check the indexes
            cmp     %rsi, %rdx
            jg      loop_array_is_sorted_int
            je      end_array_is_sorted_int

            # start > end --> return -1 
            mov     $-1, %eax
            ret


        loop_array_is_sorted_int:

            # while (i < end)
            cmp     %rsi, %rdx
            jle     end_array_is_sorted_int

            # load array[i] and array[i+1]
            mov     (%rdi, %rsi), %eax
            add     $4, %rsi
            mov     (%rdi, %rsi), %ebx

            # array[i] > array[i+1] --> return 0
            cmp     %eax, %ebx
            jge     loop_array_is_sorted_int

            xor     %eax, %eax
            ret


        end_array_is_sorted_int:

            # array is sorted --> return 1
            mov     $1, %eax
            ret

    #endif // x86_64 Architecture
    
    /* ------ RISC-V Architecture ------ */
    #ifdef __riscv

        .global array_is_sorted_int
        .type array_is_sorted_int, @function


        array_is_sorted_int:

            # load start
            slli    a1, a1, 2

            # load end
            slli    a2, a2, 2

            # check the indexes
            blt     a1, a2, loop_array_is_sorted_int
            beq     a1, a2, end_array_is_sorted_int

            # start > end --> return -1
            li      a0, -1
            ret


        loop_array_is_sorted_int:

            # while (i < end)
            bge     a1, a2, end_array_is_sorted_int

            # load array[i] and array[i+1]
            lw      t0, a1(a0)
            addi    a1, a1, 4
            lw      t1, a1(a0)

            # array[i] > array[i+1] --> return 0
            ble     t0, t1, loop_array_is_sorted_int

            li      a0, 0
            ret

        
        end_array_is_sorted_int:

            # array is sorted --> return 1
            li      a0, 1
            ret

    #endif // RISC-V Architecture

#endif // INT_TYPE


# array_is_sorted_float()
/* ========================= FLOAT ========================= */

#ifdef FLOAT_TYPE

    /* ------ x86_64 Architecture ------ */
    #ifdef __x86_64__

        .global array_is_sorted_float
        .type array_is_sorted_float, @function


        array_is_sorted_float:

            # load start
            shl     $2, %rsi

            # load end
            shl     $2, %rdx

            # check the indexes
            cmp     %rsi, %rdx
            jg      loop_array_is_sorted_float
            je      end_array_is_sorted_float

            # start > end --> return -1
            mov     $-1, %eax
            ret


        loop_array_is_sorted_float:

            # while (i < end)
            cmp     %rsi, %rdx
            jle     end_array_is_sorted_float

            # load array[i] and array[i+1]
            movss   (%rdi, %rsi), %xmm0
            add     $4, %rsi
            movss   (%rdi, %rsi), %xmm1

            # array[i] > array[i+1] --> return 0
            ucomiss %xmm0, %xmm1
            jae     loop_array_is_sorted_float

            xor     %eax, %eax
            ret


        end_array_is_sorted_float:

            # array is sorted --> return 1
            mov     $1, %eax
            ret

    #endif // x86_64 Architecture

    /* ------ RISC-V Architecture ------ */
    #ifdef __riscv

        .global array_is_sorted_float
        .type array_is_sorted_float, @function

        array_is_sorted_float:

            # load start
            slli    a1, a1, 2

            # load end
            slli    a2, a2, 2

            # check the indexes
            blt     a1, a2, loop_array_is_sorted_float
            beq     a1, a2, end_array_is_sorted_float

            # start > end --> return -1
            li      a0, -1
            ret
        

        loop_array_is_sorted_float:

            # while (i < end)
            bge     a1, a2, end_array_is_sorted_float

            # load array[i] and array[i+1]
            flw     ft0, a1(a0)
            addi    a1, a1, 4
            flw     ft1, a1(a0)

            # array[i] > array[i+1] --> return 0
            fle.s   t0, ft0, ft1
            bne     t0, zero, loop_array_is_sorted_float

            li      a0, 0
            ret
        

        end_array_is_sorted_float:

            # array is sorted --> return 1
            li      a0, 1
            ret
        
    #endif // RISC-V Architecture

#endif // FLOAT_TYPE
# array_find(): find the first occurrence of a value in the array by linear search

# array_find_int()
/* ========================== INT ========================== */
#ifdef INT_TYPE

    /* ------ x86_64 Architecture ------ */
    #ifdef __x86_64__

        .global array_find_int
        .type array_find_int, @function


        array_find_int:

            # check the indexes
            cmp     %rsi, %rdx
            jl      end_array_find_int

            # load start
            shlq    $2, %rsi

            # load end
            shlq    $2, %rdx

            # go to the loop
            jmp     loop_array_find_int
        

        loop_array_find_int:

            # while (i <= end)
            cmp     %rsi, %rdx
            jl      end_array_find_int
            
            # load array[i]
            movl    (%rdi, %rsi), %eax

            # i++
            add     $4, %rsi

            # compare array[i] with value
            cmp     %eax, %ecx
            jne     loop_array_find_int

            # value found --> return i
            mov     %rsi, %rax
            shr     $2, %rax
            sub     $1, %rax
            ret
        

        end_array_find_int:

            # value not found --> return -1
            movl    $-1, %eax
            ret

    #endif // x86_64 Architecture

    /* ------ RISC-V Architecture ------ */
    #ifdef __riscv

        .global array_find_int
        .type array_find_int, @function


        array_find_int:

            # check the indexes
            bgt     a1, a2, end_array_find_int

            # load start
            slli    a1, a1, 2

            # load end
            slli    a2, a2, 2

            # go to the loop
            j       loop_array_find_int
        

        loop_array_find_int:

            # while (i <= end)
            bgt     a1, a2, end_array_find_int
            
            # load array[i]
            lw      t0, a1(a0)

            # i++
            addi    a1, a1, 4

            # compare array[i] with value
            bne     t0, a3, loop_array_find_int

            # value found --> return i
            mv      a0, a1
            srai    a0, a0, 2
            addi    a0, a0, -1
            ret
        

        end_array_find_int:

            # value not found --> return -1
            li      a0, -1
            ret

    #endif // RISC-V Architecture

#endif // INT_TYPE


# array_find_float()
/* ========================= FLOAT ========================= */
#ifdef FLOAT_TYPE

    /* ------ x86_64 Architecture ------ */
    #ifdef __x86_64__

        .global array_find_float
        .type array_find_float, @function


        array_find_float:

            # check the indexes
            cmp     %rsi, %rdx
            jl      end_array_find_float

            # load start
            shlq    $2, %rsi

            # load end
            shlq    $2, %rdx

            # go to the loop
            jmp     loop_array_find_float
        

        loop_array_find_float:

            # while (i <= end)
            cmp     %rsi, %rdx
            jl      end_array_find_float
            
            # load array[i]
            movss  (%rdi, %rsi), %xmm1

            # i++
            add     $4, %rsi

            # compare array[i] with value
            ucomiss %xmm0, %xmm1
            jne     loop_array_find_float

            # value found --> return i
            mov     %rsi, %rax
            shr     $2, %rax
            sub     $1, %rax
            ret
        

        end_array_find_float:

            # value not found --> return -1
            movl    $-1, %eax
            ret

    #endif // x86_64 Architecture

    /* ------ RISC-V Architecture ------ */
    #ifdef __riscv

        .global array_find_float
        .type array_find_float, @function


        array_find_float:

            # check the indexes
            bgt     a1, a2, end_array_find_float

            # load start
            slli    a1, a1, 2

            # load end
            slli    a2, a2, 2

            # go to the loop
            j       loop_array_find_float
        

        loop_array_find_float:

            # while (i <= end)
            bgt     a1, a2, end_array_find_float
            
            # load array[i]
            flw     ft0, a1(a0)

            # i++
            addi    a1, a1, 4

            # compare array[i] with value
            feq.s   t0, ft0, a3
            beq     t0, zero, loop_array_find_float            

            # value found --> return i
            mv      a0, a1
            srai    a0, a0, 2
            addi    a0, a0, -1
            ret
        

        end_array_find_float:

            # value not found --> return -1
            li      a0, -1
            ret

    #endif // RISC-V Architecture

#endif // FLOAT_TYPE
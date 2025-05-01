# array_sum(): get the sum of the elements of the array

# array_sum_int()
/* ========================== INT ========================== */
#ifdef INT_TYPE

    /* ------ x86_64 Architecture ------ */
    #ifdef __x86_64__

        .global array_sum_int
        .type array_sum_int, @function


        array_sum_int:

            # load zero
            xor     %rax, %rax

            # check indexes
            cmp     %rsi, %rdx
            jl      end_array_sum_int

            # load start
            shl     $2, %rsi

            # load end
            shl     $2, %rdx

            # get the sum
            movl    (%rdi, %rsi), %eax
            add     $4, %rsi

            # go to the loop
            jmp     loop_array_sum_int
        

        loop_array_sum_int:

            # while (i <= end)
            cmp     %rsi, %rdx
            jl      end_array_sum_int

            # sum += array[i]
            addl   (%rdi, %rsi), %eax

            # i++
            add     $4, %rsi

            # go to the loop
            jmp     loop_array_sum_int

        
        end_array_sum_int:

            # return the sum
            ret

    #endif // x86_64 Architecture

    /* ------ RISC-V Architecture ------ */
    #ifdef __riscv

        .global array_sum_int
        .type array_sum_int, @function


        array_sum_int:

            # load &array
            mv      t0, a0

            # load zero
            li      a0, 0

            # check indexes
            bgt     a1, a2, end_array_sum_int

            # load start
            slli    a1, a1, 2

            # load end
            slli    a2, a2, 2

            # get the sum
            lw      a0, a1(t0)
            addi    a1, a1, 4

            # go to the loop
            j       loop_array_sum_int
        

        loop_array_sum_int:

            # while (i <= end)
            bgt     a1, a2, end_array_sum_int

            # sum += array[i]
            lw      t1, a1(t0)
            add     a0, a0, t1

            # i++
            addi    a1, a1, 4

            # go to the loop
            j       loop_array_sum_int

        
        end_array_sum_int:

            # return the sum
            ret

    #endif // RISC-V Architecture

#endif // INT_TYPE

# array_sum_float()
/* ========================== FLOAT ========================== */
#ifdef FLOAT_TYPE

    /* ------ x86_64 Architecture ------ */
    #ifdef __x86_64__

        .global array_sum_float
        .type array_sum_float, @function


        array_sum_float:

            # load zero
            xorps   %xmm0, %xmm0

            # check indexes
            cmp     %rsi, %rdx
            jl      end_array_sum_float

            # load start
            shl     $2, %rsi

            # load end
            shl     $2, %rdx

            # get the sum
            movss   (%rdi, %rsi), %xmm0
            add     $4, %rsi

            # go to the loop
            jmp     loop_array_sum_float
        

        loop_array_sum_float:

            # while (i <= end)
            cmp     %rsi, %rdx
            jl      end_array_sum_float

            # sum += array[i]
            addss   (%rdi, %rsi), %xmm0

            # i++
            add     $4, %rsi

            # go to the loop
            jmp     loop_array_sum_float
        

        end_array_sum_float:

            # return the sum
            ret

    #endif // x86_64 Architecture

    /* ------ RISC-V Architecture ------ */
    #ifdef __riscv
    
        .global array_sum_float
        .type array_sum_float, @function


        array_sum_float:

            # load &array
            mv      t0, a0

            # load zero
            li      fa0, 0

            # check indexes
            bgt     a1, a2, end_array_sum_float

            # load start
            slli    a1, a1, 2

            # load end
            slli    a2, a2, 2

            # get the sum
            flw     fa0, a1(t0)
            addi    a1, a1, 4

            # go to the loop
            j       loop_array_sum_float
        

        loop_array_sum_float:

            # while (i <= end)
            bgt     a1, a2, end_array_sum_float

            # sum += array[i]
            flw     ft0, a1(t0)
            fadd    fa0, fa0, ft0

            # i++
            addi    a1, a1, 4

            # go to the loop
            j       loop_array_sum_float
        

        end_array_sum_float:

            # return the sum
            ret

    #endif // RISC-V Architecture

#endif // FLOAT_TYPE
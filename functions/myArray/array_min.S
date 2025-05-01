# array_max(): get the maximum value of the array

# array_max_int()
/* ========================== INT ========================== */
#ifdef INT_TYPE

    /* ------ x86_64 Architecture ------ */
    #ifdef __x86_64__

        .global array_min_int
        .type array_min_int, @function


        array_min_int:

            # load zero
            xor     %rax, %rax

            # check the indexes
            cmp     %rsi, %rdx
            jl      end_array_min_int

            # push on stack
            push    %rdi
            push    %rsi
            push    %rdx

            # call arry_is_sorted(array, start, end)
            call    array_is_sorted_int

            # pop from stack
            pop     %rdx
            pop     %rsi
            pop     %rdi

            # array_is_sorted --> min = array[start]
            cmp     $1, %rax
            je      sorted_array_min_int

            # load start
            shl     $2, %rsi

            # load end
            shl     $2, %rdx

            # get min
            movl    (%rdi, %rsi), %eax
            add     $4, %rsi

            # go to the loop
            jmp     loop_array_min_int
        

        loop_array_min_int:

            # while (i <= end)
            cmp     %rsi, %rdx
            jl      end_array_min_int

            # load array[i]
            movl    (%rdi, %rsi), %ebx

            # i++
            add     $4, %rsi

            # array[i] < min --> min = array[i]
            cmp     %eax, %ebx
            jge     loop_array_min_int
            mov     %ebx, %eax

            # go to the loop
            jmp     loop_array_min_int
        

        sorted_array_min_int:

            # min = array[end]
            shl     $2, %rsi
            movl    (%rdi, %rsi), %eax
            ret


        end_array_min_int:

            # return min
            ret
    
    #endif // x86_64 Architecture

    /* ------ RISC-V Architecture ------ */
    #ifdef __riscv

        .global array_min_int
        .type array_min_int, @function


        array_min_int:

            # load zero
            li      t0, 0

            # check the indexes
            bgt     a1, a2, end_array_min_int

            # push on stack
            addi    sp, sp, -12
            sw      a0, 0(sp)
            sw      a1, 4(sp)
            sw      a2, 8(sp)

            # call array_is_sorted(array, start, end)
            jal     array_is_sorted_int
            li      t0, 1
            mv      t1, a0

            # pop from stack
            lw      a0, 0(sp)
            lw      a1, 4(sp)
            lw      a2, 8(sp)
            addi    sp, sp, 12

            # array_is_sorted --> min = array[start]
            beq     t0, t1, sorted_array_max_int

            # load start
            slli    a1, a1, 2

            # load end
            slli    a2, a2, 2

            # get min
            lw      t0, a1(a0)
            addi    a1, a1, 4

            # go to the loop
            j       loop_array_min_int
        

        loop_array_min_int:

            # while (i <= end)
            bgt     a1, a2, end_array_min_int

            # load array[i]
            lw      t1, a1(a0)

            # i++
            addi    a1, a1, 4

            # array[i] < min --> min = array[i]
            ble     t0, t1, loop_array_min_int
            mv      t0, t1

            # go to the loop
            j       loop_array_min_int
        

        sorted_array_min_int:

            # min = array[start]
            slli    a1, a1, 2
            lw      a0, a1(a0)
            ret


        end_array_min_int:

            # return min
            mv      a0, t0
            ret            
    
    #endif // RISC-V Architecture

#endif // INT_TYPE


# array_max_float()
/* ========================= FLOAT ========================= */
#ifdef FLOAT_TYPE

    /* ------ x86_64 Architecture ------ */
    #ifdef __x86_64__

        .global array_min_float
        .type array_min_float, @function


        array_min_float:

            # load zero
            xorps   %xmm0, %xmm0

            # check the indexes
            cmp     %rsi, %rdx
            jl      end_array_min_float

            # push on stack
            push    %rdi
            push    %rsi
            push    %rdx

            # call array_is_sorted(array, start, end)
            call    array_is_sorted_float

            # pop from stack
            pop     %rdx
            pop     %rsi
            pop     %rdi

            # array_is_sorted --> min = array[start]
            cmp     $1, %rax
            je      sorted_array_min_float

            # load start
            shl     $2, %rsi

            # load end
            shl     $2, %rdx

            # get min
            movss   (%rdi, %rsi), %xmm0
            add     $4, %rsi

            # go to the loop
            jmp     loop_array_min_float
        

        loop_array_min_float:

            # while (i <= end)
            cmp     %rsi, %rdx
            jl      end_array_min_float

            # load array[i]
            movss   (%rdi, %rsi), %xmm1

            # i++
            add     $4, %rsi

            # array[i] < min --> min = array[i]
            ucomiss %xmm0, %xmm1
            jae     loop_array_min_float
            movss   %xmm1, %xmm0

            # go to the loop
            jmp     loop_array_min_float
        

        sorted_array_min_float:

            # min = array[start]
            shl     $2, %rsi
            movss   (%rdi, %rsi), %xmm0
            ret
        

        end_array_min_float:

            # return min
            ret
    
    #endif // x86_64 Architecture

    /* ------ RISC-V Architecture ------ */
    #ifdef __riscv

        .global array_min_float
        .type array_min_float, @function


        array_min_float:

            # load zero
            flw     fa0, 0

            # check the indexes
            bgt     a1, a2, end_array_min_float

            # push on stack
            addi    sp, sp, -12
            sw      a0, 0(sp)
            sw      a1, 4(sp)
            sw      a2, 8(sp)

            # call array_is_sorted(array, start, end)
            jal     array_is_sorted_float
            li      t0, 1
            lw      t1, a0

            # pop from stack
            lw      a0, 0(sp)
            lw      a1, 4(sp)
            lw      a2, 8(sp)
            addi    sp, sp, 12

            # array_is_sorted --> min = array[start]
            beq     t0, t1, sorted_array_min_float

            # load start
            slli    a1, a1, 2

            # load end
            slli    a2, a2, 2

            # get min
            flw     fa0, a1(a0)
            addi    a1, a1, 4

            # go to the loop
            j       loop_array_min_float

        
        loop_array_min_float:

            # while (i <= end)
            bgt     a1, a2, end_array_min_float

            # load array[i]
            flw     ft0, a1(a0)

            # i++
            addi    a1, a1, 4

            # array[i] < min --> min = array[i]
            fle.s   t0, fa0, ft0
            bne     t0, zero, loop_array_min_float
            fmv.s   fa0, ft0

            # go to the loop
            j       loop_array_min_float

        
        sorted_array_min_float:

            # min = array[start]
            slli    a1, a1, 2
            flw     fa0, a1(a0)
            ret
        
        end_array_min_float:

            # return min
            ret
    
    #endif // RISC-V Architecture

#endif // FLOAT_TYPE
# array_reverse(): reverse the array

# array_reverse_int()
/* ========================== INT ========================== */
#ifdef INT_TYPE

    /* ------ x86_64 Architecture ------ */
    #ifdef __x86_64__

        .global array_reverse_int
        .type array_reverse_int, @function


        array_reverse_int:

            # check the indexes
            cmp     %rsi, %rdx
            jle     end_array_reverse_int

            # load &array
            mov     %rdi, %r8

            # load start
            mov     %rsi, %r9
            shlq    $2, %r9

            # load end
            mov     %rdx, %r10
            shlq    $2, %r10

            # get the middle
            mov     %r9, %r11
            add     %r10, %r11
            shr     $1, %r11

            # go to the loop
            jmp     loop_array_reverse_int


        loop_array_reverse_int:

            # push on the stack
            push    %r8
            push    %r9
            push    %r10
            push    %r11
           
            # call array_swap_int(&array[i, &array[end - i + start]])
            lea     (%r8, %r9), %rdi
            lea     (%r8, %r10), %rsi
            call     array_swap_int

            # pop from the stack
            pop     %r11
            pop     %r10
            pop     %r9
            pop     %r8

            # i++
            add     $4, %r9

            # j--
            sub     $4, %r10

            # while (i <= middle)
            cmp     %r9, %r11
            jge     loop_array_reverse_int
            ret

        
        end_array_reverse_int:

            # exit
            ret
    
    #endif // x86_64 Architecture

    /* ------ RISC-V Architecture ------ */
    #ifdef __riscv

        .global array_reverse_int
        .type array_reverse_int, @function


        array_reverse_int:

            # check the indexes
            bge     a1, a2, end_array_reverse_int

            # load &array
            mv      t0, a0

            # load start
            slli    t1, a1, 2

            # load end
            slli    t2, a2, 2

            # get the middle
            add     s0, t1, t2
            srai    s0, s0, 1

            # go to the loop
            j       loop_array_reverse_int
        

        loop_array_reverse_int:

            # push on the stack
            addi    sp, sp, -12
            sw      t0, 0(sp)
            sw      t1, 4(sp)
            sw      t2, 8(sp)

            # call array_swap_int(array[i, array[end - i + start]])
            mv      a0, t1
            add     a0, a0, t0
            mv      a1, t2
            add     a1, a1, t0
            jal     array_swap_int

            # pop from the stack
            lw      t0, 0(sp)
            lw      t1, 4(sp)
            lw      t2, 8(sp)
            addi    sp, sp, 12

            # i++
            addi    t1, t1, 4

            # j--
            addi    t2, t2, -4

            # while (i <= middle)
            ble     t1, s0, loop_array_reverse_int
            ret


        end_array_reverse_int:

            # exit
            ret

    #endif // RISC-V Architecture

#endif // INT_TYPE


# array_reverse_float()
/* ========================== FLOAT ========================== */
#ifdef FLOAT_TYPE

    /* ------ x86_64 Architecture ------ */
    #ifdef __x86_64__

        .global array_reverse_float
        .type array_reverse_float, @function


        array_reverse_float:

            # check the indexes
            cmp     %rsi, %rdx
            jle     end_array_reverse_float

            # load &array
            mov     %rdi, %r8

            # load start
            mov     %rsi, %r9
            shlq    $2, %r9

            # load end
            mov     %rdx, %r10
            shlq    $2, %r10

            # get the middle
            mov     %r9, %r11
            add     %r10, %r11
            shr     $1, %r11

            # go to the loop
            jmp     loop_array_reverse_float


        loop_array_reverse_float:

            # push on the stack
            push    %r8
            push    %r9
            push    %r10
            push    %r11

            # call array_swap_float(&array[i, &array[end - i + start]])
            lea     (%r8, %r9), %rdi
            lea     (%r8, %r10), %rsi
            call     array_swap_float

            # pop from the stack
            pop     %r11
            pop     %r10
            pop     %r9
            pop     %r8

            # i++
            add     $4, %r9

            # j--
            sub     $4, %r10

            # while (i <= middle)
            cmp     %r9, %r11
            jge     loop_array_reverse_float
            ret
        

        end_array_reverse_float:
            
            # exit
            ret

    #endif // x86_64 Architecture

    /* ------ RISC-V Architecture ------ */
    #ifdef __riscv

        .global array_reverse_float
        .type array_reverse_float, @function


        array_reverse_float:

            # check the indexes
            bge     a1, a2, end_array_reverse_float

            # load &array
            mv      t0, a0

            # load start
            slli    t1, a1, 2

            # load end
            slli    t2, a2, 2

            # get the middle
            add     s0, t1, t2
            srai    s0, s0, 1

            # go to the loop
            j       loop_array_reverse_float


        loop_array_reverse_float:

            # push on the stack
            addi    sp, sp, -12
            sw      t0, 0(sp)
            sw      t1, 4(sp)
            sw      t2, 8(sp)

            # call array_swap_float(array[i, array[end - i + start]])
            mv      a0, t1
            add     a0, a0, t0
            mv      a1, t2
            add     a1, a1, t0
            jal     array_swap_float

            # pop from the stack
            lw      t0, 0(sp)
            lw      t1, 4(sp)
            lw      t2, 8(sp)
            addi    sp, sp, 12

            # i++
            addi    t1, t1, 4

            # j--
            addi    t2, t2, -4

            # while (i <= middle)
            ble     t1, s0, loop_array_reverse_float
            ret
        

        end_array_reverse_float:

            # exit
            ret
        
    #endif // RISCV-V Architecture

#endif // FLOAT_TYPE
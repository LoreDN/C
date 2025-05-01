# array_fill(): function to fill the array with a value

# array_fill_int()
/* ========================== INT ========================== */
#ifdef INT_TYPE

    /* ------ x86_64 Architecture ------ */
    #ifdef __x86_64__

        .global array_fill_int
        .type array_fill_int, @function


        array_fill_int:

            #check the indexes
            cmp     %rsi, %rdx
            jl      end_array_fill_int

            # load start
            shlq   $2, %rsi

            # load end
            shlq   $2, %rdx

            # go to the loop
            jmp     loop_array_fill_int
        

        loop_array_fill_int:

            # fill array[i] with value
            movl    %ecx, (%rdi, %rsi)

            # i++
            add     $4, %rsi

            # while (i <= end)
            cmp     %rsi, %rdx
            jge     loop_array_fill_int
            ret
        

        end_array_fill_int:

            # exit
            ret


    #endif // x86_64 Architecture

    /* ------ RISC-V Architecture ------ */
    #ifdef __riscv

        .global array_fill_int
        .type array_fill_int, @function


        array_fill_int:

            # check the indexes
            bgt     a1, a2, end_array_fill_int

            # load start
            slli    a1, a1, 2

            # load end
            slli    a2, a2, 2

            # go to the loop
            j       loop_array_fill_int


        loop_array_fill_int:

            # fill array[i] with value
            sw      a3, a1(a0)

            # i++
            addi    a1, a1, 4

            # while (i <= end)
            ble     a1, a2, loop_array_fill_int
            ret

        
        end_array_fill_int:

            # exit
            ret
        
    #endif // RISC-V Architecture

#endif // INT_TYPE


# array_fill_float()
/* ========================= FLOAT ========================= */
#ifdef FLOAT_TYPE

    /* ------ x86_64 Architecture ------ */
    #ifdef __x86_64__

        .global array_fill_float
        .type array_fill_float, @function


        array_fill_float:

            # check the indexes
            cmp     %rsi, %rdx
            jl      end_array_fill_float

            # load start
            shl    $2, %rsi

            # load end
            shl    $2, %rdx

            # go to the loop
            jmp     loop_array_fill_float

        
        loop_array_fill_float:

            # fill array[i] with value
            movss   %xmm0, (%rdi, %rsi)

            # i++
            add     $4, %rsi

            # while (i <= end)
            cmp     %rsi, %rdx
            jge     loop_array_fill_float
            ret
        

        end_array_fill_float:

            # exit
            ret

    #endif // x86_64 Architecture

    /* ------ RISC-V Architecture ------ */
    #ifdef __riscv

        .global array_fill_float
        .type array_fill_float, @function


        array_fill_float:

            # check the indexes
            bgt     a1, a2, end_array_fill_float

            # load start
            slli    a1, a1, 2

            # load end
            slli    a2, a2, 2

            # load value as float
            flw     fa3, 0(a3)

            # go to the loop
            j       loop_array_fill_float
        

        loop_array_fill_float:

            # fill array[i] with value
            fsw     fa3, a1(a0)

            # i++
            addi    a1, a1, 4

            # while (i <= end)
            ble     a1, a2, loop_array_fill_float
            ret
        

        end_array_fill_float:

            # exit
            ret        

    #endif // RISC-V Architecture

#endif // FLOAT_TYPE
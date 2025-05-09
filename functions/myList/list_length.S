/* ---------------------------------------------------------------------------------------------------------------
*
*  size_t list_length(LIST *list);
*
*  get the length of the list
*
--------------------------------------------------------------------------------------------------------------- */


# list_length_int()
/* ========================== INT ========================== */
#ifdef INT_TYPE

    /* ------ x86_64 Architecture ------ */
    #ifdef __x86_64__

        .global list_length_int
        .type list_length_int, @function
        .text


        list_length_int:

            # check the indexes
            xor     %rax, %rax
            cmp     %rdi, %rax
            je      end_list_length_int

            # size_t length = 1
            add     $1, %rax

            # list = list->next
            mov     8(%rdi), %rdi

            # go to the loop
            jmp     loop_list_length_int
        

        loop_list_length_int:

            # while (list != NULL)
            xor     %rbx, %rbx
            cmp     %rdi, %rbx
            je      end_list_length_int

            # length++
            add     $1, %rax
            
            # list = list->next
            mov     8(%rdi), %rdi

            # go to the loop
            jmp     loop_list_length_int
        

        end_list_length_int:

            # return length
            ret
    
    #endif // x86_64 Architecture

    /* ------ RISC-V Architecture ------ */
    #ifdef __riscv

        .global list_length_int
        .type list_length_int, @function
        .text


        list_length_int:

            # check if empty List
            beq     a0, zero, end_list_length_int

            # load list
            mv      t0, a0

            # size_t length = 1
            li      a0, 1

            # list = list->next
            ld      t0, 8(t0)

            # go to the loop
            j       loop_list_length_int

        
        loop_list_length_int:

            # while (list != NULL)
            beq     t0, zero, end_list_length_int

            # length++
            addi a0, a0, 1

            # list = list->next
            ld      t0, 8(t0)

            # go to the loop
            j       loop_list_length_int
        

        end_list_length_int:

            # return length
            ret

    #endif // RISC-V Architecture

#endif // INT_TYPE


# list_length_float()
/* ========================= FLOAT ========================= */
#ifdef FLOAT_TYPE

    /* ------ x86_64 Architecture ------ */
    #ifdef __x86_64__

        .global list_length_float
    .type list_length_float, @function
    .text


    list_length_float:

        # check the indexes
        xor     %rax, %rax
        cmp     %rdi, %rax
        je      end_list_length_float

        # size_t length = 1
        add     $1, %rax

        # list = list->next
        mov     8(%rdi), %rdi

        # go to the loop
        jmp     loop_list_length_float
    

    loop_list_length_float:

        # while (list != NULL)
        xor     %rbx, %rbx
        cmp     %rdi, %rbx
        je      end_list_length_float

        # length++
        add     $1, %rax
        
        # list = list->next
        mov     8(%rdi), %rdi

        # go to the loop
        jmp     loop_list_length_float
    

    end_list_length_float:

        # return length
        ret
    
    #endif // x86_64 Architecture

    /* ------ RISC-V Architecture ------ */
    #ifdef __riscv

        .global list_length_float
        .type list_length_float, @function
        .text


        list_length_float:

            # check if empty List
            beq     a0, zero, end_list_length_float

            # load list
            mv      t0, a0

            # size_t length = 1
            li      a0, 1

            # list = list->next
            ld      t0, 8(t0)

            # go to the loop
            j       loop_list_length_float

    
        loop_list_length_float:

            # while (list != NULL)
            beq     t0, zero, end_list_length_float

            # length++
            addi a0, a0, 1

            # list = list->next
            ld      t0, 8(t0)

            # go to the loop
            j       loop_list_length_float
    

        end_list_length_float:

            # return length
            ret

    #endif // RISC-V Architecture

#endif // FLOAT_TYPE
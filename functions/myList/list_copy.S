/* ---------------------------------------------------------------------------------------------------------------
*
*  LIST *list_copy(LIST *src);
*
*  copy the List from a src
*
--------------------------------------------------------------------------------------------------------------- */


# list_copy_int()
/* ========================== INT ========================== */
#ifdef INT_TYPE

    /* ------ x86_64 Architecture ------ */
    #ifdef __x86_64__

        .global list_copy_int
        .type list_copy_int, @function
        .extern list_add_Node_int
        .text

    
        list_copy_int:

            # check the src
            xor     %rax, %rax
            cmp     %rdi, %rax
            je      end_list_copy_int

            # load %src
            mov     %rdi, %r8

            # push on stack
            push    %r8

            # call LIST *list = list_add_Node_int(src->value)
            mov     (%rdi), %edi
            call    list_add_Node_int

            # pop from stack
            pop     %r8

            # load current_src = src->next
            mov     8(%r8), %rdi

            # load current_list = list
            mov     %rax, %r8

            # go to the loop
            jmp     loop_list_copy_int 

        
        loop_list_copy_int:

            # while (current_src != NULL)
            xor     %r9, %r9
            cmp     %rdi, %r9
            je      end_list_copy_int

            # push on stack
            push    %rdi
            push    %rax
            push    %r8

            # call current_list->next = list_add_Node_int(src->value)
            mov     (%rdi), %rdi
            call    list_add_Node_int
            mov     %rax, %r9

            # pop from stack
            pop     %r8
            pop     %rax
            pop     %rdi

            # current_list->next = list_add_Node_int(src->value)
            mov     %r9, 8(%r8)

            # current_src = current_src->next
            mov     8(%rdi), %rdi

            # current_list = current_list->next
            mov     8(%r8), %r8

            # go to the loop
            jmp     loop_list_copy_int

            
        end_list_copy_int:

            # return list
            ret
    
    #endif // x86_64 Architecture

    /* ------ RISC-V Architecture ------ */
    #ifdef __riscv

        .global list_copy_int
        .type list_copy_int, @function
        .extern list_add_Node_int
        .text


        list_copy_int:

            # check the src
            beq     a0, zero, end_list_copy_int

            # load &src
            mv      t0, a0

            # push on stack
            addi    sp, sp, -16
            sd      t0, 0(sp)
            sd      ra, 8(sp)

            # call LIST *list = list_add_Node_int(src->value)
            lw      a0, 0(a0)
            jal     list_add_Node_int

            # pop from stack
            ld      t0, 0(sp)
            ld      ra, 8(sp)
            addi    sp, sp, 16

            # load current_src = src->next
            ld      t0, 8(t0)

            # load current_list = list
            mv      t1, a0

            # go to the loop
            j       loop_list_copy_int

        
        loop_list_copy_int:

            # while (current_src != NULL)
            beq     t0, zero, end_list_copy_int

            # push on stack
            addi    sp, sp, -32
            sd      a0, 0(sp)
            sd      t0, 8(sp)
            sd      t1, 16(sp)
            sd      ra, 24(sp)

            # call current_list->next = list_add_Node_int(src->value)
            lw      a0, 0(t0)
            jal     list_add_Node_int
            mv      t2, a0

            # pop from stack
            ld      a0, 0(sp)
            ld      t0, 8(sp)
            ld      t1, 16(sp)
            ld      ra, 24(sp)
            addi    sp, sp, 32

            # current_list->next = list_add_Node_int(src->value)
            sd      t2, 8(t1)

            # current_src = current_src->next
            ld      t0, 8(t0)

            # current_list = current_list->next
            mv      t1, t2

            # go to the loop
            j       loop_list_copy_int

        
        end_list_copy_int:

            # return list
            ret        

    #endif // RISC-V Architecture

#endif // INT_TYPE


# list_copy_float()
/* ========================= FLOAT ========================= */
#ifdef FLOAT_TYPE

    /* ------ x86_64 Architecture ------ */
    #ifdef __x86_64__

        .global list_copy_float
        .type list_copy_float, @function
        .extern list_add_Node_float
        .text

        
        list_copy_float:

            # check the src
            xor     %rax, %rax
            cmp     %rdi, %rax
            je      end_list_copy_float

            # load %src
            mov     %rdi, %r8

            # push on stack
            push    %r8

            # call LIST *list = list_add_Node_float(src->value)
            movss   (%rdi), %xmm0
            call    list_add_Node_float

            # pop from stack
            pop     %r8

            # load current_src = src->next
            mov     8(%r8), %rdi

            # load current_list = list
            mov     %rax, %r8

            # go to the loop
            jmp     loop_list_copy_float 

        
        loop_list_copy_float:

            # while (current_src != NULL)
            xor     %r9, %r9
            cmp     %rdi, %r9
            je      end_list_copy_float

            # push on stack
            push    %rdi
            push    %rax
            push    %r8

            # call current_list->next = list_add_Node_float(src->value)
            movss   (%rdi), %xmm0
            call    list_add_Node_float
            mov     %rax, %r9

            # pop from stack
            pop     %r8
            pop     %rax
            pop     %rdi

            # current_list->next = list_add_Node_float(src->value)
            mov     %r9, 8(%r8)

            # current_src = current_src->next
            mov     8(%rdi), %rdi

            # current_list = current_list->next
            mov     8(%r8), %r8

            # go to the loop
            jmp     loop_list_copy_float

            
        end_list_copy_float:

            # return list
            ret
    
    #endif // x86_64 Architecture

    /* ------ RISC-V Architecture ------ */
    #ifdef __riscv

        .global list_copy_float
        .type list_copy_float, @function
        .extern list_add_Node_float
        .text


        list_copy_float:

            # check the src
            beq     a0, zero, end_list_copy_float

            # load &src
            mv      t0, a0

            # push on stack
            addi    sp, sp, -16
            sd      t0, 0(sp)
            sd      ra, 8(sp)

            # call LIST *list = list_add_Node_float(src->value)
            flw     fa0, 0(a0)
            jal     list_add_Node_float

            # pop from stack
            ld      t0, 0(sp)
            ld      ra, 8(sp)
            addi    sp, sp, 16

            # load current_src = src->next
            ld      t0, 8(t0)

            # load current_list = list
            mv      t1, a0

            # go to the loop
            j       loop_list_copy_float

        
        loop_list_copy_float:

            # while (current_src != NULL)
            beq     t0, zero, end_list_copy_float

            # push on stack
            addi    sp, sp, -32
            sd      a0, 0(sp)
            sd      t0, 8(sp)
            sd      t1, 16(sp)
            sd      ra, 24(sp)

            # call current_list->next = list_add_Node_float(src->value)
            flw     fa0, 0(t0)
            jal     list_add_Node_float
            mv      t2, a0

            # pop from stack
            ld      a0, 0(sp)
            ld      t0, 8(sp)
            ld      t1, 16(sp)
            ld      ra, 24(sp)
            addi    sp, sp, 32

            # current_list->next = list_add_Node_float(src->value)
            sd      t2, 8(t1)

            # current_src = current_src->next
            ld      t0, 8(t0)

            # current_list = current_list->next
            mv      t1, t2

            # go to the loop
            j       loop_list_copy_float

        
        end_list_copy_float:

            # return list
            ret   

    #endif // RISC-V Architecture

#endif // FLOAT_TYPE
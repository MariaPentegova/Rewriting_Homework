    .global sort
    .type sort, @function

sort:
    push %rbp
    mov %rsp, %rbp

    mov %rsi, %rcx        
    cmp $1, %rcx
    jle end               

    mov $0, %rdx         

    xor %r8, %r8          
outer_loop:
    cmp %r8, %rcx
    jge end_outer

    xor %r9, %r9          
inner_loop:
    mov %r8, %rax
    inc %rax             
    cmp %rax, %rcx
    jge end_inner

    mov %rdi, %r10        
    mov %r9, %r11
    shl $2, %r11          
    mov (%r10,%r11), %r12 
    mov %r9, %r13
    shl $2, %r13
    lea 4(%r10,%r13), %r14 
    mov (%r14), %r15    

    cmp %r15, %r12
    JGE skip_swap       
    mov %r15, (%r10,%r11)
    mov %r12, (%r14)

    inc %rdx

skip_swap:
    inc %r9
    jmp inner_loop

end_inner:
    inc %r8
    jmp outer_loop

end_outer:
    mov %rdx, %rax

end:
    pop %rbp
    ret

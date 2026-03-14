global ft_list_sort

section .text

ft_list_sort:
    push rbx
    push r12
    push r13
    push r14

    mov r12, rdi            
    mov r13, rsi            

    cmp r12, 0
    je end

    mov rax, [r12]
    cmp rax, 0
    je end

outer_loop:
    xor r14, r14            
    mov rbx, [r12]          

inner_loop:
    mov rax, [rbx + 8]      
    cmp rax, 0
    je check_done

    mov rdi, [rbx]          
    mov rsi, [rax]          

    call r13                

    cmp eax, 0
    jle no_swap

    mov rdi, [rbx]          
    mov rax, [rbx + 8]      
    mov rsi, [rax]          
    mov [rbx], rsi          
    mov [rax], rdi          
    mov r14, 1              

no_swap:
    mov rbx, [rbx + 8]      
    jmp inner_loop

check_done:
    cmp r14, 1
    je outer_loop

end:
    pop r14
    pop r13
    pop r12
    pop rbx
    ret
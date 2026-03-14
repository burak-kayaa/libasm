global ft_list_remove_if

extern free

section .text

ft_list_remove_if:
    push rbx
    push r12
    push r13
    push r14
    push r15

    mov r12, rdi            
    mov r13, rsi            
    mov r14, rdx            
    mov r15, rcx            

    cmp r12, 0
    je end

head_loop:
    mov rax, [r12]          
    cmp rax, 0
    je end

    mov rdi, [rax]          
    mov rsi, r13            
    call r14
    cmp eax, 0
    jne start_main_loop

    mov rbx, [r12]          
    mov rax, [rbx + 8]      
    mov [r12], rax          

    mov rdi, [rbx]          
    call r15

    mov rdi, rbx            
    call free wrt ..plt
    jmp head_loop

start_main_loop:
    mov rbx, [r12]          

main_loop:
    cmp rbx, 0
    je end

    mov rax, [rbx + 8]      
    cmp rax, 0
    je end

    mov rdi, [rax]          
    mov rsi, r13            
    call r14
    cmp eax, 0
    jne no_remove

    mov rax, [rbx + 8]      
    mov rdx, [rax + 8]      
    mov [rbx + 8], rdx      

    push rax                
    mov rdi, [rax]          
    call r15
    pop rax                 

    mov rdi, rax            
    call free wrt ..plt
    jmp main_loop

no_remove:
    mov rbx, [rbx + 8]      
    jmp main_loop

end:
    pop r15
    pop r14
    pop r13
    pop r12
    pop rbx
    ret
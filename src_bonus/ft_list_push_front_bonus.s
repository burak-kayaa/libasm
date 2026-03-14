global ft_list_push_front
extern malloc

section .text

ft_list_push_front:
    push rdi
    push rsi

    mov rdi, 16
    call malloc wrt ..plt

    cmp rax, 0
    je error

    pop rsi
    pop rdi

    mov [rax], rsi
    mov rdx, [rdi]
    mov [rax + 8], rdx
    mov [rdi], rax
    ret

error:
    pop rsi
    pop rdi
    ret
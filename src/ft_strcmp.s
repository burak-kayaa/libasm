global ft_strcmp

section .text

ft_strcmp:
loop:
    mov al, [rdi]
    mov bl, [rsi]

    cmp al, bl
    jne diff

    cmp al, 0
    je equal

    inc rdi
    inc rsi
    jmp loop


diff:
    movzx rax, al
    movzx rbx, bl
    sub rax, rbx
    ret

equal:
    xor rax, rax
    ret
global ft_atoi_base

section .text

ft_atoi_base:
    push rbx
    push r12
    push r13

    mov r12, rdi                
    mov r13, rsi                

    xor r10, r10

validate_base:
    mov bl, [r13 + r10]
    cmp bl, 0
    je base_done

    cmp bl, '+'
    je invalid

    cmp bl, '-'
    je invalid

    cmp bl, 32
    je invalid
    cmp bl, 9
    jb check_duplicates
    cmp bl, 13
    jbe invalid

check_duplicates:
    mov rcx, r10
    inc rcx

dup_loop:
    mov dl, [r13 + rcx]
    cmp dl, 0
    je next_base_char
    cmp dl, bl
    je invalid
    inc rcx
    jmp dup_loop

next_base_char:
    inc r10
    jmp validate_base

base_done:
    cmp r10, 2
    jb invalid

skip_ws:
    mov bl, [r12]
    cmp bl, 32
    je ws_advance
    cmp bl, 9
    jb sign_init
    cmp bl, 13
    jbe ws_advance
    jmp sign_init

ws_advance:
    inc r12
    jmp skip_ws

sign_init:
    mov r11, 1                  

sign_loop:
    mov bl, [r12]
    cmp bl, '+'
    je sign_plus
    cmp bl, '-'
    je sign_minus
    jmp parse_init

sign_plus:
    inc r12
    jmp sign_loop

sign_minus:
    neg r11                     
    inc r12
    jmp sign_loop

parse_init:
    xor rax, rax

parse_loop:
    mov bl, [r12]
    cmp bl, 0
    je apply_sign

    xor rcx, rcx                

find_in_base:
    mov dl, [r13 + rcx]
    cmp dl, 0
    je apply_sign               
    cmp dl, bl
    je digit_found
    inc rcx
    jmp find_in_base

digit_found:
    imul rax, r10               
    add rax, rcx                
    inc r12
    jmp parse_loop

apply_sign:
    cmp r11, 1
    je done
    neg rax
    jmp done

invalid:
    xor rax, rax

done:
    pop r13
    pop r12
    pop rbx
    ret
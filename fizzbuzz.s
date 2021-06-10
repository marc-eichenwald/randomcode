;;fizzbuzz in asm
;;runs the standard fizzbuzz not debugged yet wip
BITS 64
extern _printf
%define printf _printf

section .text
.start:
    push rbp
    xor rcx, rcx ;; i stored here
loop1:
    lea rcx, [rcx+1] ;; i++
fizzbuzzcheck:
    lea rax, [rcx] ;; loads i for the divide
    xor rdx, rdx
    lea rdi, [3]
    div rdi
    cmp rdx, 0 ;; mod 3 check
    jnz buzzcheck
    lea rax, [rcx]
    xor rdx, rdx
    lea rdi, [5]
    div rdi
    cmp rdx, 0 ;; mod 5 check
    jnz printfizz ;; if it passed the mod 3 but fails the mod 5 you can jump straight to printing fizz
    mov rdi, fizzbuzz ;; print fizzbuzz
    xor eax, eax
    call printf
    jmp loopend
printfizz:    
    mov rdi, fizz
    xor eax, eax
    call printf
    jmp loopend
buzzcheck:
    lea rax, [rcx]
    xor rdx, rdx
    lea rdi, [5]
    div rdi
    cmp rdx, 0
    jnz nope
    mov rdi, buzz
    xor eax, eax
    call printf
    jmp loopend
nope:
    mov rdi, nofizzbuzz
    lea rsi, [rcx]
    xor eax, eax
    call printf
loopend:
    cmp rcx, 100
    jnz loop1
cleanup:
    pop rbp
    ret


section .data
fizz    db 'fizz\n'
buzz    db 'buzz\n'
fizzbuzz db 'fizzbuzz\n'
nofizzbuzz db "%d\n"

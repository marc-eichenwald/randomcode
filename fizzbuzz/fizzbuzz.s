	;;fizzbuzz in asm
	;;runs the standard fizzbuzz not debugged yet wip
	BITS 64
	global _start
	extern printf
	;; %define printf printf

	section .text
_start:	push rbp
	mov rbp, rsp
	lea rsp, [rsp-24]
	xor rcx, rcx ;; i stored here
loop1:	lea rcx, [rcx+1] ;; i++
	mov QWORD [rbp], rcx
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
	lea	 rdi, [rel fizzbuzz] ;; print fizzbuzz
	xor rax, rax
	call printf
	jmp loopend
	printfizz:	lea rdi, [rel fizz]
	xor rax, rax
	call printf
	jmp loopend
buzzcheck:	lea rax, [rcx]
	xor rdx, rdx
	lea rdi, [5]
	div rdi
	cmp rdx, 0
	jnz nope
	lea rdi, [rel buzz]
	xor rax, rax
	call printf
	jmp loopend
nope:lea rdi, [rel nofizzbuzz]
	lea rsi, [rcx]
	xor rax, rax
	call printf
loopend:mov rcx, QWORD[rbp]
	cmp rcx, 100
	jne loop1
	lea rsp, [rsp+24]
cleanup:	pop rbp
	mov rax, 1
	 int 0x80
section .data
	fizz    db 'fizz', 10, 0
	buzz    db 'buzz', 10, 0
	fizzbuzz db 'fizzbuzz', 10, 0
	nofizzbuzz db '%d', 10, 0

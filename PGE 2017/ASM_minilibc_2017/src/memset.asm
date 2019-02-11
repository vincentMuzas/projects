BITS 64

section .text

[GLOBAL memset:]
memset:
	push rbp	;prologue
	mov rbp, rsp	;prologue
	mov rax, rdi	;set la valeur de retour au premier param
	mov r8d, 0h	;set un compteur a 0
	jmp strloop

change:
	mov [rdi], esi	;set la valeur
	inc r8d		;incrementer le compteur
	inc rdi		;incrémenter le pointeur

strloop:
	cmp r8d, edx	;on est a la fin?
	jne change
	leave		;fin
	ret
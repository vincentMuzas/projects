BITS 64

SECTION .text

[GLOBAL memmove:]
memmove:
	push rbp	;prologue
	mov rbp, rsp	;prologue
	mov r8, rdi	;premier arg
	mov r9, rsi	;deuxieme arg
	mov r10w, dx	;troisieme arg
	mov r11w, 0h	;compteur
	jmp strloop

end:
	mov rax, rdi
	leave
	ret

strloop:
	cmp r10w, r11w	;fin?
		je end
	inc r11w	;incrementer compteur
	mov byte [r8], r9b
	inc r8		;next
	inc r9		;next
	jmp strloop
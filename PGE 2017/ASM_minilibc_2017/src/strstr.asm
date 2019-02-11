BITS 64

SECTION .text

[GLOBAL strstr:]
strstr:
	push rbp	;prologue
	mov rbp, rsp	;prologue
	mov r10, 0h	;compteur position 1ere str
	mov r8, rdi	;copie du premier arg
	mov r9, rsi	;copie du deuxieme arg
	jmp strloop

incr:
	inc r8		;lettre suivante
	inc r9		;lettre suivante
	jmp strloop

exit_found:
	mov rax, r8	;return(ptr)
	leave
	ret

exit_not_found:
	mov rax, 0h	;return(null)
	leave
	ret

strloop:
	cmp byte [r8], r9b
		je incr
	inc r10				;incrementer le compteur pour lettre suivente
	cmp byte [r9], 0h		;si c'est la fin du deuxieme arg
		je exit_found		;exit la func
	cmp byte [r8], 0h		;si c'est la fin du premier arg
		je exit_not_found	;exit la fonction
	;si diférent et pas la fin
	mov r9, rsi			;reset deuxieme arg
	mov r8, rdi			;reset au premier arg
	add r8, r10			;retourner la ou on en etait
	jmp strloop			;loop
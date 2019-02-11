BITS 64

SECTION .text

[GLOBAL strcspn:]
strcspn:
	push rbp	;prologue
	mov rbp, rsp	;prologue
	mov r8, rdi	;premier arg
	mov r9, rsi	;deuxieme arg
	mov rax, 0h	;valeur de retour qui set de compteur
	jmp strloop

exit:
	leave
	ret

reject_test:
	mov bl, byte [r8]	;fix tricky
	cmp bl, byte[rsi]	;comparer char
		je exit
	cmp byte [rsi], 0h	;si fin str2
		je next
	inc rsi			;char suivant
	jmp reject_test		;boucle

next:	
	inc rax		;retour += 1
	inc r8		;char suivant
	cmp byte [r8], 0h
		je exit

strloop:
	mov rsi, r9	;reset reject str
	jmp reject_test

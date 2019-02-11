BITS 64

SECTION .text

[GLOBAL strchr:]
strchr:
	push rbp	;prologue
	mov rbp, rsp	;prologue
	mov rax, 0h	;mise a 0 de rax (registre de return)
	jmp strloop
incr:
	cmp byte [rdi], 0h 	;si c'est la fin
	je exit0
	inc rdi		;caractère suivant
	jmp strloop	;revenir sur boucle principale
exit0:
	mov rax, 0h	;valeur de retour
	leave		;fin
	ret
strloop:
	cmp byte [rdi], sil	;tant que le caractère n'est pas celui passé
	jne incr		;si c'est pas rsi (deuxieme parametre), jump a incr
	mov rax, rdi
	leave
	ret

BITS 64

SECTION .text

[GLOBAL strlen:]
strlen:
	push rbp	;prologue
	mov rbp, rsp	;prologue
	mov rax, 0	;mise a 0 de rax (registre de return)
	jmp strloop
prelen:
	inc rax	;incrementation du conteur
	inc rdi	;caractère suivant
strloop:
	cmp byte [rdi], 0h	;tand que le caractère sur lequel on se trouve n'est pas un \0
	jne prelen		;si se n'est pas un \0 alors on jump
	leave	;fin
	ret
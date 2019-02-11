BITS 64

SECTION .text

[GLOBAL rindex:]
rindex:
	push rbp	;prologue
	mov rbp, rsp	;prologue
	mov rax, 0h	;mise a 0 de rax (registre de return)
	jmp strloop
exit:
	mov rax, rdi
	leave
	ret
prelen:
	inc rax	;incrementation du conteur
	inc rdi	;caractère suivant
strloop:
	cmp byte [rdi], sil
	je exit
	cmp byte [rdi], 0h	;tand que le caractère sur lequel on se trouve n'est pas un \0
	jne prelen		;si se n'est pas un \0 alors on jump
	leave	;fin
	ret
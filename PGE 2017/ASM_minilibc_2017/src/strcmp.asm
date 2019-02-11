BITS 64

SECTION .text

[GLOBAL mystrcmp:]
mystrcmp:
	push rbp	;prologue
	mov rbp, rsp	;prologue
	jmp strloop


end_zero:
	mov rax, 0h
	jmp end

end_sup:
	mov rax, 1h
	jmp end

end_minus:
	mov rax, -1h
	jmp end

end:
	leave
	ret

strloop:
	cmp byte [rdi], sil
		jne end_sup
	cmp byte [rdi], 0h
		jne end_zero
	inc rdi
	inc rsi
	jmp strloop
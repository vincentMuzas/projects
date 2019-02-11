SRC	=	src/strlen.asm	\
		src/strchr.asm	\
		src/memset.asm	\
		src/strstr.asm	\
		src/memmove.asm	\
		src/memcpy.asm	\
		src/strcspn.asm	\
		src/strpbrk.asm	\
		src/rindex.asm	\
		src/strcmp.asm	\
#		src/strncmp.asm	\
		src/strcasecmp.asm

OBJ	=	$(SRC:.asm=.o)

NAME	=	libasm.so

%.o:	%.asm
	nasm -f elf64 $<

all: $(NAME)

$(NAME): $(OBJ)
	ld -shared -o $@ $^
	gcc test.c -L. -lasm
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) a.out

re: fclean all
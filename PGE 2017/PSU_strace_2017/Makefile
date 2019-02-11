##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/strace.c	\
		src/info.c	\
		src/proces.c

OBJ	=	$(SRC:.c=.o)

NAME	=	strace

CFLAGS	=	-Iincludes -W -Wextra -Wall -Werror

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
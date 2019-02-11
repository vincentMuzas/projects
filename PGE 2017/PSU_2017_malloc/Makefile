##
## EPITECH PROJECT, 2018
## malloc
## File description:
## Makefile
##

SRC	=	src/malloc.c	\
		src/geters.c	\
		src/utils.c	\
		src/bestfit.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Werror -Wextra -fpic -Iincludes

LIB	=	-shared -o

NAME	=	libmy_malloc.so

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(LIB) $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
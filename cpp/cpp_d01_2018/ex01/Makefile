##
## EPITECH PROJECT, 2019
## cpp_d01_2018
## File description:
## Makefile
##


SRC	=	main.c	\
		menger.c

OBJ	=	$(SRC:.c=.o)

NAME	=	menger

all: $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -std=gnu11 -Wall -Wextra

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

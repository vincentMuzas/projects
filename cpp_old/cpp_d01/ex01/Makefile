##
## EPITECH PROJECT, 2018
## menger
## File description:
## 
##


SRC	=	main.c	\
		menger.c

OBJ	=	$(SRC:.c=.o)

NAME	=	menger

all: $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -W -Wall -Wextra -Werror

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

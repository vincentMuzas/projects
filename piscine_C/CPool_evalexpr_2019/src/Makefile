##
## EPITECH PROJECT, 2019
## CPool_evalexpr_2019
## File description:
## Makefile
##

NAME	=	eval_expr

SRC	=	main.c \
		eval_expr.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Iinclude -W -Wall -Werror -Wextra
LFLAGS	=	-L../lib/my -lmy

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $@ $^ $(LFLAGS)
	cp $@ ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all

.PHONY: all re clean fclean

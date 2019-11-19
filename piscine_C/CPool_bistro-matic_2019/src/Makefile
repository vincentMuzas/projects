##
## EPITECH PROJECT, 2019
## CPool_finalstumper_2019
## File description:
## Makefile
##

NAME	=	calc

SRC	=	add_inf.c		\
		eval_expr.c		\
		eval_main.c		\
		main.c			\
		mod_inf.c		\
		mul_inf.c		\
		sub_inf.c		\
		div_inf.c		\
		choice_add.c 	\
		choice_mul.c	\
		choice_sub.c	\
		choice_div.c	\
		choice_mod.c	\
		transform.c		\
		errors.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Iinclude -W -Wall -Wextra -g3
LDFLAGS	=	-L../lib/my -lmy

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $@ $^ $(LDFLAGS)
	cp $@ ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all

.PHONY: all clean fclean re rush3

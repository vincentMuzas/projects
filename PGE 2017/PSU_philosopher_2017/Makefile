##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/things.c	\
		src/check.c

OBJ	=	$(SRC:.c=.o)

NAME	=	philo

CFLAGS	=	-L. -lriceferee -lpthread -Iinclude

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
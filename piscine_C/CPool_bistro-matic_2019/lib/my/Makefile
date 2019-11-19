##
## EPITECH PROJECT, 2019
## CPool_bistro-matic_2019
## File description:
## Makefile
##

NAME	=	libmy.a

SRC	=	my_compute_power_rec.c		\
		my_compute_square_root.c	\
		my_find_prime_sup.c			\
		my_getnbr.c					\
		my_is_prime.c				\
		my_isneg.c					\
		my_put_nbr.c				\
		my_putchar.c				\
		my_putstr.c					\
		my_revstr.c					\
		my_show_word_array.c		\
		my_showmem.c				\
		my_showstr.c				\
		my_sort_int_array.c			\
		my_str_isalpha.c			\
		my_str_islower.c			\
		my_str_isnum.c				\
		my_str_isprintable.c		\
		my_str_isupper.c			\
		my_str_to_word_array.c		\
		my_strcapitalize.c			\
		my_strcat.c					\
		my_strcmp.c					\
		my_strcpy.c					\
		my_strlen.c					\
		my_strlowcase.c				\
		my_strncat.c				\
		my_strncmp.c				\
		my_strncpy.c				\
		my_strstr.c					\
		my_strupcase.c				\
		my_swap.c					\
		my_strdup.c					\
		my_del_at_start_of_str.c	\
		my_append_str.c

OBJ	= $(SRC:.c=.o)

CFLAGS = -I
CFLAGS += -W -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^
	cp $@ ../
	cp my.h ../../include

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)
	rm -f ../../include/my.h

re: fclean all

.PHONY: all clean fclean re

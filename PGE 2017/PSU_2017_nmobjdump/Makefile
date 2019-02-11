##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## nm/objdump
##

NAME	= my_objdump

NAME2	= my_nm

CC	= gcc

RM	= rm -f

SRCS	=	./main.c 	\
		./flags64.c	\
		./flags32.c	\
		./section64.c	\
		./section32.c	\

SRCS2	= ./nm.c	\

OBJS	= $(SRCS:.c=.o)
OBJS2	= $(SRCS2:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -W -Wall -Wextra

all: $(NAME) $(NAME2)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

$(NAME2): $(OBJS2)
	  $(CC) $(OBJS2) -o $(NAME2) $(LDFLAGS)

clean:
	$(RM) $(OBJS) $(OBJS2)

fclean: clean
	$(RM) $(NAME) $(NAME2)

re: fclean all

.PHONY: all clean fclean re

##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## makefile
##

NAME	= ../rush3

CC	= gcc

RM	= rm -f

SRCS	= ./main.c \
	  ./detect.c \
	  ./detect2.c \
	  ./detect3.c \
	  ./detect4.c \
	  ./detect5.c \
	  ./size.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -Iinclude -L../lib/my -lmy
CFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

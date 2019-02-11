NAME	= libstring.a

CC	= gcc

RM	= rm -f

SRCS	=	./ex00.c 	\
			./ex01.c	\
			./ex02.c	\
			./ex03.c	\
			./ex04-07.c	\
			./ex08-10.c	\
			./utils.c	\
			

OBJS	= $(SRCS:.c=.o)

CFLAGS = -std=gnu11 -W -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 ar crs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

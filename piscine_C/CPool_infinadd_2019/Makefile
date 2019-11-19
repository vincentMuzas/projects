NAME	= infin_add

CC	= gcc

RM	= rm -f

SRCS	= ./src/main.c \
		  ./src/infin_add.c \
		  ./src/trim_spaces.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -Iinclude -L./lib/my -lmy
CFLAGS += -W -Wall -Wextra -g3

all: $(NAME)

$(NAME): $(OBJS)
	 $(MAKE) -C lib/my
	 $(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C lib/my clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C lib/my fclean

re: fclean all

.PHONY: all clean fclean re

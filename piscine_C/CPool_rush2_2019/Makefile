NAME	= rush2

CC	= gcc

RM	= rm -f

SRCS	= rush.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -Iinclude/ -L./lib/my -lmy
CFLAGS += -W -Wall -Wextra

LIBSRC = ./lib/my

all: 
	 $(MAKE) -C $(LIBSRC)
	 $(MAKE) $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBSRC) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBSRC) fclean

re: fclean all

.PHONY: all clean fclean re

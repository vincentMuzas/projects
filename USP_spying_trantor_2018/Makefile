NAME	= drone_RC

CC	= gcc

RM	= rm -f

SRCS	= ./gnl.c \
	  ./main.c \
	  ./utils.c 

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./
CFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

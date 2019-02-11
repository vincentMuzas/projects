NAME	= program

CC	= gcc

RM	= rm -f

SRCS	= ./bitmap_header.c \
	  ./bmp.c \
	  ./drawing.c \
	  ./main.c \
	  ./menger.c \
	  ./utils.c 

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./
CFLAGS += -W -Wall -Wextra -g3

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

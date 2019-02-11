NAME	= trantor_v1

CC	= gcc

RM	= rm -f

SRCS	= ./src/utils.c \
		./src/gnl.c \
		./src/main.c \
		./src/map.c \
		./src/drone.c \
		./src/int_handler.c \
		./src/commands.c \
		./src/look.c \
		./src/look_utils.c \
		./src/inventory.c \
		./src/my_str_to_wordtab.c \
		./src/drop.c \
		./src/take.c


OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -lpthread -W -Wall -Wextra -g3
THREADFLAGS = -fsanitize=thread

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(CFLAGS) 

thread: $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(THREADFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all thread clean fclean re

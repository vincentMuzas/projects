NAME	= santa

CC	= g++

RM	= rm -f

SRCS	= ./santa.cpp 

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I 
CPPFLAGS += -W -Wall -Wextra -std=c++14

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

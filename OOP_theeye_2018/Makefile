NAME	= the_eye

CC	= g++

RM	= rm -f

SRCS	= ./src/Observer.cpp \
	  ./src/Socket.cpp \
	  ./src/Case.cpp \
	  ./src/Object.cpp \
	  ./src/Player.cpp \
	  ./src/main.cpp 

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -Iincludes
CPPFLAGS += -W -Wall -Wextra -g3

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -lsfml-window -lsfml-graphics -lsfml-system

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

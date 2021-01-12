NAME	= abstractVM

CC	= g++

RM	= rm -f

SRCS	= ./src/BigDecimal.cpp	\
		./src/Chipset.cpp		\
		./src/CPU.cpp			\
		./src/Double.cpp		\
		./src/Factory.cpp		\
		./src/Float.cpp			\
		./src/IO.cpp			\
		./src/Int8.cpp			\
		./src/Int16.cpp			\
		./src/Int32.cpp			\
		./src/main.cpp			\
		./src/Memory.cpp		\
		./src/Operand.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./include -std=c++17
CPPFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

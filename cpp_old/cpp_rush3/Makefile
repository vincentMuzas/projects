##
## EPITECH PROJECT, 2018
## cpp_rush3
## File description:
## Makefile
##

CPPFLAGS = -W -Wall -Wextra -Werror -std=c++14

RM	= rm -f

NAME	= my_gkrellm

SRCS	= ./src/main.cpp \
	./src/NC_elem.cpp \
	./src/NC_display.cpp \
	./src/cpuInfo.cpp \
	./src/ModuleContainer.cpp \
	./src/ModuleContainer2.cpp \
	./src/MonitorModule.cpp 

OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	g++ $(CPPFLAGS) $(OBJS) -lncurses -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

##
## EPITECH PROJECT, 2019
## cpp_rush2_2018
## File description:
## Makefile
##

NAME	= workshop

CC	= g++

RM	= rm -f

SRCS	=	src/Box.cpp \
			src/ConveyorBeltRand.cpp \
			src/GiftDatas.cpp \
			src/GiftPaper.cpp \
			src/LittlePony.cpp \
			src/Object.cpp \
			src/PapaXmasConveyorBelt.cpp \
			src/PapaXmasElf.cpp \
			src/PapaXmasTable.cpp \
			src/Random.cpp \
			src/TableRand.cpp \
			src/Teddy.cpp \
			src/Tests.cpp \
			src/Toy.cpp \
			src/Wrap.cpp \
			src/main.cpp 

OBJS	= $(SRCS:.cpp=.o)

NAME_TESTS	=	unit_tests

SRC_TEST	=	test/Test01.cpp

LDFLAGS_TEST	=	-lcriterion -lgcov --coverage

CPPFLAGS = -I
CPPFLAGS += -W -Wall -Wextra -std=c++14

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

tests_run:
	$(CC) -o $(NAME_TESTS) $(SRCS) $(SRCS_TEST) $(CFLAGS) $(LDFLAGS_TEST)
	./$(NAME_TESTS) -j0 --always-succeed

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(NAME_TESTS) *.o *.gcda *.gcno *.xml unit_tests

re: fclean all

.PHONY: all clean fclean re 
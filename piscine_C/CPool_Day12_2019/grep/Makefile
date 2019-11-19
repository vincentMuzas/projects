NAME	= grep

CC	= gcc

RM	= rm -f

SRCS	=	./grep.c	\
			./gnl.c		\
			./my_strstr.c
NO_TEST_SRC = ./main.c

OBJS	= $(SRCS:.c=.o)
OBJS	+= $(NO_TEST_SRC:.c=.o)

CFLAGS = -Iincludes
CFLAGS += -W -Wall -Wextra

TESTNAME = test_grep
TESTSRCS = ../tests/test_grep.c
TESTFLAGS = --coverage -lcriterion


all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS) *.gcda *.gcno

fclean: clean
	$(RM) $(NAME) $(TESTNAME)

re: fclean all

tests_run:
	$(CC) -o $(TESTNAME) $(SRCS) $(TESTSRCS) $(TESTFLAGS) $(CFLAGS)
	./$(TESTNAME)

.PHONY: all clean fclean re

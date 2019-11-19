NAME	= cat

CC	= gcc

RM	= rm -f

SRCS	= cat.c
NO_TEST_SRCS = main.c

TESTSRC	= ../tests/test_cat.c

OBJS	= $(SRCS:.c=.o)
OBJS	+= $(NO_TEST_SRCS:.c=.o)

CFLAGS = -I 
CFLAGS += -W -Wall -Wextra

TESTFLAGS = --coverage -lcriterion
TESTNAME = test_cat

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS) $(TESTSRC:.c=.o) *.gcda *.gcno

fclean: clean
	$(RM) $(NAME) $(TESTNAME)

re: fclean all

tests_run:
	$(CC) -o $(TESTNAME) $(SRCS) $(TESTSRC) $(TESTFLAGS)
	./$(TESTNAME)

.PHONY: all clean fclean re

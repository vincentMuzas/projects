NAME	= workshop

CC	= g++

RM	= rm -f

SRCS	= ./Box.cpp \
	  ./ConveyorBeltRand.cpp \
	  ./GiftDatas.cpp \
	  ./GiftPaper.cpp \
	  ./LittlePony.cpp \
	  ./Object.cpp \
	  ./PapaXmasConveyorBelt.cpp \
	  ./PapaXmasElf.cpp \
	  ./PapaXmasTable.cpp \
	  ./Random.cpp \
	  ./TableRand.cpp \
	  ./Teddy.cpp \
	  ./Tests.cpp \
	  ./Toy.cpp \
	  ./Wrap.cpp \
	  ./main.cpp 

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

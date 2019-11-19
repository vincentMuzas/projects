CC	= gcc

RM	= rm -f

LIBPATH = ./
LIBSRCS	= my_put_nbr.c \
	  my_putchar.c \
	  my_putstr.c \
	  my_strlen.c \
	  my_strloccase.c \
	  my_strcpy.c

LIBSRCS := $(addprefix $(LIBPATH)/, $(LIBSRCS))
LIB	=	lib

LIBOBJS = $(LIBSRCS:.c=.o)
OBJS_TASK02	= $(SRCS_TASK02:.c=.o)

CFLAGS = -I./include -L$(LIBPATH) -lmy
CFLAGS += -W -Wall -Wextra

all: $(LIB)
	 
$(LIB): $(LIBOBJS)
	 ar rcs $(LIBPATH)/libmy.a $(LIBOBJS)

clean:
	$(RM) $(LIBOBJS)

fclean: clean
	$(RM) $(LIBPATH)/libmy.a

re: fclean all

.PHONY: all clean fclean re lib
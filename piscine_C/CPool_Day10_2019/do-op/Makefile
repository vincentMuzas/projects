NAME_TASK02	= do-op

CC	= gcc

RM	= rm -f

SRCS_TASK02 = do_op.c

LIBPATH = ../lib/my
LIBSRCS	= my_compute_power_rec.c \
	  my_compute_square_root.c \
	  my_find_prime_sup.c \
	  my_getnbr.c \
	  my_is_prime.c \
	  my_isneg.c \
	  my_put_nbr.c \
	  my_putchar.c \
	  my_putstr.c \
	  my_revstr.c \
	  my_show_word_array.c \
	  my_sort_int_array.c \
	  my_str_isalpha.c \
	  my_str_islower.c \
	  my_str_isnum.c \
	  my_str_isprintable.c \
	  my_str_isupper.c \
	  my_str_to_word_array.c \
	  my_strcapitalize.c \
	  my_strcat.c \
	  my_strcmp.c \
	  my_strcpy.c \
	  my_strdup.c \
	  my_strlen.c \
	  my_strloccase.c \
	  my_strncat.c \
	  my_strncmp.c \
	  my_strncpy.c \
	  my_strstr.c \
	  my_strupcase.c \
	  my_swap.c 
LIBSRCS := $(addprefix $(LIBPATH)/, $(LIBSRCS))
LIB	=	lib

LIBOBJS = $(LIBSRCS:.c=.o)
OBJS_TASK02	= $(SRCS_TASK02:.c=.o)

CFLAGS = -Iinclude -L$(LIBPATH) -lmy
CFLAGS += -W -Wall -Wextra

all: $(LIB) $(NAME_TASK02)
	 
$(LIB): $(LIBOBJS)
	 ar rcs $(LIBPATH)/libmy.a $(LIBOBJS)

$(NAME_TASK02): $(OBJS_TASK02)
	 $(CC) $(OBJS_TASK02) -o $(NAME_TASK02) $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJS_TASK02)
	$(RM) $(LIBOBJS)

fclean: clean
	$(RM) $(NAME_TASK02)
	$(RM) $(LIBPATH)/libmy.a

re: fclean all

.PHONY: all clean fclean re lib $(NAME_TASK02)
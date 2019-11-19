CC	= gcc

RM	= rm -f

LIBNAME = libbtree.a
LIBSRCS	= btree_apply_infix.c \
	  btree_apply_prefix.c \
	  btree_apply_sufix.c \
	  btree_create_node.c \
	  btree_insert_data.c \
	  btree_search_item.c \
	  btree_level_count.c \
	  btree_apply_by_level.c
LIB	=	lib

LIBOBJS = $(LIBSRCS:.c=.o)

CFLAGS = -I./include
CFLAGS += -W -Wall -Wextra

all: $(LIB)
	 
$(LIB):	$(LIBOBJS)
	ar rcs $(LIBNAME) $(LIBOBJS)

clean:
	$(RM) $(LIBOBJS)

fclean:	clean
	$(RM) $(LIBNAME)

re:	fclean all

.PHONY: all clean fclean re lib
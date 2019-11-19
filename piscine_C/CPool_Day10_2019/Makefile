##
## EPITECH PROJECT, 2019
## task
## File description:
## Makefile
##

LIB	=	lib
DO_OP	=	do_op

LIBDIR	=	./lib/my
DO_OPDIR	=	./do-op

all: $(LIB) $(DO_OP)

$(LIB):
	$(MAKE) -C $(LIBDIR)

$(DO_OP):
	$(MAKE) -C $(DO_OPDIR)

clean:
	$(MAKE) -C $(LIBDIR) clean
	$(MAKE) -C $(DO_OPDIR) clean

fclean:
	$(MAKE) -C $(LIBDIR) fclean
	$(MAKE) -C $(DO_OPDIR) fclean

re: fclean all

.PHONY: all clean fclean re lib do_op
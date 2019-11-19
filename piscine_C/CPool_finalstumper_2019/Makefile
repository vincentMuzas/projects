##
## EPITECH PROJECT, 2019
## CPool_evalexpr_2019
## File description:
## Makefile
##

SRC	=	src

SRCDIR	=	./src

LIB	=	lib

LIBDIR	=	./lib/my

all: $(LIB) $(SRC)

$(LIB):
	$(MAKE) -C $(LIBDIR)

$(SRC):
	$(MAKE) -C $(SRCDIR)

clean:
	$(MAKE) -C $(LIBDIR) clean
	$(MAKE) -C $(SRCDIR) clean

fclean:
	$(MAKE) -C $(LIBDIR) fclean
	$(MAKE) -C $(SRCDIR) fclean

re: fclean all

.PHONY: all re clean fclean lib src

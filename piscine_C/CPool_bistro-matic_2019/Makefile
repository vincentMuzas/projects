##
## EPITECH PROJECT, 2019
## CPool_bistro-matic_2019
## File description:
## Makefile
##

LIB	=	lib

LIBDIR	=	./lib/my

SRC	=	src

SRCDIR	=	./src

all: $(LIB) $(SRC)

$(SRC):
	$(MAKE) -C $(SRCDIR)

$(LIB):
	$(MAKE) -C $(LIBDIR)

clean_src:
	$(MAKE) -C $(SRCDIR) clean

clean_lib:
	$(MAKE) -C $(LIBDIR) clean

clean: clean_lib clean_src

fclean_src:
	$(MAKE) -C $(SRC) fclean

fclean_lib:
	$(MAKE) -C $(LIBDIR) fclean

fclean: fclean_lib fclean_src

re: fclean all

.PHONY: all re clean clean_lib clean_src fclean fclean_lib fclean_src lib src

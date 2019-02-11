MODULEDIR	=	src/data

MODULE	=	NameModule.cpp	\
		OsModule.cpp	\
		DateModule.cpp	\
		CpuModule.cpp	\
		MemoryModule.cpp

MODULE	:=	$(addprefix $(MODULEDIR)/, $(MODULE))

MODULEOBJ	= $(MODULE:.cpp=.o)

SFMLDIR	=	src/graphics/SFML

SFMLSRC	=	Sfml.cpp	\
		main.cpp

SFMLSRC	:=	$(addprefix $(SFMLDIR)/, $(SFMLSRC))

SFMLOBJ	=	$(SFMLSRC:.cpp=.o)

CXXFLAGS	=	-Iincludes -W -Wall -Werror -std=c++14 -g3

NAME	=	program

all: $(NAME)

$(NAME): $(MODULEOBJ) $(SFMLOBJ)
	g++ -o $@ $^ -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f $(MODULEOBJ)
	rm -f $(SFMLOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

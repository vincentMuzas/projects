##
## EPITECH PROJECT, 2018
## iostream
## File description:
## 
##


SRC	=	main.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	my_convert_temp

all: $(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) -W -Wall -Werror -Wextra -g3

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

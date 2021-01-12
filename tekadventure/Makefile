##
## Makefile for  in /home/vincent/Documents/raytracer1
## 
## Made by vincent
## Login   <vincent.muzas@epitech.eu@epitech.net>
## 
## Started on  Tue Feb 21 11:27:27 2017 vincent
## Last update Sun May 28 21:55:13 2017 vincent
##

SRC	=	src/main.c				\
		src/background.c			\
		src/background2.c			\
		src/movements.c				\
		src/movements2.c			\
		src/movements3.c			\
		src/textures.c				\
		src/getline.c				\
		src/ini_gnl.c				\
		src/display_cara.c			\
		src/display_cara2.c			\
		src/gameloop.c				\
		src/print.c				\
		src/colision.c				\
		src/music.c				\
		src/lifebar.c				\
		src/ending_screen.c			\
		src/spawn_box.c				\
		src/spawn_box2.c			\
		Dylan/Gauge/gauge/get_gauge_color.c	\
		Dylan/Gauge/usefull/get_sfcolor.c	\
		src/menu/main.c				\
                src/menu/menu/create_window.c		\
                src/menu/menu/create_fvector.c		\
                src/menu/menu/create_text.c		\
                src/menu/menu/manage_close.c		\
                src/menu/menu/read_sprite.c		\
                src/menu/menu/my_strjoin.c		\
                src/menu/menu/my_strlen.c		\
                src/menu/menu/my_strcmp.c		\
                src/menu/menu/render_sprites.c		\
                src/menu/menu/generate_menu.c		\
                src/menu/menu/manage_parallax.c		\
                src/menu/menu/create_titles.c		\
                src/menu/menu/render_titles.c		\
                src/menu/menu/create_text_bounds.c	\
                src/menu/menu/manage_color.c		\
                src/menu/menu/contains.c		\
                src/menu/menu/manage_inputs.c		\
                src/menu/menu/manage_graph.c


OBJ	=	$(SRC:.c=.o)

NAME	=	tekadventure

all: $(NAME)

$(NAME):	$(OBJ)
	gcc -g -g3 -o $(NAME) $(OBJ) -ansi -pedantic -Wall -Wextra -lm -lc_graph_prog_full

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

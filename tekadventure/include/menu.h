/*
** menu.h for  in /home/Majoris/teky/z_new_code/include
** 
** Made by Florian ESCUDE
** Login   <Majoris@epitech.net>
** 
** Started on  Sat Apr 29 15:40:46 2017 Florian ESCUDE
** Last update Sun May 28 18:24:55 2017 Florian ESCUDE
*/

#ifndef MENU_H_
# define MENU_H_
# define WIDTH 1920
# define HEIGHT 1080
# define TITLE "Tek Adventure"
# define GRAPH_SPEED 15

# include <SFML/Graphics.h>
# include <SFML/Audio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>

typedef struct s_graph
{
  int		current_pos;
  int		next_pos;
  int		moving;
  sfIntRect	rect;
  sfVector2f	player;
  sfVector2f	start;
  sfVector2f	end;
  float		distance;
  float		dir_x;
  float		dir_y;
}	t_graph;

typedef struct s_menu
{
  sfText	**titles;
  sfFloatRect	*titles_box;
  sfSprite	**imgs;
  sfFont	*font;
  sfEvent	event;
  sfVector2i	mouse_pos;
  int		status;
  sfSprite	*main;
  sfVector2i	mouse;
  int		flag;
  double	moon_x;
  double	moon_y;
  double	st_1;
  double	st_2;
  double	bck1;
  double	bck2;
  double	cld1;
  double	cld2;
  int		on;
  int		last;
  t_graph	*graph;
}	t_menu;

int		manage_color(sfText **, sfVector2i, sfFloatRect *, t_menu *);
void		proceed_move(t_graph *, sfRenderWindow *, t_menu *);
void		manage_close(sfRenderWindow *, sfEvent);
int		my_strcmp(char *, char *);
int		contains(sfFloatRect, sfVector2i);
sfSprite	*create_sprite(char *);
sfFloatRect	*create_text_bounds(sfText **, int);
sfText		**create_titles(void);
void		render_titles(sfText **, sfRenderWindow *);
sfSprite	**read_sprite(char *);
int		my_strlen(char *);
char		*my_strjoin(char *, char *, char *);
t_menu		*init_menu(void);
sfVector2f	create_fvector(double, double);
sfText		*create_text(char *, sfFont *, sfColor, sfVector2f);
sfRenderWindow	*create_window(char *, int, int);
void		render_sprites(sfSprite **, sfRenderWindow *);
void		manage_parallax(sfSprite **, sfRenderWindow *, t_menu *);
t_menu		*generate_menu(void);
void		manage_graph(t_menu *, sfRenderWindow *);
void		manage_inputs(sfRenderWindow *, t_menu *);
int		start_function(sfRenderWindow *);

#endif /* !MENU_H_ */

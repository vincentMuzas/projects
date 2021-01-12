/*
** my.h for  in /home/vincent/Documents/tekadventure
** 
** Made by vincent
** Login   <vincent.muzas@epitech.eu>
** 
** Started on  Thu Apr 13 10:56:24 2017 vincent
** Last update Sun May 28 21:45:50 2017 vincent
*/

#ifndef MY_H_
# define MY_H_

# include <SFML/Graphics.h>
# include <SFML/Audio.h>
# include <stdlib.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <unistd.h>
# include <stdio.h>

# define WIDTH 1920
# define HEIGHT 1080
# define FPS 60

# define MIN_Y 876

# define JUMPING 1
# define WALKING 0
# define LEFT 1
# define RIGHT 0
# define IDLE 2

# define ARCHER 0
# define GUNMAN 1
# define LANCER 2
# define SABER	3

# define OPEN 1
# define CLOSE 0


typedef struct s_music
{
  sfMusic *ambiance;
}		t_music;

typedef struct s_myvector
{
  int x;
  int y;
  int z;
  int w;
}		t_myvector;

typedef struct s_player
{
  int x;
  int initial_y;
  int y;
  int hp;
  int mana;
  int hero_selected;
  int ult_call_down;
  int facing;
  int status;
  sfKeyCode left;
  sfKeyCode right;
  int frame;
  int time;
  sfTexture *cara;
  sfSprite *sprite;
  int target;
  char plan;
  int  plan_cd;
}	t_player;

typedef struct  s_box
{
  sfVector2f	**pos_xy;
  sfTexture	*texture;
  sfSprite	*sprite;
  sfText	*pv;
  sfText	*power_up;
  int           status;
  int           time;
  int           frame;
  int           nbr_box;
  int           buff;
  int           rank;
}               t_box;

typedef struct s_texture
{
  sfTexture *mountains1;
  sfTexture *mountains2;
  sfTexture *ground;
  sfTexture *clouds;
  sfTexture *hp_bar;
  sfTexture *hp_overlay;
  sfTexture *platform;
  sfTexture *player1win;
  sfTexture *player2win;
  sfTexture *background;
  int error;
  t_music *music;
  t_box *box;
}	t_texture;

typedef struct t_map
{
  sfVector2f *position;
}	t_map;

void		print_ground(sfRenderWindow *window, t_texture texture, int offset);
void		print_background(sfRenderWindow *window, t_texture texture, t_player *players, sfVector2f *map);
int		check_map(char **map);
void		movements(t_player *player, sfVector2f *map);
void		free_everything(t_texture texture, sfRenderWindow *window, t_player *players);
t_texture       load_textures2(t_texture texture);
t_texture       load_textures(int fd);
void		disp_cara(t_player *player, sfRenderWindow *window);
void		walk_1(t_player *player, int nb, sfIntRect rect);
void		init_texture_player(t_player *player);
void		sprite_of_cara(t_player *player, sfRenderWindow *window);
char		*the_getline(int fd);
void		inistr(char *str, int max);
char		*init_gnl(char save, char *c, char *res);
char		*my_char_append(char *str, char c);
sfVector2f      *get_map(int av, char **ac, t_texture *texture, int *fd);
sfVector2f	*get_map2(char **map, t_texture *texture);
int		game_loop(t_texture textures, sfRenderWindow *window, t_player *players, sfVector2f *map);
void		print_map(sfRenderWindow *window, t_texture texture, sfVector2f *map, int offset);
void		print_mountains1(sfRenderWindow *window, t_texture texture, int offset);
void		print_mountains2(sfRenderWindow *window, t_texture texture, int offset);
sfMusic		*let_s_play_it(char *str);
sfMusic		*let_play_and_reapeaut(char *str);
int		colision(t_player *player, int i, sfVector2f *map, int offset);
void		print_life(sfRenderWindow *window, t_player *players);
void		print_health_bar1(sfRenderWindow *window, t_player *player, t_texture textures);
void		print_health_bar2(sfRenderWindow *window, t_player *player, t_texture textures);
void		print_menu_background(sfRenderWindow *window, t_texture texture, t_player *players, int offset);
int             random_value(void);
void		my_set_scale(sfSprite *sprite, float scale);
sfIntRect	get_rect_box(int nb);
void		set_pos_text(t_box *box);
void		disp_box(sfRenderWindow *window, t_box *box, int rank, int set_buff);
void		chose_box(sfRenderWindow *window, t_box *box);
int		ending_screen(t_player *players, sfRenderWindow *window, t_texture textures);
void		plan(t_player *player);
void		disp_box(sfRenderWindow *window, t_box *box, int rank, int set_buff);
void		chose_box(sfRenderWindow *window, t_box *box);
void		move_left(t_player *player, int i, sfVector2f *map, int offset);
void		gravity(t_player *player, int i, sfVector2f *map, int offset);
void		move_right(t_player *player, int i, sfVector2f *map, int offset);
void		jump(t_player *player, int i, sfVector2f *map, int offset);
void		move_down(t_player *player, int i, sfVector2f *map, int offset);
void		move_up(t_player *player, int i, sfVector2f *map, int offset);

#endif /* !MY_H_ */

/*
** main.c for  in /home/vincent/Documents/tekadventure
** 
** Made by vincent
** Login   <vincent.muzas@epitech.eu>
** 
** Started on  Wed Apr 12 14:28:24 2017 vincent
** Last update Sun May 28 22:09:29 2017 vincent
*/

#include "../include/menu.h"
#include "../my.h"

sfRenderWindow	*do_the_shit_billy()
{
  sfVideoMode mode;
  sfRenderWindow *window;

  mode.width = WIDTH;
  mode.height = HEIGHT;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, "SuperBaston 2",
				 sfClose | sfFullscreen, NULL);
  sfRenderWindow_setFramerateLimit(window, 30);
  return (window);
}

void		init_players_sequel(t_player *player)
{
  player[0].frame = 0;
  player[1].frame = 0;
  player[0].time = 0;
  player[1].time = 0;
  player[0].sprite = sfSprite_create();
  player[1].sprite = sfSprite_create();
  player[0].plan_cd = 0;
  player[1].plan_cd = 0;
  player[0].hero_selected = random_value() % 4;
  player[1].hero_selected = rand() % 4;
  init_texture_player(player);
}

t_player	*init_players()
{
  t_player *players;

  if ((players = malloc(sizeof(t_player) * 2)) == NULL)
    return (NULL);
  players[0].x = 1200;
  players[1].x = 1800;
  players[0].y = HEIGHT - 204;
  players[1].y = HEIGHT - 204;
  players[0].hp = 100;
  players[1].hp = 100;
  players[0].plan = 1;
  players[1].plan = 1;
  players[0].ult_call_down = 0;
  players[1].ult_call_down = 0;
  players[0].facing = RIGHT;
  players[1].facing = LEFT;
  players[0].initial_y = players[0].x;
  players[1].initial_y = players[0].y;
  players[0].status = IDLE;
  players[1].status = IDLE;
  players[0].target = players[0].y;
  players[1].target = players[1].y;
  init_players_sequel(players);
  return (players);
}

int	check_map(char **map)
{
  int i;
  int j;

  i = 0;
  while (map[i] != NULL)
    {
      j = 0;
      while (map[i][j] != 0)
	{
	  if (map[i][j] != ' ' &&
	      map[i][j] != 'X')
	    return (84);
	  j++;
	}
      i++;
    }
  return (0);
}

int	main(int av, char **ac)
{
  t_texture textures;
  sfRenderWindow *window;
  t_player *players;
  sfVector2f *map;
  int fd;

  if ((map = get_map(av, ac, &textures, &fd)) == NULL)
    return (84);
  window = do_the_shit_billy();
  sfRenderWindow_setFramerateLimit(window, 60);
  textures = load_textures(fd);
  if ((players = init_players()) == NULL)
    sfRenderWindow_close(window);
  if (textures.error == 1)
    sfRenderWindow_close(window);
  game_loop(textures, window, players, map);
  sfTexture_destroy(players[0].cara);
  sfTexture_destroy(players[1].cara);
  sfSprite_destroy(players[0].sprite);
  sfSprite_destroy(players[1].sprite);
  close(fd);
  free(map);
  free_everything(textures, window, players);
}

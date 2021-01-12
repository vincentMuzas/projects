/*
** gameloop.c for  in /home/vincent/Documents/tekadventure
** 
** Made by vincent
** Login   <vincent.muzas@epitech.eu>
** 
** Started on  Tue May  2 10:38:11 2017 vincent
** Last update Sun May 28 22:23:12 2017 vincent
*/

#include "../my.h"
#include "../Dylan/Gauge/include/my.h"
#include "../Dylan/Gauge/include/gauge.h"
#include "../Dylan/Gauge/include/usefull_dylan.h"

sfVector2f	*get_map(int av, char **ac, t_texture *texture, int *fd)
{
  int i;
  char **map;

  i = 0;
  if (av != 2)
    {
      write(1, "bad number of arguments\n", 24);
      return (NULL);
    }
  if ((*fd = open(ac[1], O_RDONLY)) == -1)
    {
      write(1, "error while opening the file\n", 29);
      return (NULL);
    }
  if ((map = malloc(sizeof(char **) * 17)) == NULL)
    return (NULL);
  while ((map[i] = the_getline(*fd)) != NULL)
    i++;
  if (check_map(map) == 84)
    return (NULL);
  return (get_map2(map, texture));
}

int	set_pos(char **map, sfVector2f *maped, t_myvector pos,
		t_texture *texture)
{
  if (map[pos.y][pos.x] == 'X')
    {
      maped[pos.z].y = (pos.y) * 64;
      maped[pos.z].x = pos.x * 64;
      pos.z++;
    }
  return (pos.z);
}

sfVector2f	*get_map2(char **map, t_texture *texture)
{
  sfVector2f *maped;
  t_myvector pos;

  pos.x = pos.y = pos.z = 0;
  maped = malloc(sizeof(sfVector2f *) * 1024);
  while (map[pos.y] != NULL)
    {
      pos.x = 0;
      while (map[pos.y][pos.x] != 0)
	{
	  pos.z = set_pos(map, maped, pos, texture);
	  pos.x++;
	}
      free(map[pos.y++]);
    }
  free(map);
  maped[pos.z].y = -1;
  return (maped);
}

void	print_health_overlay(sfRenderWindow *window, t_player *player,
			     t_texture textures)
{
  sfSprite	*sprite;
  sfVector2f	pos;

  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, textures.hp_overlay, sfTrue);
  pos.x= 1.3;
  pos.y= 1.3;
  sfSprite_setScale(sprite, pos);
  sfRenderWindow_drawSprite(window, sprite, NULL);
  pos.x = WIDTH - 893;
  pos.y = 0;
  sfSprite_setPosition(sprite, pos);
  sfRenderWindow_drawSprite(window, sprite, NULL);
  sfSprite_destroy(sprite);
}


int	game_loop(t_texture textures, sfRenderWindow *window,
		  t_player *players, sfVector2f *map)
{
  sfEvent *event;

  while (sfRenderWindow_isOpen(window))
    {
      if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	sfRenderWindow_close(window);
      ending_screen(players, window, textures);
      movements(players, map);
      sfRenderWindow_clear(window, sfBlue);
      print_background(window, textures, players, map);
      sprite_of_cara(players, window);
      print_health_overlay(window, players, textures);
      print_health_bar1(window, players, textures);
      print_health_bar2(window, players, textures);
      sfRenderWindow_display(window);
    }
}

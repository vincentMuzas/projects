/*
** background.c for  in /home/vincent/Documents/tekadventure
** 
** Made by vincent
** Login   <vincent.muzas@epitech.eu>
** 
** Started on  Mon Apr 24 15:57:48 2017 vincent
** Last update Sun May 28 21:22:58 2017 vincent
*/

#include "../my.h"

void	print_clouds(sfRenderWindow *window, t_texture texture, int offset)
{
  sfVector2f pos;
  sfSprite *sprite;

  offset *= 0.1;
  sprite = sfSprite_create();
  pos.y = 0;
  sfSprite_setTexture(sprite, texture.clouds, sfTrue);
  pos.x = (offset * 1) % 640 - 640;
  while (pos.x < WIDTH)
    {
      sfSprite_setPosition(sprite, pos);
      sfRenderWindow_drawSprite(window, sprite, NULL);
      pos.x += 640;
    }
  sfSprite_destroy(sprite);
}

void	print_map(sfRenderWindow *window, t_texture texture,
		  sfVector2f *map, int offset)
{
  int i;
  sfVector2f pos;
  sfSprite *sprite;

  i = 0;
  pos.x = 2;
  pos.y = 2;
  offset += WIDTH / 2;
  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, texture.platform, sfTrue);
  sfSprite_setScale(sprite, pos);
  while (map[i].y != -1)
    {
      pos.x = map[i].x + offset;
      pos.y = map[i].y;
      sfSprite_setPosition(sprite, pos);
      sfRenderWindow_drawSprite(window, sprite, NULL);
      i++;
    }
  sfSprite_destroy(sprite);
}


void	print_background(sfRenderWindow *window, t_texture texture,
			 t_player *players, sfVector2f *map)
{
  int i;
  int offset;

  i = -1;
  offset = (players[0].x + players[1].x) / -2;
  print_mountains1(window, texture, offset);
  print_mountains2(window, texture, offset);
  print_ground(window, texture, offset);
  print_clouds(window, texture, offset);
  print_map(window, texture, map, offset);
}

void	print_menu_background(sfRenderWindow *window, t_texture texture,
			      t_player *players, int offset)
{
  sfVector2f pos;
  sfIntRect size;

  print_mountains1(window, texture, offset);
  print_mountains2(window, texture, offset);
  print_ground(window, texture, offset);
  print_clouds(window, texture, offset);
}

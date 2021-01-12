/*
** background2.c for  in /home/vincent/Documents/tekadventure/src
** 
** Made by vincent
** Login   <vincent.muzas@epitech.eu>
** 
** Started on  Sun May 28 21:21:29 2017 vincent
** Last update Sun May 28 21:25:57 2017 vincent
*/

#include "../my.h"

void		print_ground(sfRenderWindow *window, t_texture texture, int offset)
{
  sfVector2f	scale;
  sfVector2f	pos;
  sfSprite	*sprite;

  scale.x = 2;
  scale.y = 2;
  sprite = sfSprite_create();
  pos.y = HEIGHT - 64;
  sfSprite_setTexture(sprite, texture.ground, sfTrue);
  pos.x = offset % 192 - 192;
  sfSprite_setScale(sprite, scale);
  while (pos.x < WIDTH)
    {
      sfSprite_setPosition(sprite, pos);
      sfRenderWindow_drawSprite(window, sprite, NULL);
      pos.x += 192;
    }
  sfSprite_destroy(sprite);
}

void		print_mountains1(sfRenderWindow *window, t_texture texture, int offset)
{
  sfVector2f	pos;
  sfSprite	*sprite;

  offset *= 0.3;
  sprite = sfSprite_create();
  pos.y = HEIGHT - 340;
  sfSprite_setTexture(sprite, texture.mountains1, sfTrue);
  pos.x = offset % 800 - 800;
  while (pos.x < WIDTH)
    {
      sfSprite_setPosition(sprite, pos);
      sfRenderWindow_drawSprite(window, sprite, NULL);
      pos.x += 800;
    }
  sfSprite_destroy(sprite);
}

void		print_mountains2(sfRenderWindow *window, t_texture texture, int offset)
{
  sfVector2f	pos;
  sfSprite	*sprite;

  offset *= 0.5;
  sprite = sfSprite_create();
  pos.y = HEIGHT - 320;
  sfSprite_setTexture(sprite, texture.mountains2, sfTrue);
  pos.x = offset % 800 - 800;
  while (pos.x < WIDTH)
    {
      sfSprite_setPosition(sprite, pos);
      sfRenderWindow_drawSprite(window, sprite, NULL);
      pos.x += 800;
    }
  sfSprite_destroy(sprite);
}

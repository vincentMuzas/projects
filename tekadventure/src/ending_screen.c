/*
** ending_screen.c for  in /home/vincent/Documents/tekadventure
** 
** Made by vincent
** Login   <vincent.muzas@epitech.eu>
** 
** Started on  Sat May 27 16:34:32 2017 vincent
** Last update Sun May 28 02:04:36 2017 vincent
*/

#include "../my.h"

sfVector2i	get_mouse_pos(sfRenderWindow *window)
{
  sfVector2i	mouse;

  mouse = sfMouse_getPositionRenderWindow(window);
  mouse.x -= WIDTH / 2;
  mouse.y -= HEIGHT / 2;
  return (mouse);
}

sfSprite	*set_right_origin(t_texture texture, int winner, int bg)
{
  sfVector2u	size;
  sfVector2f	origin;
  sfSprite	*sprite;
  sfVector2f	scale;

  sprite = sfSprite_create();
  if (bg == 1)
    {
      if (winner == 1)
	sfSprite_setTexture(sprite, texture.player1win, 0);
      else if (winner == 2)
	sfSprite_setTexture(sprite, texture.player2win, 0);
      size = sfTexture_getSize(texture.player1win);
    }
  else
    {
      sfSprite_setTexture(sprite, texture.background, 0);
      scale.x = scale.y = 1.05;
      sfSprite_setScale(sprite, scale);
      size = sfTexture_getSize(texture.background);
    }
  origin.x = size.x / 2;
  origin.y = size.y / 2;
  sfSprite_setOrigin(sprite, origin);
  return (sprite);
}

void		my_set_pos(sfSprite *sprite, sfSprite *background, sfVector2i mouse)
{
  sfVector2f	pos;

  pos.x = WIDTH / 2 - (mouse.x / 100);
  pos.y = HEIGHT / 2 - (mouse.y / 100);
  sfSprite_setPosition(sprite, pos);
  pos.x = WIDTH / 2 + (mouse.x / 100);
  pos.y = HEIGHT / 2 + (mouse.y / 100);
  sfSprite_setPosition(background, pos);
}

int		print_end(sfRenderWindow *window, t_texture texture, int winner)
{
  sfSprite	*sprite;
  sfSprite	*background;
  sfVector2i	mouse;
  sfVector2u	texture_size;

  background = set_right_origin(texture, winner, 0);
  sprite = set_right_origin(texture, winner, 1);
  while (sfRenderWindow_isOpen(window))
    {
      mouse = get_mouse_pos(window);
      if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	sfRenderWindow_close(window);
      sfRenderWindow_clear(window, sfBlack);
      my_set_pos(sprite, background, mouse);
      sfRenderWindow_drawSprite(window, background, NULL);
      sfRenderWindow_drawSprite(window, sprite, NULL);
      sfRenderWindow_display(window);
    }
  sfSprite_destroy(sprite);
  sfSprite_destroy(background);
}

int		ending_screen(t_player *players,
			      sfRenderWindow *window, t_texture textures)
{
  if (players[0].hp == 0)
    print_end(window, textures, 2);
  if (players[1].hp == 0)
    print_end(window, textures, 1);
}

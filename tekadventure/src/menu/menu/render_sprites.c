/*
** render_sprites.c for  in /home/Majoris/1_new_tek
** 
** Made by Florian ESCUDE
** Login   <Majoris@epitech.net>
** 
** Started on  Mon May  8 16:37:07 2017 Florian ESCUDE
** Last update Sun May 28 14:29:20 2017 Florian ESCUDE
*/

#include "../../../include/menu.h"

void	render_sprites(sfSprite **sprites, sfRenderWindow *window)
{
  int	i;

  i = 0;
  while (sprites[i] != '\0')
    {
      sfRenderWindow_drawSprite(window, sprites[i], NULL);
      i++;
    }
}

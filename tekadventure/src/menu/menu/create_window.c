/*
** create_window.c for  in /home/Majoris/teky/z_new_code
** 
** Made by Florian ESCUDE
** Login   <Majoris@epitech.net>
** 
** Started on  Sat Apr 29 16:09:07 2017 Florian ESCUDE
** Last update Sun May 28 14:29:22 2017 Florian ESCUDE
*/

#include "../../../include/menu.h"

sfRenderWindow	*create_window(char *title, int width, int height)
{
  sfRenderWindow	*window;
  sfVideoMode		mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, title, sfResize | sfClose, NULL);
  if (window == NULL)
    return (NULL);
  sfRenderWindow_setFramerateLimit(window, 20);
  return (window);
}

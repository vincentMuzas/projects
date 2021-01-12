/*
** usefull_cGraphical.c for  in /home/dylan/Delivery/Boostrap/raytracer1
** 
** Made by Dylan
** Login   <dylan.riba@epitech.eu>
** 
** Started on  Wed Feb  8 16:48:40 2017 Dylan
** Last update Tue Mar 14 17:02:19 2017 Dylan
*/

#include "my.h"

sfRenderWindow*		create_window(char* name, int width, int height)
{
  sfRenderWindow*	window;
  sfVideoMode		mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  if (window == NULL)
    exit(MY_EXIT_FAILURE);
  return (window);
}

t_my_framebuffer	*my_framebuffer_create(int width, int height)
{
  int			i;
  t_my_framebuffer	*framebuffer;

  framebuffer = malloc(sizeof(t_my_framebuffer));
  framebuffer->width = width;
  framebuffer->height = height;
  framebuffer->pixels = malloc(width * height * 4 * sizeof(sfUint8));
  if (framebuffer->pixels == NULL)
    exit(MY_EXIT_FAILURE);
  i = 0;
  while (i < width * height * 4)
    {
      framebuffer->pixels[i] = 0;
      i = i + 1;
    }
  return (framebuffer);
}

void	my_framebuffer_destroy(t_my_framebuffer *framebuffer)
{
  free(framebuffer->pixels);
  free(framebuffer);
}

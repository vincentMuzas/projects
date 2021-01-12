/*
** main.c for  in /home/Majoris/1_new_tek
** 
** Made by Florian ESCUDE
** Login   <Majoris@epitech.net>
** 
** Started on  Mon May  8 15:15:32 2017 Florian ESCUDE
** Last update Sun May 28 22:07:32 2017 vincent
*/

#include "../../include/menu.h"

int	start_function(sfRenderWindow *window)
{
  t_menu	*menu;

  if ((menu = generate_menu()) == NULL)
    {
      write(2, "Failed to create menu.\n", 24);
      return (1);
    }
  while (sfRenderWindow_isOpen(window))
    {
      sfRenderWindow_clear(window, sfWhite);
      menu->mouse = sfMouse_getPositionRenderWindow(window);
      manage_parallax(menu->imgs, window, menu);
      render_titles(menu->titles, window);
      manage_inputs(window, menu);
      manage_color(menu->titles, menu->mouse, menu->titles_box, menu);
      manage_close(window, menu->event);
      if (menu->flag == 2)
	manage_graph(menu, window);
      if (menu->flag == 2 && menu->graph->moving == 1)
	return (1);
      if (menu->flag == 1)
	return (0);
      sfRenderWindow_drawSprite(window, menu->main, NULL);
      sfRenderWindow_display(window);
    }
}

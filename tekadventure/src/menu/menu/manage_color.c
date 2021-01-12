/*
** manage_color.c for  in /home/Majoris/1_new_tek
** 
** Made by Florian ESCUDE
** Login   <Majoris@epitech.net>
** 
** Started on  Tue May  9 14:26:37 2017 Florian ESCUDE
** Last update Sun May 28 21:49:20 2017 vincent
*/

#include "../../../include/menu.h"

int	manage_color(sfText **titles, sfVector2i mouse, sfFloatRect *bounds,
		     t_menu *menu)
{
  int	i;

  i = 0;
  while (titles[i] != '\0')
    {
      if (contains(bounds[i], mouse) == sfTrue)
	{
	  menu->on = i;
	  break;
	}
      i++;
    }
  i = 0;
  while (titles[i] != '\0')
    {
      if (i == menu->on)
	sfText_setColor(titles[i], sfRed);
      else
	sfText_setColor(titles[i], sfWhite);
      i++;
    }
  if (menu->on != 3)
    menu->last = menu->on;
  return (menu->last);
}

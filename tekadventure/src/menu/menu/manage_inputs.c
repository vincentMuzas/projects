/*
** manage_inputs.c for  in /home/Majoris/1_new_tek
** 
** Made by Florian ESCUDE
** Login   <Majoris@epitech.net>
** 
** Started on  Tue May  9 13:47:29 2017 Florian ESCUDE
** Last update Sun May 28 15:15:38 2017 Florian ESCUDE
*/

#include "../../../include/menu.h"

void	manage_inputs(sfRenderWindow *window, t_menu *menu)
{
  if ((sfFloatRect_contains(&menu->titles_box[0], (float)menu->mouse.x,
			    (float)menu->mouse.y)) == sfTrue
      && sfMouse_isButtonPressed(sfMouseLeft))
    menu->flag = 1;
  if ((sfFloatRect_contains(&menu->titles_box[1], (float)menu->mouse.x,
			    (float)menu->mouse.y)) == sfTrue
      && sfMouse_isButtonPressed(sfMouseLeft))
    menu->flag = 2;
}

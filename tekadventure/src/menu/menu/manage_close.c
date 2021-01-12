/*
** manage_close.c for  in /home/Majoris/teky/z_new_code/menu
** 
** Made by Florian ESCUDE
** Login   <Majoris@epitech.net>
** 
** Started on  Sun Apr 30 13:15:46 2017 Florian ESCUDE
** Last update Sun May 28 14:29:22 2017 Florian ESCUDE
*/

#include "../../../include/menu.h"

void	manage_close(sfRenderWindow *window, sfEvent event)
{
  while (sfRenderWindow_pollEvent(window, &event))
    {
      if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
	sfRenderWindow_close(window);
    }
}

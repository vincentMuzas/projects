/*
** render_titles.c for  in /home/Majoris/1_new_tek
** 
** Made by Florian ESCUDE
** Login   <Majoris@epitech.net>
** 
** Started on  Mon May  8 16:38:38 2017 Florian ESCUDE
** Last update Sun May 28 14:29:19 2017 Florian ESCUDE
*/

#include "../../../include/menu.h"

void	render_titles(sfText **titles, sfRenderWindow *window)
{
  int	i;

  i = 0;
  while (titles[i] != '\0')
    {
      sfRenderWindow_drawText(window, titles[i], NULL);
      i++;
    }
}

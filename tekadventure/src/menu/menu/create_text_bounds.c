/*
** create_text_bounds.c for  in /home/Majoris/1_new_tek
** 
** Made by Florian ESCUDE
** Login   <Majoris@epitech.net>
** 
** Started on  Tue May  9 09:38:32 2017 Florian ESCUDE
** Last update Sun May 28 14:50:16 2017 Florian ESCUDE
*/

#include "../../../include/menu.h"

sfFloatRect	*create_text_bounds(sfText **titles, int nb_text)
{
  int	i;
  sfFloatRect	*bounds;

  i = 0;
  if ((bounds = malloc(sizeof(sfFloatRect) * (nb_text + 1))) == NULL)
    {
      write(2, "Failed to create text bounds.\n", 31);
      return (NULL);
    }
  while (titles[i] != '\0')
    {
      bounds[i] = sfText_getGlobalBounds(titles[i]);
      i++;
    }
  return (bounds);
}

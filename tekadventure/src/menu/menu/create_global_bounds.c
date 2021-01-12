/*
** create_global_bounds.c for  in /home/Majoris/teky/z_new_code/menu
** 
** Made by Florian ESCUDE
** Login   <Majoris@epitech.net>
** 
** Started on  Sun May  7 15:48:29 2017 Florian ESCUDE
** Last update Sun May 28 14:29:23 2017 Florian ESCUDE
*/

#include "../../../include/menu.h"

sfFloatRect	*create_global_bounds(sfSprite **sprites, char *folder_name)
{
  int	i;
  int	n_bounds;
  sfFloatRect	*bounds;

  i = 0;
  if (n_bounds == -1)
    return (NULL);
  if ((n_bounds = get_sprite_number(folder_name)) == 0)
    {
      write(2, "Unable to create bounds, no sprites found.\n", 44);
      return (NULL);
    }
  if ((bounds = malloc(sizeof(sfFloatRect) * (n_bounds + 1))) == NULL)
    return (NULL);
  while (sprites[i] != NULL)
    {
      bounds[i] = sfSprite_getGlobalBounds(sprites[i]);
      i++;
    }
  bounds[i] = NULL;
  return (bounds);
}

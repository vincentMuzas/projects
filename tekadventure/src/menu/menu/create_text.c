/*
** create_text.c for  in /home/Majoris/teky/z_new_code
** 
** Made by Florian ESCUDE
** Login   <Majoris@epitech.net>
** 
** Started on  Sun Apr 30 13:44:04 2017 Florian ESCUDE
** Last update Sun May 28 22:11:10 2017 vincent
*/

#include "../../../include/menu.h"

sfText		*create_text(char *name, sfFont *font, sfColor color, sfVector2f pos)
{
  sfText        *new;

  if ((new = sfText_create()) == NULL)
    {
      write(2, "Failed to create text.\n", 24);
      return (NULL);
    }
  color.a = 150;
  sfText_setColor(new, color);
  sfText_setFont(new, font);
  sfText_setString(new, name);
  sfText_setCharacterSize(new, 100);
  sfText_setPosition(new, pos);
  return (new);
}

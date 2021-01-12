/*
** create_font.c for  in /home/Majoris/teky/z_new_code/menu
** 
** Made by Florian ESCUDE
** Login   <Majoris@epitech.net>
** 
** Started on  Sun May  7 15:59:22 2017 Florian ESCUDE
** Last update Sun May 28 14:29:23 2017 Florian ESCUDE
*/

#include "../../../include/menu.h"

sfFont	*create_font(char *font_path)
{
  sfFont	*font;

  if ((font = sfFont_createFromFile(font_path)) == NULL)
    {
      write(2, "Unable to create font.\n", 24);
      return (NULL);
    }
  return (font);
}

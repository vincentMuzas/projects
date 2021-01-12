/*
** create_titles.c for  in /home/Majoris/1_new_tek
** 
** Made by Florian ESCUDE
** Login   <Majoris@epitech.net>
** 
** Started on  Tue May  9 09:06:15 2017 Florian ESCUDE
** Last update Sun May 28 15:10:58 2017 Florian ESCUDE
*/

#include "../../../include/menu.h"

sfText	**create_titles(void)
{
  sfText	**titles;
  sfFont	*font;

  if ((titles = malloc(sizeof(sfText *) * 4)) == NULL)
    return (NULL);
  if ((font = sfFont_createFromFile("./Ressources/Font/menu.ttf")) == NULL)
    {
      write(2, "Failed to load main menu font.\n", 32);
      return (NULL);
    }
  titles[0] = create_text("Play", font, sfRed,
			  create_fvector(WIDTH - 1500, HEIGHT / 2));
  titles[1] = create_text("Exit", font, sfWhite,
			  create_fvector(WIDTH / 1.3, HEIGHT / 2));
  titles[2] = NULL;
  return (titles);
}

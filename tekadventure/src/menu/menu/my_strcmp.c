/*
** my_strcmp.c for  in /home/Majoris/z_new_code
** 
** Made by Florian ESCUDE
** Login   <Majoris@epitech.net>
** 
** Started on  Mon May  8 14:54:46 2017 Florian ESCUDE
** Last update Sun May 28 14:29:21 2017 Florian ESCUDE
*/

#include "../../../include/menu.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i])
    {
      if (s1[i] == '\0' && s2[i] == '\0')
	return (0);
      i++;
    }
  return (s1[i] - s2[i]);
}

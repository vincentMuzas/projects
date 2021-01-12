/*
** ini_gnl.c for  in /home/mathias/Bureau/projet_epitech/infograph/tekadventure/test
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Thu Apr 27 16:29:56 2017 Mathias
** Last update Wed May 10 12:51:18 2017 vincent
*/

#include "../my.h"

void	inistr(char *str, int max)
{
  int	i;

  i = 0;
  while (i != max)
    {
      str[i] = '\0';
      i += 1;
    }
}

char	*init_gnl(char save, char *c, char *res)
{
  res = malloc(sizeof(char));
  inistr(c, 3);
  res[0] = '\0';
  if (save != '\0')
    res = my_char_append(res, save);
  return (res);
}

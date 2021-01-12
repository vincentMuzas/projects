/*
** test.c for  in /home/mathias/Bureau/projet_epitech/synthèse/ADM_FASTAtools_2016
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Mon Jun 19 09:30:50 2017 Mathias
** Last update Mon Jun 19 10:55:32 2017 vincent
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char	*append_str(char *str, char *c)
{
  int	i;
  int	count;

  i = -1;
  count = i;
  while (c[++count] != '\0');
  while (str[++i] != '\0');
  if ((str = realloc(str, sizeof(char) * (i + 2 + count))) == NULL)
    return (NULL);
  count = -1;
  while (c[++count] != '\0')
    {
      str[i] = c[count];
      i += 1;
    }
  str[i] = '\0';
  return (str);
}

char	*append_char(char *str, char c)
{
  int	i;

  i = -1;
  while (str[++i] != '\0');
  if ((str = realloc(str, sizeof(char) * (i + 2))) == NULL)
    return (NULL);
  str[i] = c;
  str[i + 1] = '\0';
  return (str);
}

char	*my_gnl_sequel(char *str, char *c, int fd)
{
  int	k;

  while (1)
    {
      memset(c, 0, 3);
      k = read(fd, c, 2);
      if (k < 2 || c[0] < 0 || c[1] < 0 || c[0] == '\n' ||
	  c[1] == '\n' || c[0] =='\0')
	break;
      if ((str = append_str(str, c)) == NULL)
	return (NULL);
    }
  return (str);
}

char	*quit_w(char *str, char *c)
{
  free(str);
  free(c);
  return (NULL);
}

char		*my_gnl(int fd)
{
  static char	sv = '\0';
  char		*str;
  char		*c;

  if ((str = malloc(sizeof(char))) == NULL)
    return (NULL);
  if ((c = malloc(sizeof(char) * 3)) == NULL)
    return (NULL);
  str[0] = '\0';
  if (sv != '\0')
    if ((str = append_char(str, sv) == NULL)
      return (NULL);
  sv = '\0';
  if ((str = my_gnl_sequel(str, c, fd)) == NULL)
    return (NULL);
  if (str[0] == '\0' || c[0] < 0 || c[1] < 0)
    return (quit_w(str, c));
  if (c[0] == '\n' && c[1] != '\n')
    sv = c[1];
  else if (c[1] == '\n' && c[0] != '\n')
    if ((str = append_char(str, c[0])) == NULL)
      return (NULL);
  free(c);
  return (str);
}

/*
** test.c for  in /home/mathias/Bureau/projet_epitech/synthèse/ADM_FASTAtools_2016
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Mon Jun 19 09:30:50 2017 Mathias
** Last update Mon Jun 19 12:40:39 2017 vincent
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char **append_chartab(char **tab, char *str)
{
  int i;

  i = -1;
  while (tab[++i] != NULL);
  tab = realloc(tab, sizeof(char *) * (i + 2));
  tab[i] = str;
  tab[i + 1] = NULL;
  return (tab);
}

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

char **free_gaf(char **tab, char *str)
{
  int i;

  if (str != NULL)
    free(str);
  if (tab != NULL)
    {
      i = -1;
      while (tab[++i] != NULL)
	free(tab);
      free(tab);
    }
  return (NULL);
}

char **get_all_file(int fd)
{
  char *str;
  char **tab;
  char c;

  if ((str = calloc(1, sizeof(char))) == NULL ||
      (tab = malloc(sizeof(char *))) == NULL)
    return (NULL);
  tab[0] = NULL;
  while (1)
    {
      if (read(fd, &c, 1) <= 0 || c < 0)
	break;
      if (c == '\n' && str[0] != '\0')
	{
	  if ((tab = append_chartab(tab, str)) == NULL)
	    return (free_gaf(tab, str));
	  if ((str = calloc(1, sizeof(char))) == NULL)
	    return (free_gaf(tab, str));
	}
      else if (c != '\n')
	if ((str = append_char(str, c)) == NULL)
	  return (free_gaf(tab, str));
    }
  return ((c != '\n' ? append_chartab(tab, str) : tab));
}

/*
** getline.c for  in /home/mathias/Bureau/projet_epitech/infograph/tekadventure
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Tue May  2 20:16:27 2017 Mathias
** Last update Sun May 28 22:18:45 2017 vincent
*/

#include "../my.h"

int	my_len(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
    i += 1;
  return (i + 1);
}

char	*my_cat(char *st, char *tr)
{
  char *res;
  int i;
  int count;

  i = 0;
  count = 0;
  res = malloc(sizeof(char) * (my_len(st) + my_len(tr) + 2));
  inistr(res, my_len(st) + my_len(tr) + 2);
  while (st[i] != '\0')
    {
      res[i] = st[i];
      i += 1;
    }
  while (tr[count] != '\0')
    {
      res[i] = tr[count];
      i += 1;
      count += 1;
    }
  free(st);
  return (res);
}

char	*my_if(char *res, char *c)
{
  if (c[0] == '\n')
    ;
  else if (c[1] == '\n')
    {
      c[1] = '\0';
      res = my_cat(res, c);
      c[1] = '\n';
    }
  else
    res = my_cat(res, c);
  return (res);
}

char	*my_char_append(char *str, char c)
{
  int i;
  char *res;

  i = 0;
  if ((res = malloc(sizeof(char) * (my_len(str) + 2))) == NULL)
    return (NULL);
  inistr(res, my_len(str) + 2);
  while (str[i] != '\0')
    {
      res[i] = str[i];
      i += 1;
    }
  res[i] = c;
  free(str);
  return (res);
}

char	*the_getline(int fd)
{
  static char save = '\0';
  char *c;
  char *res;
  int k;

  if ((c = malloc(sizeof(char) * 3)) == NULL)
    return (NULL);
  res = init_gnl(save, c, res);
  save = '\0';
  while (1)
    {
      k = read(fd, c, 2);
      res = my_if(res, c);
      if (c[0] == '\n' || c[1] == '\n' || k != 2)
	break;
      inistr(c, 3);
    }
  if (c[0] == '\n')
    save = c[1];
  free(c);
  if (res[0] == '\0')
    {
      free(res);
      return (NULL);
    }
  return (res);
}

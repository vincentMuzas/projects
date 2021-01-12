/*
** my_strjoin.c for  in /home/Majoris/teky/z_new_code/menu
** 
** Made by Florian ESCUDE
** Login   <Majoris@epitech.net>
** 
** Started on  Sun May  7 15:43:14 2017 Florian ESCUDE
** Last update Sun May 28 14:29:20 2017 Florian ESCUDE
*/

#include "../../../include/menu.h"

char	*my_strjoin(char *folder_name, char *img_name, char *dest)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (folder_name[i] != '\0')
    {
      dest[i] = folder_name[i];
      i++;
    }
  while (img_name[j] != '\0')
    {
      dest[i + j] = img_name[j];
      j++;
    }
  dest[i + j] = '\0';
  return (dest);
}

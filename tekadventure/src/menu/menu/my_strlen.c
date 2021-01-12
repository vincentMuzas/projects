/*
** my_strlen.c for  in /home/Majoris/z_new_code
** 
** Made by Florian ESCUDE
** Login   <Majoris@epitech.net>
** 
** Started on  Mon May  8 14:58:04 2017 Florian ESCUDE
** Last update Sun May 28 14:29:20 2017 Florian ESCUDE
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

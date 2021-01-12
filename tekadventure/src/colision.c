/*
** colision.c for  in /home/vincent/Documents/tekadventure
** 
** Made by vincent
** Login   <vincent.muzas@epitech.eu>
** 
** Started on  Wed May  3 16:46:29 2017 vincent
** Last update Sun May 28 16:03:58 2017 vincent
*/

#include "../my.h"

int	colision(t_player *player, int j, sfVector2f *map, int offset)
{
  sfFloatRect rect1;
  sfFloatRect rect2;
  int i;

  if (player[j].plan == 0)
    return (0);
  rect1.left = player[j].x - 30;
  rect1.top = player[j].y + 80;
  rect1.width = 55;
  rect1.height = 60;
  rect2.width = 64;
  rect2.height = 64;
  i = 0;
  while (map[i].y != -1)
    {
      rect2.left = map[i].x;
      rect2.top = map[i].y;
      if (sfFloatRect_intersects(&rect2, &rect1, NULL) == sfTrue)
	return (1);
      i++;
    }
  return (0);
}

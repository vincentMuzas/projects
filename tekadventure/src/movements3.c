/*
** movements3.c for  in /home/vincent/Documents/tekadventure/src
** 
** Made by vincent
** Login   <vincent.muzas@epitech.eu>
** 
** Started on  Sun May 28 21:32:21 2017 vincent
** Last update Sun May 28 21:33:35 2017 vincent
*/

#include "../my.h"

void	move_right(t_player *player, int i,
		   sfVector2f *map, int offset)
{
  player[i].status = WALKING;
  player[i].facing = RIGHT;
  player[i].x += 5;
  if (colision(player, i, map, offset) == 1)
    player[i].x -= 5;
}

void	jump(t_player *player, int i,
	     sfVector2f *map, int offset)
{
  if (player[0].target > player[0].y)
    move_down(player, 0, map, offset);
  else if (player[0].target < player[0].y)
    move_up(player, 0, map, offset);
  else
    gravity(player, 0, map, offset);
  if (i == 0)
    jump(&player[1], 1, map, offset);
}

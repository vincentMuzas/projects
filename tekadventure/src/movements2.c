/*
** movements2.c for  in /home/vincent/Documents/tekadventure/src
** 
** Made by vincent
** Login   <vincent.muzas@epitech.eu>
** 
** Started on  Sun May 28 21:29:21 2017 vincent
** Last update Sun May 28 21:41:06 2017 vincent
*/

#include "../my.h"

void	move_down(t_player *player, int i,
		  sfVector2f *map, int offset)
{
  player[i].y += 10;
  if (colision(player, i, map, offset) == 1)
    {
      player[i].y -= 10;
      player[i].target = player[i].y;
    }
  else
    player[i].status = JUMPING;
}

void	gravity(t_player *player, int i,
		sfVector2f *map, int offset)
{
  player[i].y += 10;
  if (colision(player, i, map, offset) == 0)
    player[i].target = MIN_Y;
  player[i].y -= 10;
}

void	move_up(t_player *player, int i,
		sfVector2f *map, int offset)
{
  player[i].y -= 10;
  if (colision(player, i, map, offset) == 1)
    {
      player[i].target = MIN_Y;
      player[i].y += 10;
    }
  else if (player[i].target >= player[i].y)
    player[i].target = MIN_Y;
  else
    player[i].status = JUMPING;
}

void	move_left(t_player *player, int i,
		  sfVector2f *map, int offset)
{
  player[i].status = WALKING;
  player[i].facing = LEFT;
  player[i].x -= 5;
  if (colision(player, i, map, offset) == 1)
    player[i].x += 5;
}

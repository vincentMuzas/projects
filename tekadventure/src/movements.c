/*
** movements.c for  in /home/vincent/Documents/tekadventure
** 
** Made by vincent
** Login   <vincent.muzas@epitech.eu>
** 
** Started on  Wed Apr 26 16:24:01 2017 vincent
** Last update Sun May 28 21:33:20 2017 vincent
*/

#include "../my.h"

void	my_set_player_origin(t_player *player)
{
  sfVector2f vect;

  vect.x = 16;
  vect.y = 0;
  if (player[0].plan == 0)
    vect.y = 8;
  sfSprite_setOrigin(player[0].sprite, vect);
  vect.y = 0;
  if (player[1].plan == 0)
    vect.y = 8;
  else
    vect.y = 0;
  sfSprite_setOrigin(player[1].sprite, vect);
}

void	plan2(t_player *player)
{
  if (player[0].plan == 0)
    my_set_scale(player[0].sprite, 7);
  else
    my_set_scale(player[0].sprite, 5);
  if (player[1].plan == 0)
    my_set_scale(player[1].sprite, 7);
  else
    my_set_scale(player[1].sprite, 5);
  my_set_player_origin(player);
}

void	plan(t_player *player)
{
  if (sfKeyboard_isKeyPressed(sfKeyS) &&
      player[0].plan_cd <= 0)
    {
      player[0].plan_cd = 60;
      player[0].plan = !player[0].plan;
    }
  if (sfKeyboard_isKeyPressed(sfKeyDown) &&
      player[1].plan_cd <= 0)
    {
      player[1].plan_cd = 60;
      player[1].plan = !player[1].plan;
    }
  plan2(player);
  player[0].plan_cd --;
  player[1].plan_cd --;
}

void	move_player_1(t_player *player,
		      sfVector2f *map, int offset)
{
  if (sfKeyboard_isKeyPressed(sfKeyLeft))
    move_left(player, 1, map, offset);
  else if (sfKeyboard_isKeyPressed(sfKeyRight))
    move_right(player, 1, map, offset);
  else
    player[1].status = IDLE;
  if (sfKeyboard_isKeyPressed(sfKeyUp) && (player[1].y == player[1].target))
    {
      player[1].initial_y = player[1].y;
      player[1].target = player[1].y - 250;
    }
  if (sfKeyboard_isKeyPressed(sfKeyY) && player[1].hp > 0)
      player[1].hp -= 1;
}

void	movements(t_player *player, sfVector2f *map)
{
  int offset;

  offset = (player[0].x + player[1].x) / -2;
  plan(player);
  move_player_1(player, map, offset);
  if (sfKeyboard_isKeyPressed(sfKeyQ))
    move_left(player, 0, map, offset);
  else if (sfKeyboard_isKeyPressed(sfKeyD))
    move_right(player, 0, map, offset);
  else
    player[0].status = IDLE;
  if (sfKeyboard_isKeyPressed(sfKeyZ) && (player[0].y == player[0].target))
    {
      player[0].initial_y = player[0].y;
      player[0].target = player[0].y - 250;
    }
  if (sfKeyboard_isKeyPressed(sfKeyT) && player[0].hp > 0)
    player[0].hp -= 1;
  jump(player, 0, map, offset);
}

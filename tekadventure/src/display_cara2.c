/*
** display_cara2.c for  in /home/vincent/Documents/tekadventure/src
** 
** Made by vincent
** Login   <vincent.muzas@epitech.eu>
** 
** Started on  Sun May 28 21:26:12 2017 vincent
** Last update Sun May 28 21:26:51 2017 vincent
*/

#include "../my.h"

void	walk_1(t_player *player, int nb, sfIntRect rect)
{
  sfSprite_destroy(player[nb].sprite);
  player[nb].sprite = sfSprite_create();
  sfSprite_setTexture(player[nb].sprite, player[nb].cara, sfTrue);
  sfSprite_setTextureRect(player[nb].sprite, rect);
}

/*
** display_cara.c for  in /home/mathias/Bureau/projet_epitech/infograph/tekadventure
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Thu Apr 27 17:02:41 2017 Mathias
** Last update Sun May 28 21:26:56 2017 vincent
*/

#include "../my.h"

void		disp_cara(t_player *player, sfRenderWindow *window)
{
  sfVector2f	mv;

  if (player[0].x < player[1].x)
    {
      mv.x = (float)(WIDTH / 2) - ((float)(player[1].x - player[0].x)
				    / (float)2);
      mv.y = player[0].y;
      sfSprite_setPosition(player[0].sprite, mv);
      mv.y = player[1].y;
      mv.x = ((float)(WIDTH / 2) - mv.x) + (float)(WIDTH / 2);
      sfSprite_setPosition(player[1].sprite, mv);
    }
  else
    {
      mv.x = (float)(WIDTH / 2) - ((float)(player[0].x - player[1].x)
				   / (float)2);
      mv.y = player[1].y;
      sfSprite_setPosition(player[1].sprite, mv);
      mv.y = player[0].y;
      mv.x = ((float)(WIDTH / 2) - mv.x) + (float)(WIDTH / 2);
      sfSprite_setPosition(player[0].sprite, mv);
    }
  sfRenderWindow_drawSprite(window, player[0].sprite, NULL);
  sfRenderWindow_drawSprite(window, player[1].sprite, NULL);
}

void	init_texture_player(t_player *player)
{
  if (player[0].hero_selected == ARCHER)
    player[0].cara = sfTexture_createFromFile("Sprites/archer.png", NULL);
  else if (player[0].hero_selected == GUNMAN)
    player[0].cara = sfTexture_createFromFile("Sprites/gunman.png", NULL);
  else if (player[0].hero_selected == LANCER)
    player[0].cara = sfTexture_createFromFile("Sprites/lancer.png", NULL);
  else if (player[0].hero_selected == SABER)
    player[0].cara = sfTexture_createFromFile("Sprites/saber.png", NULL);
  if (player[1].hero_selected == ARCHER)
    player[1].cara = sfTexture_createFromFile("Sprites/archer.png", NULL);
  else if (player[1].hero_selected == GUNMAN)
    player[1].cara = sfTexture_createFromFile("Sprites/gunman.png", NULL);
  else if (player[1].hero_selected == LANCER)
    player[1].cara = sfTexture_createFromFile("Sprites/lancer.png", NULL);
  else if (player[1].hero_selected == SABER)
    player[1].cara = sfTexture_createFromFile("Sprites/saber.png", NULL);
}


void		is_walking(t_player *player, int nb)
{
  sfIntRect	rect;

  rect.top = 32 * player[nb].facing;
  rect.width = 32;
  rect.height = 32;
  if (player[nb].time == 2)
    {
      if (player[nb].frame == 10)
	player[nb].frame = 0;
      else
	player[nb].frame += 1;
      player[nb].time = 0;
      rect.left = 32 * player[nb].frame;
      walk_1(player, nb, rect);
    }
  else
    {
      player[nb].time += 1;
      rect.left = 32 * player[nb].frame;
      walk_1(player, nb, rect);
    }
}

void		is_standing(t_player *player, int nb)
{
  sfIntRect	rect;

  rect.left = 0;
  rect.top = 32 * player[nb].facing;
  rect.width = 32;
  rect.height = 32;
  sfSprite_destroy(player[nb].sprite);
  player[nb].sprite = sfSprite_create();
  sfSprite_setTexture(player[nb].sprite, player[nb].cara, sfTrue);
  sfSprite_setTextureRect(player[nb].sprite, rect);
  player[nb].time = 0;
  player[nb].frame = 0;
}

void		sprite_of_cara(t_player *player, sfRenderWindow *window)
{
  if (player[0].status == WALKING)
    is_walking(player, 0);
  else
    is_standing(player, 0);
  if (player[1].status == WALKING)
    is_walking(player, 1);
  else
    is_standing(player, 1);
  plan(player);
  disp_cara(player, window);
}

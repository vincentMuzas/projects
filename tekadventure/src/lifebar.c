/*
** lifebar.c for  in /home/vincent/Documents/tekadventure/src
** 
** Made by vincent
** Login   <vincent.muzas@epitech.eu>
** 
** Started on  Tue May 23 04:05:14 2017 vincent
** Last update Sun May 28 02:05:36 2017 vincent
*/

#include "../my.h"
#include "../Dylan/Gauge/include/my.h"
#include "../Dylan/Gauge/include/gauge.h"
#include "../Dylan/Gauge/include/usefull_dylan.h"

void		print_health_bar1(sfRenderWindow *window, t_player *player,
				  t_texture textures)
{
  sfSprite      *sprite;
  sfVector2f    pos;
  sfColor       color;
  float         hp;
  sfIntRect     rect;

  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, textures.hp_bar, sfTrue);
  color = get_gauge_color_1(player[0].hp, 100);
  sfSprite_setColor(sprite, color);
  pos.x = 6;
  pos.y = 21;
  rect.left = rect.top = 0;
  rect.width = sfTexture_getSize(textures.hp_bar).x * player[0].hp / 100;
  rect.height = sfTexture_getSize(textures.hp_bar).y;
  sfSprite_setTextureRect(sprite, rect);
  sfSprite_setPosition(sprite, pos);
  pos.x= 1.3;
  pos.y= 1.3;
  sfSprite_setScale(sprite, pos);
  sfRenderWindow_drawSprite(window, sprite, NULL);
  sfSprite_destroy(sprite);
}

void		print_health_bar2(sfRenderWindow *window, t_player *player,
				  t_texture textures)
{
  sfSprite      *sprite;
  sfVector2f    pos;
  sfColor       color;
  float         hp;
  sfIntRect     rect;

  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, textures.hp_bar, sfTrue);
  color = get_gauge_color_1(player[1].hp, 100);
  sfSprite_setColor(sprite, color);
  pos.x = 1910;
  pos.y = 37;
  rect.left = rect.top = 0;
  rect.width = sfTexture_getSize(textures.hp_bar).x * player[1].hp / 100;
  rect.height = sfTexture_getSize(textures.hp_bar).y;
  sfSprite_setTextureRect(sprite, rect);
  sfSprite_setPosition(sprite, pos);
  sfSprite_setRotation(sprite, 180);
  pos.x = 1.3;
  pos.y = 1.3;
  sfSprite_setScale(sprite, pos);
  sfRenderWindow_drawSprite(window, sprite, NULL);
  sfSprite_destroy(sprite);
}

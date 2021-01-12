/*
** manage_parallax.c for  in /home/Majoris/1_new_tek
** 
** Made by Florian ESCUDE
** Login   <Majoris@epitech.net>
** 
** Started on  Mon May  8 18:19:08 2017 Florian ESCUDE
** Last update Sun May 28 18:18:47 2017 Florian ESCUDE
*/

#include "../../../include/menu.h"

void	move_stars(sfSprite **imgs, t_menu *menu)
{
  sfSprite_setPosition(imgs[0], create_fvector(menu->st_1, 0));
  sfSprite_setPosition(imgs[1], create_fvector(menu->st_2, 0));
  menu->st_1 += 0.2;
  menu->st_2 += 0.2;
  if (menu->st_2 > 1920)
    menu->st_2 = -1919;
  if (menu->st_1 > 1920)
    menu->st_1= -1919;
}

void	move_background(sfSprite **imgs, t_menu *menu)
{
  sfSprite_setPosition(imgs[2], create_fvector(menu->moon_x, menu->moon_y));
  sfSprite_setPosition(imgs[3], create_fvector(menu->bck1, 0));
  sfSprite_setPosition(imgs[4], create_fvector(menu->bck2, 0));
  menu->bck1 += 0.6;
  menu->bck2 += 0.6;
  if (menu->moon_x < 1940)
    menu->moon_x += 0.3;
  if (menu->moon_y < 1120)
    menu->moon_y += 0.1;
  if (menu->bck2 > 1920)
    menu->bck2 = -1919;
  if (menu->bck1 > 1920)
    menu->bck1 = -1919;
}

void	move_clouds(sfSprite **imgs, t_menu *menu)
{
  sfSprite_setPosition(imgs[5], create_fvector(menu->cld1, 0));
  sfSprite_setPosition(imgs[6], create_fvector(menu->cld2, 0));
  menu->cld1 += 0.7;
  menu->cld2 += 0.7;
  if (menu->cld2 > 1920)
    menu->cld2 = -1080;
  if (menu->cld1 > 1920)
    menu->cld1 = -1080;
}

void	manage_parallax(sfSprite **imgs, sfRenderWindow *window, t_menu *menu)
{
  move_stars(imgs, menu);
  move_background(imgs, menu);
  move_clouds(imgs, menu);
  render_sprites(imgs, window);
}

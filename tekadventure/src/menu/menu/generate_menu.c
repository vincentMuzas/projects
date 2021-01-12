/*
** generate_menu.c for  in /home/Majoris/1_new_tek
** 
** Made by Florian ESCUDE
** Login   <Majoris@epitech.net>
** 
** Started on  Mon May  8 16:54:48 2017 Florian ESCUDE
** Last update Sun May 28 18:17:35 2017 Florian ESCUDE
*/

#include "../../../include/menu.h"

void	edit_img_menu(t_menu *menu)
{
  sfSprite_setPosition(menu->imgs[0], create_fvector(-1920, 0));
  sfSprite_setPosition(menu->imgs[1], create_fvector(0, 0));
  sfSprite_setPosition(menu->imgs[2], create_fvector(100, 100));
  sfSprite_scale(menu->imgs[3], create_fvector(1.875, 1.543));
  sfSprite_scale(menu->imgs[4], create_fvector(1.875, 1.543));
  sfSprite_setPosition(menu->imgs[3], create_fvector(-1920, 0));
  sfSprite_setPosition(menu->imgs[4], create_fvector(0, 0));
  sfSprite_setPosition(menu->imgs[5], create_fvector(-1080, 20));
  sfSprite_setPosition(menu->imgs[6], create_fvector(300, 0));
  sfSprite_scale(menu->imgs[7], create_fvector(0.9, 0.9));
  sfSprite_setPosition(menu->imgs[7], create_fvector(580, 140));
}

void	edit_char_menu(sfSprite *sprite, t_graph *graph)
{
  sfIntRect rect;

  graph->rect.top = 0;
  graph->rect.left = 0;
  graph->rect.width = 32;
  graph->rect.height = 100;
  sfSprite_scale(sprite, create_fvector(6.01, 6.01));
  sfSprite_setPosition(sprite, create_fvector(WIDTH - 1500, HEIGHT / 3));
  sfSprite_setTextureRect(sprite, graph->rect);
}

t_menu	*generate_menu(void)
{
  t_menu	*menu;

  if ((menu = malloc(sizeof(t_menu))) == NULL)
    return (NULL);
  menu->imgs = read_sprite("./Ressources/Menu/");
  edit_img_menu(menu);
  if ((menu->titles = create_titles()) == NULL)
    return (NULL);
   menu->titles_box = create_text_bounds(menu->titles, 3);
   menu->main = create_sprite("./Ressources/Players/gunman.png");
   menu->graph = malloc(sizeof(t_graph));
   edit_char_menu(menu->main, menu->graph);
   menu->moon_x = 100;
   menu->moon_y = 100;
   menu->bck1 = -1920;
   menu->bck2 = 0;
   menu->st_1 = 0;
   menu->st_2 = -1920;
   menu->cld1 = -1080;
   menu->cld2 = 340;
   return (menu);
}

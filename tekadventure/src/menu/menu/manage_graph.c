/*
** manage_graph.c for  in /home/Majoris/1_new_tek
**
** Made by Florian ESCUDE
** Login   <Majoris@epitech.net>
**
** Started on  Sat May 13 14:11:18 2017 Florian ESCUDE
** Last update Sun May 28 15:14:15 2017 Florian ESCUDE
*/

#include "../../../include/menu.h"

void	fill_info_graph(t_menu *menu)
{
  menu->graph->player = create_fvector(WIDTH - 1500, HEIGHT / 3);
  menu->graph->start = create_fvector((float)WIDTH - 1500, (float)HEIGHT / 3);
  menu->graph->end = sfText_getPosition(menu->titles[(menu->flag - 1)]);
  menu->graph->moving = 0;
  menu->graph->distance = sqrt(pow((menu->graph->end.x -
				    menu->graph->start.x), 2)+ pow((menu->graph->end.y -
								    menu->graph->start.y), 2));
  menu->graph->dir_x = (menu->graph->end.x - menu->graph->start.x)
    / menu->graph->distance;
  menu->graph->dir_y = (menu->graph->end.y - menu->graph->start.y)
    / menu->graph->distance;
}

void	manage_graph(t_menu *menu, sfRenderWindow *window)
{
  if (menu->flag != 0 && menu->flag != 1 && menu->status != 1)
    {
      fill_info_graph(menu);
      menu->status = 1;
    }
  if (menu->graph->moving == 0)
    proceed_move(menu->graph, window, menu);
}

void	proceed_move(t_graph *graph, sfRenderWindow *window, t_menu *menu)
{
  if (graph->moving == 0)
    {
      sfSprite_setTextureRect(menu->main, graph->rect);
      graph->rect.left += 32;
      if (graph->rect.left >= 352)
	graph->rect.left = 0;
      sfSprite_setPosition(menu->main, graph->player);
      sfSprite_scale(menu->main, create_fvector(0.99, 0.99));
      graph->player.x += graph->dir_x * GRAPH_SPEED;
      graph->player.y += graph->dir_y * GRAPH_SPEED;
      if (sqrt(pow((graph->player.x - graph->start.x), 2) + pow(
								(graph->player.y - graph->start.y), 2))
	  >= graph->distance)
	graph->moving = 1;
    }
}

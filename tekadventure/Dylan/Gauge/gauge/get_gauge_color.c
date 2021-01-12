/*
** get_gauge_life_color.c for  in /home/dylan/Delivery/Project/tekadventure/Dylan
** 
** Made by Dylan
** Login   <dylan.riba@epitech.eu>
** 
** Started on  Mon May  8 11:49:03 2017 Dylan
** Last update Fri May 26 18:30:03 2017 vincent
*/

#include "../include/my.h"
#include "../include/gauge.h"
#include "../include/usefull_dylan.h"

sfColor         get_gauge_color(t_my_gauge gauge)
{
  sfColor	color;
  
  if (gauge.color_type == GAUGE_LIFE_COLOR_TYPE)
    color = get_gauge_color_1(gauge.unit, gauge.unit_max);
  else if (gauge.color_type == GAUGE_MANA_COLOR_TYPE)
    color = get_gauge_color_2(gauge.unit, gauge.unit_max);
  else
    color = sfGreen;
  return (color);
}

sfColor		get_gauge_color_1(float unit, float unit_max)
{
  sfColor	color;
  int		green;
  int		red;

  green = unit * 0.01 * 255;
  red = unit * 255;
  color = get_sfColor(red, green, 0, 255);
  return (color);
}

sfColor         get_gauge_color_2(float unit, float unit_max)
{
  sfColor       color;
  float		ratio;

  ratio = unit / unit_max;
  if (ratio >= 0.9 && ratio <= 1)
    color = get_sfColor(127, 0, 255, 255);
  else if (ratio >= 0.8 && ratio < 0.9)
    color = get_sfColor(153, 51, 255, 255);
  else if (ratio >= 0.7 && ratio < 0.8)
    color = get_sfColor(178, 102, 255, 255);
  else if (ratio >= 0.6 && ratio < 0.7)
    color = get_sfColor(204, 153, 255, 255);
  else if (ratio >= 0.5 && ratio < 0.6)
    color = get_sfColor(255, 204, 204, 255);
  else if (ratio >= 0.4 && ratio < 0.5)
    color = get_sfColor(255, 153, 153, 255);
  else if (ratio >= 0.3 && ratio < 0.4)
    color = get_sfColor(255, 102, 102, 255);
  else if (ratio >= 0.2 && ratio < 0.3)
    color = get_sfColor(255, 51, 51, 255);
  else
    color = sfRed;
  return (color);
}

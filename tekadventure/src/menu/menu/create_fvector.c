/*
** create_fvector.c for  in /home/Majoris/teky/z_new_code/menu
** 
** Made by Florian ESCUDE
** Login   <Majoris@epitech.net>
** 
** Started on  Sun Apr 30 13:11:52 2017 Florian ESCUDE
** Last update Sun May 28 14:29:23 2017 Florian ESCUDE
*/

#include "../../../include/menu.h"

sfVector2f	create_fvector(double pos_x, double pos_y)
{
  sfVector2f fvector;

  fvector.x = pos_x;
  fvector.y = pos_y;
  return (fvector);
}

/*
** contains.c for  in /home/Majoris/1_new_tek/menu
** 
** Made by Florian ESCUDE
** Login   <Majoris@epitech.net>
** 
** Started on  Tue May  9 09:53:27 2017 Florian ESCUDE
** Last update Sun May 28 14:29:17 2017 Florian ESCUDE
*/

#include "../../../include/menu.h"

sfBool	contains(sfFloatRect bounds, sfVector2i pos)
{
  return (sfFloatRect_contains(&bounds, (float)pos.x, (float)pos.y));
}

sfBool	v_contains(sfFloatRect bounds, sfVector2f pos)
{
  return (sfFloatRect_contains(&bounds, pos.x, pos.y));
}


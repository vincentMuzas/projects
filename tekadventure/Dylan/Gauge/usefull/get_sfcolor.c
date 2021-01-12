/*
** get_sfcolor.c for  in /home/dylan/Delivery/Project/tekadventure/Dylan
** 
** Made by Dylan
** Login   <dylan.riba@epitech.eu>
** 
** Started on  Sun May  7 13:14:20 2017 Dylan
** Last update Fri May 26 18:37:12 2017 vincent
*/

#include "../include/my.h"

sfColor		get_sfColor(float r, float g, float b, float a)
{
  sfColor	color;

  color.r = r;
  color.g = g;
  color.b = b;
  color.a = a;
  return (color);
}

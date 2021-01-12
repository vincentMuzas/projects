/*
** usefull_dylan.h for  in /home/dylan/Delivery/Project/tekadventure/Dylan
** 
** Made by Dylan
** Login   <dylan.riba@epitech.eu>
** 
** Started on  Mon May  8 11:09:56 2017 Dylan
** Last update Mon May  8 16:12:28 2017 Dylan
*/

/*
** get_sfColor.c
*/

sfColor         get_sfColor(float, float, float, float);

/*
** get_sfVector.c
*/

sfVector3f      get_sfVector3f(float, float, float);

sfVector2f      get_sfVector2f(float, float);

/*
** display_rectangle.c
*/

void    display_rectangle(sfVector2f, sfVector2f, t_my_framebuffer *, sfColor);

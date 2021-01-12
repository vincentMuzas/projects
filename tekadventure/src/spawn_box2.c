/*
** spawn_box2.c for  in /home/vincent/Documents/tekadventure/src
** 
** Made by vincent
** Login   <vincent.muzas@epitech.eu>
** 
** Started on  Sun May 28 21:34:48 2017 vincent
** Last update Sun May 28 21:35:54 2017 vincent
*/

 #include "../my.h"


int		random_value(void)
{
  unsigned int  rand_ptr;

  rand_ptr = (unsigned long)&rand_ptr;
  srand(rand_ptr);
  return (rand());
}

void		my_set_scale(sfSprite *sprite, float scale)
{
  sfVector2f	vector;

  vector.x = scale;
  vector.y = scale;
  sfSprite_setScale(sprite, vector);
}

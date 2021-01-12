/*
** spawn_box.c for  in /home/mathias/Bureau/projet_epitech/infograph/tekadventure
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Thu May 25 15:28:26 2017 Mathias
** Last update Sun May 28 21:36:25 2017 vincent
*/

#include "../my.h"


t_box	*init_box(void)
{
  t_box	*box;

  if ((box = malloc(sizeof(t_box))) == NULL)
    return (NULL);
  box->pos_xy = NULL;
  if ((box->texture = sfTexture_createFromFile
       ("Sprites/chest/png", NULL)) == NULL)
    return (NULL);
  box->sprite = sfSprite_create();
  box->pv = sfText_create();
  sfText_setString(box->pv, "+20 hp");
  box->power_up = sfText_create();
  sfText_setString(box->power_up, "+0.3 dmg");
  box->status = CLOSE;
  box->time = 0;
  box->frame = 0;
  box->buff = 0;
  box->rank = -1;
  return (box);
}

sfIntRect	get_rect_box(int nb)
{
  sfIntRect	rect;

  rect.width = 17;
  rect.height = 24;
  rect.top = 0;
  rect.left = (nb * 17) + 17;
  return (rect);
}

void	set_pos_text(t_box *box)
{
  box->pos_xy[box->rank]->y -= 10;
  sfText_setPosition(box->pv, *box->pos_xy[box->rank]);
  sfText_setPosition(box->power_up, *box->pos_xy[box->rank]);
  box->pos_xy[box->rank]->y += 10;
}

void	disp_box(sfRenderWindow *window, t_box *box, int rank, int set_buff)
{
  if (set_buff == 1)
    box->buff = random_value() % 2;
  box->sprite = sfSprite_create();
  box->rank = rank;
  set_pos_text(box);
  sfSprite_setTexture(box->sprite, box->texture, sfTrue);
  if (box->status == CLOSE)
    sfSprite_setTextureRect(box->sprite, get_rect_box(0));
  else
    {
      sfSprite_setTextureRect(box->sprite, get_rect_box(1));
      if (box->buff == 0)
	sfRenderWindow_drawText(window, box->pv, NULL);
      else
	sfRenderWindow_drawText(window, box->power_up, NULL);
    }
  sfSprite_setPosition(box->sprite, *box->pos_xy[rank]);
  sfRenderWindow_drawSprite(window, box->sprite, NULL);
  sfSprite_destroy(box->sprite);
}

void	chose_box(sfRenderWindow *window, t_box *box)
{
  int	i;

  i = 0;
  if (box->time == 10)
    {
      box->time = 0;
      while (box->pos_xy[i] != NULL)
	{
	  if (random_value() % box->nbr_box == 0)
	    break;
	  i += 1;
	}
      if (box->pos_xy[i] != NULL)
	disp_box(window, box, i, 0);
    }
  else
    {
      if (box->frame == FPS)
	{
	  box->frame = 0;
	  box->time += 1;
	}
      else
	box->frame += 1;
    }
}

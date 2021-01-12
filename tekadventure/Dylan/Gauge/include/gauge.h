/*
** gauge.h for  in /home/dylan/Delivery/Project/tekadventure/Dylan
** 
** Made by Dylan
** Login   <dylan.riba@epitech.eu>
** 
** Started on  Mon May  8 10:27:59 2017 Dylan
** Last update Mon May  8 16:10:59 2017 Dylan
*/

typedef struct	s_my_gauge
{
  int		unit;
  int		unit_max;
  sfVector2f	pos_start;
  sfVector2f	pos_end;
  int		side;
  int		border_size;
  int		separator_frequency;
  int		separator_size;
  int		color_type;
  sfColor	border_color;
  sfColor	separator_color;
  sfColor	background_color;
}		t_my_gauge;

#define GAUGE_SIDE_LEFT (0)
#define GAUGE_SIDE_RIGHT (1)
#define GAUGE_LIFE_COLOR_TYPE (0)
#define GAUGE_MANA_COLOR_TYPE (1)

/*     
** display_gauge.c                     
*/

void    display_gauge(t_my_gauge, t_my_framebuffer *);

void	display_gauge_border(t_my_gauge, t_my_framebuffer *);

void	display_gauge_separator(t_my_gauge, t_my_framebuffer *);

/*
** get_gauge_life_color.c
*/

sfColor	get_gauge_color(t_my_gauge);

sfColor	get_gauge_color_1(float, float);

sfColor get_gauge_color_2(float, float);

/*
** my.h for  in /home/dylan/Delivery/Project/tekadventure/Dylan
** 
** Made by Dylan
** Login   <dylan.riba@epitech.eu>
** 
** Started on  Sun May  7 12:53:41 2017 Dylan
** Last update Tue May 23 04:31:50 2017 vincent
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>

#define SCREEN_WIDTH (600)
#define	SCREEN_HEIGHT (400)
#define FRAMEBUFFER_HEIGHT (400)
#define FRAMEBUFFER_WIDTH (600)
#define FRAMEBUFFER_HEIGHT (400)
#define ERROR (84)
#define MY_EXIT_SUCCESS (0)
#define MY_EXIT_FAILURE (84)

typedef struct	s_my_framebuffer
{
  sfUint8*      pixels;
  int		width;
  int		height;
}		t_my_framebuffer;

/*
** main.c
*/

int             process_game_loop(sfRenderWindow *window, sfSprite *sprite,
				  t_my_framebuffer *framebuffer, sfTexture *texture);

/*
** my_put_pixel.c
*/

void    my_put_pixel(t_my_framebuffer *framebuffer, int x, int y,
		     sfColor color);

/*
** usefull_cGraphical.c
*/

sfRenderWindow*         create_window(char* name, int width, int height);

t_my_framebuffer        *my_framebuffer_create(int width, int height);

void    my_framebuffer_destroy(t_my_framebuffer *framebuffer);

/*
** my_strlen.c
*/

int	my_strlen(char *str);

/*
** textures.c for  in /home/vincent/Documents/tekadventure
** 
** Made by vincent
** Login   <vincent.muzas@epitech.eu>
** 
** Started on  Wed Apr 26 18:40:00 2017 vincent
** Last update Sun May 28 18:33:17 2017 vincent
*/

#include "../my.h"

void	free_everything(t_texture texture, sfRenderWindow *window,
			 t_player *players)
{
  sfTexture_destroy(texture.mountains1);
  sfTexture_destroy(texture.mountains2);
  sfTexture_destroy(texture.clouds);
  sfTexture_destroy(texture.ground);
  sfTexture_destroy(texture.hp_bar);
  sfTexture_destroy(texture.hp_overlay);
  sfTexture_destroy(texture.platform);
  sfTexture_destroy(texture.player1win);
  sfTexture_destroy(texture.player2win);
  sfTexture_destroy(texture.background);
  sfRenderWindow_destroy(window);
  free(players);
}

t_texture	load_textures2(t_texture texture)
{
  if ((texture.clouds = sfTexture_createFromFile
       ("Sprites/Background/bg_clouds.png", NULL)) == NULL)
    texture.error = 1;
  if ((texture.hp_bar = sfTexture_createFromFile
       ("Sprites/hp_bar.png", NULL)) == NULL)
    texture.error = 1;
  if ((texture.hp_overlay = sfTexture_createFromFile
       ("Sprites/hp_overlay.png", NULL)) == NULL)
    texture.error = 1;
  if ((texture.platform = sfTexture_createFromFile
       ("Sprites/Background/mono_block.png", NULL)) == NULL)
    texture.error = 1;
  if ((texture.player1win = sfTexture_createFromFile
       ("Sprites/player1win.png", NULL)) == NULL)
    texture.error = 1;
  if ((texture.player2win = sfTexture_createFromFile
       ("Sprites/player2win.png", NULL)) == NULL)
    texture.error = 1;
  return (texture);
}

t_texture	load_textures(int fd)
{
  t_texture texture;

  texture.error = 0;
  if ((texture.mountains1 = sfTexture_createFromFile
       ("Sprites/Background/bg_montagne_1.png", NULL)) == NULL)
    texture.error = 1;
  if ((texture.mountains2 = sfTexture_createFromFile
       ("Sprites/Background/bg_montagne_2.png", NULL)) == NULL)
    texture.error = 1;
  if ((texture.ground = sfTexture_createFromFile
       ("Sprites/Background/block.png", NULL)) == NULL)
    texture.error = 1;
  if ((texture.background = sfTexture_createFromFile
       ("Sprites/background.png", NULL)) == NULL)
    texture.error = 1;
  texture = load_textures2(texture);
  return (texture);
}

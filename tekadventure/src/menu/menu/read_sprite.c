/*
** read_sprite.c for  in /home/Majoris/teky/z_new_code/menu
** 
** Made by Florian ESCUDE
** Login   <Majoris@epitech.net>
** 
** Started on  Sun May  7 14:59:43 2017 Florian ESCUDE
** Last update Sun May 28 20:55:23 2017 vincent
*/

#include "../../../include/menu.h"

char	*get_img_path(char *folder_name, char *image_name)
{
  char	*img_path;
  int	total_len;

  total_len = my_strlen(image_name) + my_strlen(folder_name) + 1;
  if ((img_path = malloc(sizeof(char) * (total_len))) == NULL)
    {
      write(2, "Failed to get image path.\n", 27);
      return (NULL);
    }
  img_path = my_strjoin(folder_name, image_name, img_path);
  return (img_path);
}

sfSprite	*create_sprite(char *texture_path)
{
  sfSprite	*sprite;
  sfTexture	*texture;

  if ((sprite = sfSprite_create()) == NULL)
    {
      write(2, "Failed to create sprite.\n", 26);
      return (NULL);
    }
  if ((texture = sfTexture_createFromFile(texture_path, NULL)) == NULL)
    {
      write(2, "Failed to create texture.\n", 27);
      return (NULL);
    }
  sfSprite_setTexture(sprite, texture, sfTrue);
  return (sprite);
}

int	get_sprite_number(char *folder_name)
{
  int	n_sprites;
  DIR	*dirp;
  struct dirent *dp;

  n_sprites = 0;
  if ((dirp = opendir(folder_name)) == NULL)
    {
      write(2, "Could not open sprites' directory.\n", 37);
      return (-1);
    }
  while ((dp = readdir(dirp)) != NULL)
    {
      if (my_strcmp(dp->d_name + my_strlen(dp->d_name) - 4, ".png") == 0)
	n_sprites++;
    }
  closedir(dirp);
  return (n_sprites);
}

sfSprite	**load_sprite_imgs(char	*folder_name, sfSprite **sprites)
{
  DIR	*dirp;
  struct dirent *dp;
  int	i;
  char	*img;

  i = 0;
  if ((dirp = opendir(folder_name)) == NULL)
    return (NULL);
  while ((dp = readdir(dirp)) != NULL)
    {
      if ((img = get_img_path(folder_name, dp->d_name)) == NULL)
	return (NULL);
      if (my_strcmp(dp->d_name + my_strlen(dp->d_name) - 4, ".png") == 0)
	{
	  if ((sprites[i] = create_sprite(img)) == NULL)
	    return (NULL);
	  i++;
	}
      free(img);
    }
  sprites[i] = NULL;
  closedir(dirp);
  return (sprites);
}

sfSprite	**read_sprite(char *folder_name)
{
  sfSprite	**sprites;
  int		n_sprites;
  int		i;

  i = 0;
  if ((n_sprites = get_sprite_number(folder_name)) == -1)
    return (NULL);
  if (n_sprites == 0)
    {
      write(2, "Invalid folder: no sprites found.\n", 35);
      return (NULL);
    }
  if ((sprites = malloc(sizeof(sfSprite *) * (n_sprites + 1))) == NULL)
    return (NULL);
  if ((sprites = load_sprite_imgs(folder_name, sprites)) == NULL)
    return (NULL);
  return (sprites);
}

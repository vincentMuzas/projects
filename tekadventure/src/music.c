/*
** music.c for  in /home/mathias/Bureau/projet_epitech/infograph/tekadventure
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Wed May  3 17:16:22 2017 Mathias
** Last update Sun May 28 02:06:56 2017 vincent
*/

#include "../my.h"

sfMusic		*let_s_play_it(char *str)
{
  sfMusic	*music;

  music = sfMusic_createFromFile(str);
  sfMusic_setLoop(music, sfFalse);
  sfMusic_play(music);
  return (music);
}

sfMusic		*let_play_and_reapeat(char *str)
{
  sfMusic	*music;

  music = sfMusic_createFromFile(str);
  sfMusic_setLoop(music, sfTrue);
  sfMusic_play(music);
  return (music);
}

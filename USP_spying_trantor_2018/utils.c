/*
** EPITECH PROJECT, 2018
** spying_trantor
** File description:
** utils.c
*/

#include "spying_trantor.h"

int is_Valid_Ip_Address(char *ipAddress)
{
  struct sockaddr_in sa;
  int result = inet_pton(AF_INET, ipAddress, &(sa.sin_addr));
  return (result != 0);
}

int str_is_digit(char *str)
{
  int i = 0;
  while (str[i] != 0)
  {
    if (!isdigit(str[i])) {
      printf("error at index %d\n", i);
      return (0);
    }
    i++;
  }
  return (1);
}

void print_help(char *name)
{
  printf("USAGE: %s ip port squad [script]\n", name);
}
/*
** EPITECH PROJECT, 2019
** rush3
** File description:
** rush3.h
*/

#ifndef RUSH3_H_
#define RUSH3_H_

#include <stdlib.h>

typedef struct liste_s
{
    char *str;
    struct liste_s *next;
} liste_t;

int detect1(liste_t *);
int detect2(liste_t *);
int detect3(liste_t *);
int detect4(liste_t *);
int detect5(liste_t *);
int middle_is(char *, char);
int size(liste_t *);
int detect_line(char *str, char c);


#endif /* !RUSH3_H_ */

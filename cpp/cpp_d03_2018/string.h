/*
** EPITECH PROJECT, 2019
** cpp_d03_2018
** File description:
** string
*/

#ifndef MYSTRING_H_
	#define MYSTRING_H_

#include <stddef.h>

typedef struct string_s {
    char *str;
    void (*assign_s)(struct string_s *, const struct string_s *);
    void (*assign_c)(struct string_s *, const char *);
    void (*append_s)(struct string_s *, const struct string_s *);
    void (*append_c)(struct string_s *, const char *);
    char (*at)(const struct string_s *, size_t);
    void (*clear)(struct string_s *);
    int (*size)(const struct string_s *);
    int (*compare_s)(const struct string_s *, const struct string_s *str);
    int (*compare_c)(const struct string_s *, const char *str);
    size_t (*copy)(const struct string_s *, char *s, size_t n, size_t pos);
    const char *(*c_str)(const struct string_s *);
    int (*empty)(const struct string_s *);
    int (*find_s)(const struct string_s*,const struct string_s *str,size_t pos);
    int (*find_c)(const struct string_s *, const char *str, size_t pos);
} string_t;

/**
 * ex00.c
 */
void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);

/***
 * utils.c
 */
char *cpy(char *dest, const char *src);
int len(const char *str);


#endif /* !MYSTRING_H_ */
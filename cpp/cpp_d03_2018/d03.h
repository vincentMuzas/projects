/*
** EPITECH PROJECT, 2019
** cpp_d03_2018
** File description:
** d03
*/

#ifndef D03_H_
	#define D03_H_

#include "string.h"

/**
 * ex01.c
 */
void assign_s(string_t *, const string_t *);
void assign_c(string_t *, const char *);
void append_s(string_t *this, const string_t *ap);

/**
 * ex02.c
 */
void append_s(string_t *this, const string_t *ap);
void append_c(string_t *this, const char *ap);

/**
 * ex03.c
 */
char at(const string_t *, size_t);

/**
 * ex04-07.c
 */
void clear(string_t *this);
int size(const string_t *this);
int compare_s(const string_t *this, const string_t *str);
int compare_c(const string_t *this, const char *str);
size_t copy(const string_t *this, char *s, size_t n, size_t pos);

/**
 * ex08-10.c
 */
const char *c_str(const string_t *this);
int empty(const string_t *this);
int find_s(const string_t *this, const string_t *str, size_t pos);
int find_c(const string_t *this, const char *str, size_t pos);

#endif /* !D03_H_ */

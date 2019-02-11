/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** geters.c
*/

#include "malloc.h"

size_t get_enough_space(size_t size)
{
	size_t res = 2;

	while (res < size)
		res *= 2;
	return (res);
}

size_t get_enough_pages(size_t size)
{
	size_t res;

	while (res < size + sizeof(header_t))
		res += PAGES;
	return (res);
}

header_t *getstart(size_t size)
{
	static header_t *start = NULL;

	if (start == NULL) {
		start = sbrk(0);
		start = sbrk(size);
	}
	return (start);
}
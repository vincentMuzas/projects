/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc
*/

#include "malloc.h"

void *calloc(size_t nmemb, size_t size)
{
	void *tmp = NULL;

	if (!(nmemb == 0 || size == 0)) {
		tmp = malloc(nmemb * size);
		if (tmp != NULL)
			memset(tmp, 0, nmemb * size);
	}
	return (tmp);
}

void *malloc(size_t size)
{
	static void *brk_ptr = NULL;
	header_t *loc;

	if (brk_ptr == NULL) {
		if ((brk_ptr =
		getstart(get_enough_pages(get_enough_space(size)))) == NULL)
			return (NULL);
		brk_ptr += get_enough_pages(get_enough_space(size));
		getstart(0)->next = NULL;
		getstart(0)->size = get_enough_space(size);
		getstart(0)->used = size;
		getstart(0)->is_free = USED;
		return ((void *)(getstart(0)) + sizeof(header_t));
	}
	if ((loc = bestfit(brk_ptr, get_enough_space(size))) != NULL) {
		loc->is_free = USED;
		loc->used = size;
		return ((void *)loc + sizeof(header_t));
	}
	if (sbrk(get_enough_pages(get_enough_space(size))) == (void *)-1)
		return (NULL);
	brk_ptr += get_enough_pages(get_enough_space(size));
	return (malloc(size));
}

void free(void *ptr)
{
	header_t *tmp;
	if (ptr != NULL) {
		if (is_valid(ptr) == 0)
			exit(84);
		tmp = ptr - sizeof(header_t);
		tmp->is_free = FREE;
		tmp->used = 0;
		merge_it();
	}
}

void *realloc(void *ptr, size_t size)
{
	header_t *tmp = NULL;
	void *new;

	if (ptr != NULL) {
		if (size == 0) {
			free(ptr);
			return (NULL);
		}
		tmp = ptr - sizeof(header_t);
		if (size <= tmp->size)
			return (ptr);
		new = memcpy(malloc(size), ptr, tmp->used);
		ptr = new;
		return (new);
	} else {
		return (malloc(size));
	}
}

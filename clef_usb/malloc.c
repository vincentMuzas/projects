/*
** EPITECH PROJECT, 2018
** Malloc
** File description:
** 
*/

#include "includes/malloc.h"
#include <pthread.h>

static header_t *start()
{
	static header_t *start = NULL;
	if (start == NULL)
		start = sbrk(0);
	return (start);
}

int is_valid(void *ptr)
{
	header_t *loc = start();

	while (loc != NULL && (void *)loc < ptr){
		if (loc->ptr_start == ptr)
			return (1);
		loc = loc->next;
	}
	return (0);
}

static size_t get_enough_space(size_t size)
{
	size_t ret = 2;

	while (ret < size)
		ret *= 2;
	return (ret);
}

static size_t get_enough_pages(size_t size)
{
	size_t ret = sizeof(header_t);

	while (ret <= size)
		ret += getpagesize();
	return (ret);
}

static void *bestfit(void *end, size_t size)
{
	header_t *tmp = start();
	header_t *best = NULL;
	write(1, "bestfit\n", 8);
	while (tmp->next != NULL/* && (void *)tmp->next <= end && (void *)tmp->next >= (void *)start*/) {
		write(1, "start while\n", 12);
		if (tmp->is_free == 1 && best == NULL)
			best = tmp;
		else if (tmp->size - tmp->used >= size + sizeof(header_t) &&
				best != NULL && best->size - best->used > tmp->size - tmp->used)
			best = tmp;
		write(1, "before\n", 7);
		tmp = tmp->next;
		write(1, "after\n", 6);
	}
	write(1, "ccc\n", 4);
	if (best == NULL)
		write(1, "NULL\n", 5);
	if (best == NULL && (void *)tmp + (sizeof(header_t) * 2) + tmp->size + size <= end) {
		write(1, "ddd\n", 4);
		tmp->next = (void *)tmp + sizeof(header_t) + tmp->size;
		tmp = tmp->next;
		tmp->size = size;
		tmp->ptr_start = (void *)tmp + sizeof(header_t);
		tmp->next = NULL;
		best = tmp;
	} else if (best != NULL && best->used != 0) {
		write(1, "kkk\n", 4);
		tmp = (void *)best + sizeof(header_t) + best->used;
		tmp->size = best->size - best->used - sizeof(header_t);
		tmp->next = best->next;
		best->next = (void *)tmp;
		best->size = best->used;
		tmp->ptr_start = (void *)tmp + sizeof(header_t);
		best = tmp;
	}
	write(1, "end bestfit\n", 12);
	return (best);
}

void	my_putnbr(size_t nb)
{
  char	robert;
  size_t	mult;
  int	i;

  i = 0;
  mult = 1;
  while (nb / mult >= 10)
    mult = mult * 10;
  while (mult >= 1)
    {
      robert = nb / mult + '0';
      write(1, &robert, 1);
      nb = nb % mult;
      mult = mult / 10;
    }
    write(1, "\n", 1);
}

void *malloc(size_t size)
{
	static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
	static void *brk_ptr = NULL;
	header_t *loc;
	pthread_mutex_lock(&mutex);
	my_putnbr(size);
	my_putnbr(get_enough_space(size));
	write(1, "malloc\n", 7);
	if (brk_ptr == NULL) {
		brk_ptr = sbrk(0);
		start();
		brk_ptr = sbrk(get_enough_pages(get_enough_space(size)));
		brk_ptr = sbrk(0);
		start()->ptr_start = start() + sizeof(header_t);
		start()->size = get_enough_space(size);
		start()->used = size;
		start()->is_free = 0;
		start()->next = NULL;
		write(1, "street malloc\n", 14);
	}
	else if ((loc = bestfit(brk_ptr, get_enough_space(size))) != NULL) {
		loc->is_free = 0;
		loc->used = size;
		write(1, "end malloc1\n", 12);
		pthread_mutex_unlock(&mutex);
		return (loc->ptr_start);
	} else {
		sbrk(get_enough_pages(get_enough_space(size)));
		brk_ptr = sbrk(0);
		write(1, "end malloc2\n", 12);
		pthread_mutex_unlock(&mutex);
		return (malloc(size));
	}
	write(1, "end malloc\n", 11);
	pthread_mutex_unlock(&mutex);
	return (start()->ptr_start);
}

void *realloc(void *ptr, size_t size)
{
	header_t *loc = ptr - sizeof(header_t);
	void *new;
	write(1, "realloc\n", 8);
	if (!is_valid(ptr))
		return (NULL);
	if (loc->size <= size)
		return (ptr);
	new = malloc(size);
	memcpy(new, ptr, loc->size);
	write(1, "end realloc\n", 12);
	return (new);
}

static void merge_it()
{
	header_t *tmp = start();
	header_t *merge = NULL;
	write(1, "merge\n", 6);
	while (tmp->next != NULL) {
		if (tmp->is_free == 1) {
			if (merge == NULL)
				merge = tmp;
			else {
				merge->size += sizeof(header_t) + tmp->size;
				merge->next = tmp->next;
			}
		} else if (tmp->next->is_free == 1) {
			merge = tmp;
			tmp->size += sizeof(header_t) + tmp->next->size;
			tmp->next = tmp->next->next;
		} else
			merge = NULL;
		if (tmp->next != NULL)
			tmp = tmp->next;
	}
	write(1, "end merge\n", 10);
}

void free(void *ptr)
{
	header_t *tmp = start();
	write(1, "free\n", 5);
	if(ptr != NULL) {
		if (is_valid(ptr) == 0)
			exit(84);
		while (tmp->ptr_start != ptr)
			tmp = tmp->next;
		tmp->is_free = 1;
		tmp->used = 0;
		merge_it();
	}
	write(1, "end free\n", 9);
}
/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** bestfit
*/

#include "malloc.h"

header_t *bestfit2(void *end, size_t size, header_t *tmp, header_t *best)
{
	if (best == NULL && (void *)tmp +
	(sizeof(header_t) * 2) + tmp->size + size <= end) {
		tmp->next = (void *)tmp + tmp->size + sizeof(header_t);
		tmp = tmp->next;
		tmp->size = size;
		tmp->next = NULL;
		best = tmp;
	} else if (best != NULL && best->size -
	best->used >= size + sizeof(header_t)) {
		if (best->used != 0) {
			tmp = (void *)best + sizeof(header_t) + best->used;
			tmp->next = best->next;
			best->next = (void *)tmp;
			tmp->size = best->size - best->used - sizeof(header_t);
			best->size = best->used;
			best = tmp;
			best->used = size;
		}
	}
	return (best);
}

header_t *bestfit(void *end, size_t size)
{
	header_t *tmp = getstart(0);
	header_t *best = NULL;

	while (tmp != NULL) {
		if (best == NULL) {
			if (tmp->is_free == FREE)
				best = tmp;
			else if (tmp->size - tmp->used >=
			size + sizeof(header_t))
				best = tmp;
		} else if (tmp->size - tmp->used >= size + sizeof(header_t) &&
			   tmp->size - tmp->used < best->size - best->used)
			best = tmp;
		if (tmp->next == NULL)
			break;
		tmp = tmp->next;
	}
	return (bestfit2(end, size, tmp, best));
}

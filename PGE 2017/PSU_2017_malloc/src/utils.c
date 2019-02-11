/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** utils
*/

#include "malloc.h"

void my_putnbr(size_t nb, size_t base)
{
  	char	robert;
  	size_t mult;

  	mult = 1;
  	while (nb / mult >= base)
    		mult = mult * base;
  	while (mult >= 1)
    	{
      		robert = nb / mult;
      		if (robert < 10)
			robert += '0';
		else
			robert = robert - 10 + 'A';
		write(1, &robert, 1);
      		nb = nb % mult;
      		mult = mult / base;
	}
}

void show_alloc_mem()
{
	header_t *tmp = getstart(0);

	write(1, "break : 0x", 11);
	my_putnbr((size_t)sbrk(0), 16);
	while (tmp != NULL) {
		if (tmp->is_free == USED) {
			write(1, "0x", 2);
			my_putnbr((size_t)((void *)tmp), 16);
			write(1, " - 0x", 5);
			my_putnbr(((size_t)((void *)tmp) + tmp->size), 16);
			write(1, " : ", 3);
			my_putnbr(tmp->size, 10);
			write(1, " bytess\n", 8);
		}
		tmp = tmp->next;
	}
}

int is_valid(void *ptr)
{
	header_t *loc = getstart(0);

	while (loc != NULL && (void *)loc < ptr){
		if ((void *)loc + sizeof(header_t) == ptr)
			return (1);
		loc = loc->next;
	}
	return (0);
}

void merge_it(void)
{
	header_t *start = getstart(0);
	header_t *merge = NULL;

	while (start != NULL) {
		if (start->is_free == USED && start->next != NULL &&
		start->next->is_free == FREE)
			merge = start;
		else if (start->is_free == USED)
			merge = NULL;
		if (merge == NULL && start->is_free == FREE)
			merge = start;
		else if (merge != NULL && start->is_free == FREE) {
			merge->next = start->next;
			merge->size += start->size + sizeof(header_t);
		}
		start = start->next;
	}
}
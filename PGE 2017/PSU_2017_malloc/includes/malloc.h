/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** header
*/

#ifndef MALLOC_H_
#define MALLOC_H_

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

#define PAGES getpagesize()

enum {
	FREE = 1,
	USED = 0
};

typedef struct header_s {
	struct header_s *next;
	size_t size;
	size_t used;
	int is_free;
}		header_t;

size_t get_enough_space(size_t size);
size_t get_enough_pages(size_t size);
header_t *getstart(size_t size);

header_t *bestfit2(void *end, size_t size, header_t *tmp, header_t *best);
header_t *bestfit(void *end, size_t size);

void my_putnbr(size_t nb, size_t base);
void show_alloc_mem();
int is_valid(void *ptr);
void merge_it(void);

#endif /* !MALLOC_H_ */

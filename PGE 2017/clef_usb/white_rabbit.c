/*
** EPITECH PROJECT, 2018
** white_rabbit.c
** File description:
** follow_the_white_rabbit
*/

#include <stdio.h>
#include <stdlib.h>

int follow_the_white_rabbit(void)
{
	long int i = 0, res = 0;

	while (1) {
		i = (random() % 37) + 1;
		res += i;
		if (i % 11 == 0 || i == 12)
			continue;
		if (i == 37 || res == 421 || res >= 397 || i == 1)
			break;
		if (i == 23 || i == 15 || i == 10)
			printf("forward\n");
		if (i == 26 || i % 8 == 0)
			printf("backward\n");
		if ((i >= 4 && i <= 6) || i == 28 || (i >= 17 && i <= 21))
			printf("left\n");
		if (i == 13 || i >= 34)
			printf("right\n");
	}
	printf("RABBIT!!!\n");
	return ((int)res);
}

// 1. 421, 2. 447, 3. 424
// 1. OK, 2. OK, 3. output

int main(void)
{
	int i;

	srandom(421);
	i = follow_the_white_rabbit();
	printf("%d\n", i);
	return(i);
	/* int i = 0; */

	/* while (follow_the_white_rabbit() != 374) */
	/* 	srandom(++i); */
	/* printf("%d\n", i); */
}

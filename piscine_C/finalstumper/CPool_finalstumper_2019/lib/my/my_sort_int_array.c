/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** my_sort_int_array
*/

void my_swap(int *a, int *b);

void my_sort_int_array(int *array, int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j+1])
                my_swap(&array[j], &array[j+1]);
        }
    }
}
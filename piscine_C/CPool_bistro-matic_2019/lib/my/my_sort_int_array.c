/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** my_sort_int_array
*/

void my_sort_int_array(int *array, int size)
{
    int i = 0, mod = 0, tmp;

    if (i >= size)
        return;
    while (1) {
        if (array[i] > array[i + 1]) {
            tmp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = tmp;
            mod = 1;
        }
        i++;
        if (i == size) {
            i = 0;
            if (mod == 0)
                break;
            mod = 0;
        }
    }
}

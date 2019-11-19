/*
** EPITECH PROJECT, 2019
** fir_tree
** File description:
** main
*/

void my_putchar(char c);

void print_xtime(char c, int ocurances)
{
    int i = 0;
    while (i < ocurances) {
        my_putchar(c);
        i++;
    }
}

int calc_middle(int size)
{
    int width = 0;
    int current_flor = 0;
    int detab = 1;
    while (current_flor < size) {
        width += current_flor + 4;
        if (current_flor % 2 == 0)
            detab ++;
        width -= detab;
        current_flor++;
    }
    return (width + ((current_flor + 1) / 2));
}

void print_tronc(int size)
{
    int spaces = calc_middle(size) - (size / 2);
    int pipes = ((size / 2) * 2) + 1;
    int i = 0;
    while (i < size) {
        print_xtime(' ', spaces);
        print_xtime('|', pipes);
        my_putchar('\n');
        i++;
    }
}

void tree(int size)
{
    int spaces = calc_middle(size);
    int flor_status = 4;
    int flor_nb = 1;
    int stars = 1;
    while (flor_nb <= size) {
        print_xtime(' ', spaces);
        print_xtime('*', stars);
        my_putchar('\n');
        spaces -= 1;
        flor_status--;
        if (flor_status == 0) {
            spaces += ((flor_nb + 1) / 2) + 1;
            stars -= (((flor_nb + 1) / 2) + 1) * 2;
            flor_nb += 1;
            flor_status = flor_nb + 3;
        }
        stars += 2;
    }
    print_tronc(size);
}
/*
** EPITECH PROJECT, 2019
** cpp_d01_2018
** File description:
** bmp
*/

#include  <stdlib.h>
#include  <unistd.h>
#include  <fcntl.h>
#include  <string.h>
#include "drawing.h"
#include "bitmap.h"

void write_bmp_header(int fd)
{
    bmp_header_t  header;
    make_bmp_header (&header , 64);
    write(fd, &header , sizeof(header));
}
void write_bmp_info_header(int fd)
{
    bmp_info_header_t  info;
    make_bmp_info_header (&info , 64);
    write(fd, &info , sizeof(info));
}

void initialize_image(size_t size, unsigned int *buffer, unsigned  int **img)
{
    memset(buffer , 0, size * size * sizeof (* buffer));
    for (size_t i = 0; i < size; ++i)
        img[i] = buffer + i * size;
}

void create_image(size_t size, unsigned int *buffer, unsigned int **img)
{
    point_t p = { 0, 0 };
    initialize_image(size * 9 , buffer , img);
    draw_square(img , &p, size , 0x0000FFFF);
    p.y = 3;
    p.x = 3;
    draw_square(img , &p, 22, 0x00CC0000);
}

void create_bitmap_from_buffer(size_t size, unsigned int *buffer)
{
    int fd = open("square.bmp", O_CREAT | O_TRUNC | O_WRONLY , 0644);
    write_bmp_header(fd);
    write_bmp_info_header(fd);
    write(fd, buffer , size * size * sizeof (* buffer));
    close(fd);
}
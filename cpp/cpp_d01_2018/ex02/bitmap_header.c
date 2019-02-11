/*
** EPITECH PROJECT, 2019
** cpp_d01_2018
** File description:
** bitmap_header
*/

#include "bitmap.h"

void make_bmp_header(bmp_header_t *header, size_t size){
    header->magic = 0x4d42;
    header->size = size;
    header->_app1 = 0;
    header->_app2 = 0;
    header->offset = sizeof(bmp_header_t) + sizeof(bmp_info_header_t);
}

void make_bmp_info_header(bmp_info_header_t *header, size_t size)
{
    header->size = 40;
    header->width = size;
    header->height = size;
    header->planes = 1;
    header->bpp = 32;
    header->compression = 0;
    header->raw_data_size = 32 * size * size;
    header->h_resolution = 0;
    header->v_resolution = 0;
    header->palette_size = 0;
    header->important_colors = 0;
}
/*
** EPITECH PROJECT, 2019
** cpp_d01_2018
** File description:
** bitmap
*/

#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

typedef struct __attribute__((packed)) bmp_header_t {
    uint16_t magic;
    uint32_t size;
    uint16_t _app1;
    uint16_t _app2;
    uint32_t offset;
} bmp_header_t;

typedef struct __attribute__((packed)) bmp_info_header_t {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bpp;
    uint32_t compression;
    uint32_t raw_data_size;
    int32_t h_resolution;
    int32_t v_resolution;
    uint32_t palette_size;
    uint32_t important_colors;
} bmp_info_header_t;

void make_bmp_header(bmp_header_t *header, size_t size);
void make_bmp_info_header(bmp_info_header_t *header, size_t size);
void create_image(size_t size, unsigned int *buffer, unsigned int **img);
void create_bitmap_from_buffer(size_t size, unsigned int *buffer);
/*
** EPITECH PROJECT, 2018
** bmpheader
** File description:
** 
*/

#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

typedef struct bmp_header_t {
	uint16_t magic;
	uint32_t size;
	uint16_t _app1;
	uint16_t _app2;
	uint32_t offset;
} bmp_header_t;

typedef struct bmp_info_header_t {
	uint32_t size;
	int32_t width;
	int32_t height;
	uint16_t planes;
	uint16_t bpp;
	uint32_t compression;
	uint16_t raw_data_size;
	int32_t h_resolution;
	int32_t v_resolution;
	uint32_t palette_size;
	uint32_t important_colors;
} bmp_info_header_t;

/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** .h
*/

#ifndef OBJDUMP_H_
	#define OBJDUMP_H_

#include "libs.h"

#define TO_PRINT(c) (isprint(c) ? c : '.')

int ignore_section(const char *str);
void parse_flags(long flag);

long get_flags64(char *buf);
long header64(char *map, char *file);
void print_section64(Elf64_Shdr shdr, char *buf);
void print_name64(char *buf);

long get_flags32(char *buf);
long header32(char *map, char *file);
void print_name32(char *buf);
void print_section32(Elf32_Shdr shdr, char *buf);

void endline(unsigned long index, unsigned int size);

typedef unsigned char Uchar;

#endif /* !OBJDUMP_H_ */
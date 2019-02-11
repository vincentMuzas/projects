/*
** EPITECH PROJECT, 2018
** flags32
** File description:
** objdump
*/

#include "libs.h"
#include "objdump.h"
#include "flags.h"

long get_flags(char *buf)
{
	Elf32_Ehdr *ehdr = (Elf32_Ehdr*)buf;
	Elf32_Shdr *shdr = (Elf32_Shdr *)(buf + ehdr->e_shoff);
	int shnum = ehdr->e_shnum;
	long flags = 0x0;

	for (int i = 0; i < shnum; ++i) {
		flags |= shdr[i].sh_flags;
	}
	return (flags);
}

long header32(char *map, char *file)
{
	long flags = get_flags(map);
	Elf32_Ehdr *header = (Elf32_Ehdr *)map;

	printf("%*c", 17 - (printf("\n%s:", file)), ' ');
	printf("file format elf32-i386\n");
	printf("architecture: i386, flags ");
	printf("0x%08lx\n", flags);
	parse_flags(flags);
	printf("start address 0x%016ux\n\n", header->e_entry);
	print_name32(map);
	return (flags);
}
/*
** EPITECH PROJECT, 2018
** flags64
** File description:
** objdump
*/

#include "libs.h"
#include "objdump.h"
#include "flags.h"

long get_flags64(char *buf)
{
	Elf64_Ehdr *ehdr = (Elf64_Ehdr*)buf;
	Elf64_Shdr *shdr = (Elf64_Shdr *)(buf + ehdr->e_shoff);
	int shnum = ehdr->e_shnum;
	long flags = 0x0;

	for (int i = 0; i < shnum; ++i) {
		flags |= shdr[i].sh_flags;
	}
	return (flags);
}

void parse_flags(long flag)
{
	int i = 0;
	long value[] = {HAS_RELOC, EXEC_P, HAS_LINENO, HAS_DEBUG, 
	HAS_SYMS, HAS_LOCALS, DYNAMIC, WP_TEXT, D_PAGED};
	char *str[] = {"HAS_RELOC", "EXEC_P", "HAS_LINENO", "HAS_DEBUG",
	"HAS_SYMS", "HAS_LOCALS", "DYNAMIC", "WP_TEXT", "D_PAGED", NULL};

	if (flag == BFD_NO_FLAGS)
		printf("BFD_NO_FLAGS");
	else while (str[i] != NULL) {
		if ((flag & value[i]) == value[i]) {
			printf("%s", str[i]);
			flag -= value[i];
			if (flag > 0)
				printf(", ");
		}
		i ++;
	}
	printf("\n");
}

long header64(char *map, char *file)
{
	long flags = get_flags64(map);
	Elf64_Ehdr *header = (Elf64_Ehdr *)map;

	printf("%*c", 17 - (printf("\n%s:", file)), ' ');
	printf("file format elf64-x86-64\n");
	printf("architecture: i386:x86-64, flags ");
	printf("0x%08lx\n", flags);
	parse_flags(flags);
	printf("start address 0x%016lx\n\n", header->e_entry);
	print_name64(map);
	return (flags);
}
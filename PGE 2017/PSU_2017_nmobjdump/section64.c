/*
** EPITECH PROJECT, 2018
** section64
** File description:
** objdump
*/

#include "objdump.h"
#include "flags.h"

void print_section64(Elf64_Shdr shdr, char *buf)
{
	unsigned long index = 0;
	unsigned long i;
	int printed = 0;
	char *s = &buf[shdr.sh_offset];

	while (index < shdr.sh_size) {
		if (index % 16 == 0) {
			printf("\n %04lx ", shdr.sh_addr + index);
			for (i = 0; i < 16 && index + i < shdr.sh_size; i++) {
				printed += printf("%02x", (Uchar)s[index + i]);
				if ((i + 1) % 4 == 0)
					printed += printf(" ");
			}
			printf("%*c", 37 - printed, ' ');
		}
		printf("%c", TO_PRINT(s[index]));
		index ++;
		endline(index, shdr.sh_size);
		printed = 0;
	}
	printf("\n");
}

void print_name64(char *buf)
{
	Elf64_Ehdr *ehdr = (Elf64_Ehdr*)buf;
	Elf64_Shdr *shdr = (Elf64_Shdr *)(buf + ehdr->e_shoff);
	int shnum = ehdr->e_shnum;

	Elf64_Shdr *sh_strtab = &shdr[ehdr->e_shstrndx];
	const char *const sh_strtab_p = buf + sh_strtab->sh_offset;

	for (int i = 0; i < shnum; ++i) {
		if (!ignore_section(sh_strtab_p + shdr[i].sh_name)) {
			printf("Contents of section %s:",
			sh_strtab_p + shdr[i].sh_name);
			print_section64(shdr[i], buf);
		}
	}
}
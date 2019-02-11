/*
** EPITECH PROJECT, 2018
** nm/objdump
** File description:
** objdump
*/

#include "libs.h"
#include "objdump.h"
#include "flags.h"

int is_elf(char *buf)
{
	char str[] = "\0ELF";

	str[0] = 127;
	if (strlen(buf) >= 4 && !strncmp(str, buf, 4))
		return (1);
	return (0);
}

int ignore_section(const char *str)
{
	char *_ignore[] = {"", ".bss", ".symtab", ".strtab",
			".shstrtab", ".rela.text", ".note.GNU-stack", 
			".rela.eh_frame", NULL};

	for (int i = 0; _ignore[i] != NULL; i++) {
		if (!strcmp(str, _ignore[i]))
			return (1);
	}
	return (0);
}

void endline(unsigned long index, unsigned int size)
{
	if (index == size && index % 16 != 0) {
		printf("%*c", 16 - size % 16, ' ');
	}
}

void objdump(char *file)
{
	int fd = open(file, O_RDONLY);
	char *buf;
	struct stat s;

	if (fd == -1)
		printf("objdump: '%s': No such file\n", file);
	else if	(stat(file, &s) == 0) {
		buf = mmap(NULL , s.st_size , PROT_READ , MAP_PRIVATE , fd, 0);
		if (is_elf(buf)) {
			if (buf[4] == 2)
				header64(buf, file);
			else if (buf[4] == 1)
				header32(buf, file);
		} else
		printf("objdump: %s: File format not recognised\n", file);
	}
}

int main(int ac, char **av)
{
	int i = 1;
	if (ac == 1) {
		objdump("a.out");
	}
	while (i < ac) {
		objdump(av[i]);
		i++;
	}
	return (0);
}
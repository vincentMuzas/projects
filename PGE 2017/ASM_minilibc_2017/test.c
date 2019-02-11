#include <string.h>
#include <stdio.h>

extern int mystrcmp(char *a, char *b);

int main()
{
	char str[16];
	char str2[16];
	char var = 'a';
	printf("strlen(\"hello\"): %lu\n", strlen("hello"));
	printf("------\nstrchr(\"hello\", 'l'): %s\n", strchr("hello", 'l'));
	printf("strchr(\"hello\", 'a'): %p\n", strchr("hello", var));
	printf("------\nmemset(str, 'a', sizeof(char *) * 10): %s\n", (char *)memset(str, 'a', sizeof(char) * 10));
	printf("memset(str, 'a', sizeof(char *) * 5): %s\n", (char *)memset(str, 'a', sizeof(char) * 5));
	printf("str = %s\n", str);
	printf("------\nstrstr(\"aabbccdd\", \"bccd\"):%s\n", strstr("aabbccdd", "bccd"));
	printf("strstr(\"aabbccdd\", \"wala\"):%p\n", strstr("aabbccdd", "wala"));
	printf("------\nmemmove before: %p\n", str2);
	printf("cmd: memmove(str2, str, 10);\n");
	memmove(str2, str, 10);
	printf("str2 content: %s\n", str2);
	printf("memmove after: %p\n", str2);
	printf("------\n");
	printf("strcspn(\"bonjour\", \"nj\"): %lu\n", strcspn("bonjour", "nj"));
	printf("strcspn(\"bonjour\", \"XD\"): %lu\n", strcspn("bonjour", "XD"));
	printf("------\nstrpbrk(\"bonjour\", \"onj\"): %s\n", strpbrk("bonjour", "onj"));
	printf("strpbrk(\"bonjour\", \"XD\"): %p\n", strpbrk("bonjour", "XD"));
	printf("------\nrindex(\"yolo\", 'l'): %s\n", rindex("yolo", 'l'));
	printf("rindex(\"yolo\", 'a'): %p\n", rindex("yolo", 'a'));
	printf("------\nstrcmp(\"bonjour\", \"bonjour\"): %d\n", mystrcmp("bonjour", "bonjour"));
	printf("strcmp(\"bonjour\", \"bonjouRE\"): %d\n", mystrcmp("bonjour", "bonjouRE"));

}
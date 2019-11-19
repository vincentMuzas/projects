#/bin/sh

gcc -c *.c -I../../include
ar rcs libmy.a *.o
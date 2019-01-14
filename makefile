all:main.c function.o
	gcc -Wall -std=c99 -pedantic function.o main.c -o avltree
	rm *.o
function.o:function.c
	gcc -Wall -std=c99 -pedantic -c function.c

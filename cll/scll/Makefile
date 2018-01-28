scll:main.o sll.o 
	gcc main.c scll.c -o scll
	rm main.o scll.o
main.o:main.c scll.h
	gcc -c main.c
scll.o:scll.c scll.h
	gcc -c scll.c

sll:sll_main.o sll.o 
	gcc sll_main.c sll.c -o sll
	rm sll_main.o sll.o
sll_main.o:sll_main.c sll.h
	gcc -c sll_main.c
sll.o:sll.c sll.h
	gcc -c sll.c

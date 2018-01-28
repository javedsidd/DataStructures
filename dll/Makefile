dll:dll_main.o dll.o 
	gcc -g dll_main.c dll.c -o dll
	rm dll_main.o dll.o
dll_main.o:dll_main.c dll.h
	gcc -g -c dll_main.c
dll.o:dll.c dll.h
	gcc -g -c dll.c

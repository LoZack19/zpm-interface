CC = /usr/bin/gcc

zpm: unirun.o interface.o main.o
	$(CC) unirun.o interface.o main.o -o zpm

unirun.o: Unirun/unirun.c
	$(CC) -c Unirun/unirun.c -o unirun.o

interface.o: interface.c
	$(CC) -c interface.c -o interface.o

main.o: main.c
	$(CC) -c main.c -o main.o


clean:
	rm *.o

install:
	sudo install zpm /usr/bin
	rm zpm

uninstall:
	rm /usr/bin/zpm
CC = gcc
AR = ar
UNIRUN = Unirun
TARGET = librgmint.a

$(TARGET): interface.o unirun.o
	$(AR) -r $(TARGET) unirun.o interface.o

interface.o: interface.h interface.c
	$(CC) -c interface.c -o interface.o

unirun.o: $(UNIRUN)/unirun.h $(UNIRUN)/unirun.c
	gcc -c $(UNIRUN)/unirun.c -o unirun.o


configure:
	git clone https://github.com/LoZack19/Unirun

clean:
	rm *.o

clean_all: clean
	rm *.a
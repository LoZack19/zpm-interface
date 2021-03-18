CC=gcc
CFLAGS=
AR=ar

OBJ=interface.o Unirun/unirun.o
TARGET=librgmint.a

all: configure $(TARGET)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

$(TARGET): $(OBJ)
	$(AR) -r $@ $^


configure:
	git clone https://github.com/LoZack19/Unirun

clean:
	rm -rf *.o *.a Unirun/
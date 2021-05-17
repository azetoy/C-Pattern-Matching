# Compilation generique
CC=gcc
SRC=patternmatching.c main.c
OBJ=$(SRC:.c=.o)
CFLAGS=-Wall

Pattern-Matching: $(OBJ) patternmatching.h
	$(CC) -o $@ $(OBJ)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

# Clean
clean:
		rm *.o *~ core
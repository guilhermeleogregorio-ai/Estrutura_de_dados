CC = gcc
CFLAGS = -Wall -Wextra

all: programa

programa: main.o list.o
	$(CC) $(CFLAGS) -o programa main.o list.o

main.o: main.c list.h
	$(CC) $(CFLAGS) -c -o main.o main.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c -o list.o list.c

clean:
	rm -f programa main.o list.o

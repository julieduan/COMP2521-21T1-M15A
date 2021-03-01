CC = gcc

CFLAGS = -g

OBJS = main.o library.o

prog: $(OBJS)
	$(CC) $(CFLAGS) -o prog $(OBJS)

main.o: main.c library.h
library.o: library.c library.h

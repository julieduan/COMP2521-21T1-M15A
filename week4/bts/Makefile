# COMP2521 ... Lab 03 Makefile

CC = gcc
CFLAGS = -Wall -Werror -g

OBJS = bst.o BSTree.o Queue.o

bst: $(OBJS)
	$(CC) $(CFLAGS) -o bst $(OBJS)

bst.o: bst.c BSTree.h
BSTree.o: BSTree.c BSTree.h Queue.h
Queue.o: Queue.c Queue.h

.PHONY: clean
clean:
	rm -rf  $(OBJS) core *.dSYM tests/*.out


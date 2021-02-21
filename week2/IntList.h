// Written by Julie Duan, Feb 2021

#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct node {
	int data;
	struct node *next;
} Node;
typedef Node *List;


List newIntList(int*, int);
int listLength(List);
int listCountOdds(List);
bool listIsSorted(List);
void listShow(List);

#endif

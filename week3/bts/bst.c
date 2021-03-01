// bst.c ... client for BSTree ADT

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "BSTree.h"

#define MAXVALS 1000

#define KEY 3

int main(void)
{
	// Build BST from values in stdin
	BSTree T = BSTreeNew();
	int nvals = 0;
	int v[MAXVALS];
	
	int n;
	while (nvals < MAXVALS && scanf("%d", &n) == 1) {
		v[nvals++] = n;
		T = BSTreeInsert(T, n);
	}

	// Display information about constructed tree
	printf("Tree:\n");
	BSTreePrint(T);
	printf("\n");

	printf("#nodes = %d\n", BSTreeNumNodes(T));
	printf("#odd nodes = %d\n", BSTreeCountOdds(T));
	printf("#height = %d\n", BSTreeHeight(T));
	printf("#interal nodes = %d\n", BSTreeCountInternal(T));
	printf("%d depth in the tree = %d\n", KEY, BSTreeNodeDepth(T, KEY));
	printf("#greater nodes = %d\n", BSTreeCountGreater(T, KEY));

	// Check correctness of tree
	// Every inserted value can be found
	for (int i = 0; i < nvals; i++) {
		assert(BSTreeFind(T, v[i]) != 0);
	}

	BSTreeFree(T);
	return EXIT_SUCCESS;
}


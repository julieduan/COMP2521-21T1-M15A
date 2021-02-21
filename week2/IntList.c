// Written by Julie Duan, Feb 2021

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "IntList.h"

List newIntList(int* list, int len) {
    if(list == NULL) {
        return NULL;
    }
    List head = NULL;
    List tail = NULL;
    for(int i = 0;i < len;i++){
        List new = malloc(sizeof(Node));
        new->data = list[i];
        new->next = NULL;
        if(head == NULL){
            head = new;
            tail = new;
        }else{
            tail->next = new;
            tail = new;
        }
    }
    return head;
}

int listLength(List L){
    int count = 0;
	for (Node *curr = L; curr != NULL; curr = curr->next) {
		count++;
	}
	return count;
}

int listCountOdds(List L){
    int count = 0;
	for (Node *curr = L; curr != NULL; curr = curr->next) {
		if (curr->data % 2 != 0) {
			count++;
		}
	}
	return count;
}

bool listIsSorted(List L){
    if (L == NULL) {
		return true;
	}
	
	for (Node *curr = L; curr->next != NULL; curr = curr->next) {
		if (curr->data > curr->next->data) {
			return false;
		}
	}
	return true;
}

void listShow(List L){
    printf("List:");

    List curr = L;
    while (curr != NULL) {
        printf(" %d", curr->data);
        curr = curr->next;
    }

    printf("\n");
}
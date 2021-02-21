#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "List.h"

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
    // int count = 0;
	// for (Node *curr = L; curr != NULL; curr = curr->next) {
	// 	count++;
	// }
	// return count;
    if (L == NULL) {
		return 0;
	} else {
		return 1 + length(L->next);
	}
}

int listCountOdds(List L){
    // int count = 0;
	// for (Node *curr = L; curr != NULL; curr = curr->next) {
	// 	if (curr->data % 2 != 0) {
	// 		count++;
	// 	}
	// }
	// return count;
    if (L == NULL) {
		return 0;
	} else if (L->data % 2 != 0) {
		return 1 + listCountOdds(L->next);
	} else {
		return listCountOdds(L->next);
	}
}

bool listIsSorted(List L){
    // if (L == NULL) {
	// 	return true;
	// }
	
	// for (Node *curr = L; curr->next != NULL; curr = curr->next) {
	// 	if (curr->data > curr->next->data) {
	// 		return false;
	// 	}
	// }
	// return true;
    // an empty list is sorted
	if (L == NULL) {
		return true;
	
	// a list with one item is sorted
	} else if (L->next == NULL) {
		return true;
	
	// if first item is greater than second item, list is not sorted
	} else if (L->data > L->next->data) {
		return false;
	
	// check whether rest of the list is sorted
	} else {
		return listIsSorted(L->next);
	}
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
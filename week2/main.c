// useIntList.c - testing IntList data type

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "IntList.h"

int main(int argc, char *argv[])
{
	int* nums = malloc(sizeof(int) * (argc - 1));

    for (int i = 1; i < argc; i++) {
        nums[i - 1] = atoi(argv[i]);
    }

    List l = newIntList(nums, argc - 1);

    listShow(l);
    printf("List length = %d\n", listLength(l));
    printf("Odd count = %d\n", listCountOdds(l));
    printf("List is sorted? %s\n", listIsSorted(l) ? "Yes" : "No");

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
    int zid;
    char name[15];
};

typedef struct record *Record;

void RecordShow(Record r) {
    printf("%d|%s\n", r->zid, r->name);
}

/**
 *  Pre: size > 0
 */
Record func(Record students, int size,
            int (*cmp)(Record, Record))
{
    Record rec = &students[0];

    if (size == 1) return rec;

    for (int i = 1; i < size; i++) {
        if (cmp(&students[i], rec) < 0) {
            rec = &students[i];
        }
    }

    return rec; 
}

int cmpId(Record r1, Record r2) {
    // (a)
    return (r1->zid - r2->zid); 
}

int myCmpId(Record r1, Record r2) {
    // TODO: (b)
    // compapre the zid
    // return something <0, when the r1.zid > r2.zid
    // if (r1->zid > r2->zid){
    //     return -1;
    // }
    // return 0;
    return r2->zid - r1->zid;
}

// Declaration
// Following is the declaration for strcmp() function.

// int strcmp(const char *str1, const char *str2)
// Parameters
// str1 − This is the first string to be compared.

// str2 − This is the second string to be compared.

// Return Value
// This function return values that are as follows −

// if Return value < 0 then it indicates str1 is less than str2.

// if Return value > 0 then it indicates str2 is less than str1.

// if Return value = 0 then it indicates str1 is equal to str2.

int myCmpName(Record r1, Record r2) {
    // TODO: (c)
    // if r1->name > r2->name return negative
    // else : something >=0
    int r = strcmp(r1->name, r2->name);
    if(r > 0){
        // r1->name > r2->name
        return -1;
    }
    return 0;
}

int main(void) {
    struct record students[] = {
        { 2134567, "John" },
        { 3312902, "Mary" },
        { 1249805, "Rita" },
        { 2209067, "Dawn" },
        { 1239876, "Jack" },
    };

    // Record myRec1 = func(students, 5, cmpId);
    // RecordShow(myRec1);

    // Record myRec2 = func(students, 5, myCmpId);
    // RecordShow(myRec2);

    Record myRec3 = func(students, 5, myCmpName);
    RecordShow(myRec3);
}

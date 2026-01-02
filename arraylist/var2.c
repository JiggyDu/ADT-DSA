
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* -------------------------
   STRUCTURE & TYPEDEF
------------------------- */
typedef struct {
    int elem[MAX];
    int count;
} List;

typedef List* EPtr;

/* -------------------------
   FUNCTION PROTOTYPES
------------------------- */
void initialize(EPtr L);

void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);

int locate(EPtr L, int data);
int retrieve(EPtr L, int position);

void insertSorted(EPtr L, int data);

void display(EPtr L);
void makeNULL(EPtr L);

/* -------------------------
   MAIN (TESTING)
------------------------- */
int main() {
    List *L = (List*)malloc(sizeof(List));

    initialize(L);

    insertPos(L, 1, 0);
    insertPos(L, 3, 1);
    insertPos(L, 2, 2);
    insertPos(L, 5, 3);

    display(L);

    insertPos(L, 4, 2);
    display(L);

    deletePos(L, 1);
    display(L);

    printf("Locate 5: %d\n", locate(L, 5));
    printf("Retrieve index 1: %d\n", retrieve(L, 1));

    makeNULL(L);
    return 0;
}

/* -------------------------
   FUNCTIONS
------------------------- */

void initialize(EPtr L) {
    L->count = 0;
}

void insertPos(EPtr L, int data, int position) {
    if (position < 0 || position > L->count) return;
    if (L->count == MAX) return;

    for (int i = L->count; i > position; i--) {
        L->elem[i] = L->elem[i - 1];
    }

    L->elem[position] = data;
    L->count++;
}

void deletePos(EPtr L, int position) {
    if (position < 0 || position >= L->count) return;

    for (int i = position; i < L->count - 1; i++) {
        L->elem[i] = L->elem[i + 1];
    }

    L->count--;
}

int locate(EPtr L, int data) {
    for (int i = 0; i < L->count; i++) {
        if (L->elem[i] == data)
            return i;
    }
    return -1;
}

int retrieve(EPtr L, int position) {
    if (position < 0 || position >= L->count)
        return -1;

    return L->elem[position];
}

void insertSorted(EPtr L, int data) {
    if (L->count == MAX) return;

    int i = L->count - 1;

    while (i >= 0 && L->elem[i] > data) {
        L->elem[i + 1] = L->elem[i];
        i--;
    }

    L->elem[i + 1] = data;
    L->count++;
}

void display(EPtr L) {
    for (int i = 0; i < L->count; i++) {
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}

void makeNULL(EPtr L) {
    free(L);
}

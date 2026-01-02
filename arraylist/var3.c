#include <stdio.h>
#include <stdlib.h>

#define LENGTH 4

/* -------------------------
   STRUCTURE
------------------------- */
typedef struct {
    int *elem;
    int count;
    int max;
} List;

/* -------------------------
   FUNCTION PROTOTYPES
------------------------- */
List initialize(List L);
List resize(List L);

List insertPos(List L, int data, int position);
List deletePos(List L, int position);

int locate(List L, int data);
List insertSorted(List L, int data);

void display(List L);

/* -------------------------
   MAIN (TESTING)
------------------------- */
int main() {
    List L;

    L = initialize(L);

    L = insertPos(L, 1, 0);
    L = insertPos(L, 3, 1);
    L = insertPos(L, 2, 2);
    L = insertPos(L, 5, 3);

    display(L);

    L = insertPos(L, 4, 2);
    display(L);

    L = deletePos(L, 1);
    display(L);

    printf("Locate 5: %d\n", locate(L, 5));

    L = insertSorted(L, 8);
    display(L);

    free(L.elem);
    return 0;
}

/* -------------------------
   FUNCTIONS
------------------------- */

List initialize(List L) {
    L.elem = (int*)malloc(LENGTH * sizeof(int));
    L.max = LENGTH;
    L.count = 0;
    return L;
}

List resize(List L) {
    L.max *= 2;
    L.elem = (int*)realloc(L.elem, L.max * sizeof(int));
    return L;
}

List insertPos(List L, int data, int position) {
    if (position < 0 || position > L.count)
        return L;

    if (L.count == L.max)
        L = resize(L);

    for (int i = L.count; i > position; i--) {
        L.elem[i] = L.elem[i - 1];
    }

    L.elem[position] = data;
    L.count++;

    return L;
}

List deletePos(List L, int position) {
    if (position < 0 || position >= L.count)
        return L;

    for (int i = position; i < L.count - 1; i++) {
        L.elem[i] = L.elem[i + 1];
    }

    L.count--;
    return L;
}

int locate(List L, int data) {
    for (int i = 0; i < L.count; i++) {
        if (L.elem[i] == data)
            return i;
    }
    return -1;
}

List insertSorted(List L, int data) {
    if (L.count == L.max)
        L = resize(L);

    int i = L.count - 1;

    while (i >= 0 && L.elem[i] > data) {
        L.elem[i + 1] = L.elem[i];
        i--;
    }

    L.elem[i + 1] = data;
    L.count++;

    return L;
}

void display(List L) {
    for (int i = 0; i < L.count; i++) {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}


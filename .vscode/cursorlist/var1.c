
#include <stdio.h>
#include <stdlib.h>

#define MAX 4

typedef struct {
    int elem;
    int next;
} Cell, HeapSpace[MAX];

typedef struct {
    HeadSpace H;
    int avail;
} VHeap;

typedef int list;

void initialize(VHeap* V);
int alloSpace(VHeap* V);
void deallocSpace(VHeap* V, int index);
void insertFirst(int* L, VHeap* V, int elem);
void insertLast(int* L, VHeap* V, int elem);
void insertSorted(int* L, VHeap* V, int elem);
void delete(int* L, VHeap* V, int elem);
void deleteAllOccurrence(int* L, VHeap* V, int elem);
void display(int L, VHeap V);


void initialize(VHeap* V)
{
    V->avail = 0;
    
    
}

void insertFirst(int* L, VHeap* V, int elem)
{
    int newCell = alloc();
    if(newCell != -1)
    {
        V->H[newCell].elem = elem;
        V->H[newCell].next = *L;
    }
    *L = newCell;
}

voidinsertLast(int* L, VHeap* V, int elem)
{
    int newCell = alloc();
    if (newCell != -1)
    {
        V->H[newCell].elem = elem;
        V->H[newCell].next = -1;
        int *trav = L;
        while(*trav != -1)
        {
            trav = &V->H[*trav].next;
        }
        *trav = newCell;
    }
}

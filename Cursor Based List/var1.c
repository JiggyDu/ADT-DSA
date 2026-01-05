
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
    // Create a linked list of available cells
    for (int i = 0; i < MAX_HEAP_SIZE - 1; i++) {
        V->H[i].next = i + 1;
    }
    V->H[MAX_HEAP_SIZE - 1].next = -1;  

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

void delete(int* L, VHeap* V, int elem) {
    int* trav = L;
    while (*trav != -1 && V->H[*trav].elem != elem) {
        trav = &V->H[*trav].next;
    }
    if (*trav != -1) {  // Element found
        int toDelete = *trav;
        *trav = V->H[toDelete].next;  // Update the previous cell's next pointer
        deallocSpace(V, toDelete);  // Deallocate the cell
    }
}

int allocSpace(VHeap* V) {
    if (V->avail == -1) {
        return -1;  // No space available
    }
    int allocatedCell = V->avail;  // The first available cell
    V->avail = V->H[allocatedCell].next;  // Update 'avail' to the next available cell
    return allocatedCell;
}

// Deallocate a cell and return it to the virtual heap
void deallocSpace(VHeap* V, int index) {
    V->H[index].next = V->avail;  // Point the deallocated cell to the current 'avail'
    V->avail = index;  // Update 'avail' to the deallocated cell
}

void insertSorted(int* L, VHeap* V, int elem) {
    int newCell = allocSpace(V);
    if (newCell != -1) {
        V->H[newCell].elem = elem;
        int* trav = L;
        while (*trav != -1 && V->H[*trav].elem < elem) {
            trav = &V->H[*trav].next;  // Traverse until we find the right spot
        }
        V->H[newCell].next = *trav;  // Insert after the current element
        *trav = newCell;  // Update previous cell to point to the new cell
    }
}

void deleteAllOccurrence(int* L, VHeap* V, int elem) {
    int* trav = L;
    while (*trav != -1) {
        if (V->H[*trav].elem == elem) {
            int toDelete = *trav;
            *trav = V->H[toDelete].next;  // Remove this cell from the list
            deallocSpace(V, toDelete);  // Deallocate the cell
        } else {
            trav = &V->H[*trav].next;  // Move to the next element
        }
    }
}

// Display the list starting from the head
void display(int L, VHeap V) {
    int current = L;
    while (current != -1) {
        printf("%d -> ", V.H[current].elem);  // Print element
        current = V.H[current].next;  // Move to the next element
    }
    printf("NULL\n");  // End of list
}

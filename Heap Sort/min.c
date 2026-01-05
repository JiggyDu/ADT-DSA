#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct {
    int data[MAX];
    int size;
} MinHeap;

/* Initialize min heap */
void initMinHeap(MinHeap *h) {
    h->size = 0;
}

/* Swap helper */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Heapify UP */
void heapifyUpMin(MinHeap *h, int index) {
    int parent = (index - 1) / 2;

    if (index > 0 && h->data[index] < h->data[parent]) {
        swap(&h->data[index], &h->data[parent]);
        heapifyUpMin(h, parent);
    }
}

/* Heapify DOWN */
void heapifyDownMin(MinHeap *h, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < h->size && h->data[left] < h->data[smallest])
        smallest = left;

    if (right < h->size && h->data[right] < h->data[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&h->data[index], &h->data[smallest]);
        heapifyDownMin(h, smallest);
    }
}

/* Insert into min heap */
void insertMinHeap(MinHeap *h, int value) {
    if (h->size == MAX) {
        printf("Min Heap is full\n");
        return;
    }

    h->data[h->size] = value;
    heapifyUpMin(h, h->size);
    h->size++;
}

/* Remove minimum (root) */
int removeMin(MinHeap *h) {
    if (h->size == 0) {
        printf("Min Heap is empty\n");
        return -1;
    }

    int min = h->data[0];
    h->data[0] = h->data[h->size - 1];
    h->size--;
    heapifyDownMin(h, 0);

    return min;
}

/* Display heap */
void displayMinHeap(MinHeap h) {
    for (int i = 0; i < h.size; i++)
        printf("%d ", h.data[i]);
    printf("\n");
}

/* Test */
int main() {
    MinHeap h;
    initMinHeap(&h);

    insertMinHeap(&h, 40);
    insertMinHeap(&h, 10);
    insertMinHeap(&h, 30);
    insertMinHeap(&h, 5);
    insertMinHeap(&h, 20);

    printf("Min Heap: ");
    displayMinHeap(h);

    printf("Removed Min: %d\n", removeMin(&h));
    printf("After Removal: ");
    displayMinHeap(h);

    return 0;
}

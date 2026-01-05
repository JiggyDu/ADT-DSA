#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct {
    int data[MAX];
    int size;
} MaxHeap;

/* Initialize max heap */
void initMaxHeap(MaxHeap *h) {
    h->size = 0;
}

/* Swap helper */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Heapify UP */
void heapifyUpMax(MaxHeap *h, int index) {
    int parent = (index - 1) / 2;

    if (index > 0 && h->data[index] > h->data[parent]) {
        swap(&h->data[index], &h->data[parent]);
        heapifyUpMax(h, parent);
    }
}

/* Heapify DOWN */
void heapifyDownMax(MaxHeap *h, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < h->size && h->data[left] > h->data[largest])
        largest = left;

    if (right < h->size && h->data[right] > h->data[largest])
        largest = right;

    if (largest != index) {
        swap(&h->data[index], &h->data[largest]);
        heapifyDownMax(h, largest);
    }
}

/* Insert into max heap */
void insertMaxHeap(MaxHeap *h, int value) {
    if (h->size == MAX) {
        printf("Max Heap is full\n");
        return;
    }

    h->data[h->size] = value;
    heapifyUpMax(h, h->size);
    h->size++;
}

/* Remove maximum (root) */
int removeMax(MaxHeap *h) {
    if (h->size == 0) {
        printf("Max Heap is empty\n");
        return -1;
    }

    int max = h->data[0];
    h->data[0] = h->data[h->size - 1];
    h->size--;
    heapifyDownMax(h, 0);

    return max;
}

/* Display heap */
void displayMaxHeap(MaxHeap h) {
    for (int i = 0; i < h.size; i++)
        printf("%d ", h.data[i]);
    printf("\n");
}

/* Test */
int main() {
    MaxHeap h;
    initMaxHeap(&h);

    insertMaxHeap(&h, 40);
    insertMaxHeap(&h, 10);
    insertMaxHeap(&h, 30);
    insertMaxHeap(&h, 50);
    insertMaxHeap(&h, 20);

    printf("Max Heap: ");
    displayMaxHeap(h);

    printf("Removed Max: %d\n", removeMax(&h));
    printf("After Removal: ");
    displayMaxHeap(h);

    return 0;
}

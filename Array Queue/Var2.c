#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

/* -------------------------
   STRUCTURE
------------------------- */
typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

/* -------------------------
   FUNCTION PROTOTYPES
------------------------- */
Queue* initialize();

bool isEmpty(Queue *q);
bool isFull(Queue *q);

void enqueue(Queue *q, int value);
int dequeue(Queue *q);

int front(Queue *q);
void display(Queue *q);

/* -------------------------
   MAIN (TESTING)
------------------------- */
int main() {
    Queue *Q = initialize();

    enqueue(Q, 1);
    enqueue(Q, 3);
    enqueue(Q, 2);
    enqueue(Q, 5);

    display(Q);

    enqueue(Q, 4);
    display(Q);

    int value = dequeue(Q);
    printf("Dequeued value: %d\n", value);

    display(Q);

    printf("Front value: %d\n", front(Q));

    free(Q);
    return 0;
}

/* -------------------------
   FUNCTIONS
------------------------- */

Queue* initialize() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    if (!q) return NULL;

    q->front = 1;
    q->rear = 0;
    return q;
}

bool isEmpty(Queue *q) {
    return q->front == (q->rear + 1) % MAX;
}

bool isFull(Queue *q) {
    return q->front == (q->rear + 2) % MAX;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }

    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    int value = q->items[q->front];
    q->front = (q->front + 1) % MAX;
    return value;
}

int front(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    return q->items[q->front];
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    int i = q->front;
    while (i != (q->rear + 1) % MAX) {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

/* -------------------------
   STRUCTURES
------------------------- */
typedef struct {
    int items[MAX];
    int count;
} List;

typedef struct {
    List list;
    int front;
    int rear;
} Queue;

/* -------------------------
   FUNCTION PROTOTYPES
------------------------- */
Queue* initialize();

bool isFull(Queue *q);
bool isEmpty(Queue *q);

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

    q->list.count = 0;
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isFull(Queue *q) {
    return q->list.count == MAX;
}

bool isEmpty(Queue *q) {
    return q->list.count == 0;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }

    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }

    q->list.items[q->rear] = value;
    q->list.count++;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    int value = q->list.items[q->front];

    if (q->list.count == 1) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }

    q->list.count--;
    return value;
}

int front(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    return q->list.items[q->front];
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    int i = q->front;
    for (int c = 0; c < q->list.count; c++) {
        printf("%d ", q->list.items[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

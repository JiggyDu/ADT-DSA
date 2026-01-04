
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* ===== NODE DEFINITION ===== */
typedef struct node {
    int data;
    struct node* next;
} Node;

/* ===== QUEUE DEFINITION ===== */
typedef struct {
    Node* front;
    Node* rear;
} Queue;

/* ===== FUNCTION PROTOTYPES ===== */
Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int frontValue(Queue* q);
void display(Queue* q);

/* ===== INITIALIZE QUEUE ===== */
Queue* initialize() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q != NULL) {
        q->front = NULL;
        q->rear = NULL;
    }
    return q;
}

/* ===== IS FULL ===== */
/* Linked list queue is never full */
bool isFull(Queue* q) {
    return false;
}

/* ===== IS EMPTY ===== */
bool isEmpty(Queue* q) {
    return q->front == NULL;
}

/* ===== ENQUEUE ===== */
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    /* If queue is empty */
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } 
    /* If queue is not empty */
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

/* ===== DEQUEUE ===== */
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    }

    Node* temp = q->front;
    int value = temp->data;

    q->front = temp->next;

    /* If queue becomes empty */
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return value;
}

/* ===== FRONT VALUE ===== */
int frontValue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}

/* ===== DISPLAY QUEUE ===== */
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    Node* temp = q->front;
    printf("Queue (front -> rear): ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* ===== MAIN FUNCTION ===== */
int main() {
    Queue* Q = initialize();

    enqueue(Q, 1);
    enqueue(Q, 3);
    enqueue(Q, 5);
    display(Q);

    enqueue(Q, 4);
    display(Q);

    printf("Dequeued value: %d\n", dequeue(Q));
    display(Q);

    printf("Front value: %d\n", frontValue(Q));

    return 0;
}

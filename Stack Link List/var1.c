
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* ===== NODE DEFINITION ===== */
typedef struct node {
    int data;
    struct node* next;
} Node;

/* ===== STACK DEFINITION ===== */
typedef struct {
    Node* top;
} Stack;

/* ===== FUNCTION PROTOTYPES ===== */
Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
void display(Stack* s);

/* ===== INITIALIZE STACK ===== */
Stack* initialize() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if (s != NULL) {
        s->top = NULL;
    }
    return s;
}

/* ===== IS FULL ===== */
/* Linked list stack is never full */
bool isFull(Stack* s) {
    return false;
}

/* ===== IS EMPTY ===== */
bool isEmpty(Stack* s) {
    return s->top == NULL;
}

/* ===== PUSH ===== */
void push(Stack* s, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

/* ===== POP ===== */
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }

    Node* temp = s->top;
    int value = temp->data;

    s->top = temp->next;
    free(temp);

    return value;
}

/* ===== PEEK ===== */
int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->top->data;
}

/* ===== DISPLAY ===== */
void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }

    Node* temp = s->top;
    printf("Stack (top -> bottom): ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* ===== MAIN FUNCTION ===== */
int main() {
    Stack* S = initialize();

    push(S, 1);
    push(S, 3);
    push(S, 5);
    display(S);

    push(S, 4);
    display(S);

    printf("Popped value: %d\n", pop(S));
    display(S);

    printf("Top value: %d\n", peek(S));

    return 0;
}

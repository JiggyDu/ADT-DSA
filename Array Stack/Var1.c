#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

/* -------------------------
   STRUCTURE
------------------------- */
typedef struct {
    int items[MAX];
    int top;
} Stack;

/* -------------------------
   FUNCTION PROTOTYPES
------------------------- */
Stack* initialize();

bool isFull(Stack *s);
bool isEmpty(Stack *s);

void push(Stack *s, int value);
int pop(Stack *s);

int peek(Stack *s);
int top(Stack *s);

void display(Stack *s);

/* -------------------------
   MAIN (TESTING)
------------------------- */
int main() {
    Stack *S = initialize();

    push(S, 1);
    push(S, 3);
    push(S, 2);
    push(S, 5);

    display(S);

    push(S, 4);
    display(S);

    int value = pop(S);
    printf("Popped value: %d\n", value);

    display(S);

    printf("Peek: %d\n", peek(S));
    printf("Top index: %d\n", top(S));

    free(S);
    return 0;
}

/* -------------------------
   FUNCTIONS
------------------------- */

Stack* initialize() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    if (!s) return NULL;

    s->top = -1;
    return s;
}

bool isFull(Stack *s) {
    return s->top == MAX - 1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack is full\n");
        return;
    }

    s->top++;
    s->items[s->top] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }

    int value = s->items[s->top];
    s->top--;
    return value;
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }

    return s->items[s->top];
}

int top(Stack *s) {
    return s->top;
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }

    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->items[i]);
    }
}


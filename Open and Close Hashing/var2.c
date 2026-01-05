#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *table[SIZE];
} Dictionary;

int hash(int key) {
    return key % SIZE;
}

void initDict(Dictionary *d) {
    for (int i = 0; i < SIZE; i++)
        d->table[i] = NULL;
}

void insert(Dictionary *d, int value) {
    int index = hash(value);

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = d->table[index];
    d->table[index] = newNode;
}

int search(Dictionary *d, int value) {
    int index = hash(value);
    Node *current = d->table[index];

    while (current != NULL) {
        if (current->data == value)
            return 1;
        current = current->next;
    }
    return 0;
}

void delete(Dictionary *d, int value) {
    int index = hash(value);
    Node *current = d->table[index];
    Node *prev = NULL;

    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL)
                d->table[index] = current->next;
            else
                prev->next = current->next;

            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void display(Dictionary *d) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d: ", i);
        Node *current = d->table[i];
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Dictionary d;
    initDict(&d);

    insert(&d, 10);
    insert(&d, 15);
    insert(&d, 7);
    insert(&d, 9);
    insert(&d, 14);

    display(&d);

    delete(&d, 15);
    display(&d);

    return 0;
}

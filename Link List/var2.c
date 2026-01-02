
#include <stdio.h>
#include <stdlib.h>

/* -------------------------
   STRUCTURES
------------------------- */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int count;
} List;

/* -------------------------
   FUNCTION PROTOTYPES
------------------------- */
List* initialize();
void empty(List *list);

void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);

void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);

int retrieve(List *list, int index);
int locate(List *list, int data);

void display(List *list);

/* -------------------------
   MAIN (TESTING)
------------------------- */
int main() {
    List *list = initialize();

    insertLast(list, 2);
    insertLast(list, 6);
    insertLast(list, 5);

    display(list);

    insertFirst(list, 7);
    display(list);

    insertPos(list, 9, 2);
    display(list);

    deleteStart(list);
    display(list);

    deleteLast(list);
    display(list);

    deletePos(list, 1);
    display(list);

    printf("Retrieve index 1: %d\n", retrieve(list, 1));
    printf("Locate value 5: %d\n", locate(list, 5));

    empty(list);
    free(list);

    return 0;
}

/* -------------------------
   FUNCTIONS
------------------------- */
List* initialize() {
    List *list = (List*)malloc(sizeof(List));
    if (!list) return NULL;

    list->head = NULL;
    list->count = 0;
    return list;
}

void empty(List *list) {
    Node *current = list->head;
    Node *temp;

    while (current) {
        temp = current;
        current = current->next;
        free(temp);
    }

    list->head = NULL;
    list->count = 0;
}

void insertFirst(List *list, int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (!node) return;

    node->data = data;
    node->next = list->head;
    list->head = node;
    list->count++;
}

void insertLast(List *list, int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (!node) return;

    node->data = data;
    node->next = NULL;

    if (!list->head) {
        list->head = node;
    } else {
        Node *current = list->head;
        while (current->next)
            current = current->next;
        current->next = node;
    }

    list->count++;
}

void insertPos(List *list, int data, int index) {
    if (index < 0 || index > list->count) return;

    if (index == 0) {
        insertFirst(list, data);
        return;
    }

    if (index == list->count) {
        insertLast(list, data);
        return;
    }

    Node *node = (Node*)malloc(sizeof(Node));
    if (!node) return;

    node->data = data;

    Node *current = list->head;
    for (int i = 0; i < index - 1; i++)
        current = current->next;

    node->next = current->next;
    current->next = node;
    list->count++;
}

void deleteStart(List *list) {
    if (!list->head) return;

    Node *temp = list->head;
    list->head = temp->next;
    free(temp);
    list->count--;
}

void deleteLast(List *list) {
    if (!list->head) return;

    if (list->count == 1) {
        free(list->head);
        list->head = NULL;
    } else {
        Node *current = list->head;
        for (int i = 0; i < list->count - 2; i++)
            current = current->next;

        free(current->next);
        current->next = NULL;
    }

    list->count--;
}

void deletePos(List *list, int index) {
    if (index < 0 || index >= list->count) return;

    if (index == 0) {
        deleteStart(list);
        return;
    }

    Node *current = list->head;
    for (int i = 0; i < index - 1; i++)
        current = current->next;

    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    list->count--;
}

int retrieve(List *list, int index) {
    if (index < 0 || index >= list->count) return -1;

    Node *current = list->head;
    for (int i = 0; i < index; i++)
        current = current->next;

    return current->data;
}

int locate(List *list, int data) {
    Node *current = list->head;
    int index = 0;

    while (current) {
        if (current->data == data)
            return index;
        current = current->next;
        index++;
    }

    return -1;
}

void display(List *list) {
    Node *current = list->head;

    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

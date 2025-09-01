
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *head;
    int count;
} List;

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

List* initialize()
{
    List* L = (List*) malloc(sizeof(List));


    L-> head = NULL;
    L-> count = 0;
    return L;
}

void empty(List *list)
{
L-> head = NULL;
L-> count = 0;
return L;

}

void insertFirst(List *list, int data)
{
    Node *newNode = (Node*) malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = data;
    newNode -> next = NULL;
     if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node *temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    list->count++;
}


void insertLast(List *list, int data)
{

}

void insertPos(List *list, int data, int index)
{

}

void deleteStart(List *list)
{
if (*list == NULL) { 
        return;
    }
    Node *temp = *list; 
    *list = (*list)->next; 
    free(temp);
}

void deleteLast(List *list)
{

}

void deletePos(List *list, int index)
{

}

int retrieve(List *list, int index)
{

}


int locate(List *list, int data)
{

}

void display(List *list)
{

}

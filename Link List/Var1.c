#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

typedef struct{
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

    if(L == NULL)
    {
        printf("Memory allocation failed\n");
    }
    else
    {
        L->head = NULL;
        L->count = 0;
    }

    return L;
}

void empty(List *list)
{
    Node *temp;

    while(list->head != NULL)
    {
        temp = list->head;
        list->head = list->head->next;
        free(temp);
    }

    list->count = 0;
}

void insertFirst(List *list, int data)
{
    Node *newNode = (Node*) malloc(sizeof(Node));

    if(newNode == NULL)
    {
        printf("Memory allocation failed\n");
    }
    else
    {
        newNode->data = data;
        newNode->next = list->head;
        list->head = newNode;
        list->count++;
    }
}

void insertLast(List *list, int data)
{
    Node *newNode = (Node*) malloc(sizeof(Node));
    Node *temp;

    if(newNode == NULL)
    {
        printf("Memory allocation failed\n");
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;

        if(list->head == NULL)
        {
            list->head = newNode;
        }
        else
        {
            temp = list->head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        list->count++;
    }
}

void insertPos(List *list, int data, int index)
{
    Node *newNode;
    Node *temp;
    int i;

    if(index < 0 || index > list->count)
    {
        printf("Invalid index\n");
    }
    else if(index == 0)
    {
        insertFirst(list, data);
    }
    else
    {
        newNode = (Node*) malloc(sizeof(Node));

        if(newNode == NULL)
        {
            printf("Memory allocation failed\n");
        }
        else
        {
            newNode->data = data;

            temp = list->head;

            for(i = 0; i < index-1; i++)
            {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;

            list->count++;
        }
    }
}

void deleteStart(List *list)
{
    Node *temp;

    if(list->head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = list->head;
        list->head = temp->next;
        free(temp);
        list->count--;
    }
}

void deleteLast(List *list)
{
    Node *temp;
    Node *prev = NULL;

    if(list->head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = list->head;

        while(temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        if(prev == NULL)
        {
            list->head = NULL;
        }
        else
        {
            prev->next = NULL;
        }

        free(temp);
        list->count--;
    }
}

void deletePos(List *list, int index)
{
    Node *temp;
    Node *prev;
    int i;

    if(index < 0 || index >= list->count)
    {
        printf("Invalid index\n");
    }
    else if(index == 0)
    {
        deleteStart(list);
    }
    else
    {
        temp = list->head;

        for(i = 0; i < index; i++)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        free(temp);
        list->count--;
    }
}

int retrieve(List *list, int index)
{
    Node *temp;
    int i;
    int value = -1;

    if(index < 0 || index >= list->count)
    {
        printf("Invalid index\n");
    }
    else
    {
        temp = list->head;

        for(i = 0; i < index; i++)
        {
            temp = temp->next;
        }

        value = temp->data;
    }

    return value;
}

int locate(List *list, int data)
{
    Node *temp = list->head;
    int pos = 0;
    int found = -1;

    while(temp != NULL && found == -1)
    {
        if(temp->data == data)
        {
            found = pos;
        }
        else
        {
            temp = temp->next;
            pos++;
        }
    }

    return found;
}

void display(List *list)
{
    Node *temp = list->head;

    if(temp == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main()
{
    List *L = initialize();

    insertFirst(L, 10);
    insertLast(L, 20);
    insertLast(L, 30);
    insertPos(L, 15, 1);

    display(L);

    printf("Position of 20: %d\n", locate(L,20));
    printf("Value at index 2: %d\n", retrieve(L,2));

    deleteStart(L);
    deleteLast(L);

    display(L);

    empty(L);

    display(L);

    return 0;
}

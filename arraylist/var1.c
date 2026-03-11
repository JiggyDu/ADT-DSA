#include <stdio.h>
#define size 10

typedef struct {
    int elem[size];
    int count;
} List;

List initialize();
int insertPos(List *L, int data, int position);
void deletePos(List *L, int position);
int locate(List *L, int data);
void insertSorted(List *L, int data);
void display(List *L);

int main()
{
    List L = initialize();

    insertPos(&L,10,0);
    insertPos(&L,20,1);
    insertPos(&L,10,1);
    insertPos(&L,10,2);

    display(&L);

    return 0;
}

List initialize()
{
    List L;
    L.count = 0;

    for(int i = 0; i < size; i++)
    {
        L.elem[i] = -1;
    }

    return L;
}

int insertPos(List *L, int data, int position)
{
    if (L->count >= size)
    {
        printf("Size is full\n");
        return 0;
    }

    if (position < 0 || position > L->count)
    {
        printf("Invalid Position\n");
        return 0;
    }

    for (int i = L->count; i > position; i--)
    {
        L->elem[i] = L->elem[i - 1];
    }

    L->elem[position] = data;
    L->count++;

    return 1;
}

void deletePos(List *L, int position)
{
    if (position < 0 || position >= L->count)
    {
        printf("Invalid Position\n");
        return;
    }

    for (int i = position; i < L->count - 1; i++)
    {
        L->elem[i] = L->elem[i + 1];
    }

    L->count--;
}

int locate(List *L, int data)
{
    for (int i = 0; i < L->count; i++)
    {
        if (L->elem[i] == data)
        {
            return i;
        }
    }

    return -1;
}

void insertSorted(List *L, int data)
{
    int i;

    if (L->count >= size)
    {
        printf("List Full\n");
        return;
    }

    for(i = L->count - 1; i >= 0 && L->elem[i] > data; i--)
    {
        L->elem[i+1] = L->elem[i];
    }

    L->elem[i+1] = data;
    L->count++;
}

void display(List *L)
{
    if (L->count == 0)
    {
        printf("Empty\n");
        return;
    }

    for (int i = 0; i < L->count; i++)
    {
        printf("%d ", L->elem[i]);
    }

    printf("\n");
}

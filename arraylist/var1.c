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
    int i;

    L.count = 0;

    for(i = 0; i < size; i++)
    {
        L.elem[i] = -1;
    }

    return L;
}

int insertPos(List *L, int data, int position)
{
    int i;
    int success = 0;

    if(L->count >= size)
    {
        printf("Error: List is full\n");
    }
    else if(position < 0 || position > L->count)
    {
        printf("Error: Invalid position\n");
    }
    else
    {
        for(i = L->count; i > position; i--)
        {
            L->elem[i] = L->elem[i-1];
        }

        L->elem[position] = data;
        L->count++;
        success = 1;
    }

    return success;
}

void deletePos(List *L, int position)
{
    int i;

    if(L->count == 0)
    {
        printf("Error: List is empty\n");
    }
    else if(position < 0 || position >= L->count)
    {
        printf("Error: Invalid position\n");
    }
    else
    {
        for(i = position; i < L->count-1; i++)
        {
            L->elem[i] = L->elem[i+1];
        }

        L->count--;
    }
}

int locate(List *L, int data)
{
    int i = 0;
    int pos = -1;

    while(i < L->count && pos == -1)
    {
        if(L->elem[i] == data)
        {
            pos = i;
        }
        else
        {
            i++;
        }
    }

    return pos;
}

void display(List *L)
{
    int i;

    if(L->count == 0)
    {
        printf("List is empty\n");
    }
    else
    {
        for(i = 0; i < L->count; i++)
        {
            printf("%d ", L->elem[i]);
        }
        printf("\n");
    }
}

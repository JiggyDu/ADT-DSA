#include <stdio.h>
#define size 10

typedef struct {
    int elem[size];
    int count;
} List;


void List initialize();
int insertPos(List *L, int data, int position);
void deletePos(List *L, int position);
int locate(List *L, int data);
void insertSorted(List *L, int data);
void display(List *L);

int main()
{
List L;

L = insertPos(L,0,10);

L = insertPos(L,1,20);

L = insertPos(L,1,10);

L = insertPos(L,2,10);



}

void List initialize()
{
List L;
L.count = 0;
for (int i = 0; i < size; i++)
{
    L.elem[i] = -1;
}

return L;
}

int List insertPos( List *L, int data, int position)
{
if (L->count >= size )
{
    printf("Size is full");
}

if (position < 0 || position > L->count)
{
    printf("Invalid Position");
}

 for (int i = L->count; i > position; i--)
{
    L->elem[i] = L->elem[i - 1];
}

L -> elem[position] = data;
L-> count++;
return 1;
}


void List deletePos(List *L, int position)
{
    if (position < 0 || position > L->count)
{
    printf("Invalid Position");
}

for (int i = position; i < L->count - 1; i++)
{
    L->elem[i] = L->elem[i + 1];
}
L -> count--;
}

int locate(List *L, int data)
{
for (int i = 0; i < L->count; i++)
{
    if (L->element[i] == data)
    {
    return i;
    }
}
return -1;
}

void List insertSorted (List *L, int data)
{

}

void display (List *L)
{
if (L->count == 0)
{
    printf("Empty");
}

for (int i = 0; i < L->count; i++) {
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}
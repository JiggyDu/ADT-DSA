#include <stdio.h>

#define SIZE 10
#define EMPTY -1
#define DELETED -2

typedef struct {
    int table[SIZE];
} Dictionary;

/* Hash function */
int hash(int key) {
    return key % SIZE;
}

/* Initialize dictionary */
void initDict(Dictionary *d) {
    for (int i = 0; i < SIZE; i++)
        d->table[i] = EMPTY;
}

/* Insert using linear probing */
void insert(Dictionary *d, int value) {
    int index = hash(value);

    while (d->table[index] != EMPTY && d->table[index] != DELETED) {
        index = (index + 1) % SIZE;
    }

    d->table[index] = value;
}

/* Search */
int search(Dictionary *d, int value) {
    int index = hash(value);
    int start = index;

    while (d->table[index] != EMPTY) {
        if (d->table[index] == value)
            return 1;
        index = (index + 1) % SIZE;
        if (index == start)
            break;
    }
    return 0;
}

/* Delete */
void delete(Dictionary *d, int value) {
    int index = hash(value);
    int start = index;

    while (d->table[index] != EMPTY) {
        if (d->table[index] == value) {
            d->table[index] = DELETED;
            return;
        }
        index = (index + 1) % SIZE;
        if (index == start)
            break;
    }
}

/* Display table */
void display(Dictionary *d) {
    for (int i = 0; i < SIZE; i++) {
        if (d->table[i] == EMPTY)
            printf("%d: EMPTY\n", i);
        else if (d->table[i] == DELETED)
            printf("%d: DELETED\n", i);
        else
            printf("%d: %d\n", i, d->table[i]);
    }
}

int main() {
    Dictionary d;
    initDict(&d);

    insert(&d, 23);
    insert(&d, 43);
    insert(&d, 13);
    insert(&d, 27);

    display(&d);

    delete(&d, 43);
    printf("\nAfter deletion:\n");
    display(&d);

    return 0;
}

#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 8   // elements 0 to 7

/* Set definition using boolean array */
typedef struct {
    bool elem[ARRAY_SIZE];
} Set;

/* Initialize the set */
void initialize(Set *set) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        set->elem[i] = false;
    }
}

/* Insert an element */
void insert(Set *set, int element) {
    if (element < 0 || element >= ARRAY_SIZE)
        return;

    set->elem[element] = true;
}

/* Delete an element */
void delete(Set *set, int element) {
    if (element < 0 || element >= ARRAY_SIZE)
        return;

    set->elem[element] = false;
}

/* Find an element */
bool find(Set set, int element) {
    if (element < 0 || element >= ARRAY_SIZE)
        return false;

    return set.elem[element];
}

/* Union of two sets: C = A ∪ B */
void unionSet(Set A, Set B, Set *C) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        C->elem[i] = A.elem[i] || B.elem[i];
    }
}

/* Intersection of two sets: C = A ∩ B */
void intersection(Set A, Set B, Set *C) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        C->elem[i] = A.elem[i] && B.elem[i];
    }
}

/* Difference of two sets: C = A - B */
void difference(Set A, Set B, Set *C) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        C->elem[i] = A.elem[i] && !B.elem[i];
    }
}

/* Display the set */
void display(Set set) {
    printf("{");
    bool first = true;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (set.elem[i]) {
            if (!first)
                printf(", ");
            printf("%d", i);
            first = false;
        }
    }

    printf("}\n");
}

/* Test driver */
int main(void) {
    Set A, B, C;

    initialize(&A);
    initialize(&B);

    insert(&A, 0);
    insert(&A, 2);
    insert(&A, 7);
    // A = {0, 2, 7}

    insert(&B, 2);
    insert(&B, 4);
    insert(&B, 5);
    // B = {2, 4, 5}

    printf("Set A: ");
    display(A);

    printf("Set B: ");
    display(B);

    unionSet(A, B, &C);
    printf("Union: ");
    display(C);

    intersection(A, B, &C);
    printf("Intersection: ");
    display(C);

    difference(A, B, &C);
    printf("Difference (A - B): ");
    display(C);

    delete(&A, 0);
    delete(&A, 7);
    printf("A after deletions: ");
    display(A);

    return 0;
}

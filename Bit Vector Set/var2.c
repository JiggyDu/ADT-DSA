#include <stdio.h>
#include <stdbool.h>

/*
 * Set ADT using bit fields (8 elements: 0–7)
 */

typedef struct {
    unsigned char field;   // each bit represents one element
} Set;

/* Initialize the set */
void initialize(Set *set) {
    set->field = 0;
}

/* Insert an element into the set */
void insert(Set *set, int element) {
    if (element < 0 || element > 7)
        return;

    set->field |= (1 << element);
}

/* Delete an element from the set */
void delete(Set *set, int element) {
    if (element < 0 || element > 7)
        return;

    set->field &= ~(1 << element);
}

/* Find if an element exists in the set */
bool find(Set set, int element) {
    if (element < 0 || element > 7)
        return false;

    return (set.field & (1 << element)) != 0;
}

/* Union of two sets */
Set unionSet(Set A, Set B) {
    Set C;
    C.field = A.field | B.field;
    return C;
}

/* Intersection of two sets */
Set intersection(Set A, Set B) {
    Set C;
    C.field = A.field & B.field;
    return C;
}

/* Difference of two sets (A - B) */
Set difference(Set A, Set B) {
    Set C;
    C.field = A.field & ~(B.field);
    return C;
}

/* Display the set */
void display(unsigned char set) {
    printf("{");
    bool first = true;

    for (int i = 0; i < 8; i++) {
        if (set & (1 << i)) {
            if (!first)
                printf(", ");
            printf("%d", i);
            first = false;
        }
    }

    printf("}\n");
}

/* Main function for testing */
int main(void) {
    Set A, B, C;

    initialize(&A);
    initialize(&B);

    insert(&A, 0);
    insert(&A, 4);
    insert(&A, 5);
    // A = {0, 4, 5}

    insert(&B, 2);
    insert(&B, 5);
    // B = {2, 5}

    printf("Set A: ");
    display(A.field);

    printf("Set B: ");
    display(B.field);

    C = unionSet(A, B);
    printf("Union: ");
    display(C.field);

    C = intersection(A, B);
    printf("Intersection: ");
    display(C.field);

    C = difference(A, B);
    printf("Difference (A - B): ");
    display(C.field);

    delete(&A, 5);
    delete(&A, 4);
    printf("A after deletions: ");
    display(A.field);

    return 0;
}

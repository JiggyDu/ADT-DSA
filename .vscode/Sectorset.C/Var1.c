
#include <stdio.h>
#include <stdbool.h>

// Initialize the set to zero
void initialize(unsigned char *set) {
    *set = 0;
}

// Insert an element (bit) into the set
void insert(unsigned char *set, int element) {
    if (element < 0 || element > 7) {
        printf("Error: element %d out of range (0-7).\n", element);
        return;
    }
    unsigned char mask = 1 << element;
    *set |= mask;
}

// Delete an element (bit) from the set
void delete(unsigned char *set, int element) {
    if (element < 0 || element > 7) {
        printf("Error: element %d out of range (0-7).\n", element);
        return;
    }
    unsigned char mask = 1 << element;
    *set &= ~mask;
}

// Find if an element is present in the set
bool find(unsigned char set, int element) {
    if (element < 0 || element > 7) {
        printf("Error: element %d out of range (0-7).\n", element);
        return false;
    }
    unsigned char mask = 1 << element;
    return (set & mask) != 0;
}

// Union of two sets (bitwise OR)
unsigned char union_set(unsigned char A, unsigned char B) {
    return A | B;
}

// Intersection of two sets (bitwise AND)
unsigned char intersection(unsigned char A, unsigned char B) {
    return A & B;
}

// Difference of two sets (A - B) = A & (~B)
unsigned char difference(unsigned char A, unsigned char B) {
    return A & (~B);
}

// Display the elements of the set
void display(unsigned char set) {
    printf("{");
    bool first = true;
    for (int i = 0; i < 8; i++) {
        if (find(set, i)) {
            if (!first) {
                printf(", ");
            }
            printf("%d", i);
            first = false;
        }
    }
    printf("}\n");
}

// Example usage
int main() {
    unsigned char A;
    unsigned char B;

    initialize(&A);
    insert(&A, 1);
    insert(&A, 6);
    printf("Set A: ");
    display(A);  // {1, 6}

    initialize(&B);
    insert(&B, 3);
    insert(&B, 6);
    insert(&B, 7);
    printf("Set B: ");
    display(B);  // {3, 6, 7}

    unsigned char C;

    C = union_set(A, B);
    printf("Union: ");
    display(C);  // {1, 3, 6, 7}

    C = intersection(A, B);
    printf("Intersection: ");
    display(C);  // {6}

    C = difference(A, B);
    printf("Difference (A - B): ");
    display(C);  // {1}

    delete(&A, 6);
    printf("Set A after deleting 6: ");
    display(A);  // {1}

    delete(&A, 1);
    printf("Set A after deleting 1: ");
    display(A);  // {}

    return 0;
}

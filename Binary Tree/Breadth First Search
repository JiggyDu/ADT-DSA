#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 10
#define INVALID_NODE -1

typedef int Node;

// Adjacency list node
typedef struct ChildNode {
    Node childIndex;
    struct ChildNode *next;
} ChildNode;

// Tree structure
typedef struct {
    Node root;
    ChildNode* children[MAX_NODES];
} Tree;

// Initialize tree
void initializeTree(Tree *T) {
    T->root = INVALID_NODE;
    for (int i = 0; i < MAX_NODES; i++)
        T->children[i] = NULL;
}

// Add child
void addChild(Tree *T, Node parent, Node child) {
    ChildNode *newNode = (ChildNode*)malloc(sizeof(ChildNode));
    newNode->childIndex = child;
    newNode->next = T->children[parent];
    T->children[parent] = newNode;
}

// BFS traversal
void bfs(Tree *T) {
    if (T->root == INVALID_NODE) return;

    bool visited[MAX_NODES] = {false};
    Node queue[MAX_NODES];
    int front = 0, rear = 0;

    queue[rear++] = T->root;
    visited[T->root] = true;

    printf("BFS: ");
    while (front < rear) {
        Node current = queue[front++];
        printf("%d ", current);

        ChildNode *child = T->children[current];
        while (child != NULL) {
            if (!visited[child->childIndex]) {
                visited[child->childIndex] = true;
                queue[rear++] = child->childIndex;
            }
            child = child->next;
        }
    }
    printf("\n");
}

// Free tree memory
void freeTree(Tree *T) {
    for (int i = 0; i < MAX_NODES; i++) {
        ChildNode *curr = T->children[i];
        while (curr != NULL) {
            ChildNode *next = curr->next;
            free(curr);
            curr = next;
        }
        T->children[i] = NULL;
    }
}

int main() {
    Tree T;
    initializeTree(&T);

    // Create root
    T.root = 0;

    // Build sample tree
    addChild(&T, 0, 1);
    addChild(&T, 0, 2);
    addChild(&T, 1, 3);
    addChild(&T, 1, 4);
    addChild(&T, 2, 5);
    addChild(&T, 5, 8);
    addChild(&T, 5, 9);

    // BFS traversal
    bfs(&T);

    freeTree(&T);
    return 0;
}

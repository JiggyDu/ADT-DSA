#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ---------------- BFS Traversal ----------------
#define MAX_QUEUE 100

void bfs(Node* root) {
    if (root == NULL) return;

    Node* queue[MAX_QUEUE];
    int front = 0, rear = 0;

    queue[rear++] = root;

    printf("BFS (Level-order): ");
    while (front < rear) {
        Node* current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL)
            queue[rear++] = current->left;
        if (current->right != NULL)
            queue[rear++] = current->right;
    }
    printf("\n");
}

// ---------------- DFS Traversals ----------------

// Preorder: Root -> Left -> Right
void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Inorder: Left -> Root -> Right
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Postorder: Left -> Right -> Root
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// ---------------- Main ----------------
int main() {
    // Sample Binary Tree
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // BFS Traversal
    bfs(root);

    // DFS Traversals
    printf("Preorder (DFS): ");
    preorder(root);
    printf("\n");

    printf("Inorder (DFS): ");
    inorder(root);
    printf("\n");

    printf("Postorder (DFS): ");
    postorder(root);
    printf("\n");

    return 0;
}

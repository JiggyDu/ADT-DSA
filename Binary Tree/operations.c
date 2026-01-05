#include <stdio.h>
#include <stdlib.h>

// --------- BST Node ----------
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create a new BST node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// --------- BST Insert ----------
Node* insert(Node* root, int data) {
    if (root == NULL) return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    // Duplicate values are ignored
    return root;
}

// --------- BST Search ----------
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) return root;

    if (data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

// --------- Find Minimum Node (for delete) ----------
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// --------- BST Delete ----------
Node* delete(Node* root, int data) {
    if (root == NULL) return NULL;

    if (data < root->data)
        root->left = delete(root->left, data);
    else if (data > root->data)
        root->right = delete(root->right, data);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

// --------- DFS Traversals ----------
void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// --------- BFS Traversal ----------
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

        if (current->left != NULL) queue[rear++] = current->left;
        if (current->right != NULL) queue[rear++] = current->right;
    }
    printf("\n");
}

// --------- Free Tree ----------
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// --------- Main ----------
int main() {
    Node* root = NULL;

    // Insert nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Traversals
    printf("Inorder (DFS): ");
    inorder(root);
    printf("\n");

    printf("Preorder (DFS): ");
    preorder(root);
    printf("\n");

    printf("Postorder (DFS): ");
    postorder(root);
    printf("\n");

    bfs(root);

    // Search
    int key = 40;
    Node* found = search(root, key);
    if (found) printf("Node %d found in BST.\n", key);
    else printf("Node %d not found.\n", key);

    // Delete
    root = delete(root, 30);
    printf("After deleting 30, Inorder: ");
    inorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}

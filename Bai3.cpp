#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

int search(Node* root, int value) {
    if (root == NULL) {
        return 0;
    }
    if (value == root->data) {
        return 1;
    }
    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Node* root = NULL;
    int values[] = {20, 10, 30, 5, 15, 25, 35};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    int searchValue1;
    int searchValue2;

    printf("Search = ");
    scanf("%d", &searchValue1);
    if (search(root, searchValue1)) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }
    
	printf("Search = ");
    scanf("%d", &searchValue2);
    if (search(root, searchValue2)) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    freeTree(root);
    return 0;
}


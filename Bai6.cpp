#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

bool isBSTUtil(Node* root, int min, int max) {
    if (root == NULL) {
        return true;
    }
    if (root->data <= min || root->data >= max) {
        return false;
    }
    return isBSTUtil(root->left, min, root->data) && isBSTUtil(root->right, root->data, max);
}

bool isBST(Node* root) {
    return isBSTUtil(root, -__INT_MAX__, __INT_MAX__);
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Node* root = NULL;
    int choice, value, n;

    while (1) {
        printf("\nChon thao tac:\n");
        printf("1. Chen gia tri vao cay\n");
        printf("2. Kiem tra tinh chat BST\n");
        printf("3. Thoat chuong trinh\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so luong gia tri can chen: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Nhap gia tri thu %d: ", i + 1);
                    scanf("%d", &value);
                    root = insertNode(root, value);
                }
                break;

            case 2:
                if (isBST(root)) {
                    printf("Cay la cay nhi phan tim kiem (BST).\n");
                } else {
                    printf("Cay KHONG phai la cay nhi phan tim kiem (BST).\n");
                }
                break;

            case 3:
                freeTree(root);
                printf("Ket thuc chuong trinh.\n");
                return 0;

            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    }
    return 0;
}


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

Node* searchNode(Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return searchNode(root->left, value);
    } else {
        return searchNode(root->right, value);
    }
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
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
    int choice, value, n, searchValue;

    while (1) {
        printf("\nChon thao tac:\n");
        printf("1. Chen gia tri vao cay\n");
        printf("2. Duyet cay inorder\n");
        printf("3. Tim kiem gia tri\n");
        printf("4. Thoat chuong trinh\n");
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
                printf("Duyet cay theo thu tu inorder: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 3:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &searchValue);
                if (searchNode(root, searchValue) != NULL) {
                    printf("Gia tri %d ton tai trong cay.\n", searchValue);
                } else {
                    printf("Gia tri %d khong ton tai trong cay.\n", searchValue);
                }
                break;

            case 4:
                freeTree(root);
                printf("Ket thuc chuong trinh.\n");
                return 0;

            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    }
    return 0;
}


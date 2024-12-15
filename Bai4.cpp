#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* taoDinh(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* themDinh(Node* root, int value) {
    if (root == NULL) {
        return taoDinh(value);
    }
    char huong;
    printf("Nhap 'L' de them vao con trai, 'R' de them vao con phai cua %d: ", root->data);
    scanf(" %c", &huong);
    if (huong == 'L' || huong == 'l') {
        root->left = themDinh(root->left, value);
    } else if (huong == 'R' || huong == 'r') {
        root->right = themDinh(root->right, value);
    }
    return root;
}

int tinhChieuCao(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int chieuCaoTrai = tinhChieuCao(root->left);
    int chieuCaoPhai = tinhChieuCao(root->right);
    return (chieuCaoTrai > chieuCaoPhai ? chieuCaoTrai : chieuCaoPhai) + 1;
}

void giaiPhongCay(Node* root) {
    if (root == NULL) return;
    giaiPhongCay(root->left);
    giaiPhongCay(root->right);
    free(root);
}

int main() {
    Node* root = NULL;
    int n, value;

    printf("Nhap so dinh cua cay: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri dinh thu %d: ", i + 1);
        scanf("%d", &value);
        if (root == NULL) {
            root = taoDinh(value);
        } else {
            root = themDinh(root, value);
        }
    }

    int chieuCao = tinhChieuCao(root);
    printf("Chieu cao cua cay: %d\n", chieuCao);

    giaiPhongCay(root);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* firstChild;
    struct Node* nextSibling;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

void addChild(Node* parent, int data) {
    Node* child = createNode(data);
    if (parent->firstChild == NULL) {
        parent->firstChild = child;
    } else {
        Node* temp = parent->firstChild;
        while (temp->nextSibling != NULL) {
            temp = temp->nextSibling;
        }
        temp->nextSibling = child;
    }
}

void findLevel2Nodes(Node* root) {
    if (root == NULL || root->firstChild == NULL) {
        printf("Khong co dinh lop 2\n");
        return;
    }
    Node* child = root->firstChild;
    printf("Cac dinh lop 2: ");
    while (child != NULL) {
        Node* grandChild = child->firstChild;
        while (grandChild != NULL) {
            printf("%d ", grandChild->data);
            grandChild = grandChild->nextSibling;
        }
        child = child->nextSibling;
    }
    printf("\n");
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->firstChild);
    freeTree(root->nextSibling);
    free(root);
}

int main() {
    Node* root1 = createNode(1);
    addChild(root1, 2);
    addChild(root1, 3);
    addChild(root1->firstChild, 4);
    addChild(root1->firstChild, 5);
    addChild(root1->firstChild->nextSibling, 6);
    printf("Cay 1:\n");
    findLevel2Nodes(root1);
    freeTree(root1);

    Node* root2 = createNode(1);
    addChild(root2, 2);
    addChild(root2->firstChild, 3);
    printf("\nCay 2:\n");
    findLevel2Nodes(root2);
    freeTree(root2);

    Node* root3 = createNode(1);
    addChild(root3, 2);
    addChild(root3, 3);
    addChild(root3->firstChild, 4);
    addChild(root3->firstChild, 5);
    addChild(root3->firstChild->nextSibling, 6);
    addChild(root3->firstChild->nextSibling, 7);
    addChild(root3->firstChild->nextSibling->nextSibling, 8);
    printf("\nCay 3:\n");
    findLevel2Nodes(root3);
    freeTree(root3);

    return 0;
}


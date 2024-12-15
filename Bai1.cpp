#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
} Node;

Node* createNode(int data){
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node* insertNode(Node *node, int data){
	if(node == NULL){
		node = createNode(data);
	}
	if(data < node->data){
		node->left = insertNode(node->left, data);
	} else if(data > node->data) {
		node->right = insertNode(node->right, data);
	}
	return node;
}

void preOrdered(Node* node){
	if(node != NULL){
		printf("%d \t", node->data);
		preOrdered(node->left);
		preOrdered(node->right);
	}
}

void inOrdered(Node* node){
	if(node != NULL){
		inOrdered(node->left);
		printf("%d \t", node->data);
		inOrdered(node->right);
	}
}

void postOrdered(Node* node){
	if(node != NULL){
		postOrdered(node->left);
		postOrdered(node->right);
		printf("%d \t", node->data);
	}
}

int main(){
	Node* tree = NULL;
	int n, value;
	printf("nhap so gia tri muon them");
	scanf("%d", &n);
	printf("nhap cac gia tri:\n");
	for(int i = 0; i < n; i++){
		scanf("%d", &value);
		tree = insertNode(tree, value);
	}
	printf("Tien thu tu:\t");
	preOrdered(tree);
	printf("\n");
	printf("Trung thu tu:\n");
	inOrdered(tree);
	printf("\n");
	printf("Hau thu tu:\n");
	postOrdered(tree);
	return 0;
}


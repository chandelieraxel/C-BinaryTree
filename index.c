#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* leftChild;
    struct Node* rightChild;
};

struct Node* initNode(int value) {
    struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->value = value;

    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    return newNode;
};

void initNodeToLeftChild(struct Node* parentNode, int value) {
    parentNode->leftChild = initNode(value);
};

void initNodeToRightChild(struct Node* parentNode, int value) {
    parentNode->rightChild = initNode(value);
};

void loopTree(struct Node* root) {
    if (root == NULL) return;

    printf("The value is : %i\n", root->value);

    /*
        Work because C handle functions in a Stack
    */
    loopTree(root->leftChild);
    loopTree(root->rightChild);


};


void deleteTree(struct Node* node) {
    if (node) {
        deleteTree(node->leftChild);
        deleteTree(node->rightChild);

        free(node);
    }
}


int main() {
    printf("Hello world\n");

    /*
            1
           / \
           2   3
          / \ / \
         4  5 6  7
    */

    struct Node* root = initNode(1);
    initNodeToLeftChild(root, 2);
    initNodeToRightChild(root, 3);

    initNodeToLeftChild(root->leftChild, 4);
    initNodeToRightChild(root->leftChild, 5);

    initNodeToLeftChild(root->rightChild, 6);
    initNodeToRightChild(root->rightChild, 7);

    loopTree(root);

    deleteTree(root);

    return 0;
};
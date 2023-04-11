#include <stdio.h>
#include <stdlib.h>

#define N 10

struct node {
    int data;

    struct node *leftChild;
    struct node *rightChild;
};

int max(int x, int y) {
    if(x >= y) {
        return x;
    } else {
        return y;
    }
}

void insert(struct node *root, int data) {
    struct node *tempNode = (struct node *) malloc(sizeof(struct node));
    struct node *current;
    struct node *parent;

    tempNode->data = data;
    tempNode->leftChild = NULL;
    tempNode->rightChild = NULL;

    if (root == NULL) {
        root = tempNode;
        return;
    } else {
        current = root;
        parent = NULL;

        while(1) {
            parent = current;

            if(data < parent->data) {
                current = current->leftChild;

                if(current == NULL) {
                    parent->leftChild = tempNode;
                    return;
                }
            } else {
                current = current->rightChild;

                if(current == NULL) {
                    parent->rightChild = tempNode;
                    return;
                }
            }

        }
    }
}

int height(struct node *root) {
    if(root == NULL) {
        return 0;
    } else {
        int leftHeight = height(root->leftChild);
        int rightHeight = height(root->rightChild);
        return 1 + max(leftHeight, rightHeight);
    }
}

int echilibrat(struct node *root) {
    if (root == NULL) {
        return 1;
    } else {
        int leftHeight = height(root->leftChild);
        int rightHeight = height(root->rightChild);

        if(abs(leftHeight - rightHeight) <= 1 && echilibrat(root->leftChild) && echilibrat(root->rightChild)) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main(){
    struct node *root = NULL;
    int nr_elemente;
    int element;

    printf("Introduceti numarul de elemente al arborilor: ");
    scanf("%d",&nr_elemente);
    printf("Introduceti elemntele arborelui: ");
    for(int i = 0; i < nr_elemente; i++) {
        scanf("%d", &element);
        insert(root, element);
    }

    if(echilibrat(root) == 1) {
        printf("\nArbroele binar este echilibrat");
    } else {
        printf("\nArbroele binar nu este echilibrat");
    }

    return 0;
}
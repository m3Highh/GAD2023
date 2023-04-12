#include <stdio.h>
#include <stdlib.h>

#define N 10

struct node {
    int data;

    struct node *leftChild;
    struct node *rightChild;
};

void insert(struct node **root, int data) {
    struct node *tempNode = (struct node *) malloc (sizeof(struct node));
    struct node *current;
    struct node *parent;

    tempNode->data = data;
    tempNode->leftChild = NULL;
    tempNode->rightChild = NULL;

    if (*root == NULL) {
        *root = tempNode;
        return;
    } else {
        current = *root;
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

void preOrderTaversal(struct node *root) {
    if(root == NULL) {
        return;
    } else {
        printf("%d ", root->data);
        preOrderTaversal(root->leftChild);
        preOrderTaversal(root->rightChild);
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
        insert(&root, element);
    }

    printf("Arborele traversat cu metoda pre-order este: ");
    preOrderTaversal(root);

    return 0;
}
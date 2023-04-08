#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int isEmpty(int top) {
    return top == -1;
}

int isFull(int top) {
    return top == SIZE - 1;
}

void push(int stack[], int *top, int x){
    if(isFull(*top)){
        printf("\nStack overflow!!");
    }else{
        *top = *top + 1;
        stack[*top] = x;
    }
}

int pop(int stack[], int *top){
    if(isEmpty(*top)){
        printf("\nStack underflow!!");
        exit(EXIT_FAILURE);
    } else {
        int x = stack[*top];
        *top = *top - 1;
        return x;
    }
} 

void enqueue(int x, int stack1[], int *top1, int stack2[], int *top2) {
    push(stack1, top1, x);
}

int dequeue(int stack1[], int *top1, int stack2[], int *top2) {
    if (*top1 == -1 && *top2 == -1) {
        printf("Error: queue is empty\n");
        exit(EXIT_FAILURE);
    }
    if (*top2 == -1) {
        while (*top1 != -1) {
            int x = pop(stack1, top1);
            push(stack2, top2, x);
        }
    }
    return pop(stack2, top2);
}

int main(){
    int stack1[SIZE], stack2[SIZE];
    int top1 = -1;
    int top2 = -1;
    int nr_elemente, x;

    //citirea si introducerea elementelor in coada
    printf("\nIntroduceti dimensiunea cozii: ");
    scanf("%d", &nr_elemente);
    printf("Introduceti cele %d numere: ", nr_elemente);
    for(int i  = 0; i < nr_elemente; i++){
        scanf("%d", &x);
        enqueue(x, stack1, &top1, stack2, &top2);
    }

    //afisarea cozii
    for(int i = 0; i < nr_elemente; i++){
        printf("%d ", dequeue(stack1, &top1, stack2, &top2));
    }

    return 0;
}

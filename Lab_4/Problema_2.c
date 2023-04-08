#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

void afisareStiva1(int top, int stack[]){
    for(int i = 0; i <= top; i++){
        printf("%d ", stack[i]);
    }
}

void afisareStiva2(int top1, int top2, int stack[]){
    for(int i = top1 + 1; i <= top2; i++){
        printf("%d ", stack[i]);
    }
}

void push(int *top, int stack[]){
        int x;

        if(*top == SIZE - 1){
            printf("\nStack overflow!!");
            return ;
        }else{
            printf("Introduceti elementul pe care vreti sa il adaugati in stiva: ");
            scanf("%d", &x);
            *top = *top + 1;
            stack[*top] = x;
        }
    }

void pop(int *top, int stack[]){
        if(*top == -1){
            printf("\nStack underflow!!");
            return ;
        }else{
            printf("\nElementul scos este: %d", stack[*top]);
            *top = *top - 1;
        }
    }   

int main(){
    int stack[SIZE];
    int size1, size2;
    int top1, top2;

    printf("\nIntroduceti dimensiunea stivei 1: ");
    scanf("%d", &size1);
    size2 = SIZE - size1;
    printf("Dimensinuea stivei 2 este: %d", size2);
    top1 = -1;
    top2 = size1 - 1;

    printf("\nIntroduceti valorile pentru stiva 1:\n ");
    for(int i = 0; i < size1; i++){
        push(&top1, stack);
    }

    printf("\nIntroduceti valorile pentru stiva 2:\n ");
    for(int i = 0; i < size2; i++){
        push(&top2, stack);
    }

    printf("Elementele din prima stiva sunt: ");
    afisareStiva1(top1, stack);
    printf("\n");
    printf("Elementele din a 2 a stiva sunt: ");
    afisareStiva2(top1, top2, stack);

    while(top2 > top1){
        pop(&top2, stack);
    }

    while(top1 > -1){
        pop(&top1, stack);
    }

    printf("\n****************************************************************");
    return 0;
}
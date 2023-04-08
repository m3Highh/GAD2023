#include<stdio.h>
#include<stdlib.h>

#define SIZE 20

void afisareStiva(int top, int stack[]){
    for(int i = 0; i <= top; i++){
        printf("%d ", stack[i]);
    }
}

void push(int *top, int stack[]){
        int x;

        if(*top == SIZE - 1){
            printf("\nStack overflow!!");
        }else{
            printf("\nIntroduceti elementul pe care vreti sa il adaugati in stiva: ");
            scanf("%d", &x);
            *top = *top + 1;
            stack[*top] = x;
        }
    }

void pop(int *top, int stack[]){
        if(*top == -1){
            printf("\nStack underflow!!");
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
    printf("\nDimensinuea stivei 2 este: %d", size2);
    top1 = -1;
    top2 = size1 - 1;

    printf("\nIntroduceti valorile pentru stiva 1: ");
    for(int i = 0; i < size1; i++){
        push(&top1, stack);
    }

    printf("\nIntroduceti valorile pentru stiva 2: ");4
    for(int i = 0; i < size2; i++){
        push(&top2, stack);
    }

    afisareStiva(top2, stack);
    printf("\n****************************************************************");
    return 0;
}
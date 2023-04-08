    #include <stdio.h>
    #include <stdlib.h>

    #define SIZE 10

    //functii pentru stiva
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

    void peekStack(int top, int stack[]){
        if(top == -1){
            printf("\nStack underflow!!");
        }else if(top == SIZE - 1){
            printf("\nStack overflow!!");
        }else{
            printf("\nElementul de la capatul stivei este: %d", stack[top]);
        }
    }

    void isFull(int top){
        if(top == SIZE - 1){
            printf("\nStack overflow!!");
        }
        else{
            printf("\nStack is not full!!");
        }
    }

    void isEmpty(int top){
        if(top == -1){
            printf("\nStack underflow!!");
        }
        else{
            printf("\nStack is not empty!!");
        }
    }

    
    //functii pentru coada
    void enqueue(int *rear, int queue[]){
        int insert_item;
        
        if(*rear == SIZE - 1){
            printf("\nQueue overflow!!");
            return ;
        }else{
            printf("\nIntroduceti elementul pe care sa il introduceti in coada: ");
            scanf("%d", &insert_item);
            *rear = *rear +1;
            queue[*rear] = insert_item;
        }
    }

    void dequeue(int *front, int *rear, int queue[]){
        if(front == -1 || *front > *rear){
            printf("\nQueue is underflow!!");
            return ;
        } else {
            printf("\nElementul sters din coada este: %d", queue[*front]);
            for(int i = 0; i < *rear - 1; i++){
                queue[i] = queue[i + 1];
            }
            *rear = *rear - 1;
        }
    }

    void peekQueue(int queue[], int front, int rear){
        if(rear == SIZE - 1){
            printf("\nQueue overflow!!");
            return ;
        } else if(front == -1 || front > rear){
            printf("\nQueue is underflow!!");
            return ;
        } else {
            printf("\nPrimul element din coada este: %d", queue[front]);
        }
    }

    void isFullQueue(int rear){
        if(rear == SIZE - 1){
            printf("\nQueue overflow!!");
        }
        else{
            printf("\nQueue is not full!!");
        }
    }

    void isEmptyQueue(int front, int rear){
        if(front == -1 || front > rear){
            printf("\nQueue underflow!!");
        }
        else{
            printf("\nQueue is not empty!!");
        }
    }

    int main(){
        int stack[SIZE] = {8, 4, 2, 7, 4, 9};
        int queue[SIZE] = {9, 5, 3, 8, 1, 4};
        int top = 5;
        int rear = 5;
        int front = 0;

        //comenzi stiva
        push(&top, stack);
        peekStack(top, stack);
        pop(&top, stack);
        peekStack(top, stack);
        isEmpty(top);
        isFull(top);

        //comenzi coada
        enqueue(&rear, queue);
        peekQueue(queue, front, rear);
        dequeue(&front, &rear, queue);
        peekQueue(queue, front, rear);
        isEmptyQueue(front, rear);
        isFullQueue(rear);

        return 0;
    }

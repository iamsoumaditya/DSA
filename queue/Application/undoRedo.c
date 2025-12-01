#define MAX 150
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
struct Node{
    struct Node *prev;
    char data[MAX];
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;
struct Node *curr = NULL;

struct Node *create(char data[]){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL){
        printf("Insufficient Memory!!");
        return ptr;
    }
    ptr->prev = NULL;
    strcpy(ptr->data,data);
    ptr->next = NULL;
    return ptr;
}

int isEmpty(){
    return rear == NULL;
}

// int isFull(){
//  this is not needed as dynamically memory allocated so never it's full until memory insufficient
//}

void enqueueRear(char data[]){
    struct Node *curr = create(data);
    if (curr == NULL)
        return;
    if (rear == NULL){
        rear = curr;
        front = rear;
        return;
    }
    rear->next = curr;
    curr->prev = rear;
    rear = curr;
}

void dequeueRear(){
    if (isEmpty()){
        printf("Queue underflow!!");
        return ;
    }
    struct Node *temp = rear;
    rear = rear->prev;
    free(temp);
    if (rear != NULL)
        rear->next = NULL;
    else
        front = NULL;
}

void addInstruction(char data[]){
    if(rear != curr){
        while(rear != curr)
            dequeueRear();
    }
    enqueueRear(data);
    curr = rear;
}

void undoInstruction(){
    if(curr == front){
        printf("Nothing to undo!!");
        return;
    }
    curr = curr->prev;
}

void redoInstruction(){
    if(curr == rear){
        printf("Nothing to Redo");
        return;
    }
    curr = curr->next;
}

void display(){
    if(curr == NULL){
        printf("Nothing to display!!");
        return;
    }
    printf("%s ", curr->data);
}

int main(){
    int choice,n;
    char instruction[MAX];

    while (1){
        printf("\n--- DeQueue Menu ---\n");
        printf("1. Add instruction\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            printf("Enter the instruction: ");
            scanf("%s", instruction);
            addInstruction(instruction);
            break;

        case 2:
            undoInstruction();
            break;

        case 3:
            redoInstruction();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

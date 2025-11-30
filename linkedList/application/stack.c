#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *top = NULL;

struct Node *create(int val){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL){
        printf("Insufficient Memory!!\n");
        return ptr;
    }
    ptr->data = val;
    ptr->next = NULL;
    return ptr;
}

int isEmpty(){
    return top == NULL;
}

// int isFull(){
//  this is not needed as dynamically memory allocated so never it's full until memory insufficient
//}

void push(int val){
    struct Node *curr = create(val);
    if (curr == NULL)
        return;
    curr->next = top;
    top = curr;
}

int peek(){
    if (isEmpty()){
        printf("Stack is empty!!");
        return INT_MIN;
    }
    return top->data;
}

int pop(){
    if (isEmpty()){
        printf("Stack underflow!!");
        return INT_MIN;
    }
    struct Node *temp = top;
    int x = temp->data;
    top = top->next;
    free(temp);
    return x;
}

void display(){
    if (isEmpty()){
        printf("Stack is empty!!");
        return;
    }
    struct Node *temp = top;
    while(temp !=NULL){
        printf("%3d\t",temp->data);
        temp = temp->next;
    }
    printf("\n");
} 
int main(){
    int choice, val;

    while (1){
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &val);
            push(val);
            break;

        case 2:
            val = pop();
            if (val != INT_MIN)
                printf("Popped element: %d\n", val);
            break;

        case 3:
            val = peek();
            if (val != INT_MIN)
                printf("Top element: %d\n", val);
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
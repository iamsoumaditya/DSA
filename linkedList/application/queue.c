#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;

struct Node *create(int val){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL){
        printf("Insufficient Memory!!");
        return ptr;
    }
    ptr->data = val;
    ptr->next = NULL;
    return ptr;
}

int isEmpty(){
    return rear == NULL;
}

// int isFull(){
//  this is not needed as dynamically memory allocated so never it's full until memory insufficient
//}

void enqueue(int val){
    struct Node *curr = create(val);
    if (curr == NULL)
        return;
    if (rear == NULL){
        rear = curr;
        front = curr;
        return;
    }
    rear->next = curr;
    rear = curr;
}

int peek(){
    if (isEmpty()){
        printf("Nothing to delete.");
        return INT_MIN;
    }
    return front->data;
}

int dequeue(){
    if (isEmpty()){
        printf("Queue underflow!!");
        return INT_MIN;
    }
    struct Node *temp = front;
    int x = temp->data;
    front = front->next;
    free(temp);
    if (front == NULL)
        rear = NULL;
    return x;
}

void display(){
    if (isEmpty()){
        printf("Queue is empty!!");
        return;
    }
    struct Node *temp = front;
    while (temp != rear->next){
        printf("%3d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    int choice, val;

    while (1){
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &val);
            enqueue(val);
            break;

        case 2:
            val = dequeue();
            if (val != INT_MIN)
                printf("Dequeued element: %d\n", val);
            break;

        case 3:
            val = peek();
            if (val != INT_MIN)
                printf("Front element: %d\n", val);
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

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
struct Node{
    struct Node *prev;
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
    ptr->prev = NULL;
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

void enqueueFront(int val){
    struct Node *curr = create(val);
    if (curr == NULL)
        return;
    if (front == NULL){
        front = curr;
        rear = front;
        return;
    }
    curr->next = front;
    front->prev = curr;
    front = curr;
}

void enqueueRear(int val){
    struct Node *curr = create(val);
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

int peekFront(){
    if (isEmpty()){
        printf("Nothing to delete.");
        return INT_MIN;
    }
    return front->data;
}

int peekRear(){
    if (isEmpty()){
        printf("Nothing to delete.");
        return INT_MIN;
    }
    return rear->data;
}

int dequeueFront(){
    if (isEmpty()){
        printf("Queue underflow!!");
        return INT_MIN;
    }
    struct Node *temp = front;
    int x = front->data;
    front = front->next;
    free(temp);
    if(front != NULL)
        front->prev = NULL;
    else
        rear = NULL;
    return x;
}

int dequeueRear(){
    if (isEmpty()){
        printf("Queue underflow!!");
        return INT_MIN;
    }
    struct Node *temp = rear;
    int x = rear->data;
    rear = rear->prev;
    free(temp);
    if (rear != NULL)
        rear->next = NULL;
    else
        front = NULL;
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
        printf("\n--- DeQueue Menu ---\n");
        printf("1. EnqueueFront\n");
        printf("2. EnqueueRear\n");
        printf("3. DequeueFront\n");
        printf("4. DequeueRear\n");
        printf("5. PeekFront\n");
        printf("6. PeekRear\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &val);
            enqueueFront(val);
            break;

        case 2:
            printf("Enter value to enqueue: ");
            scanf("%d", &val);
            enqueueRear(val);
            break;

        case 3:
            val = dequeueFront();
            if (val != INT_MIN)
                printf("Dequeued element: %d\n", val);
            break;

        case 4:
            val = dequeueRear();
            if (val != INT_MIN)
                printf("Dequeued element: %d\n", val);
            break;

        case 5:
            val = peekFront();
            if (val != INT_MIN)
                printf("Front element: %d\n", val);
            break;

        case 6:
            val = peekRear();
            if (val != INT_MIN)
                printf("Front element: %d\n", val);
            break;

        case 7:
            display();
            break;

        case 8:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

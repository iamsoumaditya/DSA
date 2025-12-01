#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
struct Node{
    int priority;
    char data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;

struct Node *create(int priority,char data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL){
        printf("Insufficient Memory!!");
        return ptr;
    }
    ptr->priority = priority;
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

int isEmpty(){
    return rear == NULL;
}

// int isFull(){
//  this is not needed as dynamically memory allocated so never it's full until memory insufficient
//}

void enqueue(int priority,char ch){
    struct Node *curr = create(priority,ch);
    if (curr == NULL)
        return;
    if (rear == NULL){
        rear = curr;
        front = curr;
        return;
    }
    if(priority < front->priority){
        curr->next = front;
        front = curr;
        return;
    }
    struct Node *temp = front;
    while (temp->next != NULL && temp->next->priority <= priority)
        temp = temp->next;
    curr->next = temp->next;
    if(temp->next == NULL)
        rear = curr;
    temp->next = curr;
}

char peek(){
    if (isEmpty()){
        printf("Nothing to delete.");
        return ' ';
    }
    return front->data;
}

char dequeue(){
    if (isEmpty()){
        printf("Queue underflow!!");
        return ' ';
    }
    struct Node *temp = front;
    char x = temp->data;
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
        printf("%c (%d)\t", temp->data,temp->priority);
        temp = temp->next;
    }
    printf("\n");
}


int main(){
    int choice, val;
    char ch;
    while (1){
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            printf("Enter data & priority to enqueue: ");
            scanf(" %c %d", &ch, &val);
            enqueue(val,ch);
            break;

        case 2:
            val = dequeue();
            if (val != ' ')
                printf("Dequeued element: %c\n", val);
            break;

        case 3:
            val = peek();
            if (val != ' ')
                printf("Front element: %c\n", val);
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

#include <stdio.h>
#include <limits.h>
#define MAX 7
int queue[MAX];
int rear = -1, front = -1;
int isFull(){
    if ((rear+1)%MAX == front)
        return 1;
    return 0;
}
int isEmpty(){
    if (rear == front)
        return 1;
    return 0;
}
void enqueue(int val){
    if (isFull()){
        printf("Queue Overflow!!\n");
        return;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = val;
}
int peek(){
    if (isEmpty())
        return INT_MIN;
    return queue[(front + 1)%MAX];
}
int dequeue(){
    if (isEmpty()){
        printf("Queue Underflow!!\n");
        return INT_MIN;
    }
    front = (front + 1) % MAX;
    return queue[front];
}
void display(){
    if (isEmpty()){
        printf("Nothing to display!!\n");
        return;
    }
    int i = (front + 1) % MAX;
    while (i != (rear + 1) % MAX){
        printf("%3d\t", queue[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}
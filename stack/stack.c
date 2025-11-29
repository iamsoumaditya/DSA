#define MAX 5
#include<stdio.h>
#include<limits.h>
int stack[MAX];
int top = -1;
int isFull(){
    if(top == MAX -1)
        return 1;
    return 0;
}
int isEmpty(){
    if(top == -1)
        return 1;
    return 0;
}
void push(int val){
    if(isFull()){
        printf("Stack overflow!!");
        return;
    }
    top++;
    stack[top] = val;
}
int peek(){
    if(isEmpty())
        return INT_MIN;

    return stack[top];
}
int pop(){
    if(isEmpty())
        return INT_MIN;

    return stack[top--];
}

int main(){
    
    return 0;
}

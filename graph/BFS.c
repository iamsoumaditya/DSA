#define v 6
#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#define MAX 7
int queue[MAX];
int rear = -1, front = -1;

int isFull(){
    if (rear == MAX - 1)
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
    queue[++rear] = val;
}

int dequeue(){
    if (isEmpty()) {
        printf("Queue Underflow!!\n");
        return INT_MIN;
    }
    return queue[++front];
}

void BFS(int adj[v][v],int start){
    int visited[v] = {0};
    visited[start] = 1;
    enqueue(start);
    while(!isEmpty()){
        int val = dequeue();
        printf("%d\t",val);
        for (int i = 0; i < v;i++){
            if(adj[val][i]==1 && !visited[i]){
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main(){
    int adj[v][v] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 1},
        {0, 0, 1, 1, 1, 0}};

    printf("BFS starting from vertex 0:\n");
    BFS(adj, 0);

    return 0;
}
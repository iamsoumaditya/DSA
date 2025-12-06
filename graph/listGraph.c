#include <stdio.h>
#include <stdlib.h>

#define V 5

struct Node{
    int data;
    struct Node *next;
};

struct Node *create(int val){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL){
        printf("Insufficient Memory!!\n");
        return NULL;
    }
    ptr->data = val;
    ptr->next = NULL;
    return ptr;
}

void addEnd(struct Node **head, int val){
    if (*head == NULL){
        *head = create(val);
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = create(val);
}

void printList(struct Node *head){ // can be used to get any vertex adjacents
    while (head != NULL){
        printf("%c -> ", head->data+'A');
        head = head->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node *head[V] = {NULL}; // adjacency list heads

    // Example graph edges
    addEnd(&head[0], 1);
    addEnd(&head[0], 2);
    addEnd(&head[0], 3);
    addEnd(&head[1], 0);
    addEnd(&head[1], 4);
    addEnd(&head[2], 0);
    addEnd(&head[2], 4);
    addEnd(&head[3], 0);
    addEnd(&head[3], 4);
    addEnd(&head[4], 1);
    addEnd(&head[4], 2);
    addEnd(&head[4], 3);

    // Print adjacency list
    for (int i = 0; i < V; i++){
        printf("Adj[%c]: ", i+'A');
        printList(head[i]);
    }
    
    //count degree and edge
    int count = 0;
    for (int i = 0; i < V;i++){
        struct Node *temp = head[i];
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
    }
    printf("Total number of degree is %d",count);
    return 0;
}
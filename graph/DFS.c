#define v 6
#include<stdio.h>

void DFShelper(int adj[v][v],int start,int visited[v]){
    visited[start] = 1;
    printf("%d\t", start);
    for (int i = 0; i < v;i++){
        if(adj[start][i]==1 && !visited[i]){
            DFShelper(adj, i,visited);
        }
    }
}

void DFS(int adj[v][v],int start){
    int visited[v] = {0};
    DFShelper(adj,start,visited);
}

int main(){
    int adj[v][v] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 1},
        {0, 0, 1, 1, 1, 0}};

    printf("\nDFS starting from vertex 0:\n");
    DFS(adj, 0);

    return 0;
}
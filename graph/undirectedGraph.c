#include<stdio.h>
#define v 5
int main(){
    int count = 0;
    // adjacency matrix
    int adj[v][v] = {{0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0}};

    //count total degree
    for (int i = 0; i < v;i++){
        for (int j = 0; j < v;j++){
            if(adj[i][j]==1)
                count++;
        }
    }
    printf("Total degree of this graph is %d\n",count);
    printf("Total edge of this graph is %d\n",count/2);

    //adjacent vertex of any vertex
    int i = 1; //A-> 0, B->1, C->2, D->3, E->4
    for (int j = 0; j < v;j++){
        if(adj[i][j]==1)
            printf("%c - %c\t",'A'+i, 'A' + j);
    }
    return 0;
}
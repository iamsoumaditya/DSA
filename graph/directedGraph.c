#include <stdio.h>
#define v 4
int main(){
    int count = 0;
    // adjacency matrix
    int adj[v][v] = {{0, 1, 0, 1}, {0, 0, 1, 0}, {1, 0, 0, 0}, {0, 0, 1, 0}};

    // count in-degree for particular vertex -> through column
    int j = 2;
    for (int i = 0; i < v; i++){
        if (adj[i][j] == 1)
            count++;
    }
    printf("Total in-degree of this graph is %d\n", count);

    count = 0;
    // count out-degree for particular vertex -> through row
    int i = 2;
    for (int j = 0; j < v; j++){
        if (adj[i][j] == 1)
            count++;
    }
    printf("Total out-degree of this graph is %d\n", count);

    return 0;
}
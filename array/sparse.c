#define MAX 10
#include <stdio.h>

typedef struct{
    int row;
    int col;
    int val;
} compact;

void read(int arr[MAX][MAX], int *n, int *m){
    printf("Enter the elements: ");
    for (int i = 0; i < *m; i++)
        for (int j = 0; j < *n; j++)
            scanf("%d", &arr[i][j]);
}
void print(int arr[MAX][MAX], int *n, int *m){
    printf("The elements are: \n");
    for (int i = 0; i < *m; i++){
        for (int j = 0; j < *n; j++){
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

int isSparse(int arr[MAX][MAX], int *m, int *n){
    int count = 0;
    for (int i = 0; i < *m; i++){
        for (int j = 0; j < *n; j++){
            if (arr[i][j] != 0)
                count++;
        }
    }
    if (count > (*m * *n) / 2)
        return 0;
    return 1;
}
int createCompact(int arr[MAX][MAX], int *m, int *n, compact c[]){
    int k = 1;
    for (int i = 0; i < *m; i++){
        for (int j = 0; j < *n; j++){
            if (arr[i][j] != 0){
                c[k].row = i;
                c[k].col = j;
                c[k++].val = arr[i][j];
            }
        }
    }
    c[0].row = *m, c[0].col = *n, c[0].val = k - 1;
    return k - 1;
}

void createCompactTranspose(compact c[], compact t[]){
    int k = 1;
    for (int i = 0; i < c[0].col; i++){
        for (int j = 1; j <= c[0].val; j++){
            if (i == c[j].col){
                t[k].row = c[j].col;
                t[k].col = c[j].row;
                t[k++].val = c[j].val;
            }
        }
    }
    t[0].row = c[0].col, t[0].col = c[0].row, t[0].val = c[0].val;
}
void compactSum(compact c1[], compact c2[], compact c3[]){
    if (c1[0].row != c2[0].row || c1[0].col != c2[0].col){
        printf("Matrix addition not possible");
        return;
    }
    c3[0] = c1[0];
    int i = 1, j = 1, k = 1;
    while(i<=c1[0].val && j<=c2[0].val){
        if (c1[i].row == c2[j].row && c1[i].col == c2[j].col){
            c3[k].row = c1[i].row;
            c3[k].col = c1[i].col;
            c3[k++].val = c1[i++].val + c2[j++].val;
        }
        else if (c1[i].row < c2[j].row || (c1[i].row == c2[j].row && c1[i].col < c2[j].col)){
            c3[k++] = c1[i++];
        }else{
            c3[k++] = c2[j++];
        }
    }
}

int main(){
    int n, m;
    int arr[MAX][MAX] = {{0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 1, 0},
                         {0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 3},
                         {4, 0, 0, 0, 0, 0},
                         {0, 2, 0, 0, 0, 0}};
    printf("Enter the row size of the array: ");
    scanf("%d", &m);
    printf("Enter the col size of the array: ");
    scanf("%d", &n);
    // read(arr, &n, &m);
    print(arr, &n, &m);
    /*if (isSparse(arr, &m, &n)){
        compact c[MAX];
        int k = createCompact(arr, &m, &n, c);
        for (int i = 0; i <= k; i++){
            printf("Row: %d, Col: %d, Val: %d\n", c[i].row, c[i].col, c[i].val);
        }
        printf("Transpose\n");
        compact t[MAX];
        createCompactTranspose(c, t);
        for (int i = 0; i <= k; i++){
            printf("Col: %d, Row: %d, Val: %d\n", t[i].row, t[i].col, t[i].val);
        }
    }*/
    compact c[MAX];
    compact c1[MAX];
    int k = createCompact(arr, &m, &n, c);
    compactSum(c, c, c1);
    for (int i = 0; i <= k; i++){
        printf("Row: %d, Col: %d, Val: %d\n", c1[i].row, c1[i].col, c1[i].val);
    }
    return 0;
}
#define MAX 100
#include <stdio.h>

void read(int arr[], int *n){
    printf("Enter the elements: ");
    for (int i = 0; i < *n; i++)
        scanf("%d", &arr[i]);
}
void print(int arr[], int *n){
    printf("The elements are: ");
    for (int i = 0; i < *n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}
void insert(int arr[], int *n, int pos, int val){
    if (pos < 0 || pos >= *n){
        printf("Invalid poitions\n");
        return;
    }
    if (*n == MAX - 1) {
        printf("Insertion not possible\n");
    }
    for (int i = *n; i >=pos ;i--){
        arr[i] = arr[i-1];
    }
    arr[pos - 1] = val;
    (*n)++;
}

void delete(int arr[],int *n,int pos){
    if(pos < 0 || pos >=*n){
        printf("Invalid positions\n");
        return;
    }
    for (int i = pos; i < *n;i++){
        arr[i - 1] = arr[i];
    }
    (*n)--;
}

void update(int arr[],int *n,int pos,int val){
    if(pos < 0 || pos >=*n){
        printf("Invalid positions\n");
        return;
    }
    arr[pos] = val;
}
void reverse(int arr[],int *n){
    for (int i = 0; i < (*n)/2;i++){
        int temp = arr[i];
        arr[i] = arr[*n - i - 1];
        arr[*n - i - 1] = temp;
    }
}

int main(){
    int arr[MAX], n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    read(arr, &n);
    insert(arr, &n, 3, 2);
    print(arr, &n);
    delete(arr, &n, 3);
    print(arr, &n);
    update(arr, &n, 4, 6);
    print(arr, &n);
    reverse(arr, &n);
    print(arr, &n);
    return 0;
}
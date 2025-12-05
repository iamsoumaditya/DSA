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

int linearSearch(int arr[],int n,int key){
    for (int i = 0; i < n;i++)
    if(arr[i]==key)
        return i+1;
    return -1;
}

int main(){
    int n,key;
    printf("Enter the size of an array: ");
    scanf("%d", &n);
    int arr[n];
    read(arr, &n);
    printf("The array is:\n");
    print(arr, &n);
    printf("Enter the element to search: ");
    scanf("%d", &key);
    int res =linearSearch(arr, n, key);
    res == -1 ? printf("Element not found!!") : printf("Element found at index %d",res);
    return 0;
}

/*
----------Time complexity--------

Best case :- O(1)
average case :- O(n)
worst case :- O(n)

----------Space complexity--------

iterative = O(1)
recursive = O(n) call stack depth

*/
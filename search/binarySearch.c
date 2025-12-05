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

int binarySearch(int arr[], int low, int high,int key){
    if(low > high)
        return -1;
    int mid = low + (high-low) / 2;
    if (arr[mid] == key)
        return mid + 1;
    else if(arr[mid] > key)
        return binarySearch(arr, low, mid, key);
    else
        return binarySearch(arr, mid + 1, high, key);
}

int main(){
    int n, key;
    printf("Enter the size of an array: ");
    scanf("%d", &n);
    int arr[n];
    read(arr, &n);
    printf("The array is:\n");
    print(arr, &n);
    printf("Enter the element to search: ");
    scanf("%d", &key);
    int res = binarySearch(arr, 0,n-1,key);
    res == -1 ? printf("Element not found!!") : printf("Element found at index %d", res);
    return 0;
}

/*
----------Time complexity--------

Best case :- O(1)
average case :- O(logn)
worst case :- O(logn)

----------Space complexity--------

iterative = O(1)
recursive = O(n) call stack depth

*/
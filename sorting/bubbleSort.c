#include<stdio.h>

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

void bubble_sort(int arr[], int n){ // T -> O(n^2)  S-> O(1)
    for (int i = 0; i < n-1;i++){ // bubble sort require n-1 passes last element is always sorted
        for (int j = 0; j < n - i - 1; j++){
            if(arr[j+1] < arr[j]){
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    int n;
    printf("Enter the size of an array: ");
    scanf("%d",&n);
    int arr[n];
    read(arr, &n);
    printf("The array is:\n");
    print(arr, &n);
    bubble_sort(arr, n);
    printf("The Sorted array is:\n");
    print(arr, &n);
    return 0;
}

/*
----------Time complexity--------

Best case :- O(n^2)
average case :- O(n^2)
worst case :- O(n^2)


but there is an optimized bubble sort in which best case tc is o(n)

how??

ans:- after one pass lets say i = 0 
    if no element swaps
    that means array is sorted
    so they break the loop
    means only n-1 comparison

*/
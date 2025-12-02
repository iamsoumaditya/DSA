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

void insertion_sort(int arr[], int n){ // T -> O(n^2)  S-> O(1) for best case o(n) as the inner loop doesnot run
    for (int i = 1; i < n; i++){
        int curr = arr[i];
        int prev = i - 1;
        while (prev >= 0 && curr < arr[prev]){
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}

int main(){
    int n;
    printf("Enter the size of an array: ");
    scanf("%d", &n);
    int arr[n];
    read(arr, &n);
    printf("The array is:\n");
    print(arr, &n);
    insertion_sort(arr, n);
    printf("The Sorted array is:\n");
    print(arr, &n);
    return 0;
}
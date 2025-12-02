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

void selection_sort(int arr[], int n){ // T -> O(n^2)  S-> O(1) //for all cases
    for (int i = 0; i < n - 1; i++){
        int minIdx = i;
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        if(i != minIdx){
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

int main()
{
    int n;
    printf("Enter the size of an array: ");
    scanf("%d", &n);
    int arr[n];
    read(arr, &n);
    printf("The array is:\n");
    print(arr, &n);
    selection_sort(arr, n);
    printf("The Sorted array is:\n");
    print(arr, &n);
    return 0;
}
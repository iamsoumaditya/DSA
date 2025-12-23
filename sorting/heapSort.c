#include <stdio.h>

void read(int arr[], int *n){
    printf("Enter the elements: ");
    for (int i = 1; i <= *n; i++)
        scanf("%d", &arr[i]);
}

void print(int arr[], int *n){
    printf("The elements are: ");
    for (int i = 1; i <= *n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

void makeHeap(int arr[],int n){ //O(n)
    for (int i = n / 2; i >= 1;i--)
        heapAdjust(arr, i, n); // runs n/2 times though complexity O(logn) but in many best cases complexity O(1)
}

void heapAdjust(int arr[],int i,int n){ // O(logn) worst case best case O(1)
    int key = arr[i];
    int j = 2 * i;
    while(j<=n){
        if (j < n &&arr[j] < arr[j + 1])
            j = j + 1;
        if(key > arr[j])
            break;
        arr[j / 2] = arr[j];
        j *= 2;
    }
    arr[j / 2] = key;
}

void heap_sort(int arr[], int n){ //O(nlogn) space O(1)
    makeHeap(arr,n); //O(n)
    for (int i = n; i >= 2;i--){
        arr[1] = arr[1] ^ arr[i];
        arr[i] = arr[1] ^ arr[i];
        arr[1] = arr[1] ^ arr[i];
        heapAdjust(arr, 1, i - 1); //O(logn) worst case runs n times = O(nlogn)
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
    heap_sort(arr, n);
    printf("The Sorted array is:\n");
    print(arr, &n);
    return 0;
}

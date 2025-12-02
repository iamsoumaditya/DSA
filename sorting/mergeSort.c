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

void merge(int arr[],int low, int mid, int high){
    int i = low;
    int j = mid+1;
    int k = low;
    int arr1[high-low + 1];
    while (i <= mid && j <= high){
        if(arr[i] <= arr[j])
            arr1[k++] = arr[i++];
        else
            arr1[k++] = arr[j++];
    }
    while (i <= mid)
        arr1[k++] = arr[i++];
    while (j <= high)
        arr1[k++] = arr[j++];
    for (int i = low; i <= high; i++)
        arr[i] = arr1[i];
}

void merge_sort(int arr[], int low, int high){ // T -> O(nlogn)  S-> O(n) for all cases
    if(low < high){ //no. of elements >= 2
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
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
    merge_sort(arr,0, n-1);
    printf("The Sorted array is:\n");
    print(arr, &n);
    return 0;
}
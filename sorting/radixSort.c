#include <stdio.h>
#include <limits.h>

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

int getMax(int arr[], int n){
    int max = INT_MIN;
    for (int i = 0; i < n;i++)
        max = (arr[i] > max) ? arr[i] : max;
    return max;
}

void countingSort (int arr[],int n,int pow10){
    int count[10]={0}, output[n];
    for (int i = 0; i < n;i++){
        int digit = (arr[i] / pow10) % 10;
        count[digit]++;
    }
    for (int i = 1; i < 10;i++)
        count[i] = count[i - 1] + count[i];
    for (int i = n - 1; i >= 0;i--){
        int digit = (arr[i] / pow10) % 10;
        int index = count[digit] - 1;
        count[digit] --;
        output[index] = arr[i];
    }
    for (int i = 0; i < n;i++)
        arr[i] = output[i];
}

void radix_sort(int arr[], int n){ //T ==> O(k*n) k = no. of digits in max  S ==> O(n+k)
    int max = getMax(arr,n);
    int pow10 = 1;
    while(max != 0){
        countingSort(arr,n,pow10);
        pow10 *= 10;
        max /= 10;
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
    radix_sort(arr, n);
    printf("The Sorted array is:\n");
    print(arr, &n);
    return 0;
}
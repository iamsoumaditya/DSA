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

// int interpolationSearch(int arr[], int low, int high, int key){
//     while(low<=high && key>=arr[low] && key <= arr[high]){
//         int pos = low + (double){(high - low) / (arr[high] - arr[low])} * (key - arr[low]);
//         if(key == arr[pos])
//             return pos+1;
//         else if(key < arr[pos])
//             high = pos - 1;
//         else
//             low = pos + 1;
//     }
//     return -1;
// }

int interpolationSearch(int arr[], int low, int high, int key){
    if (low > high || key < arr[low] || key > arr[high])
        return -1;

    int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]);
    if (key == arr[pos])
        return pos + 1;
    else if (key < arr[pos])
        high = pos - 1;
    else
        low = pos + 1;
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
    int res = interpolationSearch(arr, 0, n - 1, key);
    res == -1 ? printf("Element not found!!") : printf("Element found at index %d", res);
    return 0;
}

/*
----------Time complexity--------

Best case :- O(1)
average case :- O(loglogn) data uniformly distributed
worst case :- O(n) values are clustered

----------Space complexity--------

iterative = O(1)
recursive = O(logn) call stack depth

*/
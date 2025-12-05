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

int ternarySearch(int arr[], int low, int high, int key){
    if (low > high)
        return -1;
    int mid1 = low + (high - low) / 3;
    int mid2 = high - (high - low) / 3;
    if (arr[mid1] == key)
        return mid1 + 1;
    if (arr[mid2] == key)
        return mid2 + 1;
    if (arr[mid1] > key)
        return ternarySearch(arr, low, mid1 - 1, key);
    else if (arr[mid2] > key)
        return ternarySearch(arr, mid1 + 1, mid2, key);
    else
        return ternarySearch(arr, mid2 + 1, high, key);
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
    int res = ternarySearch(arr, 0, n - 1, key);
    res == -1 ? printf("Element not found!!") : printf("Element found at index %d", res);
    return 0;
}
/*
----------Time complexity--------

Best case :- O(1)
average case :- O(log3n)
worst case :- O(log3n)
-Although log3n looks smaller than log2n, ternary search does more comparisons per step (two midpoints instead of one). In practice, binary search is usually faster.


----------Space complexity--------

iterative = O(1)
recursive = O(log3n) call stack depth log base 3 n

*/
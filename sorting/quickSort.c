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

void swap(int arr[],int i,int j){
    if (i == j)
        return;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
/*
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++){
        if (arr[j] < pivot){
            i += 1;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return i + 1;
}
*/
int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low;
    for (int j = low + 1; j <= high; j++){
        if (arr[j] < pivot){
            i += 1;
            swap(arr, i, j);
        }
    }
    swap(arr, i, low); // for pivot from low if we did i + 1 here then after swapping one big element comes at first. As we choose pivot from left so in the left side only small elements are allowed after partition. so we swap with i. [50(pivot),30,10,20(i),80,70,60] if swap with i+ 1 ==> [80,30,10,20(i),50(pivot),70,60] that's gonna wrong. so with i ==> [20(i),30,10,50(pivot),80,70,60]
    return i;
}

void quick_sort(int arr[], int low, int high){ // T -> O(nlogn)  S-> O(1) for best and avg for worst sorted array o(n^2)
    if (low < high){ // no. of elements >= 2
        int j = partition(arr, low, high);
        quick_sort(arr, low, j-1);
        quick_sort(arr, j+1, high);
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
    quick_sort(arr, 0, n - 1);
    printf("The Sorted array is:\n");
    print(arr, &n);
    return 0;
}

/*
------------Time complexity-------------
for sorted array if we took last element as pivot
then after partitioning it is placed at last and there's no right array
only left array of size n-1 and this continues

so tc becomes (n-1) + (n-2) + (n-3) +...........+ 3 + 2 + 1
{n(n+1)}/2 tc is O(n^2)

------------Space complexity-------------


and as there no extra temp array or something like that
but it uses recursion stack

recursion stack height for best case and average case is logn in each case divided / 2 so O(logn)
but for worst case recusrion stack height is n so O(n)

*/
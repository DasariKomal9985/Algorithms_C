/* 


Binary Search is a fast searching algorithm used on sorted arrays.
It repeatedly divides the search space into half until the element is found.



This is one of the most important algorithms in DSA.


How it works (logic)


Take two pointers:

low = 0

high = n - 1

Find the middle index:

mid = (low + high) / 2

Compare:


                                                If arr[mid] == key → found.

                                                If arr[mid] < key → search in right half
                                                (low = mid + 1)

                                                If arr[mid] > key → search in left half
                                                (high = mid - 1)



Repeat steps 2–3 until low > high.



Complexity

Time: O(log n)



Space:

Iterative → O(1)

Recursive → O(log n)


*/

    

#include <stdio.h>
void sort(int arr[], int size) {
    printf("Given array:\n");
    printf("=================================================================================\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("=================================================================================\n");
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Sorted array:\n");
    printf("=================================================================================\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("=================================================================================\n");
    
}
int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1; 
        }
        else {
            right = mid - 1; 
        }
    }

    return -1; 
}
int main()
{
    int size, target, result;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d sorted elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target element to search: ");
    scanf("%d", &target);
    sort(arr, size); 
    result = binary_search(arr, size, target);
    if (result != -1) {
    printf("=================================================================================\n");
        printf("Element found at index: %d\n", result);
    printf("=================================================================================\n");
    } else {
    printf("=================================================================================\n");
        printf("Element not found in the array.\n");
    printf("=================================================================================\n");
    }
    return 0;
}
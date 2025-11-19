/*



How it works (logic)

Divide array into 2 halves recursively.

Sort left half.

Sort right half.

Merge the two sorted halves into one sorted array.




Complexity

Time: O(n log n)

Space: O(n)


*/



#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted halves
void merge(int arr[], int lower, int mid, int upper)
{
    int i = lower;      // Start of left half
    int j = mid + 1;    // Start of right half
    int k = 0;          // Index for temp array

    int size = upper - lower + 1;
    int temp[size];     // Temporary array

    // Merge elements into temp[] in sorted order
    while (i <= mid && j <= upper)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements from left half
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements from right half
    while (j <= upper)
    {
        temp[k++] = arr[j++];
    }

    // Copy sorted result back into original array
    for (int x = 0; x < size; x++)
    {
        arr[lower + x] = temp[x];
    }
}

// Recursive Merge Sort
void mergeSort(int arr[], int lower, int upper)
{
    if (lower < upper)
    {
        int mid = (lower + upper) / 2;

        // Sort left half
        mergeSort(arr, lower, mid);

        // Sort right half
        mergeSort(arr, mid + 1, upper);

        // Merge both halves
        merge(arr, lower, mid, upper);
    }
}

int main()
{
    int size;
    printf("Enter number of elements: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Call MergeSort with full range
    mergeSort(arr, 0, size - 1);

    // Print sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

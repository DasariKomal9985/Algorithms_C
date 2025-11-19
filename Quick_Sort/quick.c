/*


How it works (logic)

Choose pivot (e.g., last element).

Partition:

All elements < pivot → left

All elements > pivot → right

Recursively sort left and right partitions.





Complexity

Average: O(n log n)

Worst: O(n²) (if pivot chosen badly)

Space: O(log n)



*/
#include <stdio.h>
#include <stdlib.h>

// QuickSort function using Lomuto Partition Scheme
void quickSort(int arr[], int Low, int high)
{
    // Base condition: sort only if sub-array has 2 or more elements
    if (Low < high)
    {
        // Choose last element as pivot
        int pivot = arr[high];

        // i marks the position for elements smaller than pivot
        int i = (Low - 1);

        // Partition the array around pivot
        for (int j = Low; j <= high - 1; j++)
        {
            // If element is smaller than pivot → move it to the left partition
            if (arr[j] < pivot)
            {
                i++;   // expand the "small elements" region

                // Swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // Place the pivot in its correct sorted position
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        // pi = pivot index
        int pi = i + 1;

        // Recursively sort left and right partitions
        quickSort(arr, Low, pi - 1);   // left part
        quickSort(arr, pi + 1, high);  // right part
    }

    return;
}

int main()
{
    int size, Low = 0, high;

    // Input array size
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];

    // Input array elements
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // high is last index
    high = size - 1;

    // Call quicksort
    quickSort(arr, Low, high);

    // Print sorted array
    printf("Sorted array: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

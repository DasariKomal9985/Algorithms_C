/*

How it works (logic)

Build a max heap from the array.

Swap the first element (largest) with last.

Reduce heap size and heapify.

Repeat until array sorted.



Complexity

Time: O(n log n)

Space: O(1)

*/

#include <stdio.h>

// Function to heapify a subtree rooted at index 'i'
// 'n' is the size of the heap
void heapify(int arr[], int n, int i)
{
    int largest = i;          // Assume root is largest
    int left = 2 * i + 1;     // Left child
    int right = 2 * i + 2;    // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root, swap and continue heapifying
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Main Heap Sort Function
void heapSort(int arr[], int n)
{
    // Step 1: Build max heap
    // Start from last non-leaf node → (n/2 - 1)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Step 2: Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root (max value) to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapify the reduced heap
        heapify(arr, i, 0);
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    heapSort(arr, n);

    printf("Sorted array using Heap Sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}

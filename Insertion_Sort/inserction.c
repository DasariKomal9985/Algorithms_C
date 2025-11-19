/*


How it works (logic)

Start from index 1 → key.

Compare key with left side elements.

Shift bigger elements to the right.

Insert key in correct position.





    for (i = 1; i < size; i++)   
{
    // Take the current element as "key"
    key = arr[i];

    // j points to the previous element
    j = i - 1;

    // Shift all elements greater than key to the right
    while (j >= 0 && arr[j] > key)
    {
        arr[j + 1] = arr[j];   // Shift element to next position
        j = j - 1;             // Move backward in the array
    }

    // Insert the key at its correct sorted position
    arr[j + 1] = key;
}





Complexity

Time: O(n²)

Space: O(1)


 */

#include<stdio.h>
void InserctionSort(int arr[], int size)
{
    int i, j, key;
    printf("Given array:\n");
    printf("=================================================================================\n");
    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("=================================================================================\n");
    for(i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    printf("Sorted array:\n");
    printf("=================================================================================\n");
    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("=================================================================================\n");
}


int main()
{
    int size , i;
    printf("Enter number of elements: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements:\n", size);
    for(i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    InserctionSort(arr, size);
    return 0;
}
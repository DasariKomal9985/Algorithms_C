/* 

A simple comparison-based algorithm. It repeatedly compares adjacent elements and swaps them if they are in the wrong order.

How it works (logic)

Compare arr[i] and arr[i+1].

If left > right → swap.

After each full pass, the largest element “bubbles” to the end.

Repeat until no swaps happen.

Complexity

Time: O(n²)

Space: O(1)


*/




#include <stdio.h>
#include <stdlib.h>
void Ascending_Bubble_Sort(int arr[], int size)
{
    int flag = 0;
    int cycle = 0;
    printf("Given array:\n");
    printf("=================================================================================\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("=================================================================================\n");
    for (int i = 0; i < size - 1; i++)
    {
        flag = 0;
        cycle++;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    printf("Sorted array in Ascending order:\n");
    printf("=================================================================================\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    printf("Number of cycles: %d\n", cycle);
    printf("=================================================================================\n");
}


void Descending_Bubble_Sort(int arr[], int size)
{
    int flag = 0;
    int cycle = 0;
    printf("Given array:\n");
    printf("=================================================================================\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("=================================================================================\n");
    for (int i = 0; i < size - 1; i++)
    {
        flag = 0;
        cycle++;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    printf("Sorted array in Descending order:\n");
    printf("=================================================================================\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    printf("Number of cycles: %d\n", cycle);
    printf("=================================================================================\n");
}


int main()
{
    int size, choise;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter Choise\n\n 1.)Ascending\n 2.)Descending\n 3.)Exit:\n ");
    scanf("%d", &choise);
    switch (choise)
    {
    case 1:
        Ascending_Bubble_Sort(arr, size);
        break;
    case 2:
        Descending_Bubble_Sort(arr, size);
        break;
    case 3:
        exit(0);
        break;
    default:
        printf("Invalid Choise\n");
        break;
    }
}
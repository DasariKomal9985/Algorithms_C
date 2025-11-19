/*
How it works (logic)

For each index i:

Find the smallest element from i to end.

Swap it with arr[i].

Complexity

Time: O(n²)

Space: O(1)
*/


#include<stdio.h>

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void SelectionSort(int arr[], int size)
{
    for(int i=0;i<size-1;i++)
    {
        int min = i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[min])
            {
                min = j;
            }
        }
      if(min != i)
      {
          Swap(&arr[i],&arr[min]);
      }
    }
    printf("\nAfter sorting array:\n ");
    printf("=================================================================================\n");
    for(int i=0;i<size;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n=================================================================================\n");
}
int main()
{
    int size;
    printf("Enter size of array\n: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter elements of array\n:\n ");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Before sorting array:\n ");
    printf("=================================================================================\n");
    for(int i=0;i<size;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n=================================================================================\n");
    SelectionSort(arr,size);
    return 0;
}
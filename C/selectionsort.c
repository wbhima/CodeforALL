// C program for implementation of selection sort
#include <stdio.h>
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
           if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

#include <stdio.h>
int smallest (int arr[] ,int k, intn);
void selection_sort (int arr[] , int n);
int main ()
{
  int arr [10] , i , n;
  printf ("\n Enter the elemets in the array: ");
  scanf ("%d" ,&n);
  printf ("\n Enter the elements of the array : ");
  for (i = 0;i <n;i++)
  {
   scanf ("%d" , &arr[i]);
  }
 selection_sort (arr ,n);
 printf("\n The sorted array is: \n");
 for (i = 0 ;i<n;i++)
  printf ("%d\t" ,arr[i] );
  }
int smallest (int arr[], int k, int n
{ 
  int pos = k, small = arr [k] , i ;
  for (i = k+1;i < n;i++)
  {
    if arr[i] < small)
    {
     small = arr [i];
     pos = i;
     }
    }
    return pos;
   }
 void selection_sort (int arr[] ,int n );            
              {
                int k , pos, temp;
                for (k = 0;k < n;k++)
                {
                 pos = (smallest arr ,k, n);
                 temp = arr[k] ;
                 arr[k] = arr [pos];
                 arr [pos] = temp;
                }
              }

 

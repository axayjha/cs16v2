/* Day 7
 * Question 1
 * Write a program to implement heapsort algo.
 *
 * Author - 
 * Akshay Anand
 * CSE 3nd Sem - St. Thomas' College of Engineering & Technology
 */

#include <stdio.h>

void maxHeapify(int arr[], int n, int i);
void buildMaxHeap(int *arr, int n);
void heapSort(int arr[], int n);
void exchange(int *a, int *b);
void printArray(int arr[], int n);
int LEFT(int i);
int RIGHT(int i);


int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    heapSort(arr, n);
 
    printf("Sorted array is \n");
    printArray(arr, n);
}

void exchange(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
int LEFT(int i)
{
    return 2*i + 1;
} 

int RIGHT(int i)
{
    return 2*i + 2;
}

void maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int l = LEFT(i);  
    int r = RIGHT(i); 

    if (l < n && arr[l] > arr[largest])
        largest = l;
 
   
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    
    if (largest != i)
    {
        exchange(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}
 
void heapSort(int arr[], int n)
{
    
    buildMaxHeap(arr, n);

    for (int i=n-1; i>=0; i--) 
    {        
        exchange(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void buildMaxHeap(int *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}
 
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}


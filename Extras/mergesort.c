/*
 *  Implementation of merge sort algorithm 
 *  github.com/AxayJha                    
 *
 */

#include <stdio.h>
 
void mergesort(int *arr, int low, int high);
void merge(int *arr, int l, int m, int h);

int main()
{
	int n, i;

	printf("Enter the size of array: "); 
	scanf("%d", &n);
	int arr[n];

	printf("Enter the elements: ");
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);

	mergesort(arr, 0, n-1);  

	printf("Sorted array: "); 
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	

	return 0;
}

void mergesort(int *arr, int low, int high)
{
	int mid;
	if(low < high) 
	{
		mid = (low + high)/2;
		mergesort(arr, low, mid);
		mergesort(arr, mid+1, high);
		merge(arr, low, mid, high);
	}

}

void merge(int *arr, int low, int mid, int high)
{
	int lefthalf[10], righthalf[10]; 
	int n1, n2, i, j, k;
	n1 = mid - low + 1;
	n2 = high - mid;

	for(i = 0; i < n1; i++)
		lefthalf[i] = arr[low + i];
	for(j = 0; j < n2; j++)
		righthalf[j] = arr[mid + j + 1];

	lefthalf[i] = 9999; 
	righthalf[j] = 9999;

	i=0;
	j=0;
	for(k = low; k <= high; k++) 
	{ 
		if(lefthalf[i] <= righthalf[j])
	  		arr[k] = lefthalf[i++];
		else
	  		arr[k] = righthalf[j++];
	}	

}
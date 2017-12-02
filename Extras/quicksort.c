/*
 *  Implementation of randomized quicksort algorithm 
 *  github.com/AxayJha                    
 *
 */

#include <stdio.h>
#define SIZE(array) sizeof(array)/sizeof(array[0])

void rand_quicksort(int a[], int n));
int partition(int *A, int p, int r);
void swap(int *a, int *b);


int main()
{
   int n;
   printf("Enter the length of the array: ");
   scanf("%d", &n);

   int a[n];
   printf("Enter the elements of the array: ");
   for(int i=0; i<n; i++)
      scanf("%d", &a[i]);

   rand_quicksort(a, SIZE(a));

   for(int i=0; i<n; i++)
      printf("%d ", a[i]);
   printf("\n");


}

void rand_quicksort(int a[], int n)
{
	int last=0;
	if(n<=1) return;

	swap(&a[0], &a[rand()%n]);
	for(int i=0; i<n; i++)
		if(a[i] < a[0])
			swap(&a[++last], &a[i]);
	swap(&a[0], &a[last]);

	rand_quicksort(a, last);
	rand_quicksort(a+last+1, n-last-1);
}

void swap(int *a, int *b)
{
   int t = *a;
   *a = *b;
   *b = t;
}

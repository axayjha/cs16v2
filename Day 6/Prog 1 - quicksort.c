/* Day 6
 * Question 1
 * Write a program to implement quicksort algo
 *
 * Author - 
 * Akshay Anand
 * CSE 3nd Sem - St. Thomas' College of Engineering & Technology
 */


#include <stdio.h>

void quicksort(int *A, int p, int r);
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

   quicksort(a, 0, n-1);

   for(int i=0; i<n; i++)
      printf("%d ", a[i]);
   printf("\n");


}

void quicksort(int *A, int p, int r)
{
   if( p < r )
   {
      int q = partition(A, p, r);
      quicksort(A, p, q-1);
      quicksort(A, q+1, r);
   }
}

int partition(int *A, int p, int r)
{
   int x = A[r];
   int i = p-1;
   for(int j=p; j <= r-1; j++)
   {
      if( A[j] <= x )
      {
         i++;
         swap(&A[i], &A[j]);
      }
   }
   swap(&A[i+1], &A[r]);
   return (i+1);
}

void swap(int *a, int *b)
{
   int t = *a;
   *a = *b;
   *b = t;
}

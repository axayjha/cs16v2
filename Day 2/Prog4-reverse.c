/* Day 2
 * Question 4
 * Write a program to reverse a given array
 *
 * Author - 
 * Akshay Anand
 * CSE 3nd Sem - St. Thomas' College of Engineering & Technology
 */

#include <stdio.h>

int main()
{
	int n;
	printf("Enter the length of the array: ");
	scanf("%d", &n);
	int a[n];

	printf("Enter the elements of the array: \n");
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for(int i = 0, j = 0; i < n; i++)
	{
		j = n-i-1;
		if(i >= j) break;
		int temp = a[i];
		a[i]     = a[j];
		a[j]     = temp;
	}

	printf("Reversed array: ");
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");


}

/*OUTPUT

Enter the length of the array: 6
Enter the elements of the array: 
6 2 32 1 7 3
Reversed array: 3 7 1 32 2 6

*/
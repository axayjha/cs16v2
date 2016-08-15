/* Day 2
 * Question 3
 * WAP to print the frequencies of all elements in a given array
 *
 * Author - 
 * Akshay Anand
 * CSE 3nd Sem - St. Thomas' College of Engineering & Technology
 */

#include <stdio.h>

int main()
{
	int p, q, i, j, k;
	printf("Enter the row and column of the array\n");
	scanf("%d %d", &p, &q);

	int a[p][q];
	int b[p*q];
	

	printf("Enter the elements of the array: ");
	for(i = 0; i < p; i++)
		for( j = 0; j < q; j++)
			scanf("%d", &a[i][j]);

	for(k=0, i = 0; i < p; i++)
		for( j = 0; j < q; j++, k++)
			b[k] = a[i][j];


	int freq=0;
	for(i = 0; i < k; i++)
	{
		if(b[i]<0) continue;

		freq = 0;
		for(j = 0; j < k; j++)
		{
			if(b[i] == b[j])
			{
				freq++;
				if(i != j) b[j] = -98917 + i;
			}
		}
		printf("Frequency of %d = %d\n", b[i], freq);
	}

}

/* OUTPUT

Enter the row and column of the array
2 3
Enter the elements of the array: 1 2 3 1 1 5
Frequency of 1 = 3
Frequency of 2 = 1
Frequency of 3 = 1
Frequency of 5 = 1

*/
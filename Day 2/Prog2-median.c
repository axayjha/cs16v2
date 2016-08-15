/* Day 2
* Question 2
* WAP to calculate the median of the given 2D array
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

	if(p*q % 2 == 0) 
	{
		printf("Median not possible.\n");
		return 0;
	}

	int a[p][q];
	int b[p*q];
	

	printf("Enter the elements of the array: ");
	for(i = 0; i < p; i++)
		for( j = 0; j < q; j++)
			scanf("%d", &a[i][j]);

	for(k=0, i = 0; i < p; i++)
		for( j = 0; j < q; j++, k++)
			b[k] = a[i][j];

	for(i=0; i<k; i++)
	{
		for(j=0; j<k-i; j++)
		{
			if(b[j]>b[j+1])
			{
				int temp = b[j];
				b[j] = b[j+1];
				b[j+1] = temp;
			}
		}
	}

	printf("Median of the provided array: %d\n", b[((k-1)/2)]);

	return 0;

}

/*OUTPUT

Enter the row and column of the array
3 5
Enter the elements of the array: 1 2 3 4 5 10 9 8 7 6 14 12 13 11 15
Median of the provided array: 8


*/
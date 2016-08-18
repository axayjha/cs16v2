/* Day 1
 * Question 2
 * Write a program to sort an array using bubble sort
 *
 * Author - 
 * Akshay Anand
 * CSE 3rd Sem - St. Thomas' College of Engineering & Technology
 */

 #include <stdio.h>

 int main()
{
	int length, i, j, temp;

	printf("Enter the length of the array: ");
	scanf("%d", &length);

	int array[length];

	printf("Enter the elements of the array: \n");
	for(i=0; i<length; i++) scanf(" %d", &array[i]);

	for(i=0; i<length; i++)
	{
		for(j=0; j<length-1; j++)
		{
			if(array[j] > array[j+1])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}

	}	

	printf("Sorted array: \n");
	for(i=0; i<length; i++) printf("%d ", array[i]);
	printf("\n");

}

/* Output

Enter the length of the array: 6
Enter the elements of the array: 
3
4
2
6
1
5
Sorted array: 
1 2 3 4 5 6 

*/
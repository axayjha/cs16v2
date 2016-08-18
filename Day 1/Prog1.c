/* Day 1
 * Question 1
 * Write a program to search any element in an array using linear search
 *
 * Author - 
 * Akshay Anand
 * CSE 3rd Sem - St. Thomas' College of Engineering & Technology
 */

#include <stdio.h>
#include <stdlib.h>

 int main()
 {
 	int length, i, number;

 	printf("Enter the length of the array: ");
 	scanf("%d", &length);

 	int array[length];

 	printf("Enter the %d elements of the array: \n", length);
 	for(i=0; i<length; i++) scanf(" %d", &array[i]);

 	printf("Enter the number to search: ");
 	scanf("%d", &number);

 	for(i=0; i<length; i++)
 	{
 		if (array[i] == number)
 		{
 			printf("Found at position %d \n", i+1);
 			exit(0);
 		}
 	}	

 	printf("Not found\n");

 	

 }

 /* Output

Enter the length of the array: 6
Enter the 6 elements of the array: 
1
2
3
4
5
65
Enter the number to search: 3
Found at position 3 

*/
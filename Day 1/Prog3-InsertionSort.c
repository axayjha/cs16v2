/* Day 1
 * Question 3
 * Write a program to sort an array using insertion sort
 *
 * Author - 
 * Akshay Anand
 * CSE 3rd Sem - St. Thomas' College of Engineering & Technology
 */

 #include <stdio.h>

 int main()
 {
	int length, i, j, key;

	printf("Enter the length of the array: ");
	scanf("%d", &length);

	int array[length];

	printf("Enter the elements of the array: \n");
	for(i=0; i<length; i++) scanf(" %d", &array[i]);

	for(i=1; i<length; i++)	
	{
		key = array[i];
		j= i;
		while(j-- >= 0 && array[j] > key) array[j+1] = array[j];
		array[j+1] = key;
	}
	printf("Sorted array: \n");
	for(i=0; i<length; i++) printf("%d ", array[i]);
	printf("\n");
}

/* Output

Enter the length of the array: 6
Enter the elements of the array: 
6
4
3
2
5
1
Sorted array: 
1 2 3 4 5 6 

*/

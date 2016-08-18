/* Day 1
 * Question 4
 * Write a program to sort an array using selection sort
 *
 * Author - 
 * Akshay Anand
 * CSE 3rd Sem - St. Thomas' College of Engineering & Technology
 */

 #include <stdio.h>

 int main()
 {
	int length, i, j, key, position, temp;

	printf("Enter the length of the array: ");
	scanf("%d", &length);

	int array[length];

	printf("Enter the elements of the array: \n");
	for(i=0; i<length; i++) scanf(" %d", &array[i]);

	for(i=0; i< (length-1); i++)	
	{
		position = i;
		key = array[i];
		j=i+1;

		while(j<length)
		{
			if(array[j] < key)
			{
				key = array[j];
				position = j;
			}
			j++;
		}

		if(i != position)
		{
			temp = array[position];
			array[position] = array[i];
			array[i] = temp;
		}
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
5
2
7
Sorted array: 
2 3 4 5 6 7 

*/



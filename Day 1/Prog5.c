/* Day 1
 * Question 5
 * Write a program to find a number in an array using binary search
 *
 * Author - 
 * Akshay Anand
 * CSE 3rd Sem - St. Thomas' College of Engineering & Technology
 */

 #include <stdio.h>
 
int main()
{
   int i, first, last, mid, length, number;
 
   printf("Enter the length of the array: ");
   scanf("%d", &length);
   
   int array[length];
 
   printf("Enter %d elements of the array in ascending order: \n", length);
 
   for (i = 0; i < length; i++) scanf("%d", &array[i]);
 
   printf("Enter number to find: ");
   scanf("%d", &number);
 
   first = 0;
   last = length - 1;
   
 
   while (first <= last) 
   {
   	  mid = (first+last)/2;

      if (array[mid] < number) first = mid + 1;    

      else if (array[mid] == number) 
      {
         printf("Found at location %d.\n", mid+1);
         break;
      }

      else last = mid - 1;
   }

   if (first > last)  printf("Not found\n");
  
}

/* Output

Enter the length of the array: 6
Enter 6 elements of the array in ascending order: 
1
2
3
4
5
6
Enter number to find: 3
Found at location 3.

*/

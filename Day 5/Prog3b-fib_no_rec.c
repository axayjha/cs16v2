/* Day 5
 * Question 3b
 * Write a program to find the fibonacci series without using recursion
 *
 * Author - 
 * Akshay Anand
 * CSE 3nd Sem - St. Thomas' College of Engineering & Technology
 */

#include <stdio.h>

 int main()
 {
 	int i, n=8;
 	int ar[n];
 	ar[0] = 0; ar[1]=1;
 	for(i=2; i<n; i++) ar[i] = ar[i-1] + ar[i-2];
 	for(i=0; i<n; i++) printf("%d ", ar[i]);
 	printf("\n");	
 }

/*OUTPUT

0 1 1 2 3 5 8 13 

*/
/* Day 5
 * Question 3a
 * Write a program to find the fibonacci series using recursion
 *
 * Author - 
 * Akshay Anand
 * CSE 3nd Sem - St. Thomas' College of Engineering & Technology
 */

 #include <stdio.h>

 int fib(int n)
 {
 	if(n<=2) return n-1;
 	else return fib(n-1) + fib(n-2);
 }

 int main()
 {
 	for(int i=1; i<=8; i++)
 	{
 		printf("%d ", fib(i)); 		
 	}
 	printf("\n");
 }

 /* OUTPUT

 0 1 1 2 3 5 8 13 

 */
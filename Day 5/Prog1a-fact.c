/* Day 5
 * Question 1a
 * Write a program to calculate factorial of a number using recursion
 *
 * Author - 
 * Akshay Anand
 * CSE 3nd Sem - St. Thomas' College of Engineering & Technology
 */

 #include <stdio.h>

 int fact(int n)
 {
 	if(n==1) return 1;
 	else return n*fact(n-1);
 }

 int main()
 {
 	printf("fact(5) = %d\n", fact(5));

 }

 /*OUTPUT

 fact(5) = 120

 */
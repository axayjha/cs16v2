/* Day 5
 * Question 1b
 * Write a program to calculate factorial of a number using tail recursion
 *
 * Author - 
 * Akshay Anand
 * CSE 3nd Sem - St. Thomas' College of Engineering & Technology
 */

 #include <stdio.h>

 int fact(int n, int res)
 {
 	if(n==1) return res;
 	else return fact(n-1, n*res);
 }

 int main()
 {
 	int n=5, res=1;
 	printf("fact(%d) = %d\n", n, fact(n, res));

 }

 /*OUTPUT

 fact(5) = 120

 */
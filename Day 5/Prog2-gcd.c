/* Day 5
 * Question 2
 * Write a program to calculate gcd of two numbers using recursion
 *
 * Author - 
 * Akshay Anand
 * CSE 3nd Sem - St. Thomas' College of Engineering & Technology
 */

 #include <stdio.h>

 int gcd(int x, int y)
 {
 	if(x%y==0) return y;
 	else return gcd(y, x%y);
 }

 int main()
 {
 	printf("gcd(14,21) = %d\n", gcd(14,21));
 }

 /* OUTPUT

 gcd(14,21) = 7

 */
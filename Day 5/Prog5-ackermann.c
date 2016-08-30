/* Day 5
 * Question 5
 * Write a program to implement ackermann function
 *
 * Author - 
 * Akshay Anand
 * CSE 3nd Sem - St. Thomas' College of Engineering & Technology
 */

 #include <stdio.h>

 long int ack(long int m, long int n)
 {
 	if(m==0) return n+1;
 	else
 	{
 		if (n==0) return ack(m-1, 1);
 		else return ack(m-1, ack(m, n-1));
 	}
 }

 int main()
 {
 	printf("ack(1,3) = %ld\n", ack(1,3));
 }

 /* OUTPUT

 ack(1,3) = 5

 */
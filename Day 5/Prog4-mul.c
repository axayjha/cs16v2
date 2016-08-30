/* Day 5
 * Question 4
 * Write a program to calculate product of two numbers using recursion
 *
 * Author - 
 * Akshay Anand
 * CSE 3nd Sem - St. Thomas' College of Engineering & Technology
 */

 #include <stdio.h>

 int mul(int a, int b)
 {
 	if(b==1) return a;
 	else return a + mul(a, b-1);
 }
 
int main()
{
	printf("5X4 = %d\n", mul(5,4));
}

/* OUTPUT

5X4 = 20

*/
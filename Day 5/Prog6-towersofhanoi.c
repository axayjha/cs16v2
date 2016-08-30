/* Day 5
 * Question 6
 * Write a program to implement towers of hanoi
 *
 * Author - 
 * Akshay Anand
 * CSE 3nd Sem - St. Thomas' College of Engineering & Technology
 */

#include <stdio.h>
void printmove(char, char);
void towers(int, char, char, char);

int main()
{
	int n;
	printf("Enter number of rings: \n");
	scanf("%d", &n);
	towers(n, 'f', 't', 's');
}

void printmove(char f, char t)
{
	printf("Move from %c to %c\n", f, t);
}

void towers(int n, char f, char t, char s)
{
	if(n==1) printmove(f, t);
	else{
		towers(n-1, f, s, t);
		towers(1, f, t, s);
		towers(n-1, s, t, f);
	}
}

/*OUTPUT

Enter number of rings: 
2
Move from f to s
Move from f to t
Move from s to t


*/
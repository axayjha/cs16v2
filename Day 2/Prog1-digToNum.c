/* Day 2
* Question 1
* WAP to enter n digits. Form a number using the digits
*
* Author - 
* Akshay Anand
* CSE 3nd Sem - St. Thomas' College of Engineering & Technology
*/

#include <stdio.h>
#include <math.h>
int main()
{
	int n, i=0,num=0;
	printf("Enter digits (-1 to stop) : \n");
	do
	{
		scanf("%d", &n);
		if(n==-1) break;
		num=num*10 + n;
		
	}while(++i);

	printf("\nNumber= %d\n", num);

	return 0;
}

/*OUTPUT

Enter digits (-1 to stop) : 
3 4 5 7 -1

Number= 3457


*/
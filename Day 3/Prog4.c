/* Day 3
 * Question 4
 * Write a program to evaluate a prefix expression
 *
 * Author - 
 * Akshay Anand
 * CSE 3nd Sem - St. Thomas' College of Engineering & Technology
 */

#include "stack.h"
#include <string.h>
#include <math.h>

float oper(char, int, int op2);

int main()
{
	int i, j;
	char exp[100], exp1[100];

	stack stk;
	stk.top = -1;


	printf("Enter the expression: ");
	scanf("%s", exp1);

	int n=0, m=0;
	for(n=0; exp1[n]!='\0'; n++);
	for(m=0,n--; n>=0; n--, m++)
		exp[m]=exp1[n];
	exp[m]='\0';	


	char *token = strtok(exp, ",");

    while(token) {
    	n=0,m=0;
    	for(; token[n]!='\0'; n++);
    	n--;
    	while(m<n)
    	{
    		char temp = token[n];
    		token[n]=token[m];
    		token[m]=temp;
    		n--;m++;
    	}	


    	if(isdigit(token[0]))
		{
			j=atoi(token);
			push(&stk, j);
		}
		else
		{
			int op2 = pop(&stk);
			int op1 = pop(&stk);
			int value = oper(token[0], op1, op2);
			push(&stk, value);
		}

        

        token = strtok(NULL, ",");
    }	

	
	printf("Result: %d\n", pop(&stk));

}

float oper(char ch, int op1, int op2)
{
	float val;
	switch(ch)
	{
		case '+':
			val =  op1 + op2;
			break;
		case '-':
			val = op1 - op2;	
			break;
		case '*':
			val = op1*op2;
			break;
		case '/':
			val = ((float)op1)/op2;
			break;
		case '^':
			val = pow(op1, op2);
			break;
		default:
			printf("INVALID OPERATOR\n");	
			exit(-1);
	}

	return val;
}

/*OUTPUT

Enter the expression: +,-,2,7,*,8,/,4,12
Result: 29

*/
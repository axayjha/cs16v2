/* Day 3
 * Question 3
 * Write a program to evaluate a postfix expression
 *
 * Author - 
 * Akshay Anand
 * CSE 3nd Sem - St. Thomas' College of Engineering & Technology
 */

#include "stack.h"
#include <string.h>
#include <math.h>

float oper(char, int, int);

int main()
{
	int i, j;
	char exp[100];

	stack stk;
	stk.top = -1;


	printf("Enter the expression: ");
	scanf("%s", exp);


	char *token = strtok(exp, ",");

    while(token) {


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

Enter the expression: 5,6,2,+,*,12,4,/,-
Result: 37

*/
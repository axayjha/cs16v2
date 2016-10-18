/* Day 3
 * Question 3
 * Write a program to evaluate a postfix expression
 *
 * Author - 
 * Akshay Anand
 * CSE 3nd Sem - St. Thomas' College of Engineering & Technology
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 40
#define TRUE 1
#define FALSE 2


typedef struct {
	float data[MAX];
	int top;	
}stack;

void push(stack *, float);
float pop(stack *);
void display(stack);
float operate(char operator, float operand1, float operand2);

int main()
{
	stack P;
	P.top = -1;

	char expression[100];
	printf("Enter expression: ");
	scanf(" %[^\n]s", expression);
	char *token = strtok(expression, " ");
	while(token){
		if(isdigit(token[0]))
			push(&P, atof(token));
		else{
			float operand1 = pop(&P);
			float operand2 = pop(&P);
			push(&P, operate(token[0], operand1, operand2));
		}
		token = strtok(NULL, " ");
	}
	printf("Result = %.2f\n", pop(&P));


}

void push(stack *stk, float num){
	if(stk->top == MAX)	{
		printf("Stack Overflow\n");
		return;
	}

	else stk->data[++(stk->top)] = num;
}

float pop(stack *stk){
	if(stk->top == -1){
		printf("Stack underflow\n");
		exit(-1);
	}
	else stk->top--;
	return stk->data[stk->top + 1];
}

void display(stack stk){
	for(int i=0; i<=stk.top; i++)
		printf("%.2f ", stk.data[i]);
	printf("\n");
}

float operate(char operator, float operand1, float operand2){
	float result = 0;

	switch(operator){
		case '+':
			result = operand1 + operand2;
			break;
		case '-':
			result = operand2 - operand1;
			break;
		case '*':
			result = operand1 * operand2;
			break;
		case '/':
			result = operand2 / operand1; 	
			break;
		case '^':
			result = pow(operand1, operand2);
			break;
		default:
			printf("Invalid operator\n");			
			exit(-1);		

	}

	return result;
}

/*OUTPUT

Enter the expression: 5 6 2 + * 12 4 / -
Result: 37

*/

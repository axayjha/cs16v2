/*
stack.h header file
(Array) Stack functions implementations

Akshay
CSE, 3rd sem


Usage:

//Initialize
stack stk;
stk.top = -1; 

//Do operations
pushDebug(&stk, 6);
display(&stk);
delete(&stk);
display(&stk);
printReverse(&stk);

*/

#ifndef STACK_H_
#define STACK_H_


#include <stdio.h>
#include <stdlib.h>

/*Max possible length of the stacl*/
#define MAX 10

/*Struct to store stack data*/
typedef struct
{
	int top;
	int data[MAX];
}stack;

void push(stack *, int);
void pushDebug(stack *, int);
int pop(stack *);
void delete(stack *);
void display(stack *);
void printReverse(stack *);

/*pushes a value to the end of the stack and prints each step*/

void pushDebug(stack *st, int num)
{
	printf("PUSH %d --->  ", num);
	if((st->top) == (MAX-1))
	{
		printf("*Stack full*\n");
		return;
	}

	(st->top)++;
	(st->data)[st->top] = num;

	printf("[ ");

	for(int i=0; i <=(st->top); i++)
	{
		printf("%d ", (st->data)[i]);
	}
	printf("] ---> PUSHED %d\n", num);


	return;
}


/*pushes a value to the end of the stack*/
void push(stack *st, int num)
{
	
	if((st->top) == (MAX-1))
	{
		printf("*Stack full*\n");
		return;
	}

	(st->top)++;
	(st->data)[st->top] = num;

	return;
}

/*deletes a value from the end of the stack*/

void delete(stack *st)
{
	printf("DELETE --->  ");
	if(st->top == -1)
	{
		printf("*Stack empty*\n");
		return;
	}
	int num = st->data[st->top];
	(st->top)--;

	printf("[ ");

	for(int i=0; i <=(st->top); i++)
	{
		printf("%d ", (st->data)[i]);
	}
	printf("] ---> DELETED %d\n", num);

}


/*pops a value from the end of the stack and returns it*/
int pop(stack *st)
{
	
	if(st->top == -1)
	{
		printf("*Stack empty*\n");
		exit(-1);
	}
	int num = st->data[st->top];
	(st->top)--;
	return num;

}

/*prints the final stack*/
void display(stack *st)
{
	printf("STACK: ");
	if(st->top == -1)
	{
		printf("*Stack empty*\n");
		return;
	}
	printf("[ ");

	for(int i=(st->top); i >=0; i--)
	{
		printf("%d ", (st->data)[i]);
	}
	printf("]\n");
}

/*Prints the stack in reversed order*/
void printReverse(stack *st)
{
	printf("REVERSED STACK: ");
	if(st->top == -1)
	{
		printf("*Stack empty*\n");
		return;
	}
	printf("[ ");

	for(int i=0; i <=(st->top); i++)
	{
		printf("%d ", (st->data)[i]);
	}
	printf("]\n");

}




#endif

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
push(&stk, 6);
display(&stk);
pop(&stk);
display(&stk)

*/

#ifndef STACK_H_
#define STACK_H_


#include <stdio.h>
#include <stdlib.h>

/*Max possible length of the stacl*/
#define MAX 8 

/*Struct to store stack data*/
typedef struct
{
	int top;
	int data[MAX];
}stack;

void push(stack *st, int num);
void pop(stack *st);
void display(stack *st);

/*pushes a value to the end of the stack*/
void push(stack *st, int num)
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

/*deletes a value from the end of the stack*/
void pop(stack *st)
{
	printf("POP --->  ");
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
	printf("] ---> POPPED %d\n", num);

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

	for(int i=0; i <=(st->top); i++)
	{
		printf("%d ", (st->data)[i]);
	}
	printf("]\n");
}



#endif
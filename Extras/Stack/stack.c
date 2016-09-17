/*
(Array) Stack functions applications

Akshay
CSE, 3rd sem

*/



#include "stack1.h"


int main()
{
	stack stk;
	stk.top = -1;
	display(&stk);
	push(&stk, 6);
	push(&stk, 7);
	push(&stk, 3);
	push(&stk, 6);
	pop(&stk);
	push(&stk, 7);
	push(&stk, 8);
	push(&stk, 2);
	pop(&stk);
	push(&stk, 1);
	push(&stk, 7);
	display(&stk);


}

/* OUTPUT

STACK: *Stack empty*
PUSH 6 --->  [ 6 ] ---> PUSHED 6
PUSH 7 --->  [ 6 7 ] ---> PUSHED 7
PUSH 3 --->  [ 6 7 3 ] ---> PUSHED 3
PUSH 6 --->  [ 6 7 3 6 ] ---> PUSHED 6
POP --->  [ 6 7 3 ] ---> POPPED 6
PUSH 7 --->  [ 6 7 3 7 ] ---> PUSHED 7
PUSH 8 --->  [ 6 7 3 7 8 ] ---> PUSHED 8
PUSH 2 --->  [ 6 7 3 7 8 2 ] ---> PUSHED 2
POP --->  [ 6 7 3 7 8 ] ---> POPPED 2
PUSH 1 --->  [ 6 7 3 7 8 1 ] ---> PUSHED 1
PUSH 7 --->  [ 6 7 3 7 8 1 7 ] ---> PUSHED 7
STACK: [ 6 7 3 7 8 1 7 ]


*/
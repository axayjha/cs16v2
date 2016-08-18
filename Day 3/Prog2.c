/* Day 3
 * Question 2
 * Write a program to reverse a list
 *
 * Author - 
 * Akshay Anand
 * CSE 3nd Sem - St. Thomas' College of Engineering & Technology
 */

#include "stack.h"

int main()
{
	
	stack stk;
	stk.top = -1;
	pushDebug(&stk, 6);
	pushDebug(&stk, 7);
	pushDebug(&stk, 3);
	pushDebug(&stk, 6);
	pushDebug(&stk, 7);
	pushDebug(&stk, 8);
	pushDebug(&stk, 2);
	pushDebug(&stk, 1);
	pushDebug(&stk, 7);
	display(&stk);
	printReverse(&stk);

/*Scroll to bottom for output*/

}



/*OUTPUT

PUSH 6 --->  [ 6 ] ---> PUSHED 6
PUSH 7 --->  [ 6 7 ] ---> PUSHED 7
PUSH 3 --->  [ 6 7 3 ] ---> PUSHED 3
PUSH 6 --->  [ 6 7 3 6 ] ---> PUSHED 6
PUSH 7 --->  [ 6 7 3 6 7 ] ---> PUSHED 7
PUSH 8 --->  [ 6 7 3 6 7 8 ] ---> PUSHED 8
PUSH 2 --->  [ 6 7 3 6 7 8 2 ] ---> PUSHED 2
PUSH 1 --->  [ 6 7 3 6 7 8 2 1 ] ---> PUSHED 1
PUSH 7 --->  [ 6 7 3 6 7 8 2 1 7 ] ---> PUSHED 7
STACK: [ 7 1 2 8 7 6 3 7 6 ]
REVERSED STACK: [ 6 7 3 6 7 8 2 1 7 ]



*/
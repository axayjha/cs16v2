#include "stack.h"

int main()
{
	
	stack stk;
	stk.top = -1;
	display(&stk);
	pushDebug(&stk, 6);
	pushDebug(&stk, 7);
	pushDebug(&stk, 3);
	pushDebug(&stk, 6);
	delete(&stk);
	pushDebug(&stk, 7);
	pushDebug(&stk, 8);
	pushDebug(&stk, 2);
	delete(&stk);
	pushDebug(&stk, 1);
	pushDebug(&stk, 7);
	display(&stk);

/*Scroll to bottom for output*/

}


/*OUTPUT

STACK: *Stack empty*
PUSH 6 --->  [ 6 ] ---> PUSHED 6
PUSH 7 --->  [ 6 7 ] ---> PUSHED 7
PUSH 3 --->  [ 6 7 3 ] ---> PUSHED 3
PUSH 6 --->  [ 6 7 3 6 ] ---> PUSHED 6
DELETE --->  [ 6 7 3 ] ---> DELETED 6
PUSH 7 --->  [ 6 7 3 7 ] ---> PUSHED 7
PUSH 8 --->  [ 6 7 3 7 8 ] ---> PUSHED 8
PUSH 2 --->  [ 6 7 3 7 8 2 ] ---> PUSHED 2
DELETE --->  [ 6 7 3 7 8 ] ---> DELETED 2
PUSH 1 --->  [ 6 7 3 7 8 1 ] ---> PUSHED 1
PUSH 7 --->  [ 6 7 3 7 8 1 7 ] ---> PUSHED 7
STACK: [ 7 1 8 7 3 7 6 ]


*/
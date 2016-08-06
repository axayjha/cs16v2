/*Linked List*/

#include <stdio.h>
#include <stdlib.h>
#include "link.h"




int main()
{
	link *list = getNode(); //Initializes

	getInput(list); //Gets inputs

	list = delete(list); //deletes last element

	append(list, 4); //adds 4 to the end
	
	printf("Length%d\n", len(list)); //prints length
	
	
	display(list); //prints whole linked list



}

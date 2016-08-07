/*
link.c
Application of linked list using link.h header file


Akshay
CSE, 3rd sem

*/

#include <stdio.h>
#include <stdlib.h>
#include "link.h"




int main()
{
	struct link *list = getNode(); //Initializes

	getInput(list); //Gets inputs

	//list = delete(list); //deletes last element

	//append(list, 4); //adds 4 to the end
	
	printlen(list); //prints length
	printindex(list, 5); //prints of index of 5

	display(list); //prints whole linked list
	print_sorted(list); //prints sorted list

}

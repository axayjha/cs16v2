/*Linked List*/

#include <stdio.h>
#include <stdlib.h>
#include "link.h"




int main()
{
	link *head, *node;
	head = getNode();
	putData(head);
	node = head;

	while(getAns())
	{
		node -> next = getNode();
		node  = node -> next;
		putData(node);
	}

	display(head);

}

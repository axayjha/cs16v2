/*
Implemention of stack using linked list
*/

#include <stdio.h>
#include <stdlib.h>
const int sentinel = -9999;


struct link
{
	int data;
	struct link *next;
	
};

struct link *getNode();
void putData(struct link **head, int num);
void push(struct link **head, int num);
void pop(struct link **head);
int len(struct link *head);
void display(struct link *head);


int main()
{
	struct link *head = getNode();
	int ch, num;

	menu:
	printf("Choose option:\n1. Push\t\t2. Pop\n3. Display\t4. Exit\n");
	printf(">");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1:			
			printf("Enter number to push: ");
			scanf("%d", &num);
			push(&head, num);			
			goto menu;
			break;
		case 2:				
			pop(&head);
			goto menu;
			break;
		case 3:
			printf("Stack: ");
			display(head);
			goto menu;
			break;
		case 4:
			return 0;	
		default:
			printf("Invalid option. Try again.\n");	
			goto menu;

	}
	


}




struct link *getNode()
{
	struct link *node = (struct link*)malloc(sizeof(struct link *));
	node->data = sentinel;
	node->next = NULL;
	return node;

}

void putData(struct link **head, int num)
{
	(*head)->data = num;
}

void push(struct link **head, int num)
{

	if((*head) == NULL)
	{
		struct link *node = getNode();
		node->data = num;
		node->next = (*head);
		(*head) = node; 

	}
	else if((*head)->data == sentinel) putData(head, num);
	else
	{
		struct link *node = getNode();
		node->data = num;
		node->next = (*head);
		(*head) = node; 
	}
	printf("pushed --> %d\n", num);
}


void pop(struct link **head)
{
	if(((*head) == NULL) || ((*head)->data == sentinel))
	{
		printf("*Stack empty*\n");
		return;
	}
	int num = (*head)->data;
	(*head) = (*head)->next;
	printf("popped --> %d\n", num);
}

int len(struct link *head)
{
	int i = 0;
	while(head != NULL)
	{
		head = head->next;
		i++;
	}
	return i;
}

void display(struct link *head)
{
	if(head == NULL)
	{
		printf("*Stack empty*\n");
		return;
	}

	else if((head->next == NULL) && (head->data == sentinel))
	{
		printf("*Stack empty*\n");
		return;
	}
	else
	{
		printf("[ ");
		while(head!=NULL)
		{
			printf("%d ", head->data);
			head = head->next;
		}
		printf("]\n");
	}
}



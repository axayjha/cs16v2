/*
Implementation of queue using linked list
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
int len(struct link *head);
void putData(struct link **head, int num);
void insert(struct link **head, int num);
void delete(struct link **head);
void display(struct link *head);



int main()
{
	struct link *head = getNode();
	int ch, num;

	menu:
	printf("Choose option:\n1. Insert\t\t2. Delete\n3. Display\t4. Exit\n");
	printf(">");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1:			
			printf("Enter number to insert: ");
			scanf("%d", &num);
			insert(&head, num);			
			goto menu;
			break;
		case 2:				
			delete(&head);
			goto menu;
			break;
		case 3:
			printf("queue: ");
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

void putData(struct link **head, int num)
{
	(*head)->data = num;
}

void insert(struct link **head, int num)
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
	printf("inserted --> %d\n", num);
}


void delete(struct link **head)
{
	int num;
	if(len(*head)==0)
	{
		fprintf(stderr, "*queue empty*\n");
		return;
	}

	struct link *temp =(*head);
	struct link *t;
	if((*head)->next==NULL)
	{
		num=(*head)->data;
    	free(*head);
    	(*head)=NULL;
    	printf("deleted --> %d\n", num);
	}
	else
	{

		while(temp->next != NULL)
    	{
        	t=temp;
        	temp=temp->next;
		}
		num=t->next->data;
    	free(t->next);
    	t->next=NULL; 

    	printf("deleted --> %d\n", num);
	}    
}



void display(struct link *head)
{
	if(head == NULL)
	{
		printf("*queue empty*\n");
		return;
	}

	else if((head->next == NULL) && (head->data == sentinel))
	{
		printf("*queue empty*\n");
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



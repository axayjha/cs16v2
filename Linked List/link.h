/*Linked List functions implementations*/

/*
Functions implemented:

link *getNode()
void putData(link *node)
BOOLEAN getAns()
void display(link *node)
int len(link *list)
void append(link *list, int num)
link *delete(link *head)
void getInput(link *list)


*/

#ifndef LINK_H_
#define LINK_H_



#define TRUE 1
#define FALSE 0
typedef int BOOLEAN;

typedef struct
{
	int data;
	struct link *next;
	
}link;



link *getNode()
{
	link *node;
	node = (link *)malloc(sizeof(link *));
	node->next = NULL;
	return node;	
}

void putData(link *node)
{
	int input;
	printf("Enter data: ");
	scanf("%d", &input);
	node->data = input;
}

BOOLEAN getAns()
{
	BOOLEAN answer;
	printf("Enter 0 to stop, non zero to continue: ");
	scanf("%d", &answer);
	return answer;
}

void display(link *node)
{
	while(node !=NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");


}

int len(link *list)
{
	int i=0;
	while(list!=NULL)
	{
		list = list->next;
		i++;
	}
	return i;
}

void append(link *list, int num)
{
	int j=0;
	
	while(j++<=len(list))
	{
		list = list->next;
	}

	list->next = getNode();
	list=list->next;
	list->data = num;
    list->next = NULL;


}



void getInput(link *list)
{
	putData(list);
	link *node;
	node = list;

	while(getAns())
	{
		node -> next = getNode();
		node  = node -> next;
		putData(node);
	}
}

link *delete(link *head)
{
  link *temp =head;
  link *t;
  if(head->next==NULL)
  {
    free(head);
    head=NULL;
  }
  else
  {
     while(temp->next != NULL)
     {
        t=temp;
        temp=temp->next;
     }
     free(t->next);
     t->next=NULL; 
  }    
  return head;
}

#endif

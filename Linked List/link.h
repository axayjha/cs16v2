/*Linked List functions implementations*/

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

int getAns()
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


#endif
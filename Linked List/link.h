/*
link.h header file
Linked List functions implementations

Akshay
CSE, 3rd sem

Implementations will keep getting updates and added. 
*/


#ifndef LINK_H_
#define LINK_H_


/*
Just to show off. Ignore.
*/
#define TRUE 1
#define FALSE 0
typedef int BOOLEAN;

/*Prototypes of all the functions implemented*/
struct link *getNode();
BOOLEAN getAns();
void putData(struct link *node);
void display(struct link *node);
int len(struct link *list);
void append(struct link *list, int num);
struct link *delete(struct link *head);
void getInput(struct link *list);
int getIndex(struct link *list, int i);
void printlen(struct link *list);
void printindex(struct link *list, int i);
void swap(struct link *a, struct link *b);
void sort(struct link *list);
void print_sorted(struct link *list);



/*
The main linked list struct definition
*/
struct link
{
	int data;
	struct link *next;
	
};


/*
Allocates memory for next node
*/
struct link *getNode()
{
	struct link *node;
	node = (struct link *)malloc(sizeof(struct link *));
	node->next = NULL;
	return node;	
}

/*
Gets answer from user as if to continue taking values
for list or stop
*/
BOOLEAN getAns()
{
	BOOLEAN answer;
	printf("Enter 0 to stop, non zero to continue: ");
	scanf("%d", &answer);
	return answer;
}


/*
Gets and puts data in memory
*/
void putData(struct link *node)
{
	int input;
	scanf("%d", &input);
	node->data = input;
}

/*
Calls getNode to allocate new memory
and then calls putData to put values in there
 */
void getInput(struct link *list)
{
	int i=0;
	printf("Enter data for node %d: ", i++);
	putData(list);
	struct link *node;
	node = list;

	while(getAns())
	{
		printf("Enter data for node %d: ", i);
		node -> next = getNode();
		node  = node -> next;
		putData(node);
		i++;

	}
}


/*
Displays the whole linked list together in linear format
*/
void display(struct link *node)
{
	printf("{ ");
	while(node !=NULL)
	{

		printf("%d ", node->data);
		node = node->next;
	}

	printf("}\n");


}

/*
Gets the length of the list
*/
int len(struct link *list)
{
	int i=0;
	while(list!=NULL)
	{
		list = list->next;
		i++;
	}
	return i;
}

/*
Append or adds and element to the end of the list
*/
void append(struct link *list, int num)
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

/*
Deletes an element from the end of the list
*/
struct link *delete(struct link *head)
{
  struct link *temp =head;
  struct link *t;
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

/*
Searches and returns the index number (first occurence) of
an element in the list. If not found, returns -1  
*/
int getIndex(struct link *list, int i)
{
	int j=0;
	while(j<len(list))
	{
		if(list->data == i)
		{
			return j;
		}
		list = list->next;
		j++;

	}
	return -1;

}

/*print length of the list*/
void printlen(struct link *list)
{
	printf("Length: %d\n", len(list));
}

/*prints index of the given element*/
void printindex(struct link *list, int i)
{
	printf("First occurence of %d : %d\n", i, getIndex(list, i));
}

/*swaps data of two nodes*/
void swap(struct link *a, struct link *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

/*sorts the elements of a linked list in ascending order 
using bubble sort*/
void sort(struct link *list)
{
    int swapped, i;
    struct link *ptr1;
    struct link *lptr = NULL;
 
    /* Checking for empty list */
    if (ptr1 == NULL)
        return;
 
    do
    {
        swapped = 0;
        ptr1 = list;
 
        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

/*prints the sorted linked list*/
void print_sorted(struct link *list)
{
	struct link *node = list;
	sort(node);
	printf("Sorted linked list: ");
	display(node);
}
 


#endif

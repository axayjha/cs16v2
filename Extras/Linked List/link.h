/*
link.h header file
Linked List functions implementations

Akshay
CSE, 3rd sem

Implementations will keep getting updates and added. 
*/


#ifndef LINK_H_
#define LINK_H_

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TRUE 1
#define FALSE 0
typedef int BOOLEAN;



/*Prototypes of all the functions implemented*/

/*01*/struct link *getNode();
/*02*/void         deleteNode(struct link *node);
/*03*/BOOLEAN      getAns();
/*04*/void         getInput(struct link *list);
/*05*/void         putData(struct link *node);
/*06*/struct link *newList();
/*07*/void         display(struct link *node);
/*08*/int          len(struct link *list);
/*09*/void         printlen(struct link *list);
/*10*/int          count(struct link *list, int num);
/*11*/BOOLEAN      is_in(struct link *head, int num);
/*12*/int          getIndex(struct link *list, int i);
/*13*/void         printindex(struct link *list, int i);
/*14*/int          data_at(struct link *list, int p);
/*15*/int          sum(struct link *list);
/*16*/int          min(struct link *list);
/*17*/int          max(struct link *list);
/*18*/int          mode(struct link *list);
/*19*/int          median(struct link *list);
/*20*/float        mean(struct link *list);
/*21*/void         append(struct link** list, int num);
/*22*/void         push(struct link** head, int num);
/*23*/void         pop(struct link **head);
/*24*/void         insert(struct link **list, int pos, int num);
/*25*/void         Delete(struct link *head, int pos);
/*26*/void         sort(struct link *list);
/*27*/void         print_sorted(struct link *list);
/*28*/struct link *sorted(struct link *list);
/*29*/struct link *copy(struct link *list);
/*30*/BOOLEAN      equal(struct link *a, struct link *b);
/*31*/struct link *reverse(struct link *list) ;
/*32*/void         swap(struct link *a, struct link *b);
/*33*/void         remove_dups(struct link *head);
/*34*/struct link *set(struct link *head);
/*35*/struct link *subset(struct link *list, int start, int end);
/*36*/struct link *concat(struct link *a, struct link *b);
/*37*/struct link *merge(struct link *a, struct link *b);
/*38*/struct link *Union(struct link *a, struct link *b);
/*39*/struct link *Intersection(struct link *a, struct link *b);
/*40*/struct link *new_list(const char *str);
/*41*/struct link *new_List();




/*
The main linked list struct definition
*/
struct link
{
	int data;
	struct link *next;
	
};

typedef struct 
{
	int data;
	struct link *next;
	
} link;

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
void append(struct link** list, int num)
{
	int j=0;
	struct link *head = *list;

	if(*list==NULL)
	{
		(*list)=getNode();
		(*list)->data = num;
		(*list)->next = NULL;
		return;
	}
	
	while((*list)->next!=NULL)
	{
		(*list) = (*list)->next;
	}

	(*list)->next = getNode();
	(*list)=(*list)->next;
	(*list)->data = num;
    (*list)->next = NULL;
    (*list) = head;

}

/*
Deletes an element from the end of the list
*/
void pop(struct link **head)
{
	if(len(*head)==0)
	{
		fprintf(stderr, "List empty. Can't Pop(). Exiting.\n");
		exit(-1);
	}

	struct link *temp =(*head);
	struct link *t;
	if((*head)->next==NULL)
	{
    	free(*head);
    	(*head)=NULL;
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
}

/*
Searches and returns the index number (first occurence) of
an element in the list. If not found, returns -1  
*/
int getIndex(struct link *list, int i)
{
	int j=0;
	while(list!=NULL)
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


/*sorts the elements of a linked list in ascending order 
using bubble sort*/
void sort(struct link *list)
{
    int swapped, i;
    struct link *ptr1;
 
    /* Checking for empty list */
    if (ptr1 == NULL)
        return;
 
    do
    {
        swapped = 0;
        ptr1 = list;
 
        while (ptr1->next != NULL)
        {
            if (ptr1->data >  ptr1->next->data)
            { 

                int temp = ptr1->data;
   				ptr1->data = ptr1->next->data;
    			ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
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
 
 /*reverses the linked list*/
struct link *reverse(struct link *list) 
{
  struct link *new_list = 0;
  while (list) {
    struct link *next = list->next;
    list->next = new_list;
    new_list = list;
    list = next;
  }
  return new_list;
}

/*returns the data at the provided position*/
int data_at(struct link *list, int p)
{
	int i, val;
	if(p>len(list) || p<0 || list==NULL)
	{
		fprintf(stderr, "Invalid parameters provided\n");
		//return errno;		
		exit(-1);
	}
	for(i=0; i<p; i++)
	{
		list = list->next;
	}
	val = list->data;
	return val;

}

/*struct link *copy(struct link *list)
{
	struct link *listcopy;
	int i;
	while(list!=NULL)
	{
		listcopy = getNode();
		listcopy->data = list->data;
		list=list->next;
		listcopy=listcopy->next;
	}
	return listcopy;	

}*/

/*clones the provided linked list allocating new memory*/
struct link *copy(struct link *list)
{
	if(list == NULL) return NULL;

	struct link *res = getNode();
	res->data = list->data;
	res->next = copy(list->next);
	return res;	

}


/*returns the sum of all values stored in a list*/
int sum(struct link *list)
{
	int res=0;
	while(list!=NULL)
	{
		res+= list->data;
		list = list->next;
	}
	return res;

}

/*counts the number of occurences of an element in the list*/
int count(struct link *list, int num)
{
	int count=0;
	while(list!=NULL)
	{
		if(list->data == num) count++;
		list=list->next;
	}
	return count;

}

/*swaps two linked list variables*/
void swap(struct link *a, struct link *b)
{
	struct link *temp = a;
	a=b;
	b=temp;
	
}

/*allocates memory and gets input for newly inititalized
linked list */
struct link *newList()
{
	struct link *list = getNode();
	getInput(list);
	return list;

}

/*checks if two of the lists provided are identical
(not in terms of location, just data)*/
BOOLEAN equal(struct link *a, struct link *b)
{
	BOOLEAN state=TRUE;

	if(len(a)!=len(b)) return FALSE;

	else
	{
		for(; a!=NULL; a=a->next, b=b->next)
		{
			if(a->data == b->data) continue;
			else state=FALSE;		

		}
		return state;
	}

}

/*return the sorted copy of the provided list*/
struct link *sorted(struct link *list)
{
	struct link *sortedlist = copy(list);
	sort(sortedlist);
	return sortedlist;
}

/*inserts the given data to the provided position*/
void insert(struct link **list, int pos, int num)
{
	if(pos==0) 
		{
			append(list, num);
			return;
		}
	else if (pos>len((*list)))
	{
		fprintf(stderr, "Index out of range\n");
		exit(-1);
	}


	int i;
	for(i=0;i<pos-1; i++)
	{
		(*list)=(*list)->next;
	}
	struct link *node=getNode();
	node->data=num;
	node->next = (*list)->next;
	(*list)->next = node;

}

/*deletes the node frm the provided position*/
void Delete(struct link *head, int pos)
{
	if(head == NULL) return;

	struct link *temp = head;

	if(pos == 0)
	{
		head = temp->next;
		free(temp);
		return;
	}

	for (int i=0; temp!=NULL && i<pos-1; i++)
         temp = temp->next;

    if(temp == NULL || temp->next == NULL)
    	return;

    struct link *next = temp->next->next;
    free(temp->next);	 
    temp->next = next;
	
}

/*deletes the node provided*/
void deleteNode(struct link *node)   
{
	if(node == NULL) return;

	struct link *temp = node;

	if(len(node) == 1)
	{
		node = temp->next;
		free(temp);
		return;
	}

	else
	{
		struct link *temp = node->next;
	    node->data     = temp->data;
	    node->next     = temp->next;
	    free(temp);

	}

   
}

/*returns TRUE if a number is present in the list,
FALSE otherwise*/
BOOLEAN is_in(struct link *head, int num)
{
	BOOLEAN state = FALSE;

	while(head != NULL)
	{
		if(head->data == num) state = TRUE;
		head = head->next;
	}
	return state;
}

/*removes the duplicate elements frm a linked list*/
void remove_dups(struct link *head)
{
	struct link *ptr1, *ptr2, *dup;
	ptr1 = head;

	while(ptr1 != NULL && ptr1->next != NULL)
	{
		ptr2 = ptr1;

		while(ptr2->next != NULL)
		{
			if(ptr1->data == ptr2->next->data)
			{
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				free(dup);
			}

			else ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}

/*returns the copy of the list with no duplicates*/
struct link *set(struct link *head)
{
	struct link *setlist = copy(head);
	remove_dups(setlist);
	return setlist;
}


/*joins two lists tail to head*/
struct link *concat(struct link *a, struct link *b)
{
	struct link *list = copy(a);
	struct link *head =list;

	while((list != NULL) )
	{
		if(list->next == NULL)
		{
			list->next = b;
			break;

		}	
		list = list->next;
		
	}
	
	return head;
}

/*returns the union set of two lists*/
struct link *Union(struct link *a, struct link *b)
{
	struct link *list = concat(a,b);
	return set(list);
}

/*add an element to the start of the list*/
void push(struct link** head, int num)
{
	struct link *node = getNode();
	node->data = num;
	node->next = (*head);
	(*head) = node; 
}

/*returns the intersected set of the lists*/
struct link *Intersection(struct link *a, struct link *b)
{
	struct link *list = NULL;
	struct link *temp = a;
	
	while(temp!=NULL)
	{
		if(is_in(b, temp->data)) 
			push(&list, temp->data);
		temp = temp->next;
		
	}	

	return set(list);
}

/*returns the subset of the list in the range provided*/
struct link *subset(struct link *list, int start, int end)
{
	struct link *result=NULL, *head=list;
	int i;
	if(end > len(list))
	{
		fprintf(stderr, "Index out of range\n");
		exit(-1);
	}

	for(i=0; i<start; i++)
	{
		list=list->next;
	}

	for(i=start; i<=end; i++)
	{
		push(&result, list->data);
		list = list->next;
	}
	list=head;
	return reverse(result);
}

/*returns the element with the most frequency of occurence*/
int mode(struct link *list)
{
	struct link *head = list, *nodup = set(list);
	int largest = count(list, nodup->data), maxFreq=0;
	while(nodup!=NULL)
	{
		if(count(list, nodup->data) > largest) 
		{
			largest = count(list, nodup->data);
			maxFreq = nodup->data;
		}
		nodup = nodup->next;

	}
	return maxFreq;
}

/*returns the median (mid term of the sorted list) of the 
provided list
Limitation: only for the lists which have odd number of nodes*/
int median(struct link *list)
{
	struct link *newlist = sorted(list);
	return data_at(newlist, (len(list)-1)/2);
}

/*returns the average of the data in the list*/
float mean(struct link *list)
{
	float avg=0;
	avg = ((float)sum(list))/len(list);
	return avg;
}

/*merges two lists (concatenates and sorts)*/
struct link *merge(struct link *a, struct link *b)
{
	return sorted(concat(a,b)) ;
}

/*returns the smallest element of the linked list*/
int min(struct link *list)
{
	int sm = list->data;
	struct link *head = list;
	while(list != NULL)
	{
		if(list->data < sm)
			sm = list->data;
		list = list->next;
	}
	list = head;
	return sm;
}

/*returns the largest element of the linked list*/
int max(struct link *list)
{
	int lg = list->data;
	struct link *head = list;
	while(list != NULL)
	{
		if(list->data >  lg)
			lg = list->data;
		list = list->next;
	}
	list = head;
	return lg;
}

/*Inputs linked list directly from string*/
struct link *new_list(const char *str)
{
	char inp[1000] = "";
	strcpy(inp,str);

	struct link *list = NULL;
	char *token = strtok(inp, ",");
    while(token) {
        int i = atoi(token);
        push(&list, i);
        token = strtok(NULL, ",");
    }	

    return reverse(list);
}

/*Inputs data at run time like any array*/
struct link *new_List()
{
	printf("Enter data (enter \"x\" to stop): ");
	struct link *list = NULL;
	int dat;
	char inp[1000]="";
	scanf("%s", inp);	
	while(strcmp(inp, "x")!=0)
	{		
		push(&list, atoi(inp));
		scanf("%s", inp);
	}

    return reverse(list);
}

#endif


/* Day 4
 * Question 2
 * Write a menu driven program to do operations on a circular queue
 *
 * Author - 
 * Akshay Anand
 * CSE 3nd Sem - St. Thomas' College of Engineering & Technology
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct
{
	int data[MAX];
	int rear, front;
} cqueue;

void init(cqueue *);
void insert(cqueue *, int);
void delete(cqueue *);
void display(cqueue *);

int main()
{
	cqueue q1;
	init(&q1);
	printf("\nChoose option: \n");
	printf("1. Insert \n2. Delete \n3. Display \n4. Exit\n");
	menu:
	printf("> ");
	char ch;
	scanf(" %c", &ch);
	switch(ch)
	{
		case '1':
			printf("Enter number to insert: \n");
			int num;
			scanf("%d", &num);
			insert(&q1, num);
			goto menu;

		case '2':
			delete(&q1);
			goto menu;

		case '3':
			display(&q1);
			goto menu;

		case '4':
		case 'q':
			return 0;	

		default:
			printf("Invalid option entered.\n Try Again;");	
			goto menu;
				
	}

}


void insert(cqueue *q1, int num)
{
	if ( ((q1->rear == MAX-1) && (q1->front == 0)) || ((q1->rear == q1->front -1) && q1->rear!=-1))
	{
		printf("*QUEUE FULL!*\n");
		return;
	}
	else if(q1->front == -1)
	{
		q1->front++;
		insert(q1, num);
	}
	else if((q1->rear == MAX-1) && (q1->front != 0))
	{
		q1->rear=-1;
		insert(q1, num);
	}
	else q1->data[++q1->rear] = num;

}

void display(cqueue *q1)
{
	if(q1->rear == -1)
	{
		printf("*QUEUE EMPTY!*\n");
		return;
	}
	
	else if(q1->rear < q1->front)
	{
		printf("CIRCULAR QUEUE: [ ");
		for(int i=0; i<=q1->rear; i++)
			printf("%d ", q1->data[i]);
		for(int i=q1->front; i<=MAX-1; i++)
			printf("%d ", q1->data[i]);
		printf("]\n");
	}
	else
	{
		printf("CIRCULAR QUEUE: [ ");
		for(int i=q1->front; i<=q1->rear; i++)
			printf("%d ", q1->data[i]);
		printf("]\n");
	}		
	
}

void init(cqueue *q1)
{
	q1->rear = q1->front = -1;
}

void delete(cqueue *q1)
{
	if(q1->front == -1)
	{
		printf("*QUEUE EMPTY!*\n");
		return;
	}

	else if(q1->rear == q1->front)
	{
		q1->rear = q1->front = -1;
	}
	else q1->front++;
	printf("*deleted %d*\n", q1->data[q1->front - 1]);
}

/* OUTPUT

Choose option: 
1. Insert 
2. Delete 
3. Display 
4. Exit
> 3
*QUEUE EMPTY!*
> 1
Enter number to insert: 
12
> 1
Enter number to insert: 
3
> 1
Enter number to insert: 
4
> 1
Enter number to insert: 
5
> 1
Enter number to insert: 
6
> 1
Enter number to insert: 
7
> 1
Enter number to insert: 
9
> 1
Enter number to insert: 
10
> 1
Enter number to insert: 
13
> 1
Enter number to insert: 
155
> 1
Enter number to insert: 
3
*QUEUE FULL!*
> 3
CIRCULAR QUEUE: [ 12 3 4 5 6 7 9 10 13 155 ]
> 2
*deleted 12*
> 1
Enter number to insert: 
100
> 3
CIRCULAR QUEUE: [ 100 3 4 5 6 7 9 10 13 155 ]
> 4 



*/
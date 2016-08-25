/* Day 4
 * Question 1
 * Write a menu driven program to do operations on a linear queue
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
} queue;

void init(queue *);
void insert(queue *, int);
void delete(queue *);
void display(queue *);

int main()
{
	queue q1;
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


void insert(queue *q1, int num)
{
	if (q1->rear == MAX-1)
	{
		printf("*QUEUE FULL!*\n");
		return;
	}
	else if(q1->front == -1)
	{
		q1->front++;
		insert(q1, num);
	}
	else q1->data[++q1->rear] = num;
}

void display(queue *q1)
{
	if(q1->rear == -1)
	{
		printf("*QUEUE EMPTY!*\n");
		return;
	}
	else
		printf("QUEUE: [ ");
		for(int i=q1->front; i<=q1->rear; i++)
			printf("%d ", q1->data[i]);
		printf("]\n");
}

void init(queue *q1)
{
	q1->rear = q1->front = -1;
}

void delete(queue *q1)
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
> 2
*QUEUE EMPTY!*
> 1
Enter number to insert: 
3
> 1
Enter number to insert: 
6
> 3
QUEUE: [ 3 6 ]
> 2
*deleted 3*
> 1
Enter number to insert: 
2
> 3
QUEUE: [ 6 2 ]
> 4

*/
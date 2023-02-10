#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#define max 5

int queue[max];
int front=-1;
int rear=-1;

void enqueue(int element)
{
	if(front==-1&&rear==-1)
	{
		front=0;
		rear=0;
		queue[rear]=element;
	}
	else if((rear+1)%max==front)
	{
		printf("\n Queue is overflown");
	}
	else
	{
		rear=(rear+1)%max;
		queue[rear]=element;
	}
}

int dequeue()
{
	if((front==-1)&&(rear==-1))
	{
		printf("\n Queue is underflown ");
	}
	else if(front==rear)
	{
			printf("\n The Dequeued element is %d ",queue[front]);
			front=-1;
			rear=-1;
	}
	else
	{
	printf("\n The Dequeued element is %d ",queue[front]);
	front=(front+1)%max;	
	}
}

void display()
{
	int i=front;
	if((front==-1&&rear==-1))
	{
		printf("\n Queue is empty");
	}
	else
	{
		printf("\n Elements of the queue are : ");
		
		while(i<=rear)
		{
			printf("%d",queue[i]);
			i=(i+1)%max;
		}
	}
}



/*
void insert();
void dequeue();
void display();

int queue_array[MAX];
int rear=-1;
int front=-1;

main()
{
	int choice;
	while(1)
	{
		printf("\n 1. Insert element to queue \n 2. Selete elements of queue \n 3. Display Elements of queue \n 4. Quit \n ");
		printf("Enter your Choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				insert();
			break;
			
			case 2:
				dequeue();
			break;
			
			case 3:
				 display();
			break;
			
			case 4:
				 exit(1);
				 
			default:
				printf("Enter a valid choice \n");
		}
	}
}

void insert()
{
	int add_item;
	
	if(rear==MAX-1)
	{
		printf("Queue is overflown ");
	}
	else
	{
		if(front==-1)
		{
			front=0;
		}
		printf("Insert the element in the queue : ");
		scanf("%d",&add_item);
		
		rear=rear+1;
		queue_array[rear]=add_item;
	}	
}

void dequeue()
{
	if(front==-1||front>rear)
	{
		printf("Queue Underflow \n ");
		return;               //
	}
	else
	{
		printf("\n Element dequeued from the queue is : %d \n",queue_array[front]);
		front=front+1;
		
	}
	
}
void display()
{
	int i;
	
	if (front==-1||front>rear)
	{
		printf("\n Queue is empty ");
	}
	else
	{
	 	printf("\n Queue is : ");
		 for(i=front;i<=rear;i++)
		 {
		 	printf("%d",queue_array[i]);
		 printf("\t");
		 }	
	}

}





















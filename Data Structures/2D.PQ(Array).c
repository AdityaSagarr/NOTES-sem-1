
#include <stdio.h>
#include <stdlib.h>
 
#define MAX 5
 
void insert_by_priority(int);
void delete_by_priority();

void display_pqueue();
 
int pri_que[MAX];
int front=-1;
int rear=-1;
int i;
 
void main()
{
    int n, ch;
 
    printf("\n1 - Insert an element into queue");
    printf("\n2 - Delete an element from queue");
    printf("\n3 - Display queue elements");
    printf("\n4 - Exit");


 
    while (1)
    {
        printf("\nEnter your choice : ");    
        scanf("%d", &ch);
 
        switch (ch)
        {
        case 1: 
            printf("\nEnter value to be inserted : ");
            scanf("%d",&n);
            insert_by_priority(n);
            break;
        case 2:
            delete_by_priority();
            break;
        case 3: 
            display_pqueue();
            break;
        case 4: 
            exit(0);
        default: 
            printf("\nChoice is incorrect, Enter a correct choice");
        }
    }
}
 

/* Function to insert value into priority queue */
//
void insert_by_priority(int data)
{
	if(front==0&&rear==MAX-1)
	{
		printf("\n Overflow");
	}
	else
	{
	 
	 
		 
		 if(front==-1)
		 {
		 	front=rear=0;
		 	pri_que[rear]=data; 
		 }
		
		 else if(rear==MAX-1)
		 {
		 	for(i=front;i<=rear;i++)
		 	{
		 		pri_que[i-front]=pri_que[i] ;
	 		}
			rear=rear-front;
			front=0; 
			for(i=rear;i>=front;i--)
			{
				if(data>pri_que[i] )
				{
					pri_que[i+1] =pri_que[i]; 
				}
				else
				break;
			}
			pri_que[i+1]=data;
			rear++;
		 }
		 
		 else
		 {
 		  	 for(i=rear;i>=front;i--)
			 {
				if(data>pri_que[i] )
				{
					pri_que[i+1] =pri_que[i]; 
				}
				else
				break;
			 }	
			pri_que[i+1]=data;
			rear++;
		 }	 	
	}
}


 
/* Function to delete an element from queue */
void delete_by_priority()
{
    if ((front==-1) && (rear==-1))
    {
        printf("\nQueue is empty, no elements to delete");
    }
 
 	else
 	{
 		printf("\n Deleted item is : %d ",pri_que[front]);
 		
		 if(front==rear)
			 {
			 	front=rear=-1;
			 }
			 else
			 {
			 	front++;
			 }
	 }
}
 
 
/* Function to display queue elements */
void display_pqueue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty");
        return;
    }
 	
 	
    for (; front <= rear; front++)
    {
        printf(" %d ", pri_que[front]);
    }
 	
 	
}





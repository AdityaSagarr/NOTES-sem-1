#include<stdio.h>
#include<conio.h>

int stack[100],choice,n,top,x,i;

void push(void);
void pop(void);
void display(void);

int main()
{
	//clescr();
	
	top=-1;
	
	printf("\n Enter the size of the stack[max 100]: ");
	scanf("%d",&n);
	printf("\n \t STACK OPERATIONS USING ARRAY ");
	printf("\n\t------------------------------------------");
	printf("\n 1.PUSH \n 2.POP \n 3.DISPLAY \n 4.EXIT");
	
	do
	{
		printf("\n Enter the Choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				{
					push();
					break;
				}
			
			case 2:
				{
					pop();
					break;
				}
			
			case 3:
				{
					display();
					break;
				}
				
			case 4:
				{
					printf("\n\t Exit Point ---------------");
					break;
				}
				
			default:
				{
					printf("\n\t Please Enter the valid choice (1/2/3/4)");
				}
		}
 	}
	 while(choice!=4);
		return 0;
}
	


	void push()
	{
		if(top>=n-1)
		{
			printf("\n Stack is full");
		}
		else
		{
			printf("\n Enter the item to be pushed: ");
			scanf("%d",&x);
			top++;
			stack[top]=x;
			
		}
	}


	void pop()
	{
		if(top<=-1)
		{
			printf("\n Stack is empty");
		}
		else
		{
			printf("\n The popped item is %d ",stack[top]);
			top--;
		}
	}


	void display()
	{
		if(top>=0)
		{
			printf("\n The elements of Stack are : ");
			for(i=0;i<=top;i++)
			{
				printf("\n %d",stack[i]);
			}
			printf("\n Enter your next choice");
		}
		else
		{
			printf("\n Stack is Empty");
			
		}
	}
	
	
	
	
	
	


// C Program to Implement a Doubly Linked List & provide Insertion, Deletion & Display Operations

#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*head,*tail,*new,*temp,*temp1;
 

void insert1();
void insert2();
void insert3();
void delete1();
void delete2();
void delete3();
void display();
 
int count = 0;
 
void main()
{
    int ch;
 
    head = NULL;
    new = tail = NULL;
 
   	printf("\n 1 - Insert at beginning");
    printf("\n 2 - Insert at end");
 	printf("\n 3 - Insert at specified position ");
 	printf("\n 4 - Delete at beginning");
 	printf("\n 5 - Delete from end");
 	printf("\n 6 - Delete at specified position");
    printf("\n 7 - display");
	printf("\n 8 - Exit");
 
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
      	   insert1();
           break; 
        
		case 2:
            insert2();
            break;
       
        case 3:
           insert3();
            break;
            
        case 4:
           delete1();
            break;    
        case 5:
           delete2();
            break;   
		case 6:
           delete3();
            break;    
                 
		case 7:
            display();
            break;
        case 8:
        	exit(0);
       
        default:
            printf("\n Wrong choice menu");
        }
    }
}
 
/* TO create an empty node */
void create()
{
    int data;
 	
	printf("\n Enter value to node : ");
    scanf("%d", &data);
    
    new =(struct node *)malloc(1*sizeof(struct node));
    new->prev = NULL;
    new->data = data;
    new->next = NULL;
   
    count++;
}
  
/* 1 TO insert at beginning */
void insert1()
{
	
    if (head == NULL)
    {
    create();	
        head = new;
        tail = head;
    }
    else
    {
    	create();
        new->next = head;
        head->prev = new;
        head = new;
    }
}
 
/* 2 To insert at end */
void insert2()
{
	
    if (head == NULL)
    {
    	create();
        head = new;
        tail = head;
    }
    else
    {
        create();
        tail->next = new;
        new->prev = tail;
        tail = new;
    }
}

/* 3 To insert at specified position */
void insert3()
{
    int pos, i = 2;
 
    printf("\n Enter position to be inserted : ");
    scanf("%d", &pos);
    temp = head;
 
    if ((pos < 1) || (pos >= count + 1))
    {
        printf("\n Position out of range to insert");
        return;
    }
    if ((head == NULL) && (pos != 1))
    {
        printf("\n Empty list cannot insert other than 1st position");
        return;
    }
    if ((head == NULL) && (pos == 1))
    {
        create();
        head = new;
        tail = head;
        return;
    }
    else
    {
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        create();
        new->prev = temp;
        new->next = temp->next;
        temp->next->prev = new;
        temp->next = new;
    }
}

// 4-deletion from begnning

void delete1()
{
	if(head==NULL)
	{
		printf("Can't Delete ,Linked list is empty \n");
	}
	else
	{
		if(head->next==NULL)
		{
		head = NULL;	
		}
		else
		{
			temp=head;
			head=head->next;
			temp->next=NULL;
			head->prev=NULL;
			free(temp);
		}
		printf("Node from begnning Deleted Successfully \n");
	}
}

// 5 -- Deletion from END
void delete2()
{
	if(head==NULL)
	{
		printf("Can't Delete ,Linked list is empty \n");
	}
	else
	{
		if(head->next==NULL)
		{
		head = NULL;	
		}
		else
		{
			temp=head;
			while(temp->next!=NULL)
			{
				temp1=temp;
				temp=temp->next;
			}
			temp1->next=NULL;
			free(temp);
		}
		printf("Node from the end Deleted Successfully \n");
	}
}

/* 6 --Deletion from specified position */
void delete3()
{
    int i = 1, pos;
 
    printf("\n Enter position to be deleted : ");
    scanf("%d", &pos);
    temp = head;
 
    if ((pos < 1) || (pos >= count + 1))
    {
        printf("\n Error : Position out of range to delete");
        return;
    }
    if (head == NULL)
    {
        printf("\n Error : Empty list no elements to delete");
        return;
    }
    else
    {
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        if (i == 1)
        {
            if (temp->next == NULL)
            {
                printf("Node deleted from list");
                free(temp);
                temp = head = NULL;
                return;
            }
        }
        if (temp->next == NULL)
        {
            temp->prev->next = NULL;
            free(temp);
            printf("Node deleted from list");
            return;
        }
        temp->next->prev = temp->prev;
        if (i != 1)
            temp->prev->next = temp->next;    /* Might not need this statement if i == 1 check */
        if (i == 1)
            head = temp->next;
        printf("\n Node deleted");
        free(temp);
    }
    count--;
}
 

// 7 -- For Displaying
void display()
{
   temp=head;
    if (tail == NULL && head == NULL)
    {
        printf("List empty to display \n");
        return;
    }
    
    printf("\n Linked list elements from begining : ");
 
    while (temp->next != NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf(" %d ", temp->data);
}




















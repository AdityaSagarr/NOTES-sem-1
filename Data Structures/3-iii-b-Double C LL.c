/*
 * C Program to Implement Circular Doubly Linked List                 
 */
#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int val;
    struct node *next;
    struct node *prev;    
};
typedef struct node n;
 
n* create_node(int);

void insert_at_first();
void insert_at_end();
void insert_at_position();
void del_beg();
void del_end();
void delete_node_position();
void display_from_beg();

 
n *new, *ptr, *prev;
n *first = NULL, *last = NULL;
int number = 0;
 
void main()
{
    int ch;
 
    printf("\n ====================linked list===================\n");
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
 
        printf("\n enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1 :
            insert_at_first();
            break;
        case 2 :
            insert_at_end();
            break;
        case 3 :
            insert_at_position();
            break;
	    case 4:
	    	del_beg();
	    	break;
    	case 5:
			del_end();
			break; 
		
        case 6 :
            delete_node_position();
            break;
 
        case 7 :
            display_from_beg();
            break;

        case 8 :
            exit(0);
    
        default:
            printf("\ninvalid choice");                
        }
    }
}
/*
 *MEMORY ALLOCATED FOR NODE DYNAMICALLY
 */
n* create_node(int info)
{
    number++;
    new = (n *)malloc(sizeof(n));
    new->val = info;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

/*
 *INSERTS ELEMENT AT FIRST
 */
void insert_at_first()
{
 
    int info;
 
    printf("\nenter the value to be inserted at first:");
    scanf("%d",&info);
    new = create_node(info);
 
    if (first == last && first == NULL)
    {    
        printf("\ninitially it is empty linked list later insertion is done");
        first = last = new;
        first->next = last->next = first;
        first->prev = last->prev = first;
    }
    else
    {
        new->next = first;
        first->prev = new;
        first = new;
        first->prev = last;
        last->next = first;
        printf("\n the value is inserted at begining");
    }
}
/*
 *INSERTS ELEMNET AT END
 */
void insert_at_end()
{
 
    int info;    
 
    printf("\nenter the value that has to be inserted at last:");
    scanf("%d", &info);
    new = create_node(info);
 
    if (first == last && first == NULL)
    {
        printf("\ninitially the list is empty and now new node is inserted but at first");
        first = last = new;
        first->next = last->next = first;    
        first->prev = last->prev = first;
    }
    else
    {
        last->next = new;
        new->prev = last;
        last = new;
        first->prev = last;
        last->next = first;
    }
}
/*
 *INSERTS THE ELEMENT AT GIVEN POSITION
 */
void insert_at_position()
{    
    int info, pos, len = 0, i;
    n *prevnode;
 
    printf("\n enter the value that you would like to insert:");
    scanf("%d", &info);
    printf("\n enter the position where you have to enter:");
    scanf("%d", &pos);
    new = create_node(info);
 
    if (first == last && first == NULL)
    {
        if (pos == 1)
        {
            first = last = new;
            first->next = last->next = first;    
            first->prev = last->prev = first;
        }
        else
            printf("\n empty linked list you cant insert at that particular position");
    }
    else
    {
        if (number < pos)
            printf("\n node cant be inserted as position is exceeding the linkedlist length");
 
        else
        {
            for (ptr = first, i = 1;i <= number;i++)
            {
                prevnode = ptr;
                ptr = ptr->next;
                if (i == pos-1)
                {
                    prevnode->next = new;
                    new->prev = prevnode;
                    new->next = ptr;
                    ptr->prev = new;
                    printf("\ninserted at position %d succesfully", pos);
                    break;
                }
            }
        }
    }
}

void del_beg()
{
	n *temp;
	
	if(first==NULL)
	{
		printf("\n UNDERFLOW \n");
	}
	else if(first->next == first)
	{
		first=NULL;
		free(first);
		
		printf("\n NODE DELETED\n");
	}
	else
	{
		number--;
		temp=first;
		while(temp->next!=first)
		{
			temp=temp->next;
		}
  		temp -> next = first -> next;  
        first -> next -> prev = temp;  
        free(first);  
        first = temp -> next;  
        printf("\nNode Deleted\n");  
	}
}

void del_end()
{
   n *temp;
  
   if(first == NULL)  
    {  
        printf("\n UNDERFLOW\n");  
    }  
  
    else if(first->next == first)  
    {  
        first = NULL;   
        free(first);   
        printf("\nNode Deleted\n");  
    }  
  
    else   
    {  
	    number--;
        temp = first;   
        while(temp->next!= first)  
        {  
            temp = temp -> next;   
        }  
        temp -> prev -> next = first;  
        first -> prev = temp -> prev;    
        free(temp);  
        printf("\nNode Deleted\n");  
    }  
 	
}

/*
 *DELETION at psoition
 */
void delete_node_position()
{    
    int pos, count = 0, i;
    n *temp, *prevnode;
 
    printf("\n enter the position which u wanted to delete:");
    scanf("%d", &pos);
 
    if (first == last && first == NULL)
        printf("\n empty linked list you cant delete");
 
    else
    {
        if (number < pos)
            printf("\n node cant be deleted at position as it is exceeding the linkedlist length");
 
        else
        {
            for (ptr = first,i = 1;i <= number;i++)
            {
                prevnode = ptr;
                ptr = ptr->next;
                if (pos == 1)
                {    
                    number--;
                    last->next = prevnode->next;
                    ptr->prev = prevnode->prev;
                    first = ptr;
                    printf("%d is deleted", prevnode->val);
                    free(prevnode);
                    break;        
                }
                else if (i == pos - 1)
                {    
                    number--;
                    prevnode->next = ptr->next;
                    ptr->next->prev = prevnode;
                    printf("%d is deleted", ptr->val);
                    free(ptr);
                    break;
                }
            }
        }
    }
}


/*
 *DISPLAYING IN BEGINNING
 */
void display_from_beg()
{
    int i;
    if (first == last && first == NULL)
    {
        printf("\nlist is empty no elemnts to print");	
	}
	
	else
    {    
        printf("\n%d number of nodes are there  :  ", number);
        
        ptr=first;
        for (i = 0;i < number;i++)
        {
			printf("%d ,", ptr->val);
        	ptr = ptr->next;
	    }
    }
}

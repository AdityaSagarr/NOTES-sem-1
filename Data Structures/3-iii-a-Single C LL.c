#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *head;  
  
void beginsert ();   
void lastinsert (); 
void ins_at_pos(); 
void begin_delete();  
void last_delete();
void del_at_pos();  
void display();

void main ()  
{  
    int choice =0;  
    
	
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining \n2.Insert at last\n3.Desired Insertion \n4.Delete from Beginning\n5.Delete from last\n6.Desired Deletion \n7.Display\n8.Exit\n");
		 
	while(choice != 8)   
    {  
 	    printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice); 
        switch(choice)  
        {  
            case 1:  
            beginsert();      
            break;  
            
            case 2:  
            lastinsert();         
            break;  
			
			case 3:  
            ins_at_pos();         
            break;  
            
			case 4:  
            begin_delete();       
            break;  
            
			case 5:  
            last_delete();        
            break;  

			case 6:  
            del_at_pos();
            break; 
            
            case 7:  
            display();        
            break;  

            case 8:  
            exit(0);  

            
            
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}  
void beginsert()  
{  
    struct node *ptr,*temp;   
    int item;   
    ptr = (struct node *)malloc(sizeof(struct node));  
    if(ptr == NULL)  //======================================================  ?????????????????
    {  
        printf("\nOVERFLOW");  
    }  
    else   
    {  
        printf("\nEnter the node data?");  
        scanf("%d",&item);  
        ptr -> data = item;  
        if(head == NULL)  
        {  
            head = ptr;  
            ptr -> next = head;  
        }  
        else   
        {     
            temp = head;  
            while(temp->next != head)  
                temp = temp->next;  
            ptr->next = head;   
            temp -> next = ptr;   
            head = ptr;  
        }   
        printf("\nnode inserted\n");  
    }  
    
}  
void lastinsert()  
{  
    struct node *ptr,*temp;   
    int item;  
    ptr = (struct node *)malloc(sizeof(struct node));  
    if(ptr == NULL)  //======================================================  ?????????????????
    {  
        printf("\nOVERFLOW\n");  
    }  
    else  
    {  
        printf("\nEnter Data?");  
        scanf("%d",&item);  
        ptr->data = item;  
        if(head == NULL)  
        {  
            head = ptr;  
            ptr -> next = head;   
        }  
        else  
        {  
            temp = head;  
            while(temp -> next != head)  
            {  
                temp = temp -> next;  
            }  
            temp -> next = ptr;   
            ptr -> next = head;  
        }  
          
        printf("\nnode inserted\n");  
        
    }  
  
}  
void ins_at_pos()  
{  
    struct node *ptr,*x,*y,*z;  
    int c = 1, pos, count = 1;  
   
    y = (struct node*)malloc(sizeof(struct node));  
    
    printf("\n Enter the data for particular position:");  
    scanf("%d", &y->data);  
    printf("\n Enter the position to be inserted:");  
    scanf("%d", &pos);  
    

    if ((head == NULL) && (pos != 1))
    {
        printf("\n Empty list cannot insert other than 1st position");
        return;
    }
    if ((head == NULL) && (pos == 1))
    {
        head=y;
        y->next=head;
        return;
    }
	else
	{
 	 	    x = head;  
		    ptr = head;  
		    while (ptr->next != head)  
		    {  
		        count++;  
		        ptr = ptr->next;  
		    }  
		    count++;  
		    if (pos > count)  
		    {  
		        printf("OUT OF BOUND");  
		        return;  
		    }  
		    while (c < pos)  
		    {  
		        z = x;  
		        x = x->next;  
		        c++;  
		    }  
		    y->next = x;  
		    z->next = y;  
	}
    
}  

  
void begin_delete()  
{  
    struct node *ptr;   
    if(head == NULL)  
    {  
        printf("\nUNDERFLOW");    
    }  
    else if(head->next == head)  
    {  
        head = NULL;  
        free(head);  
        printf("\nnode deleted\n");  
    }  
      
    else  
    {   ptr = head;   
        while(ptr -> next != head)  
            ptr = ptr -> next;   
        ptr->next = head->next;  
        free(head);  
        head = ptr->next;  
        printf("\nnode deleted\n");  
    }  
}  
void last_delete()  
{  
    struct node *ptr, *preptr;  
    if(head==NULL)  
    {  
        printf("\nUNDERFLOW");  
    }  
    else if (head ->next == head)  
    {  
        head = NULL;  
        free(head);  
        printf("\nnode deleted\n");  
  
    }  
    else   
    {  
        ptr = head;  
        while(ptr ->next != head)  
        {  
            preptr=ptr;  
            ptr = ptr->next;  
        }  
        preptr->next = ptr -> next;  
        free(ptr);  
        printf("\nnode deleted\n");  
    }  
}  

  
void display()  
{  
    struct node *ptr;  
    ptr=head;  
    if(head == NULL)  
    {  
        printf("\nnothing to print");  
    }     
    else  
    {  
        printf("\n Printing values :  ");  
          
        while(ptr -> next != head)  
        {  
          
            printf("%d,", ptr -> data);  
            ptr = ptr -> next;  
        }  
        printf("%d\n", ptr -> data);  
    }      
}  
void del_at_pos()  
{  
    struct node *ptr, *preptr;  
    if (head == NULL)  
        printf("\n List is empty");  
    else  
    {  
        int c = 1, pos;  
        printf("\n Enter the position to be deleted:");  
        scanf("%d", &pos);  
        ptr = head;  
        while (c < pos)  
        {  
            preptr = ptr;  
            ptr = ptr->next;  
            c++;  
        }  
        preptr->next = ptr->next;  
        free(ptr);  
        
        printf("\nnode deleted\n");  
    }  
}  



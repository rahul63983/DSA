#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
typedef struct lklist{
	int info;
	struct lklist *next;
	
}node;
void main()
{
	void insert_at_beg(node **,int);
	void insert_at_end(node **,int);
	void traverse(node *);
	void delete_at_beg(node **);
	void delete_at_end(node **);
	void insert_after(node* ,int);
	void insert_after_value(node**,int,int);
	int* searching_by_value(node* ,int);//by value
//	int* searching_by_count(node*);
	void delete_after(node *,int);
	void sort_list(node**,int);
	void sorting(node**);
	int choice,item;
	node *head=NULL;
	int *ptr;
	int value;
	while(1)
	{
		printf("1. Insert data item at begning at strat\n");
		printf("2. insert data at end of the linked list\n");
		printf("3. traverse the linked list\n");
		printf("4.Delete the data item from begning in linked list\n");
		printf("press 5. for delete item from ending of linked list\n");
        printf("press 6. for search a value in linkedlist\n");
		printf("press 7.for search by counting the node in linkedlist\n");
		printf("press 10. for delete for\n");
		printf("press 8. for insert data after a particular value in list\n");
		printf("press 9. for insert data after search a data in list \n");
		printf("press 12. for sorting the list\n");
		printf("press 13. for entering the element by sort wise \n");
		printf("press 11. for exit\n");		
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter the data item\n");
			        scanf("%d",&item);
			        insert_at_beg(&head,item);
			        break;
			case 2:printf("enter the data item");
			        scanf("%d",&item);
			        insert_at_end(&head, item);
			        break;
			        
			case 3:if(head==NULL)
		         	{
		         		printf("list is empty");
		         	}
		         	else
		         	{
		         	  traverse(head);
				    }
					
			    	break;
			case 4:if(head==NULL)
		          	{
				       printf("list is empty");
			        }
			        else
			        {
			        	delete_at_beg(&head);
					}
				  break;
			case 5:if(head==NULL)
		          	{
				       printf("list is empty");
			        }
			        else
			        {
			        	delete_at_end(&head);
					}
				  break;
			case 6:printf("enter the value that you want to search\n");
			      scanf("%d",&item);
			     if(ptr= searching_by_value(head,item))
			       {
				       printf("the address of given value is %d\n",ptr);
			       }
			       else
			       {
			       	printf("the given value is not found in the list\n");
				   }
				   break;/*
			case 7:printf("enter the node no.");
			       scanf("%d",&item);
			       searching_by_value(head,item);
			       break;
			       
			case 8: printf("enter the value after  2 node which you want to insert the value");
			        scanf("%d",&item);
			        if(head==NULL)
			        {
			        	printf("the list empty");
					}
					else
					{
					
			         insert_after(&head,item);
			        }
			        break;
			        */
		    case 9:printf("enter the value for searching\n");
		           scanf("%d",&item);
		           printf("enter the value that you want insert\n");
		           scanf("%d",&value);
		           insert_after_value(&head,item,value);
		           break;
		        	
	           		
			case 11: exit(1);
			        break;
			case 12:if(head==NULL)
			       { 
			          printf("list is empty\n");
		          	} 
		          	else
		          	{
					  
			             sorting(&head);
		            }
		            break;
		    case 13:printf("enter the data item\n");
			        scanf("%d",&item);
					
		             
					 	sort_list(&head,item);
					 	printf("4443\n");
					 	
					 
					 break;
			default: printf("wrong choice");
		}
		
	}
 }
void insert_at_beg(node **start,int item)
{
//	printf("dynamice memory allocation");
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->info=item;
	if(*start==NULL)
	{
		temp->next=NULL;
	}
	else
	{
		temp->next=*start;
		
	}
	*start=temp;
//	printf("dynamice memory allocation2");
	
}
void insert_at_end(node **start,int item)
{
	node *temp,*loc;
	temp  = (node*)malloc(sizeof(node));
	temp->info=item;
	temp->next=NULL;
	if(*start ==NULL)
	{
		*start=temp;
	}
	else
	{
		loc=*start;
		while(loc->next!=NULL)
		{
			loc=loc->next;
		}
		loc->next=temp;
	}
}
void traverse(node *start)
{
	while(start!=NULL)
	{
		printf("\n%d\n",start->info);
		start=start->next;
	}
}
void delete_at_beg(node **start)
{
	node *temp;//**
	temp=*start;
	*start=(*start)->next;
	free(temp);
}
void delete_at_end(node **start)
{
	node *loc,*temp;
	loc=*start;
	if((*start)->next==NULL)
	{
		temp=*start;
		*start=NULL;
	}
	else
	{
		while(((loc->next)->next)!=NULL)
        {
        	loc=loc->next;
		}
		temp=loc->next;
		loc->next=NULL;
		
	}
	free(temp);
	
}
int* searching_by_value(node *start,int item)
{
	while(start!=NULL)
	{
		if(start->info==item)
		{
			return start;
		}
		start=start->next;
	}
	return 0;
}
/*
void insert_after(node *start,int item)
{
   //int c=1;
   node *temp;
   temp=(node*)malloc(sizeof(node));
   temp->info=item;
   temp->next=NULL;
   while((start->next)!=NULL)
   {
   	 
   	 	
		
		start=start->next;
	     temp->next=start->next;	
	   }	
	   start->next=temp;
}
*/
void insert_after_value(node **start,int item,int value)
{
	node *temp,*loc;
	temp=(node*)malloc(sizeof(node));
	temp->info=value;
	temp->next=NULL;
	loc=*start;
	while(loc!=NULL)
	{
		if(loc->info==item)
		
		{
			temp->next=loc->next;
			loc->next=temp;
			//printf("word");
			//return ;
			//return start;
		}
		loc=loc->next;
		//printf("ab");
	}
	
	
}
void sorting(node **start)
{
	node *temp,*loc;
	int store;
	temp=*start;
	
	while(temp->next!=NULL)
	{
			
		loc=temp->next;
		while(loc!=NULL)
		{
		
     	if((temp->info)>(loc->info))
	     {
		  
		store=temp->info;
		temp->info=loc->info;
		loc->info=store;
		
	   }
	   loc=loc->next;
       }
	
	   temp=temp->next;	
	}
	
	
}
void sort_list(node **start,int item)
{
	node *temp,*loc=NULL,*first;
	first=*start;
	temp=(node*)malloc(sizeof(node));
	temp->info=item;
	if(first==NULL)
	{
		temp->next=NULL;
		*start=temp;
	}
	else
	{
	
	while(first!=NULL)
	{
		if((first->info)<(temp->info))
		{
			loc=first;
			first=first->next;
			
		}
		else{
			if(loc!=first)
			{
				temp=loc->next;
				loc->next=temp;
			}
			else
			{
				temp->next=first;
				*start=temp;
			}
		}
		
	}
	loc->next=temp;
	temp->next=NULL;
}
}

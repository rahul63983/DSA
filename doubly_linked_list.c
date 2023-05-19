#include<stdio.h>
#include<process.h>
#include<stdlib.h>
typedef struct dblinked_list{
	int info;
	struct dblinkend_list *next;
	struct dblinkend_list *prev;
}node;
void main()
{
	node *head=NULL,*tail=NULL;
	int choice,item,value;
    void insert_at_beg(node **, node**,int);
    void insert_at_end(node**,node**,int);
    void traverse(node *);
   void insert_at_after(node**, node**,int,int );
   void delete_ata_beg(node**,node**);
   void delete_at_end(node**,node**);
   node *search(node*,int);
   //void delete_after_element(node**,node**,int);
   void reverse(node**);
    while(1)
    {
    printf("press 1. for insert at begning in doubly linked list\n");
    printf("press 2. for insert at ending in doublt linked list\n");
    printf("press 3. for traversing the doubly linked list\n");
    printf("press 4. for insert at after an item \n ");
    printf("press 5. for delete at beg\n");
    printf("press 6 for delete at end\n");
    printf("press. 8 for reverse the linklist\n");
    
    printf("press 9. for exit() \n");
    printf("enter your choice:\n");
    scanf("%d",&choice);
    
    	switch(choice)
    	{
    		case 1:
    			printf("enter the value that you want to insert:\n");
    			scanf("%d",&item);
    			insert_at_beg(&head,&tail,item);
    			break;
    		case 2:
    			printf("enter the value that you want to insert at end\n");
    			scanf("%d",&item);
    			insert_at_end(&head,&tail,item);
    			break;
    		case 3: if(head==NULL)
    	          	{
    	          		printf("the list is empty\n");
    			
		         	}
		            else
					{
						traverse(head);
						 } 	
		        break;
		        
		    case 4: if(head==NULL)
		         	{
		         		printf("list is empty\n");
				
			          }     
			          else
			          {printf("enter that value you want to insert after\n");
			            scanf("%d",&item);
			            printf("enter the value that you wnat to insert\n");
			            scanf("%d",&value);
			          	insert_at_after( &head,&tail,item,value );
			          	printf("\naaaaa\n");
			          	break;
			          	
			          	
					  }
				break;
				printf("\newrasd\n");
					  
			case 5:if(head==NULL)
			        {
			        	printf("list is empty\n");
		  		
		          	}
		          	else{
		          		delete_at_beg(&head,&tail);
					  }
				break;
					
			case 6:if(head==NULL)
			        {
			        	printf("list is empty\n");
		  		
		          	}
		          	else{
		          		delete_at_end(&head,&tail);
					  }
				break;
					/*
			case 7:if(head==NULL)
			        {
			        	printf("list is empty\n");
		  		
		          	}
		          	else{
		          		printf("enter the element after \n");
		          		scanf("%d",&item);
		          		delete_after_element(&head,&tail,item);
					  }
					break;
					*/
				
			case 8:
				  if(tail==NULL)
				  {
				  	printf("list is empty\n");
				  }
				  else
				  {
				  	reverse(&tail);
				  }
				  break;
				
    		case 9: exit(0);
    			break;
    		default:
    			printf("you enter wrong choice\n");
		}
	}
    
}
void insert_at_beg(node **start,node **end,int value)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->info=value;
	temp->prev=NULL;
	if(*start==NULL)
	{ 
	  temp->next=NULL;
	  *end=temp;
		
	}
	else
	{
		(*start)->prev=temp;
		temp->next=*start;
	}
	*start=temp;
	
}

void insert_at_end(node **start,node **end,int item)
{
	node *temp;
	
	temp=(node*)malloc(sizeof(node));
	temp->info=item;
	temp->next=NULL;
	if(*start==NULL)
	{
		temp->prev=NULL;
		*start=temp;
	}
	else
	{
		temp->prev=*end;
		(*end)->next=temp;
		
	
	}
	*end=temp;
}
void traverse(node *start)
{
	while(start!=NULL)
	{
		printf("%d\t",start->info);
		start=start->next;
	}
}

node* search(node *start,int item)
{
	if(start==NULL)
	{
		printf("list is empty\n");
	}
	else
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
}

void insert_at_after(node **start, node **end,int item, int value)

{
	node *temp,*b,*am,*loc=NULL;
     //int *a;
	b=*start;
	loc=search(b,item);
//	printf("%d\n",loc);
	if(loc==NULL)
	{
		printf("trageted element is not found\n");
		return;
	}
	else
	{	temp=(node*)malloc(sizeof(node));
        temp->info=value;
      //  printf("%d\n",temp->info);
        	temp->prev=loc;
        temp->next=loc->next;
          printf("%d\n",loc->next);
		if(loc->next=NULL)
		{
          	loc->next=temp;
          	*end=temp;
          //	printf("%d\n",temp->next);
			
	    	}
	    	else
		   {
	    //	printf("hello\n");
		      
		  	printf("hello\n");
		  	am=loc->next;
		  	printf("\n%d\n",am);
		  //	am->prev=temp;
             loc->next=temp;
            //a=(int*) temp;
            //temp=temp->next;
           // temp->prev=a;
            
           // ((a->prev)->prev)=temp;
               
               
          	 //	printf("hello\n");
            
			 	printf("hello\n");
             // loc->next=temp;
             printf("\nhi");
         }
         
         	traverse(*start);
		
	}
   
	printf("\nhiyt\n");	
}


void delete_at_beg(node **start,node **end)
{
	node *temp,*loc;
	if(*start==*end)
	{
		temp=*start;
		*start=NULL;
		*end=NULL;
	}
	else
	
	{
		
		temp=*start;
		loc=*start;
	//	((*start)->next)->prev=NULL;
		*start=(*start)->next;
		(*start)->prev=NULL;	
      //  ((loc->next)->prev	)=NULL;
        //*start=(*start->next);
	}
	free(temp);
}

void delete_at_end(node **start,node **end)
{
	node *temp;
	if(*start==*end)
	{
		temp=*start;
		*start=*end=NULL;
	}
	else
	{
		temp=*end;
		*end=(*end)->prev;
		(*end)->next=NULL;
		//*end=*end->prev;
		
	}
	free(temp);
}
/*
 void delete_after_element(node **start,node **end,int item)
 {
 	node *temp,*loc;
 	
 	
 	
 	
 }
 */

void reverse(node **end)
{
	node *temp;
	temp=*end;
	while(temp!=NULL)

	{
		printf("%d\t",temp->info);
		temp=temp->prev;
	}
}

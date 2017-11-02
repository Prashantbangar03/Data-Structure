#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *pre,*next;
}*NODE;

NODE last=NULL;

NODE createNOde(int data)
{
	NODE NewNode=(NODE)malloc(sizeof(NODE));
	NewNode->next=NULL;
	NewNode->pre=NULL;
	NewNode->data=data; 
	//printf("pre=%d\tdata=%d\tnext=%d\tnewnode=%p\n",NewNode->pre,NewNode->data,NewNode->next,NewNode);
	return NewNode;
}

NODE createList(NODE start,int data)
{	NODE NewNode;
	if(start==NULL)
	{
		start=last=createNOde(data);
	}
	else
	{
	last->next=NewNode=createNOde(data);
	NewNode->pre=last;
	last=NewNode;
	}
	return start;
}

void display(NODE start)
{
	if(start!=NULL)
	{
		printf("%d->",start->data);
		display(start->next);
	}

}

int getLength(NODE start)
{
	if(start!=NULL)
	{
	return 1+getLength(start->next);
	}
}

int SearchElementPosition(NODE start,int data,int Position)
{
	if(start==NULL)
	{
		return 0;
	}
	
	if(start->data==data)
	{
		return Position;
	}
	SearchElementPosition(start->next,data,Position+1);
		
}
void InsertNode_At_first(NODE *start,int data)
{
	if(*start==NULL)
	{
		*start=createNOde(data);
	}
	else
	{
		NODE NEW=createNOde(data);
		NEW->next=*start;
		(*start)->pre=NEW;
		*start=NEW;
	}	
}
int  Delete_First_Node(NODE *start)
{
	if(*start==NULL)
	{
		return 0;
	}
	else
	{
	NODE temp=(*start)->next;
	free(*start);
	*start=temp;
	return 1;
	}
}

int Delete_Last_Node(){
	if(last->pre==NULL)
	{
		return 0;
	}
	else
	{
		NODE temp=last->pre;
		temp->next=NULL;
		free(last);
		last=temp;

		return 1;
	}

}
void displayReverse(NODE start)
{
	if(start!=NULL)
	{
		displayReverse(start->next);
		printf("%d\t",start->data );
	}
}

int main(int argc, char const *argv[])
{	
	int Choice,data,ret,element;
	NODE start=NULL;
		system("clear");
	
	do{
		printf("\n\n\t\t1.InsertNode At Last\n");
		printf("\t\t2.InsertNode At First\n");
		printf("\t\t3.Delete Node First\n");
		printf("\t\t4.Delete Node Last\n");
		printf("\t\t5.Display List\n");
		printf("\t\t6.Display Reverse\n");
		printf("\t\t7.Length of list\n");
		printf("\t\t8.Search Element Position\n");
		printf("\t\t9.Exit\n");
		printf("\t\tEnter the Choice:-");
		scanf("%d",&Choice);
		system("clear");
		switch(Choice)
		{
		case 1:
				//system("clear");
				printf("\t\t\n\nEnter Data\n");
				scanf("%d",&data);
				start=createList(start,data);
				break;

		case 2:
				
				printf("enter data\n");
				scanf("%d",&data);
				InsertNode_At_first(&start,data);
				break;

		case 3:
				ret=Delete_First_Node(&start);
				if(ret==1)
				{
					printf("First Element is Delete successfully\n");
					display(start);
				}
				else
				{
					printf("There is No Element For Delete \n");
				}
				break;

		case 4:
				ret=Delete_Last_Node();
				if(ret==1)
				{
					printf("Last Element is Delete successfully\n");
					display(start);
				}
				else
				{
					printf("There is No Element For Delete \n");
				}
				break;

		case 5:			
				//system("clear");
				printf("\n\n\t\t");
				display(start);
				printf("\n");
				break;

		case 6:
				printf("\n\n\t\t");
				displayReverse(start);
				printf("\n");
				break;
		case 7:	
				//system("clear");
				printf("\t\t\n\nLength of Link List is=%d\n",getLength(start));
				break;
		
		case 8:
				
				printf("Enter the element\n");
				scanf("%d",&element);
				ret=SearchElementPosition(start,element,0);
				if(ret==0)
				{
					printf("Element is Not Present in list\n");
				}
				else
				{
					printf("Element Found at Position=%d\n",ret+1 );
				}
				break;
		case 9:
				//system("clear");
				printf("Bye Bye  \n");
				break;

		default:
				//system("clear");
				printf("Enter Correct Choice\n");
				break;		
		}

	}while(Choice!=9);		
	return 0;
}
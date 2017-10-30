#include<stdio.h>
#include<malloc.h>
typedef struct node{
	int data;
	struct node *next;
}*node;



node insertnode(int data,node start){
	node nn=NULL,temp;
	nn=(node)malloc(sizeof(node));
	nn->next=NULL;
	nn->data=data;
	if(start==NULL)
		start=temp=nn;
	else
	{
		temp->next=nn;
		temp=nn;
	}
return start;
}

void display(node start){
	printf("Start->");
	for(node temp=start;temp!=NULL;temp=temp->next)
		printf("%d->",temp->data);
	printf("NULL\n");
}

node reverser(node start){
	node temp,temp1;
	temp=start;
	while(temp->next!=NULL)
	{	
	//	printf("temp->data=%d \t temp=%d \n",temp->data,temp->next );
		temp1=temp->next;
		temp->next=temp->next->next;
		temp1->next=start;
		start=temp1;
	}
	/*
		node ns=NULL;
		node temp=start;
		while(temp!=NULL)
		{
			start=start->next;
			temp->next=ns;
			ns=temp;
			temp=start;
		}*/
return start;
}

int getlength(node start)
{
	node temp=start;
	int length=0;
	while(temp!=NULL)
	{
		length++;
		temp=temp->next;
	}
return length;
}

int icnt=0;

void ReversePrint(node start)
{
if(start==NULL)
	return;
icnt++;
ReversePrint(start->next);
printf("%d\t",start->data );
}

int main(int argc, char const *argv[])
{	
	node start=NULL;
	start=insertnode(10,start);
	start=insertnode(20,start);
	start=insertnode(30,start);
	start=insertnode(40,start);
	start=insertnode(50,start);
	start=insertnode(60,start);
	start=insertnode(70,start);
	start=insertnode(80,start);	
	start=insertnode(90,start);
	start=insertnode(100,start);
	start=insertnode(110,start);			
	printf("Link List:-\n");
	display(start);
	start=reverser(start);
	printf("Reverse Link List:-\n");
	display(start);
	int length;
	length=getlength(start);
	printf("length is =%d\n",length );
	printf("Reverse print:-\n");
	ReversePrint(start);
	printf("\nicnt=%d\n",icnt);
	return 0;
}
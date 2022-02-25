#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
struct node *front1,*rear1,*front2,*rear2;
void enqueue(int x,int pr)
{
	struct node *temp;
	temp=new node;
	if(temp==NULL)
	{
		printf("\nQueue is full\n");
	}
	else
	{
		temp->data=x;
		if(pr==1)
		{
			if(front1==NULL)
		{
			temp->next=NULL;
			front1=temp;
			rear1=temp;
			
		}
		else
		{
			rear1->next=temp;
			rear1=temp;
		}
		}
		else if(pr==2)
		{
			if(front2==NULL)
			{
			temp->next=NULL;
			front2=temp;
			rear2=temp;
			}
		else
		{
			rear2->next=temp;
			rear2=temp;
		}
		}
	}
}
void dequeue()
{
	struct node *temp;
	if(front2==NULL)
	{
		printf("\nBoth the queues are empty\n");
	}
	else
	{
		if(front1==NULL)
		{
			temp=front2;
			front2=front2->next;
			delete temp;
		}
		else
		{
			temp=front1;
			front1=front1->next;
			delete temp;
		}
		}	
}
void display()
{
	if(front2==NULL)
	{
		printf("\nBoth the Queues is Empty\n");
	}
	else
	{
		if(front1==NULL)
		{
			struct node *temp;
			temp = new node;
			temp = front2;
			while(temp!=NULL)
			{
				printf("\n%d\n",temp->data);
				temp=temp->next;
			}
		}
		else
		{
			struct node *temp;
			temp=new node;
			temp = front1;
			while(temp!=NULL)
			{
				printf("\n%d\n",temp->data);
				temp=temp->next;
			}
			temp = front2;
			while(temp!=NULL)
			{
				printf("\n%d\n",temp->data);
				temp=temp->next;
			}
			
		}
	}
}
int main()
{
	enqueue(1,2);
	enqueue(10,1);
	enqueue(13,2);
	enqueue(20,1);
	display();
	return 0;
}
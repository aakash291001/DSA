#include<iostream>
using namespace std;
struct node 
{
	int data;
	struct node *next;
}*head;
void createcir(struct node *p)
{
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=head;
	
}
void insert(struct node *t,int ele,int pos)
{
	struct node *p;
	p = new node;
	p->data=ele;
	p->next=NULL;
	if(pos==0&&head==NULL)
	{
		head= p;
	}
	else if(pos==0&&head!=NULL)
	{
		while(t->next!=head)
		t=t->next;
		t->next=p;
		p->next=head;
		head=p;
	}
	else
	{
		for(int i=1;i<pos;i++)
		{
			t=t->next;
		}
		p->next=t->next;
		t->next=p;
		
	}
}
void deletecir(struct node *p,int pos)
{
	struct node *t;
	if(pos==0&&head!=NULL)
	{
		t=head;
		while(p->next!=head)
		{
			p=p->next;
		}
		p->next=head->next;
		head=head->next;
		delete t;
	}
	else
	{
		for(int i=1;i<pos;i++)
		{
			p=p->next;
		}
		t=p->next;
		p->next=t->next;
		delete t;
	}
}
void displaycir(struct node *p)
{
	cout<<"\nCircular list is \n";
	do
	{
		cout<<p->data<<"\n";
		p=p->next;
	}while(p!=head);
}
int main()
{
	insert(head,1,0);
	insert(head,2,1);
	insert(head,3,2);
	insert(head,4,3);
	createcir(head);
	displaycir(head);
	insert(head,5,4);
	displaycir(head);
	insert(head,100,8);
	displaycir(head);
	deletecir(head,5);
	displaycir(head);
	return 0;
}
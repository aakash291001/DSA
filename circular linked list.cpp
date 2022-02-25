#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
}*head;
void display(struct node *p)
 {
 	cout<<" List is "<<"\n";
 	while(p!=NULL)
 	{
 		cout<<p->data<<"\n";
 		p=p->next;
	 }
 }
  void insert(struct node *t,int ele,int pos)
 {
 	struct node *p;
 	p=new node;
 	p->data=ele;
 	p->next=NULL;
	if(pos==0)
	{
		p->next=head;
		head= p;
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
void createcir(struct node *p)
{
	struct node *last;
	while(p->next!=NULL)
	p=p->next;
	last=p;
	last->next=head;
}
void displaycir(struct node *p)
{
	do
	{
	cout<<p->data<<"\n";
	p=p->next;
	}while(p!=head);
}
int main()
{
	insert(head,2,0);
	insert(head,3,1);
	insert(head,4,2);
	insert(head,5,3);
	createcir(head);
	displaycir(head);
	return 0;
}
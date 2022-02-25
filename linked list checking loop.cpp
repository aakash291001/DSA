#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
}*first;
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
	if(pos==0||first==NULL)
	{
		p->next=first;
		first= p;
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
 int isloop(struct node*p)
{
	struct node *m,*n;
	m=n=p;
	n=n->next->next;
	while(m!=NULL&&n!=NULL&&m!=n)
	{
		m=m->next;
		n=n->next->next;
	}
	return (m!=n?1:0);
}
int main()
{
	insert(first,5,0);
	insert(first,6,1);
	insert(first,7,2);
	insert(first,2,1);
	display(first);
	struct node *p,*q;
	p=new node;
	q=new node;
	q=first;
	p=first;
	p=p->next;
	while(q->next!=NULL)
	{
		q=q->next;
	}
	q->next=p;
	
	int x;
	x=isloop(first);
	if(x==1)
	cout<<"Linear";
	else
	cout<<"Loop";
	return 0;
}
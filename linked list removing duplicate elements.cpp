#include<iostream>
using namespace std;
struct node 
{
	int data;
	struct node *next;
 }*first;
   void create(int A[])
 {
 	struct node *last,*t;
 	first=new node;
 	first->data=A[0];
 	first->next=NULL;
 	last = first;
 	for(int i=1;A[i]!='\0';i++)
 	{
 		t=new node;
 		t->data=A[i];
 		t->next=NULL;
 		last->next=t;
 		last = t;
	 }
 }
 void display(struct node *p)
 {
 	cout<<" List is "<<"\n";
 	while(p!=NULL)
 	{
 		cout<<p->data<<"\n";
 		p=p->next;
	 }
 }
 void Rdup(struct node *p)
 {
 	struct node *q;
 	q=new node;
 	q=p->next;
 	while(q!=NULL)
 	{
 		
 		if(q->data == p->data)
 		{
 			if(q->next!=NULL)
 			{
 			struct node *n;
 			n=new node;
 			n=q;
 			p->next=q->next;
 			q=q->next;
 			delete n;	
			 }
			else{
			 	p->next=NULL;
			 	delete q;
			 	break;
			 }
		 }
		else
		{
			p=q;
 	     	q=q->next;
		}
	 }
 }
 
 int main()
 {
 	int A[]={1,3,5,10,10};
 	create(A);
 	Rdup(first);
 	display(first);
 	return 0;
 }
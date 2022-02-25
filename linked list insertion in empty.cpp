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
 void insert(struct node *t,int ele,int pos)
 {
 	struct node *p;
 	p=new node;
 	p->data=ele;
	if(pos==0)
	{
		p->next=first;
		first = p;
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
 int main()
{
	
	
	insert(first,5,0);
	insert(first,6,1);
	insert(first,7,2);
	insert(first,2,1);
	display(first);
	return 0;
}
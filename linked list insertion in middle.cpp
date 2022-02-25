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
 void insert(struct node *t)
 {
 	struct node *p;
 	p=new node;
 	cout<<"Enter node"<<"\n";
 	cin>>p->data;
	cout<<"enter the Position"<<"\n";
	int pos;
	cin>>pos;
	for(int i=1;i<pos;i++) 
	{
		t=t->next;
		}
	p->next=t->next;
	t->next=p;			
 }
 int main()
{
	int A[]={2,23,55,88,91};
	create(A);
	insert(first);
	display(first);
	return 0;
}
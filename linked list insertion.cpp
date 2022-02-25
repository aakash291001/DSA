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
 void insert()
 {
 	struct node *n;
 	n=new node;
 	cout<<"Enter node"<<"\n";
 	cin>>n->data;
 	n->next=first;
 	first=n;
 }
 int main()
{
	int A[]={1,23,2,6,5};
	create(A);
	insert();
	display(first);
	return 0;
}
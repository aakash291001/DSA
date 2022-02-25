#include<iostream>
using namespace std;
struct node 
{
	int data;
	struct node *next;
 }*first,*last;
 void create(int A[])
 {
 	struct node *p,*last;
 	p=new node;
 	p->data=A[0];
 	p->next=NULL;
 	first =p;
 	last = p;
 	for(int i =1;A[i]!='\0';i++)
 	{
 		struct node *t;
 		t = new node;
 		t->data=A[i];
 		t->next=NULL;
 		last->next=t;
 		last = t;
	 }
 }
 void del(struct node *p,int pos)
 {
 	struct node *q;
 	q=NULL;
 	for(int i = 1;i<pos;i++)
 	{
 		q=p;
 		p=p->next;
	 }
	 if(pos!=1)
	 {
	 	q->next=p->next;
	 	delete p;
	 }
	 else 
	 {
	 	first=first->next;
	 	delete p;
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
 int main()
 { int A[]={10,2,33,84,15};
 	create(A);
 	cout<<"Ennter node to be deleted\n";
 	int x;
 	cin>>x;
 	del(first,1);
 	del(first,3);
 	display(first);
 	return 0;
 }
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
 void insert()
 {
 	int x;
 	cout<<"Eneter Element\n";
 	cin>>x;
 	struct node *t;
 	t=new node;
 	t->data=x;
 	t->next=NULL;
 	if(first==NULL)
 	{
 		first=last=t;
	 }
	else
	{
 	last->next=t;	
 	last=t;
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
{
	cout<<"enter the no. of element\n";
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		insert();
	}
	display(first);
	return 0;
}
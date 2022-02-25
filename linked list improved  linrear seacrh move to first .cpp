#include<iostream>
using namespace std;
struct node 
{
	int data;
	struct node *next;
 }*first;
 void lsearch(int e,struct node *p)
 {
     struct node *q;
 		q=NULL;
 		int count = 0;
 	while(p!=NULL)
 	{count ++;
 	if(p->data==e)
 	{cout<<"Position of element is "<< count<<"\n";
 		if(q!=NULL)
 		{
 			q->next=p->next;
 			p->next=first;
 			first = p;
 			break;
		 }
		 else{
		 cout<<"first Element"<<"\n";
		 break;
		 }
		 
	 }
	else
	{
		q=p;
		p=p->next;
	}	
	 }
 }
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
 	while(p!=NULL)
 	{
 		cout<<p->data<<"\n";
 		p=p->next;
	 }
 }
 int main()
{
	int A[]={1,23,2,6,5};
	create(A);
	int x;
	lsearch(23,first);
	lsearch(2,first);
	display(first);	
	return 0;
}
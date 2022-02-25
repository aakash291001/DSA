#include<iostream>
using namespace std;
struct node
{
	struct node *prev;
	int data;
	struct node *next;
}*first;
void createD(int A[])
{
	struct node *last;
	last=new node;
    first->data=A[0];
	first->prev=NULL;
	first->next=NULL;
	last = first;
	for(int i = 1;A[i]!='\0';i++)
	{
		struct node *t;
		t=new node;
		t->data=A[i];
		t->prev=last;
		t->next=last->next;
		last->next=t;
		last=t;
	}
}
void display(struct node *p)
{
	cout<<"the list is \n";
	while(p!=NULL)
	{
		cout<<p->data<<"\n";
		p=p->next;
	}
}
int main()
{
	int A[]={1,10,12,34};
	first=new node;
	createD(A);
	display(first);
	return 0;
}
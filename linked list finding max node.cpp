#include<iostream>
using namespace std;
struct node 
{
	int data;
	struct node *next;
}*first;
int max2(struct node *p)//using recursive function//
{
	int temp = -32768;
	if(p==0)
	{
		return temp;
	}
	else 
	{
		temp = max2(p->next);
		if(temp>p->data)
		return temp;
		else 
		return p->data;
	}
}
void max(struct node *p)//using iteration//
{
	int temp;
	temp = first->data;
	while(p!=NULL)
	{
		if(p->data>temp)
		temp=p->data;
		p=p->next;
	}
	cout<<"Maximum element is "<<temp;
}
void create(int A[])
{
	struct node *last,*t;
	first = new node;
	first->data = A[0];
	first->next = NULL;
	last = first;
	for(int i =1;A[i]!='\0';i++)
	{
		t=new node;
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
    }
    
}
int main()
{
	cout<<"enter the elements of linked list";
	int A[100];
	for(int i=0;i<=10;i++)
	{
		cin>>A[i];
	}
	create(A);
	int x;
	x=max2(first);
	cout<<x;
	return 0;
}
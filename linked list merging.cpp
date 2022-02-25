#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next; 
};
void create(int A[],struct node *first)
{
    struct node *last1,*t;
    first->data = A[0];
    first->next = NULL;
    last1 = first;
    for(int i =1;A[i]!='\0';i++)
    {
        t=new node;
        t->data = A[i];
        t->next = NULL;
        last1->next=t;
        last1 = t;
    }
}
void display(struct node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}
void merge(struct node *first,struct node *second,struct node *third)
{
	struct node *last;
	if(first->data<second->data)
	{
		third=first;
		last=third;
		first=first->next;
		last->next=NULL;
	}
	else
	{
		third=second;
		last=third;
		second=second->next;
		last->next=NULL;
	}
	while(first!=NULL&&second!=NULL)
	{
		if(first->data<second->data)
		{
			last->next=first;
			last=first;
			first=first->next;
			last->next=NULL;
		}
		else if(first->data>second->data)
		{
			last->next=second;
			last=second;
			second=second->next;
			last->next=NULL;
		}
		else if(first->data==second->data)
		{
			last->next=second;
			last=second;
			second=second->next;
			first=first->next;
			last->next=NULL;
		}
	}
	display(third);
}
int main()
{
	int A[]={2,3,5,6,9};
	int B[]={1,2,4,7};
	struct node *first,*second;
	first = new node;
	second = new node;
	create(A,first);
	create(B,second);
	display(first);
	display(second);
	struct node *third;
	third = new node;
	merge(first,second,third);
	return 0;
}
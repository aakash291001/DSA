#include<iostream>
using namespace std;
struct node 
{
    int data;
    struct node * next;
};
void display(struct node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}
void create(int A[],int n,struct node *first)
{
    struct node *last,*t;
    first = new node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(int i =1;i<n;i++)
    {
        t=new node;
        t->data = A[i];
        t->next = NULL;
        last->next=t;
        last = t;
    }
    display(first);
}
void concat(struct node *first,struct node *second)
{
	struct node *p,*s;
	p=first;
	while(p!=NULL)
	{
		p=p->next;
	}
	p->next=second;
	display(first);
}
int main()
{
    int A[6]= {1,2,3,4,5,6};
    int B[]={7,8,9,10,11,12};
    struct node *first,*second;
    create(A,6,first);
    create(B,6,second);
    
    return 0;
}

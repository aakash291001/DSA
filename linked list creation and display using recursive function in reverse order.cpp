#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
void display(struct node *p)
{
    if(p!=NULL)
    {
    	display(p->next);
        cout<<p->data;
    }
}
void create(int A[],int n)
{
    struct node *first,*last,*t;
    first = new node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(int i=1;i<n;i++)
    {
        t=new node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    display(first);
}
int main()
{
    int A[6]={1,2,3,4,5,6};
    create(A,6);
    return 0;
}

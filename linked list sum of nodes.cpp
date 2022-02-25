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
int count(struct node *p)
{
    if(p==0)
    return 0;
    else
    return count(p->next)+1;
}
int sum(struct node *p)
{
	if(p==0)
	return 0;
	else
	{
		return sum(p->next)+p->data;
	}
}
void create(int A[])
{
    struct node *first,*last,*t;
    first = new node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(int i =1;A[i]!='\0';i++)
    {
        t=new node;
        t->data = A[i];
        t->next = NULL;
        last->next=t;
        last = t;
    }
    int x;
    x=sum(first);
   cout<<"sum = "<<" "<<x;
}
int main()
{
    int A[]= {1,2,3,4,5,6,7,8,9,10,11};
    create(A);
    return 0;
}

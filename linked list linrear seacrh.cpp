#include<iostream>
using namespace std;
struct node 
{
	int data;
	struct node *next;
 }*first;
 int Lsearch(struct node *p,int n)
 { int count=0;
 int temp=0;
 	while(p!=NULL)
 	{
 		count++;
 		if(p->data==n)
 		{
 			temp = count;
 			break;
		 }
 		{
 			p=p->next;
		 }
	 }
	 return temp; 
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
int main()
{
	int A[]={1,23,2,6,5};
	create(A);
	int i;
	int p =23;
	i=Lsearch(first,p);
	cout<<i;
	return 0;
}
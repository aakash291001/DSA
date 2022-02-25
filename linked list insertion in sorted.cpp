#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
}*first;
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
 	cout<<" List is "<<"\n";
 	while(p!=NULL)
 	{
 		cout<<p->data<<"\n";
 		p=p->next;
	 }
 }
 void Sinsert(struct node *p,int x)
 {
 	int n;
 	struct node *t,*q;
 	if(p==NULL)
 	{
 	q=new node;
 	q->data=x;
 	q->next=NULL;
 	p=q;
	 }
	else
	{
	 q=NULL;
 	t=new node;
 	t->data=x;
 	while(p!=NULL&&p->data<t->data)
 	{
 		q=p;
 		p=p->next;
	 }
	 if(q==NULL)
	 {
	 	t->next=first;
	 	first=t;
	 }
	 else 
	 {
	 t->next=q->next;
	 q->next=t;
	 }	
	 }
 }
 void insert(int *arr,int n)
{
	for(int i =0;i<n;i++)
	{
		cin>>arr[i];
	}
}
int main()
{
	cout<<"Enter the size of array";
 	int n;
 	cin>>n;
 	cout<<"Enter the elements of array\n";
 	int *arr;
 	arr=(int*)malloc(n*sizeof(int));
 	insert(arr,n);
	create(arr);
	cout<<"Enter the elment to be inserted\n";
	int p;
	cin>>p;
	Sinsert(first,p);	
	display(first);
	return 0;
}
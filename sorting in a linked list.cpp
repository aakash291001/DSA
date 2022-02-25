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
  void display(struct node *p)
 {
 	cout<<" List is "<<"\n";
 	while(p!=NULL)
 	{
 		cout<<p->data<<"\n";
 		p=p->next;
	 }
 }
 void sort(struct node *p)
 {
 	struct node *q;
 	q=p->next;
 	int count=0;
 	while(q!=NULL)
 	{
 		
 		if(q->data>p->data)
 		{
 			p=q;
 			q=q->next;
 			count++;
		 }
		 else
		 {
		 	cout<<"Not Sorted\n";
		 	break;
		 }
	 }
	 if(count!=0)
	 cout<<"Linked is sorted";
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
 	sort(first);
 	return 0;
 }
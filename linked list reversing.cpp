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
 	cout<<"\nList is "<<"\n";
 	while(p!=NULL)
 	{
 		cout<<p->data<<" ";
 		p=p->next;
	 }
 }
 void reverse(struct node *p)
 {
 	int count=0;
 	int *A;
 	A=new int;
 	while(p!=NULL)
 	{
 		A[count]=p->data;
 		count++;
 		p=p->next;
	 }
	p=first;
	count=count-1;
	while(p!=NULL&&count>=0)
	{
	 p->data=A[count];
		count--;
		p=p->next;
	}
}
int main()
{
	int n;
	do{
		cout<<"\n1. the elements of array"<<"\n2. reversing the array"<<"\n3. displaying a array"<<"\n4. Exit";
	cout<<"\nEnter Choice";
	cin>>n;
	switch(n){
      case 1:
    	{
    	cout<<"\nEnter the number of elements to be inserted in list\n";
      int d;
      cin>>d;
      int A[d];
      cout<<"\nEnter the elements\n";
      for(int i=0;i<d;i++)
      {
      	cin>>A[i];
	  }
	  create(A);
      break;	
		}
      case 2:
      reverse(first);
      break;
      case 3:
      display(first);
      case 4:
    break;
      default:
      cout<<"Enter a valid Choice";
  	}
	}while(n!=4);
	
	return 0;
}
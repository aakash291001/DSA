#include<bits/stdc++.h>
using namespace std;
class node
{
	public:
	int data;
	node *next;
};
void insertAtTail(node* &head,int val)
{
	node *n = new node;
	n->data = val;
	n->next = NULL;
	if(head==NULL)
	{
		head = n;
		return;
	}
	node *temp = head;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next = n;
}
void insertAtHead(node* &head,int val)
{
	node *n = new node;
	n->data = val;
	n->next = NULL;
	if(head==NULL)
	{
		head=n;
		return;
	}
	else
	{
		node *temp;
		temp = head;
		n->next=head;
		head = n;
	}
}
void display(node *head)
{
	if(head==NULL)
	{
		cout<<"List is empty";
	}
	else
	{
		node *temp= head;
		while(temp!=NULL)
		{
			cout<<temp->data;
			cout<<" ";
			temp = temp->next;
		}
	}
}
//int lenghtOfll(node *head)
//{
//	node *temp;
//	temp = head;
//	int count=0;
//	while(temp!=NULL)
//	{
//		count++;
//		temp=temp->next;
//	}
//	return count;
//}
void revLl(node* &head)
{
	if(head==NULL)
	{
		return;
	}
	else
	{
		node *n,*p,*c;
		p = head;
		c = p->next;
		n = c->next;
		while(n)
		{
			c->next=p;
			p = c;
			c = n;
			n = n->next;
		}
		c->next = p;
		head->next=NULL;
		head = c;
	}
}
node* revLl2(node* &head)
{
	if(head==NULL||head->next==NULL)
	{
		return head;
	}
	node *temp = revLl2(head->next);
	head->next->next = head;
	head->next = NULL;
	return temp;
}
int main()
{
	node *head;
	int A[] = {1,23,2,6,5};
	int n = sizeof(A)/sizeof(int);
	for(int i=0;i<n;i++)
	{
		insertAtTail(head,A[i]);
	}
	head = revLl2(head);
	
	display(head);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
class node
{
	public:
		int data;
		node *next;
	node(int val)
    {
        data = val;
        next = NULL;
    }
};
void insertAtTail(node* &head,int val)
{
	node *t = new node(val);
	if(head==NULL)
	{
		head = t;
		return;
	}
	else
	{
		node *temp = head;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = t;
	}
}
void display(node *head)
{
	node *temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<"\n";
}
node* merge(node* &l1,node* &l2)
{
	if(l1==NULL)
	return l2;
	if(l2==NULL)
	return l1;
	node *f,*s,*ans;
	if(l1->data<=l2->data)
	{
		f = l1;
		s = l2;
		ans = l1;
	}
	else
	{
		f = l2;
		s = l1;
		ans = l2;
	}
	while(f!=NULL&&s!=NULL)
	{
		node *temp;
		while(f!=NULL&&f->data<=s->data)
		{
			temp = f;
			f = f->next;
		}
		temp->next = s;
		node *temp2;
		temp2 =s;
		s=f;
		f = temp2;
	}
	return ans;
}
int main()
{
	node *head1,*head2;
	head1 = NULL;
	head2 = NULL;
	insertAtTail(head1,1);
	insertAtTail(head1,2);
	insertAtTail(head1,4);
	insertAtTail(head2,1);
	insertAtTail(head2,3);
	insertAtTail(head2,4);
	display(head1);
	display(head2);
	node *ans = merge(head1,head2);
	display(ans);
	return 0;
}
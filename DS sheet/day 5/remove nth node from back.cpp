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
    node* n = new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}
void display(node *head)
{
    node *temp= head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}
int llLength(node *head)
{
	if(head==NULL)
	return 0;
	else
	{
		int count=0;
		while(head!=NULL)
		{
			count++;
			head=head->next;
		}
		return count;
	}
}
void remNthBack(node* &head,int n)
{
	int l = llLength(head);
	if(l<n)
	{
		cout<<"n is greater than length of the linked list\n";
		return;
	}
	else
	{
		int i = l-n+1;
		if(i==1)
		{
			node *rem = head;
			head = head->next;
			delete rem;
		}
		else
		{
			node *prev = NULL;
			node *rem = head;
			for(int j = 1;j<i;j++)
			{
				prev = rem;
				rem = rem->next;
			}
			prev->next = rem->next;
			delete rem;
		}
	}
}
int main()
{
    node *head1=NULL;
    insertAtTail(head1,4);
    insertAtTail(head1,3);
    insertAtTail(head1,2);
    insertAtTail(head1,1);
    display(head1);
    remNthBack(head1,3);
    display(head1);
    return 0;
}
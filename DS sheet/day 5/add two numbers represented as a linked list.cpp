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
    node *n = new node(val);
    // n->data = val;
    // n->next = NULL;
    if(head==NULL)
    {
        head = n;
    }
    else
    {
        node *t = head;
        while(t->next!=NULL)
        {
            t = t->next;
        }
        t->next = n;
    }
}
void display(node *head)
{
    if(head==NULL)
    {
        cout<<"List is empty\n";
        return;
    }
    else
    {
        node *t = head;
        while(t!=NULL)
        {
            cout<<t->data<<" ";
            t = t->next;
        }
        cout<<"\n";
    }
}
void sum(node *l1,node *l2,node* &ans)
{
    int carry=0;
    while(l1!=NULL&&l2!=NULL)
    {
        int sum = l1->data+l2->data+carry;
        if(sum<=9)
        {
            insertAtTail(ans,sum);
            carry =0;
        }
        else
        {
            int t = sum%10;
            carry  = sum/10;
            insertAtTail(ans,t);
        }
        l1=l1->next;
        l2 = l2->next;
    }
    while(l1!=NULL)
    {
        int sum = l1->data+carry;
        if(sum<=9)
        {
            insertAtTail(ans,sum);
            carry =0;
        }
        else
        {
            int t = sum%10;
            carry  = sum/10;
            insertAtTail(ans,t);
        }
        l1 = l1->next;
    }
    while(l2!=NULL)
    {
        int sum = l2->data+carry;
        if(sum<=9)
        {
            insertAtTail(ans,sum);
            carry =0;
        }
        else
        {
            int t = sum%10;
            carry  = sum/10;
            insertAtTail(ans,t);
        }
        l2 = l2->next;
    }
    while(carry>0)
    {
        int t = carry%10;
        carry = carry/10;
        insertAtTail(ans,t);
    }
}
int main()
{
    int num1 = 9999999;
    int num2 = 9999;
    node *l1 = NULL;
    node *l2 = NULL;
    while(num1>0)
    {
        int t = num1%10;
        num1 = num1/10;
        insertAtTail(l1,t);
    }
    while(num2>0)
    {
        int t = num2%10;
        num2 = num2/10;
        insertAtTail(l2,t);
    }
    display(l1);
    display(l2);
    node *ans = NULL;
    sum(l1,l2,ans);
    display(ans);
    return 0;
}
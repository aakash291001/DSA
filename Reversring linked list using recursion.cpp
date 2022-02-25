
#include<iostream>
using namespace std;
class node
{
  public:
    int data;
    struct node *next;
};
class link
{
  // private:
  //   node *head,*tail;
  public:
   node *head,*tail;
    link()
    {
      head = NULL;
      tail = NULL;
    }
    void push(int x);
    void display();
    void del();
    void reverse(node *R,node *P);
};
void link::push(int x)
{
  node *temp;
  temp = new node;
  if(temp == NULL)
  {
    cout<<"Linked list is full";
  }
  if(head == NULL)
  {
    temp->data = x;
    temp->next=NULL;
    head = tail = temp;
  }
  else
  {
    temp->data = x;
    temp->next=head;
    head=temp;
  }
}
void link::display()
{
  node *temp;
  if(head==NULL)
  {
    cout<<"Linked list is empty\n";
  }
  else
  {
    temp=head;
    while(temp!=NULL)
    {
      cout<<temp->data<<"\n";
      temp=temp->next;
    }
  }
}
void link::del()
{
  if(head==NULL)
  {
    cout<<"\nThere is nothinng to delete\n";
  }
  else
  {
    node *temp;
    temp = head;
    head = head->next;
    delete temp;
  }
}
void link::reverse(node *R,node *P)
{
  if(P==NULL)
  {
    node *temp;
    temp=new node;
    temp=head;
    head = tail;
    tail = temp;
  }
  else{
    if(R==head)
    {
      R->next=NULL;
    }
    node *Q;
    Q=new node;
    Q=P;
    P=Q->next;
    Q->next=R;
    reverse(Q,P);
  }
}
int main()
{
  link l1;
  l1.push(4);
  l1.push(3);
  l1.push(2);
  l1.push(1);
  l1.push(0);
  l1.display();
  l1.reverse(l1.head,l1.head->next);
  l1.display();
  return 0;
}
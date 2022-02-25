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
  private:
    node *head;
  public:
    link()
    {
      head = NULL;
    }
    void push(int x);
    void display();
    void del();
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
    head = temp;
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
int main()
{
  link l1;
  l1.push(5);
  l1.push(7);
  l1.del();
  l1.del();
  l1.display();
  return 0;
}
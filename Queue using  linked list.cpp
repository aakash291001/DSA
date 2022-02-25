#include<iostream>
using namespace std;
struct node
{
  int data;
  struct node *next;
}*front,*rear;
void enqueue(int x)
{
  struct node *temp;
  temp=new node;
  if(temp==NULL)
  {
    cout<<"Queue is full\n";
  }
  else
  {
    temp->data=x;
    temp->next=NULL;
    if(front==NULL)
    {
      front = temp;
      rear=temp;
    }
    else
    {
      rear->next=temp;
      rear=temp;
    }
  }
}
void dequeue()
{
  if(front==NULL)
  {
    cout<<"Queue is empty";
  }
  else
  {
    struct node *t;
    t=new node;
    t=front;
    front=front->next;
    delete t;
  }
}
void display()
{
  if(front==NULL)
  {
    cout<<"Queue is empty\n";
  }
  else
  {
    struct node *temp;
    temp=front;
    while(temp!=NULL)
    {
    cout<<temp->data<<"\n";
    temp=temp->next;
    }
  }
}
int main()
{
  enqueue(8);
  enqueue(10);
  enqueue(13);
  enqueue(20);
  enqueue(30);
  display();
  cout<<"After deletion\n";
  dequeue();
  display();
  return 0;
}
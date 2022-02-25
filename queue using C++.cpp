#include<iostream>
using namespace std;
class node
{
	public:
	int data;
	class node *next; 
};
class queue
{
	private:
		class node *front;
		class node *rear;
	public:
		queue()
		{
			front = NULL;
			rear = NULL;
		}
		void enqueue(int x)
{
  class node *temp;
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
		void display()
{
  if(front==NULL)
  {
    cout<<"Queue is empty\n";
  }
  else
  {
    class node *temp;
    temp=front;
    while(temp!=NULL)
    {
    cout<<temp->data<<"\n";
    temp=temp->next;
    }
  }
}
 void dequeue()
 {
 	class node *t;
 	t= new node;
 	t=front;
 	front = front->next;
 	delete t;
 }
};
int main()
{
	class queue Q1;
	Q1.enqueue(1);
	Q1.enqueue(2);
	Q1.enqueue(5);
	Q1.display();
	cout<<"\nAfter deletion\n";
	Q1.dequeue();
	Q1.display();
	return 0;
}
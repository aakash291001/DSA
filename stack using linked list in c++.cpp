#include<iostream>
using namespace std;
class node 
{
	public:
	int data;
	node *next;
};
class stack
{
	private:
		node *top;
	public:
		stack(){
			top=NULL;
		}
		void push(int);
		void pop();
		void display();
		void peek(int);
		int sizeofstack();
}s1;
void stack::push(int x)
{
	node *temp;
	temp = new node;
	if(temp==NULL)
	{
		printf("\nStack overflow\n");
		exit(1);
	}
	else
	{
		temp->data=x;
		temp->next=top;
		top=temp;
	}
}
void stack::display()
{
	node *temp;
	temp=top;
	if(top==NULL)
	{
		printf("\nStack is empty\n");
	}
	else
	{
		printf("Stack Elements are\n");
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);		
			temp=temp->next;
		}
		
	}
}
void stack::pop()
{
	node *temp;
	temp = top;
	if(top==NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		top=top->next;
		delete temp;	
	}
	
}
void stack::peek(int pos)
{
	node *temp;
	temp = top;
	if(top==NULL)
	{
		printf("stack is empty\n");
	}
	else if(pos<=sizeofstack())
	{
		for(int i = 1;i<pos;i++)
		{
			temp=temp->next;
		}
		printf("%d is present at %d index",temp->data,pos);
	}
	else if(pos>sizeofstack())
	{
		printf("the index you entered is incorrect\n ");
	}
}
int stack::sizeofstack()
{
	struct node *temp;
	int count=0;
	temp = top;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}
int main()	
{
	s1.push(4);
	s1.push(5);
	s1.push(6);
	s1.push(7);
	s1.push(8);
	s1.display();
	s1.pop();
	s1.display();
	s1.peek(3);
	return 0;
}
#include<iostream>
#include<string>//Stack uses LIFO (last in first out)//
using namespace std;
struct node
{
	int data;
	struct node *next;
};
struct node *top;
void push(int x)//For entering element//
{
	struct node *temp;
	temp = new node;
	if(temp==NULL)
	{
		printf("Stack overflow");
		exit(1);
	}
	temp->data=x;
	temp->next=top;
	top = temp;
}
void display()
{
	struct node *temp;
	temp=top;
	if(top==NULL)
	{
		printf("stack is empty\n");
	}
	else
	{
		printf("Stack is\n");
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}	
	}
}
int pop()//For deleting element//
{
	struct node *temp;
	temp=top;
	if(top==NULL)
	{
		printf("Stack is empty\n");
		return 0;
	}
	else
	{
	top=top->next;
	delete temp;	
	return 1;
	}
}
int size()
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
void peek(int pos)
{
	struct node *temp;
	temp = top;
	if(pos>size())
	{
		printf("\nIncorrect position\n");
	}
	else
	{
	for(int i = 1;i<pos;i++)
	{
		temp=temp->next;
	}
	printf("\nThe element at %d position is %d",pos,temp->data);	
	}
	
}
int main()
{
//	push(100);
//	push(200);
//	push(300);
//	push(400);
//	pop();
//	display();
	string str;
	cin>>str;
	int l;
	l = str.length();
	for(int i=0;i<l;i++)
	{
		if(str[i]=='a')
		push(0);
	}
	cout<<size();
	return 0;
}
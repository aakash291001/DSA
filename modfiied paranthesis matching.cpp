#include<iostream>
using namespace std;
class node
{
	public:
		char data;
		node *next;
};
class stack
{
	private: 
	node *top;
	public:
		stack()
		{
			top==NULL;
		}
		void push(char);
		void pop();
		int ifempty();
};
void stack::push(char x)
{
	node *temp;
	temp= new node;
	if(temp==NULL)
	{
		printf("stack overflow\n");
	}
	else
	{
		temp->data=x;
		temp->next=top;
		top=temp;
	}
}
void stack::pop()
{
	node *temp;
	temp=top;
	if(top==NULL)
	printf("stack is empty\n");
	else
	{
	
	top=top->next;
	delete temp;
}
}
int stack::ifempty()
{
	if(top==NULL)
	{
		return 1;
	}
	else 
	return 0;
}
void isbalanced(char *exp)
{
	stack s1;
	for(int i = 0;exp[i]!='\0';i++)
	{
		if(exp[i]=='(')
		s1.push('(');
		else
		{
			if(exp[i]==')'&&s1.ifempty())
			{
			printf("there is an mismatch\n");
			exit(1);
			}
			else if(exp[i]==')'&&!s1.ifempty())
			{
				s1.pop();
			}
		
		}
	}
	if(s1.ifempty())
	printf("No error");
	
}
int main()
{
	char *exp;
	exp="(a+b(bs)";
	isbalanced(exp);
	return 0;
}
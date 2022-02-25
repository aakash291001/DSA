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
		void peek(int);
		int sizeofstack();
		void display();
		int ifempty();
};
void stack::push(int x)
{
	node *temp;
	temp = new node;
	if(temp==NULL)
	{
		printf("Stack overflow\n");
		exit(1);
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
	{
		printf("Stack is empty\n");
	}
	else
	{
		top=top->next;
		delete temp;
	}
}
int stack::sizeofstack()
{
	int count=0;
	node *temp;
	temp=top;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}
void stack::peek(int pos)
{
	node *temp;
	temp=top;
	if(top==NULL)
	{
		printf("Stack is Empty\n");
	}
	else if(pos<=sizeofstack())
	{
		for(int i =1;i<pos;i++)
		temp=temp->next;
		printf("%d is present at %d index\n",temp->data,pos);
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
int stack::ifempty()
{
	if(top==NULL)
	{
	return 1;
	}
	else 
	return 0; 
}
int main()
{
	stack s1;
	char str[100];
	cout<<"\nEnter the paranthesis experession\n";
	cin>>str;
	int i=0;
	while(str[i]!='\0')
	{
		if(str[i]=='(')
		{
			s1.push(1);
			i++;
		}
		else if(str[i]==')'&&!s1.ifempty())
		{
			s1.pop();
			i++;
		}
		else if(str[i]==')'&&s1.ifempty())
		{
			printf("there is an error\n");
			goto jump;
		}
	}
	if(s1.ifempty())
	printf("there is no error\n");
	else
	printf("there is an error\n");	
	jump:
	return 0;
}
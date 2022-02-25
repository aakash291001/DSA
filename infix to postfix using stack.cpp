#include<iostream>
using namespace std;
struct node
{
	char data;
	struct node *next;
};
struct node *top;
void push(char x)
{
	struct node *temp;
	temp=new node;
	if(temp==NULL)
	{
		printf("stack is overloaded\n");
	}
	else
	{
		temp->data=x;
		temp->next=top;
		top=temp;
	}
}
void display()
{
  struct node *temp;
	temp=top;
	if(temp==NULL)
	{
		printf("\nStack is empty\n");
	}
	else
	{
		printf("Stack Elements are\n");
		while(temp!=NULL)
		{
			printf("%c\n",temp->data);		
			temp=temp->next;
		}
		
	}
}
char pop()
{
	char x;
	struct node *temp;
	if(top!=NULL)
	{
		temp=top;
		x=top->data;
		top=top->next;
		delete temp;
		return x;
	}
	else
	{
		printf("Stack is empty\n");
	}
}
int priority_check( char x)
{
	if(x=='+'||x=='-')
	{
		return 1;
	}
	else if(x=='*'||x=='/')
	{
		return 2;
	}
}
void check_str(char *str)
{
	char x;
	int i=0;
	struct node *temp;
	temp=top;
	while(str[i]!='\0')
	{
		if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
		{
			if(str[i]=='*'||str[i]=='/')
			{
				int x;
				if(top!=NULL)
				{
				  x=priority_check(top->data);
				  if(x==2)
				  { char y;
				  	y=pop();
						printf("%c",y);
				  }
				}
				push(str[i]);
				i++;
			}
			else if(str[i]=='-'||str[i]=='+')
			{
				if(top!=NULL)
				{
					while(top!=NULL)
					{
						x=pop();
						printf("%c",x);
					}
					push(str[i]);
					i++;
				}
				else
				{
					push(str[i]);
					i++;
			    }
				
			}
		}
		else
		{
			printf("%c",str[i]);
			i++;
		}
	}
		while(top!=NULL)
					{
						x=pop();
						printf("%c",x);
					}
}
int main()
{
	char str[]="a/b/c-d";
	check_str(str);
	return 0;
}
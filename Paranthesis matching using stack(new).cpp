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
		printf("Stack is overloaded\n");
		exit(1);
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
int match(char x,char str)
{
  if(x=='('&&str==')')
  return 0;
  else if(x=='{'&&str=='}')
  return 0;
  else if(x=='['&&str==']')
  return 0;
  else
  return 1;
}
void pop(char str)
{
  struct node *temp;
  char x;int y;
  if(top==NULL)
  {
    printf("stack is empty\n");
  }
  else
  {
    x=top->data;
    y=match(x,str);
    if(y==0)
    {
      temp=top;
      top=top->next;
      delete temp;
    }
    else if(y==1)
    {
      printf("incorrect Expression\n");
    }
  }
}

void match1()
{
  if(top==NULL)
  printf("correct Expression\n");
  else
  printf("incorrect Expression\n");
}
void insert(char *str)
{
	int i=0;
	while(str[i]!='\0') 
	{
		if(str[i]=='('||str[i]=='{'||str[i]=='[')
		push(str[i]);
		else if(str[i]==')'||str[i]=='}'||str[i]==']')
		pop(str[i]);
		i++;
	}
}
int main()
{
  char x[]="({{}})";
	insert(x);
	match1();
	display();
	return 0;
}
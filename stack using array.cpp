#include<iostream>
using namespace std;
struct stack 
{
	int size;
	int top;
	int *S;
};
void create(struct stack *st)
{
	printf("\nEnter Size\n");
	scanf("%d",&st->size);
	st->top=-1;
	st->S=(int*)malloc(st->size*sizeof(int));
	
}
void display(struct stack *st)//It will display from the top//
{
	for (int i = st->top;i>=0;i--)
	{
		printf("%d\n",st->S[i]);
	}
}
int iffull(struct stack *st)
{
	if(st->top==(st->size-1))
	{
		printf("\nStack is full\n");
		return 1;
	}
	else 
	return 0; 
}
int ifempty(struct stack *st)
{
	if(st->top==-1)
	{
		printf("\nStack is Empty\n");
		return 1;
	}
	else 
	return 0;
}
void push(struct stack *st,int data)
{
	if(!iffull(st))
	{
		++st->top;
		st->S[st->top]=data;
	}
}
void pop(struct stack *st)
{
	if(!ifempty(st))
	{
		st->top--;
	}
}
void peek(struct stack *st,int pos)
{
	if((pos-1)<=st->top)
	{
		printf("%d is the stack element at %d position",st->S[pos-1],pos); 
	}
	else
	printf("\nThis index is wrong\n");
}
int main()
{
	struct stack st;
	create(&st);
	push(&st,0);
	push(&st,1);
	push(&st,2);
	push(&st,3);
	push(&st,4);
	peek(&st,3);
	
	return 0;
}
#include<iostream>
using namespace std;
class node
{
	public:
		node *lchild;
		int data;
		node *rchild;
};
class stack
{
	private:
	int size;
	int top;
	node **s;
	public:
		void Screate();
		void push(node *p);
		node* pop();
		int isempty();
};
void stack::Screate()
{

	size =100;
	top=-1;
	s=(node**)malloc(size*sizeof(node**));
}
void stack::push(node *p)
{
	if(!(top == size-1))
	{
		++top;
		s[top]=p;
	}
}
node* stack::pop()
{
	if(!(top==-1))
	{
		return(s[top--]);
	}
}
int stack::isempty()
{
	return top==-1;
}

class queue
{
	private:
	int front;
	int rear;
	int size;
	node **q;
	public:
		void Qcreate(int n)
		{
			size =n;
			front =rear = 0;
			q= (node**)malloc(n*sizeof(node**));
		}
		void enqueue(node *x)
		{
			if(rear==(size-1))
			{
				cout<<"Queue is full\n";
			}
			else
			{
				rear++;
				q[rear]=x;
			}
		}
		node* dequeue()
		{
			node *x;
			if(rear==front)
			{
				cout<<"queue is empty\n";
			}
			else
			{
			front++;
			x= q[front];	
			}
			return x;
		}
		int isempty()
		{
			return front==rear;
		}
};
class tree
{
	public:
		node *root;
		tree()
		{
			root = NULL;
		}
		void create();
		void preorder(node *p);
		void inorder(node *p);
		void postorder(node *p);
};
void tree::create()
{
	node *p,*t;
	int x;
	root = new node;
	cin>>x;
	root->data=x;
	root->lchild=NULL;
	root->rchild=NULL;
	queue q;
	q.Qcreate(100);
	q.enqueue(root);
	while(!q.isempty())
	{
		p=q.dequeue();
		cout<<"\nEnter left child of "<<p->data<<" ";
		cin>>x;
		if(x!=-1)
		{
			t=new node;
			t->data=x;
			t->lchild=t->rchild=NULL;
			q.enqueue(t);
			p->lchild=t;	
		}
		cout<<"\nEnter right child of "<<p->data<<" ";
		cin>>x;
		if(x!=-1)
		{
			t = new node;
			t->data = x;
			t->lchild=t->rchild=NULL;
			q.enqueue(t);
			p->rchild = t;
		}
	}
}
void tree::preorder(node *p)
{
	stack s;
	s.Screate();
	while(p!=NULL||!s.isempty())
	{
		if(p!=NULL)
		{
			cout<<p->data;
			s.push(p);
			p=p->lchild;
		}
		else
		{
			p=s.pop();
			p=p->rchild;
		}
	}
}
void tree::inorder(node *p)
{
	if(p)
	{
		inorder(p->lchild);
		cout<<p->data<<" ";
		inorder(p->rchild); 
	}
}
void tree::postorder(node *p)
{
	if(p)
	{
		postorder(p->lchild);
		postorder(p->rchild); 
		cout<<p->data<<" ";
		
	}
}
int main()
{
	tree t; 
	t.create(); 
	cout<<"\nIn preorder";
	t.preorder(t.root);
	cout<<"\nIn Inorder";
	t.inorder(t.root);
	cout<<"\nIn Postorder";
	t.postorder(t.root);
	
	return 0;
}
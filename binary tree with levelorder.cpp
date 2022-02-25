#include<iostream>
using namespace std;
class node
{
	public:
   node *lchild;
	int data;
  node *rchild;
};
node *root=NULL;
class queue
{
	private:
		int size;
		int front;
		int rear;
		node **Q;
	public:
		void createQ(int n)
		{
			size = n;
			front = rear=0;
			Q=(node**)malloc(size*sizeof(node**));
		}
		void enqueue(node *x)
		{
			if(rear == size-1)
			{
				cout<<"\nQueue is full\n";
			}
			else
			{
				rear++;
				Q[rear]=x;
			}
		}
		node* dequeue()
		{
			node *x;
			if(front == rear)
			{
				cout<<"\nqueue is empty";
			}
			else
			{
				front++;
				x=Q[front];
			}
			return x;
		}
		int isEmpty()
		{
			return front == rear;
		}
};
class tree
{
	public:
		node *root;
		tree()
		{
			root=NULL;
		}
		void create();
		void preorder(node *p);
		void inorder(node *p);
		void postorder(node *p);
		void levelorder(node *p);
};
void tree::create()
	{
	node *p,*t;
	int x;
	queue Q;
	Q.createQ(100);
	cout<<"\nEnter the root value\n";
	cin>>x;
	root = new node;
	root->data=x;
	root->lchild=root->rchild=NULL;
	Q.enqueue(root);
	while(!Q.isEmpty())
	{
		p = Q.dequeue();
		cout<<"\nEnter left child of"<<p->data;
		cin>>x;
		if(x!=-1)
		{
			t=new node;
			t->data=x;
			t->lchild=t->rchild=NULL;
			Q.enqueue(t);
			p->lchild=t;
		}
		cout<<"\nEnter right  child of"<<p->data;
		cin>>x;
		if(x!=-1)
		{
			t=new node;
			t->data=x;
			t->lchild=t->rchild=NULL;
			Q.enqueue(t);
			p->rchild=t;
		}	
	}	
}
void tree::preorder(node *p)
{
	if(p)
	{
		cout<<p->data<<" ";
		preorder(p->lchild);
		preorder(p->rchild); 
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
void tree::levelorder(node *p)
{
  queue Q;
  Q.createQ(100);
  Q.enqueue(p);
  node *t;
  t=new node;
  while(!Q.isEmpty())
  {
   t=Q.dequeue();
   cout<<t->data<<" ";
   if(t->lchild!=NULL)
   Q.enqueue(t->lchild);
   if(t->rchild!=NULL)
   Q.enqueue(t->rchild);
  }
}
int main()
{
	tree t; 
	t.create(); 
	cout<<"\nIn preorder";
	t.preorder(t.root);
	cout<<"\nIn inorder";
	t.inorder(t.root);
	cout<<"\nIn Postorder";
	t.postorder(t.root);
	cout<<"\nLevel order";
	t.levelorder(t.root);
	return 0;
}
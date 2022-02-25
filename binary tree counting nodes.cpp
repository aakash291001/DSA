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
			root = NULL;
		}
		void Tcreate();
		void preorder(node *p);
		void inorder(node *p);
		void postorder(node *p);
		void levelorder(node *p);
		int countnode(node *p)
		{
			int x=0,y=0;
			if(p!=NULL)
			{
				x = countnode(p->lchild);
				y = countnode(p->rchild);
				return x+y+1;
			}
			else
			return 0;
		}
		int countleave(node *p)
		{
			int x=0,y=0;
			if(p!=NULL)
			{
				x = countleave(p->lchild);
				y = countleave(p->rchild);
				if(p->lchild==NULL&&p->rchild==NULL)
				return x+y+1;
				else
				return x+y;
			}
			else return 0;
		}
		int sum(node *p)
		{
			int s=0;
			int x=0,y=0;
			if(p!=NULL)
			{
				x = sum(p->lchild);
				y = sum(p->rchild);
				if(p->lchild==NULL&&p->rchild==NULL)
				return p->data;
				else
				return x+y;
			}
			else return 0;
		}
};
void tree::Tcreate()
	{
		node *m,*t;
		m = new node;
		cout<<"Root data\n";
		root = new node;
		cin>>root->data;
		root->lchild=NULL;
		root->rchild=NULL;
		queue Q;
		Q.createQ(100);
		Q.enqueue(root);
		int x;
		while(!Q.isEmpty())
		{
			m=Q.dequeue();
			cout<<"\nEnter left child of"<<m->data<<" ";
			cin>>x;
			if(x!=-1)
			{
				t = new node;
				t->data=x;
				t->lchild=t->rchild=NULL;
				Q.enqueue(t);
				m->lchild=t;
			}
			cout<<"\nEnter right child of "<<m->data<<" ";
			cin>>x;
			if(x!=-1)
			{
				t = new node;
				t->data=x;
				t->lchild=t->rchild=NULL;
				Q.enqueue(t);
				m->rchild=t;
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
	t.Tcreate();
	cout<<"\nIn inorder";
	t.inorder(t.root);
	cout<<"\nIn Postorder";
	t.postorder(t.root);
	cout<<"\nNo. Nodes="<<t.countnode(t.root);
	cout<<"\nNo. Leave Nodes="<<t.countleave(t.root);
	cout<<"\nSum of all nodes="<<t.sum(t.root);
	return 0;
}
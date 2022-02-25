#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node *lchild;
		node *rchild;
};
class queue
{
	private:
		int size;
		int front;
		int rear;
		node **Q;//*Q reperesents array and * reperensent pointer **Q represents array of pointers//
	public:
		void createQ(int n);
		void enqueue(node *n);
		node* dequeue();
		int isempty();
};
void queue::createQ(int n)
{
	size=n;
	front = rear =0;
	Q=(node**)malloc(n*sizeof(node**));
}
void queue::enqueue(node *x)
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
		node* queue::dequeue()
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
		int queue::isempty()
		{
			return front == rear;
		}
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
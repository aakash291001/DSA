#include<iostream>
using namespace std;
class node1
{
	public:
		int data;
		node1 *lchild;
		node1 *rchild;
};
class node2
{
	public:
		node1 *data;
		node2 *next;
};
class que
{
	public:
		node2 *head,*tail;
		que()
		{
			head = tail = 0;
		}
		void enqueue(node1 *p);
		node1 *dequeue();
};
void que::enqueue(node1 *p)
{
	node2 *temp;
	temp = new node2;
	if(temp == NULL)
	{
		cout<<"Queue is full\n";
	}
	else
	{
		temp->data = p;
		temp->next = NULL;
		if(head == NULL)
		{
			head = tail = temp;
		}
		else
		{
			tail->next = temp;
			tail=temp;
		}
	}
}
node1* que::dequeue()
{
	if(head == NULL)
	{
		return NULL;
	}
	else
	{
		node1 *p;
		p = head->data;
		node2 *t;
		t = head;
		head = head->next;
		delete t;
		return p;
	}
}
class tree
{
	public:
		node1 *root;
		tree()
		{
			root = NULL;
		}
		void create();
		void inorder(node1 *p)
		  {
		    if(p!=NULL)
		    {
		    	inorder(p->lchild);
		      cout<<p->data<<" ";
		      inorder(p->rchild);
		    }
		  }
};
void tree::create()
{
	que Q;
	node1 *p,*t;
	int x;
	root = new node1;
	cout<<"Enter root data\n";
	cin>>root->data;
	root->lchild = root->rchild = NULL;
	Q.enqueue(root);
	while(Q.head!= NULL)
	{
		p = Q.dequeue();
		cout<<"Enter the lchild of "<<p->data;
		cin>>x;
		if(x!=-1)
		{
			t = new node1;
			t->data =x;
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			Q.enqueue(t);
		}
		cout<<"Enter the right of "<<p->data;
		cin>>x;
		if(x!=-1)
		{
			t = new node1;
			t->data =x;
			t->rchild = t->rchild = NULL;
			t->rchild = t;
			Q.enqueue(t);
		}
	}
}
int main()
{
	tree t;
  t.create();
  cout<<"\nIn preorder";
	t.inorder(t.root);
  return 0;
}
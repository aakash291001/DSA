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
			head = tail = NULL;
		}
		void enqueue(node1 *p);
		node1* dequeue();	
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
	if(head==NULL)
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
		void range(int l,int h,node1 *p)
		{
			if(p==NULL)
			{
				return;
			}
			else
			{
				if(p->data<l)
				{
					range(l,h,p->rchild);
				}
				if(p->data>h)
				{
					range(l,h,p->lchild);
				}
				if(l<p->data&&p->data<h)
				{
					range(l,h,p->lchild);
					cout<<p->data<<" ";
					range(l,h,p->rchild);
				}
				else
				return;
			}
		}
};
void tree::create()
{
	node1 *p,*t;
	int x;
	que q;
	cout<<"Enter root data\n";
	root = new node1;
	cin>>root->data;
	root->lchild= root->rchild = NULL;
	q.enqueue(root);
	while(q.head!=NULL)
	{
		p=q.dequeue();
		cout<<"enter left child of "<<p->data;
		cin>>x;
		if(x!=-1)
		{
			t=new node1;
			t->data=x;
			t->lchild=t->rchild=0;
			p->lchild = t;
			q.enqueue(t);
		}
		cout<<"enter right child of "<<p->data;
		cin>>x;
		if(x!=-1)
		{
			t=new node1;
			t->data=x;
			t->rchild=t->lchild=0;
			p->rchild = t;
			q.enqueue(t);
		}
	}
}
int main()
{
	tree t;
  	t.create();
  	cout<<"\nIn inorder";
	t.inorder(t.root);
	cout<<"Enter the lower and upper element\n";
	int l,h;
	cin>>l>>h;
	t.range(l,h,t.root);
	return 0;
}
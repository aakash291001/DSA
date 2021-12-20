#include<iostream>
#include<vector>
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
		node1* cBST(int A[],int l,int h)
		{
			if(l>h)
			{
				return NULL;
			}
			else
			{
				node1 *p;
				p = new node1;
				int m;
				m = (l+h)/2;
				p->data = A[m];
				p->lchild=cBST(A,l,m-1);
				p->rchild=cBST(A,m+1,h);
				return p;
			}
		}
};
class isBSTReturn
{
	public:
		bool isBST;
		int minimum;
		int maximum;
	
};
isBSTReturn isBST2(node1 *p)
{
	if(p==NULL)
	{
		isBSTReturn output;
		output.isBST = true;
		output.minimum = INT_MAX;
		output.maximum = INT_MIN;
		return output;
	}
	else
	{
		isBSTReturn le = isBST2(p->lchild);
		isBSTReturn hi = isBST2(p->rchild);
		int minimum = min(p->data,min(le.minimum,hi.minimum));
		int maximum = max(p->data,max(le.maximum,hi.maximum));
		bool final;
		final = (le.isBST&&hi.isBST&&le.maximum<p->data&&hi.minimum>p->data);
		isBSTReturn output;
		output.isBST = final;
		output.minimum = minimum;
		output.maximum = maximum;
		return output;
	}
}
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
bool isBST3(node1 *p,int min,int max)
{
	if(p==NULL)
	return true;
	else
	{
		if(min<p->data&&p->data<max)
		return isBST3(p->lchild,min,p->data)&&isBST3(p->rchild,p->data,max);
		else
		return false;
	}
}
int main()
{
	tree t;
	int A[] ={1,2,3,4,5,6};
	t.root = t.cBST(A,0,5);
	t.inorder(t.root);
	return 0;
}
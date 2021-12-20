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
class tree
{
	private:
		void inorder(node1 *p)
		{
			if(p!=NULL)
			{
				inorder(p->lchild);
				cout<<p->data<<" ";
				inorder(p->rchild);
			}
		}
		bool Bsearchp(int data,node1 *p)
		{
			if(p==0)
			return false;
			else
			{
				if(data == p->data)
				{
					return true;
				}
				else if(data<p->data)
				{
					return Bsearchp(data,p->lchild);
				}
				else if(data>p->data)
				{
					return Bsearchp(data,p->rchild);
				}
			}
		}
		void insert(int x,node1 *s,node1* p)
		{
			if(p==NULL)
			{
				node1 *t;
				t=new node1;
				t->data = x;
				t->lchild = t->rchild = NULL;
				if(x<s->data)
				s->lchild = t;
				else
				s->rchild = t;
			}
			else
			if(x<p->data)
			{
				insert(x,p,p->lchild);
			}
			else if(p->data<x)
			{
				insert(x,p,p->rchild);
			}
			else if(x==p->data)
			{
				return;
			}
		}
	public:
		node1 *root;
		tree()
		{
			root = NULL;
		}
		bool Bsearch(int data)
		{
			return Bsearchp(data,root);
		}
		void insert(int x)
		{
			if(root == NULL)
			{
				root = new node1;
				root->data=x;
				root->lchild=root->rchild=NULL;
			}
			node1 *s= NULL;
			insert(x,s,root);
		}
		void inorder()
		{
			inorder(root);
		}
		node1* inper(node1 *p)
		{
			if(p==NULL)
			return NULL;
			else
			{
				node1 *m;
				m=inper(p->rchild);
				if(m==NULL)
				return p;
				else
				return m;
			}
		}
		void path2(node1 *p,vector<int> &s,int ele)
		{
			if(p==NULL)
			{
				return;
			}
			else
			{
				if(ele<p->data)
				path2(p->lchild,s,ele);
				else if(p->data<ele)
				path2(p->rchild,s,ele);
				else if(p->data==ele)
				{
					s.push_back(p->data);
					return;
				}
				if(s.size()!=0)
				{
					s.push_back(p->data);
				}
				else
				return;
			}
		}
		vector<int> path(node1 *p,int ele)
		{
			vector<int> s;
			path2(p,s,ele);
			return s;
		}
		node1* deleteN(node1 *p,int ele)
		{
			if(p==NULL)
			return NULL;
			else
			{
				if(ele<p->data)
				{
					p->lchild = deleteN(p->lchild,ele);
					return p;
				}
				else if(ele>p->data)
				{
					p->rchild = deleteN(p->rchild,ele);
					return p;
				}
				else
				{
					if(p->lchild==NULL&&p->rchild==NULL)
					{
						delete p;
						return NULL;
					}
					else if(p->lchild ==NULL)
					{
						node1 *t;
						t = p->rchild;
						p->rchild = NULL;
						return t;
					}
					else if(p->rchild == NULL)
					{
						node1 *t;
						t = p->lchild;
						p->lchild = NULL;
						return t;
					}
					else
					{
						node1 *m; 
						m=p->lchild;
						while(m->rchild!=NULL)
						{
							m=m->rchild;
						}
						int min;
						min = m->data;
						p->data=min;
						p->lchild = deleteN(p->lchild,min);
						return p;
					}
				}	
			}
		}
};
int main()
{
	tree t;
	t.insert(8);
	t.insert(4);
	t.insert(2);
	t.insert(6);
	t.insert(12);
	t.insert(10);
	t.insert(14);
	t.root = t.deleteN(t.root,8);
	t.inorder();
	return 0;
}
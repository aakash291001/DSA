#include<iostream>
#include<unordered_map>
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
			head=tail=NULL;
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
		temp->next=NULL;
		if(head == NULL)
		{
			head = tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}
}
node1* que::dequeue()
{
	if(head == NULL)
	return NULL;
	else
	{
		node1 *p;
		p = head->data;
		node2 *t;
		t = head;
		head=head->next;
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
			root=NULL;
		}
		void create();
		void preorder(node1 *p)
		{
			if(p==NULL)
			{
				return;
			}
			else
			{
				cout<<p->data<<" ";
				preorder(p->lchild);
				preorder(p->rchild);
			}
		}
		bool checkCousin(int n,int m,node1 *p)
		{
			pair<int,int> npos,mpos;
			npos = BTsearchP(p,NULL,0,n);
			mpos = BTsearchP(p,NULL,0,m);
			if(npos.first==mpos.first&&npos.second!=mpos.second)
			{
				return true;
			}
			else
			return false;
		// cout<<npos.first<<":"<<npos.second;
		// cout<<"\n"<<mpos.first<<":"<<mpos.second;
		}
		pair<int,int> BTsearchP(node1 *p,node1 *m,int count,int K)
		{
		  if(p==NULL)
		  {
		  	pair<int,int> m;
		  	m.first = -1;
		  	m.second=-1;
		    return m;
		  }
		  else
		  {
		    if(p->data==K)
		    {
		      if(m==NULL)
		      {
		      	pair<int,int> bp;
		      	bp.first = count;
		      	bp.second = -1;
		      	return bp;
			  }
			  else
			  {
			  	pair<int,int> bp;
		      	bp.first = count;
		      	bp.second = m->data;
		      	return bp;
			  }
		    }
		    else
		    {
		      // if(BTsearch(p->lchild,count+1,K)>-1)
		      pair<int,int> l;
		      l =BTsearchP(p->lchild,p,count+1,K);
		      if(l.first==-1)
		      {
		        return BTsearchP(p->rchild,p,count+1,K);
		      }
		      else
		      return l;
		    }
		  }
		}
		void levelVOrder(node1 *p,unordered_map<int,vector<int,int>> &map,int &count)
		{
			if(p==NULL)
			return;
			else
			{
				map[count].push_back(p->data);
				levelVOrder(p->lchild,map,count-1);
				levelVOrder(p->rchild,map,count+1);
			}
		}
		void levelOrder(node1 *p)
		{
			unordered_map<int,vector<int>> map;
			int count=0;
			levelVOrder(p,map,count);
			for(int i=-count;i<=count;i++)
			{
				for(auto m=map[i].begin();m!=map[i].end();m++)
				{
					cout<<*m<<" ";
				}
				cout<<"\n";
			}
		}
		int BTsearch(node1 *p,int count,int K)
		{
		  if(p==NULL)
		  {
		    return -1;
		  }
		  else
		  {
		    if(p->data==K)
		    {
		      return count;
		    }
		    else
		    {
		      // if(BTsearch(p->lchild,count+1,K)>-1)
		      int l;
		      l =BTsearch(p->lchild,count+1,K);
		      if(l==-1)
		      {
		        return BTsearch(p->rchild,count+1,K);
		      }
		      else
		      return l;
		    }
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
	while(Q.head!=NULL)
	{
		t = Q.dequeue();
		cout<<"Enter the left child of \n"<<t->data<<" ";
		cin>>x;
		if(x!=-1)
		{
			p = new node1;
			p->data=x;
			p->lchild = p->rchild = NULL;
			t->lchild =p;
			Q.enqueue(p);
		}
		cout<<"Enter the right child of "<<t->data<<" ";
		cin>>x;
		if(x!=-1)
		{
			p = new node1;
			p->data=x;
			p->lchild = p->rchild = NULL;
			t->rchild =p;
			Q.enqueue(p);
		}
	}
}
int main()
{
	tree t;
	t.create();
	t.levelOrder(t,root);
	return 0;
}
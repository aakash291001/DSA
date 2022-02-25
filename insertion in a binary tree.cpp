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
      tail = temp;
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
    node2 *t;
    p=head->data;
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
    else
    return;
  }
  node1* search(int n,node1 *p)
  {
    if(p==NULL||p->data == n)
    return p;
    else if(n>p->data)
    {
      search(n,p->rchild);
    }
    else if(n<p->data)
    {
      search(n,p->lchild);
    }
  }
  void insert(int n,node1 *p,node1 *t)
  {
    // cout<<"Enter the element to be inserted\n";
    // int n;
    // cin>>n;
    if(root == NULL)
    {
    	root = new node1;
    	root->data =n;
    	root->lchild = root->rchild = NULL;
	}
    else
    {
	    	if(p==NULL)
	    {
	      if(t->data >n)
	      {
	        node1 *q;
	        q = new node1;
	        q->data = n;
	        q->lchild = q->rchild = NULL;
	        t->lchild = q;
	      }
	      else if(t->data <n)
	      {
	        node1 *q;
	        q = new node1;
	        q->data = n;
	        q->lchild = q->rchild = NULL;
	        t->rchild = q;
	      }
	    }
	    else if(n>p->data)
	    {
	      t =p;
	      insert(n,p->rchild,t);
	    }
	    else if(n<p->data)
	    {
	      t =p;
	      insert(n,p->lchild,t);
	    }
	    else
	    {
	      cout<<"element already in the slist\n";
	    }
	}
  }
};
void tree::create()
{
  node1 *t,*p;
  int x;
  que Q;
  
  cout<<"Enter root element\n";
  cin>>x;
  if(x!=-1)
  {
  	root =new node1;
  	root->data = x;
  	root->lchild=root->rchild = NULL;
  	Q.enqueue(root);
  }
  while(Q.head!=NULL)
  {
    p = Q.dequeue();
    cout<<"Enter left child"<<"of "<<p->data<<"\n";
    cin>>x;
    if(x!=-1)
    {
      t = new node1;
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->lchild=t;
      Q.enqueue(t);
    }
    cout<<"Enter right child "<<"of "<<p->data<<"\n";
    cin>>x;
    if(x!=-1)
    {
      t = new node1;
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->rchild =t;
      Q.enqueue(t);
    }
  }
}
int main()
{
  tree t;
  t.create();
  cout<<"\nIn inorder";
	t.inorder(t.root);
//	do
//	{
//		cout<<"Enter the element to be inserted\n";
//		int n;
//		cin>>n;
//		t.insert(n,t.root,NULL);
//	}while(n!=-1)
	cout<<"Enter the no. of elements to be entered\n";
	int p;
	cin>>p;
	for(int i =1;i<=p;i++)
	{
		cout<<"Enter the element to be inserted\n";
		int n;
		cin>>n;
		t.insert(n,t.root,NULL);
	}
	cout<<"\nIn inorder";
	t.inorder(t.root);
  return 0;
}
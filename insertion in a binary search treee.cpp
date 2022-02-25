#include<iostream>
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
  public:
  node1 *root;
  tree()
  {
    root = NULL;
  }
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
  void insert(int n,node1 *p,node1 *t)
  {
    if(root == NULL)
    {
      root = new node1;
      root->data = n;
      root->lchild = root->rchild = NULL;
    }
    else
    {
      if(p==NULL)
      {
        if(n<t->data)
        {
          node1 *q;
          q = new node1;
          q->data = n;
          q->lchild = q->rchild = NULL;
          t->lchild = q;
        }
        else if(n>t->data)
        {
          node1 *q;
          q = new node1;
          q->data = n;
          q->lchild = q->rchild = NULL;
          t->rchild = q;
        }
      }
      else if(n<p->data)
      {
        insert(n,p->lchild,p);
      }
      else if(n>p->data)
      {
        insert(n,p->rchild,p);
      }
      else
      {
        cout<<"Element is already there\n";
      }
    }
  }
};
int main()
{
  tree t;
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
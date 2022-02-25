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
    root = 0;
  }
  void inorder(node1 *p)
  {
    if(p!=NULL)
    {
      inorder(p->lchild);
      cout<<p->data<<" ";
      inorder(p->rchild);
    }
  }
  void insert(int n,node1 *p,node1 *q)
  {
    if(root == 0)
    {
      root = new node1;
      root->data = n;
      root->lchild = root->rchild = 0;
    }
    else
    {
      if(p!=0)
      {
        if(n<p->data)
      {
        insert(n,p->lchild,p);
      }
      else if(n>p->data)
      {
        insert(n,p->rchild,p);
      }
      else
      {
        cout<<"Already in the list\n";
      }
      }
      else
      {
        if(n<q->data)
        {
          node1 *t;
          t = new node1;
          t->data  =n;
          t->lchild = t->rchild = 0;
          q->lchild = t;
        }
        else if(n>q->data)
        {
          node1 *t;
          t = new node1;
          t->data  =n;
          t->lchild = t->rchild = 0;
          q->rchild = t;
        }
      }
    }
  }
  node1* deletebst(node1 *p,int key)
  {
    if(key<p->data)
    {
      p->lchild = deletebst(p->lchild,key);
    }
    else if(key>p->data)
    {
      p->rchild = deletebst(p->rchild,key);
    }
    else
    {
      if(p->lchild == 0)
      {
        node1 *temp;
        temp=p->rchild;
        delete p;
        return temp;
      }
      else if(p->rchild == 0)
      {
        node1 *temp;
        temp=p->lchild;
        delete p;
        return temp;
      }
      else
      {
        node1 *temp = min(p->rchild);
        p->data = temp->data;
        p->rchild = deletebst(p->rchild,temp->data);
        return p;
      }
    }
    return p;
  }
  node1* min(node1 *node)
{
    node1* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->lchild != NULL)
        current = current->lchild;
 
    return current;
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
	t.deletebst(t.root,5);
	cout<<"\nIn inorder";
	t.inorder(t.root);
  return 0;
}
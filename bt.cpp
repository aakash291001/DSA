#include<iostream>
using namespace std;
class node
{
  public:
  int data;
  node *lchild;
  node *rchild;
};
class que
{
  public:
  int f;
  int r;
  int size;
  node **Q;
  que(int p)
  {
    f=-1;
    r=-1;
    size =p;
    Q=new node*[size];
  }
  void enqueue(node *p);
  node* dequeue();
  int isempty();
};
void que::enqueue(node *p)
{
  if(r==size-1)
  {
    cout<<"Queue is full\n";
  }
  else
  {
    r++;
    Q[r]=p;
  }
}
node* que::dequeue()
{
  if(r==f)
  {
    return NULL;
    
  }
  else
  {
    f++;
    return Q[f];
  }
}
int que::isempty()
{
  return r==f;
}
class tree
{
  public:
  node *root;
  tree()
  {
    root = NULL;
   
  }
  void create();
  void preorder(node *p)
  {
  if(p)
  {
    cout<<p->data<<" ";
    preorder(p->lchild);
    preorder(p->rchild);
  }
}
  void postorder(node *p)
  {
  if(p)
  {
    postorder(p->lchild);
    postorder(p->rchild);
    cout<<p->data<<" ";
  }
}
  void inorder(node *p){
  if(p)
  {
    inorder(p->lchild);
    cout<<p->data<<" ";
    inorder(p->rchild);
  }
}

};
void tree::create()
{
   que Q(100);
  node *p,*t;
  root = new node;
  cout<<"Enter root\n";
  cin>>root->data;
  root->lchild=root->rchild = NULL;
  Q.enqueue(root);
  while(!Q.isempty())
  {
    p=Q.dequeue();
    int x;
    cout<<"Enter left child of"<<p->data<<"\n";
    cin>>x;
    if(x!=-1)
    {
      t = new node;
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->lchild = t;
      Q.enqueue(t);
    }
    cout<<"Enter right child of"<<p->data<<"\n";
    cin>>x;
    if(x!=-1)
    {
      t = new node;
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->rchild = t;
      Q.enqueue(t);
    }
  }
}


int main()
{
  tree t;
  t.create();
  cout<<"\nIn preorder";
	t.preorder(t.root);
	cout<<"\nIn Inorder";
	t.inorder(t.root);
	cout<<"\nIn postorder";
	t.postorder(t.root);
  return 0;
}
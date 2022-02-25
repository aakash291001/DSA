#include<iostream>
using namespace std;
class node1
{
  public:
  int data;
  node1 *lchild;
  node1* rchild;
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
    head = tail= NULL;
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
    cout<<"Queue is Full\n";
  }
  else
  {
    temp->data = p;
    temp->next = NULL;
    if(head == NULL)
    {
      head =tail = temp;
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
    node1 *t;
    t = head->data;
    node2 *p;
    p= head;
    head = head->next;
    delete p;
    return t;
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
  node1* search(int key,node1 *p)
  {
    if(p==NULL||p->data == key)
    {
      return p;
    }
    else if(p->data > key)
    {
      return search(key,p->lchild);
    }
    else if(p->data < key)
    {
      return search(key,p->rchild);
    }
  }
};

void tree::create()
{
  node1 *p,*t;
  int x;
  que Q;
  root = new node1;
  cout<<"Enter Root data ";
  cin>>root->data;
  root->lchild = root->rchild = NULL;
  Q.enqueue(root);
  while(Q.head != NULL)
  {
    p=Q.dequeue();
    cout<<"enter left child of "<<p->data<<" ";
    cin>>x;
    if(x!=-1)
    {
      t = new node1;
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->lchild = t;
      Q.enqueue(t);
    }
    cout<<"enter right child of "<<p->data<<" ";
    cin>>x;
    if(x!=-1)
    {
      t = new node1;
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
  cout<<"\nIn inorder";
	t.inorder(t.root);
	node1 *p;
	cout<<"\nEnter the element to be searched\n";
	int key;
	cin>>key;
	p=t.search(key,t.root);
	if(p!=NULL)
	{
	  cout<<"element found\n";
	}
	else
	{
		cout<<"Element not found\n";
	}
  return 0;
}
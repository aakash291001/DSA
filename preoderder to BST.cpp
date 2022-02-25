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
class stk
{
  public:
  node2 *top;
  stk()
  {
    top = 0;
  }
  void push(node1 *m);
  node1* pop();
};
void stk::push(node1 *m)
{
  node2 *temp;
  temp = new node2;
  if(temp == NULL)
  {
    cout<<"Stack overflow\n";
  }
  else
  {
    temp->data = m;
    temp ->next=top;
    top = temp;
  }
}
node1* stk::pop()
{
  if(top == 0)
  {
    cout<<"Stack is empty\n";
    return NULL;
  }
  else
  {
    node2 *temp;
    temp = top;
    top = top->next;
    return temp->data;
  }
}
class bst
{
  public:
  node1 *root;
  bst()
  {
    root = NULL;
  }
  void inorder(node1 *p)
  {
    if(p!=0)
    {
      inorder(p->lchild);
      cout<<p->data<<" ";
      inorder(p->rchild);
    }
  }
  void prebst(int A[],int i,node1 *p)
  {
    stk stk1;
    if(root == NULL)
    {
      
      root = new node1;
      root->data = A[i];
      root->lchild = root->rchild = 0;
      p = root;
      i++;
    }
    while(A[i]!= '\0')
    {
      if(A[i]<p->data)
      {
        node1 *t;
        t = new node1;
        t->data = A[i];
        t->lchild = t->rchild = NULL;
        p->lchild = t;
        stk1.push(p);
        p = t;
        i++;
      }
      else if(A[i]>p->data)
      {
        if(stk1.top!=NULL)
        {
          if(A[i]<stk1.top->data->data)
        {
          node1 *t;
          t = new node1;
          t->data = A[i];
          t->lchild = t->rchild = 0;
          p->rchild  = t;
          p = t;
          i++;
        }//
        else if(A[i]>stk1.top->data->data)
        {
          p=stk1.pop();
        }
        }
        else
        {
          node1 *t;
          t = new node1;
          t->data = A[i];
          t->lchild = t->rchild = 0;
          p->rchild  = t;
          p = t;
          i++;
        }
      }
    }
  }
};
int main()
{
  int A[] ={30,20,10,15,25,40,50,45};
  bst b;
  b.prebst(A,0,b.root);
  b.inorder(b.root);
  return 0;
}
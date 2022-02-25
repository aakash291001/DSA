#include<iostream>
#include<climits>
using namespace std;
class node1
{
  public:
  int data;
  node1 *lchild;
  node1 *rchild;
};
node1* constructBST(int preorder[],int *idx,int key,int max,int min,int n)
{
  if(*idx>=n)
  {
    return NULL;
  }
  node1 *root;
  root = NULL;
  if(min<key&&key<max)
  {
    root = new node1;
    root->data = key;
    *idx = *idx +1;
    if(*idx<n)
    {
      root->lchild = constructBST(preorder,idx,preorder[*idx],key,min,n);
    }
    if(*idx<n)
    {
      root->rchild = constructBST(preorder,idx,preorder[*idx],max,key,n);
    }
  }
  return root;
}
void inorder(node1 *root)
  {
    if(root)
    {
      inorder(root->lchild);
      cout<<root->data<<" ";
      inorder(root->rchild);
    }
  }
int main()
{
  int preorder[] = {10,2,1,13,11};
  int n = 5;
  int idx;
  idx = 0;
  node1 *root= constructBST(preorder,&idx,preorder[idx],INT_MAX,INT_MIN,n);
  inorder(root);
  return 0;
}
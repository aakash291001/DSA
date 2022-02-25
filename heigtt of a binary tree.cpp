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
        if(head ==NULL)
        {
            tail = head = temp;
        }
        else
        {
            
        tail->next=temp;
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
        p=head;
        head=head->next;
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
    int height(node1 *p)
    {
        if(p==NULL)
        {
            return 0;
        }
        else
        {
            int x,y;
            x = height(p->lchild);
            y = height(p->rchild);
            if(x>=y)
            return x+1;
            else
            return y+1;
        }
    }
};
void tree::create()
{
    node1 *p,*t;
    int x;
    que q;
    root = new node1;
    cout<<"Enter root data\n";
    cin>>root->data;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);
    while(q.head!= NULL)
    {
        p = q.dequeue();
        cout<<"Enter left child of "<<p->data<<" ";
        cin>>x;
        if(x!=-1)
        {
            t=new node1;
            t->data = x;
            t->lchild=t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        cout<<"Enter right child of "<<p->data<<" ";
        cin>>x;
        if(x!=-1)
        {
            t=new node1;
            t->data = x;
            t->lchild=t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}          
int main()
{
    tree t;
  t.create();
  cout<<"\nIn inorder";
	t.inorder(t.root);
	cout<<"\nHeight of tree is "<<t.height(t.root);
  return 0;
}
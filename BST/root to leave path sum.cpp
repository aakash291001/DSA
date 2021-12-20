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
        head = tail =NULL;
    }
    void enqueue(node1 *p);
    node1* dequeue();
};
void que::enqueue(node1 *p)
{
    node2 *temp;
    temp = new node2;
    if(temp ==NULL)
    {
        cout<<"Queue is full";
    }
    else
    {
        temp->data = p;
        temp->next =NULL;
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
    if(head==NULL)
    {
        cout<<"Queue is empty";
        return NULL;
    }
    else
    {
        node1 *p;
        p = head->data;
        node2 *t;
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
    void dupi(node1 *p)
    {
    	if(p==NULL)
    	{
    		return;
		}
		else
		{
			node1 *a,*b;
			b = p->rchild;
			a = p->lchild;
			node1 *t;
			t = new node1;
			t->data = p->data;
			t->lchild = a;
			p->lchild = t;
			dupi(a);
			dupi(b);
		}
	}
	void realsum(node1 *p,int &m)
	{
	    if(p==NULL)
	    return;
	    else
	    {
	        realsum(p->rchild,m);
	        m= p->data +m;
	        p->data = m;
	        realsum(p->lchild,m);
	    }
	}
    void modify(node1 *p)
    {
        // Your code here
        int m =0;
    	   realsum(p,m);
    }
    void sumpath(node1 *p,int sum,vector<int> path)
    {
        if(p->data==sum&&p->lchild==NULL&&p->rchild==NULL)
        {
            path.push(p->data);
            for(auto i:path)
            {
                cout<<*i;
            }
        }
        
        else
        {
            if(p->data<=sum)
            {
                path.push(p->data);
                sumpath(p->lchild,sum-path,path);
                sumpath(p->rchild,sumpath,path);
            }
            else
            return;
        }
    }
};
void tree::create()
{
    que q;
    int x;
    node1 *p;
    cout<<"Enter root data\n";
    cin>>x;
    if(x!=-1)
    {
        root = new node1;
        root->data = x;
        root->lchild = root->rchild = NULL;
        q.enqueue(root);
    }
    while(q.head!=NULL)
    {
        p = q.dequeue();
        cout<<"enter left child of "<<p->data;
        cin>>x;
        if(x!=-1)
        {
            node1 *t;
            t = new node1;
            t->data =x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        cout<<"enter right child of "<<p->data;
        cin>>x;
        if(x!=-1)
        {
            node1 *t;
            t = new node1;
            t->data =x;
            t->lchild = t->rchild = NULL;
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
	cout<<"Enter sum\n";
	int sum;
	cin>>sum;
	vector<int> path;
	sumpath(p,sum,path);
    return 0;
}
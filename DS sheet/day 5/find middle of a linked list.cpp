 #include<iostream>
 using namespace std;
 class node
 {
     public:
     int data;
     node *next;
     node(int val)
     {
         data = val;
         node *next=NULL; 
     }
 };
 void insertAtTail(node* &head,int val)
 {
    node* n = new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
 }
 void display(node *head)
 {
     node *temp= head;
     while(temp!=NULL)
     {
         cout<<temp->data<<" ";
         temp=temp->next;
     }
     cout<<"\n";
 }
 void insertAtHead(node* &head,int val)
 {
     node *n = new node(val);
     if(head==NULL)
     {
         head=n;
         return;
     }
     else
     {
         n->next = head;
         head=n;
     }
 }
 void search(node *head,int val)
 {
     if(head==NULL)
     {
         cout<<"List is empty\n";
     }
     else
     {
         node *temp=head;
         int count=0;
         while(temp!=NULL)
         {
             if(temp->data==val)
             {
                 cout<<"Value is present at "<<count<<" index\n";
                 return;
             }
             temp=temp->next;
             count++;
         }
         cout<<"Value is not found\n";
     }
 }
 int llLength(node *head)
 {
     if(head==NULL)
     return 0;
     else
     {
         int count=0;
         while(head!=NULL)
         {
             count++;
             head=head->next;
         }
         return count;
     }
 }
 void findMid(node *head)
 {
     if(head==NULL)
     {
         cout<<"list is empty\n";
     }
     else
     {
         int l = llLength(head);
         int m= l/2;
         for(int i=1;i<m;i++)
         {
             head=head->next;
         }
         cout<<head->data;
     }
 }
 //using tortoise method
 void findMid2(node *head)
 {
 	if(head==NULL)
 	{cout<<"list is empty\n";
	}
	else
	{
		node *f,*s;
		f=NULL;
		s=NULL;
		f = s = head;
		while(f!=NULL&&f->next!=NULL)
		{
			f = f->next;
			f = f->next;
			s = s->next;
		}
		cout<<s->data<<"\n";
	}
 }
 int main()
 {
     node* head = NULL;
     insertAtHead(head,1);
     insertAtHead(head,2);
     insertAtHead(head,3);
     insertAtHead(head,4);
     display(head);
    //  search(head,3);
    //  cout<<llLength(head);
    findMid2(head);
     return 0;
 }
#include<iostream>
#include<vector>
using namespace std; 
class priorityQueueMin{
	vector<int> pq;
	public:
		priorityQueueMin()
		{
			
		}
		void swap(int *p,int *q)
		{
			int a;
			a=*p;
			*p=*q;
			*q=a;
		}
		bool empty()//return true if empty else if not empty than return false;
		{
			if(pq.size()==0)
			return true;
			else
			return false;
		}
		int size()//returns no. of elements present
		{
			return pq.size();
		}
		int top()
		{
			if(pq.size()==0)
			return -1;
			else return pq[0];
		}
		int getMin()
		{
			if(empty())
			return -1; 
			return pq[0];
		}
		void push(int ele)
		{
			pq.push_back(ele);//Element is inserted at the end of array
			int s;
			s=pq.size();
			if(s==1)
			{
				return;
			}
			else
			{
				int childIndex;
				childIndex=s-1;
				int parentIndex;
				parentIndex=(childIndex-1)/2;
				while(childIndex!=0&&pq[parentIndex]>pq[childIndex])
				{
					swap(&pq[parentIndex],&pq[childIndex]);
					childIndex=parentIndex;
					parentIndex=(childIndex-1)/2;
				}
			}
		}
		void pop()
		{
			int s=pq.size();
			if(s==0)
			{
				return;
			}
			else
			{
				if(s==1)
				{
					int p;
					
					pq.pop_back();
					return;
				}
				else
				{
					swap(&pq[0],&pq[s-1]);
					pq.pop_back();
					s--;
					int p=0;
					int lchild,rchild;
					lchild = 1;
					rchild = 2;
					while(lchild<s-1)
					{
						int main;
						if(pq[lchild]>=pq[rchild])
						main = rchild;
						else
						main = lchild;
						if(pq[p]>pq[main])
						{
							swap(&pq[p],&pq[main]);
							p=main;
							lchild = 2*main+1;
							rchild = 2*main +2;
						}
						else break;
					}
				}
			}
		}
};
class priorityQueueMax
{
  vector<int> pq;
  public:
  priorityQueueMax()
  {
    
  }
  void swap(int *a,int *b)
  {
    int c;
    c=*a;
    *a=*b;
    *b=c;
  }
  bool empty()
  {
    if(pq.size()==0)
    return true;
    else
    return false;
  }
  int size()
  {
    return pq.size();
  }
  int getMax()
  {
    if(empty())
    return -1;
    return pq[0];
  }
  int top()
		{
			if(pq.size()==0)
			return -1;
			else return pq[0];
		}
  void push(int p)
  {
    pq.push_back(p);
    int s;
    s = size();
    if(s==1)
    return;
    else
    {
      int child;
      child=s-1;
      int parent = (child)/2;
      while(child!=0&&pq[parent]<pq[child])
      {
        swap(&pq[parent],&pq[child]);
        child=parent;
        parent=(child-1)/2;
      }
    }
  }
  void pop()
  {
    if(empty())
    return;
    else
    {
      int s=size();
      if(s==1)
      {
        int p;
        p=pq[0];
        pq.pop_back();
        return;
      }
      else
      {
        int p=0;
        int max=s-1;
        int m=pq[0];
        swap(&pq[max],&pq[p]);
        pq.pop_back();
        s--;
        int lchild = 1;
        int rchild = 2;
        int main;
		while(lchild<s-1)
		{
			if(pq[lchild]>pq[rchild])
			main = lchild;
			else
			main = rchild;
			if(pq[main]>pq[p])
			{
				swap(&pq[main],&pq[p]);
				p = main;
				lchild = 2*main+1;
				rchild = 2*main+2;
			}
			else 
			break;
		}
		return;
		}
    }
  }
};
vector<int> runMed(vector<int> 	a)
{
	priorityQueueMax pqmax;
	priorityQueueMin pqmin;
	pqmax.push(a[0]);
	vector<int> vec;
	vec.push_back(a[0]);
	for(int i=1;i<a.size();i++)
	{
		
		if(a[i]>=pqmax.top())
		{
			pqmin.push(a[i]);
		}
		else
		pqmax.push(a[i]);
		if(pqmin.size()!=pqmax.size())
		{
			if(pqmin.size()-pqmax.size()>1)
			{
				pqmax.push(pqmin.top());
				pqmin.pop();
			}
			else if(pqmax.size()-pqmin.size()>1)
			{
				pqmin.push(pqmax.top());
				pqmax.pop();
			}	
		}
		if(i%2==0)
		{
			if(pqmin.size()>pqmax.size())
			vec.push_back(pqmin.top());
			else
			vec.push_back(pqmax.top());
			
		}
		else
		{
			vec.push_back((pqmin.top()+pqmax.top())/2);
		}
	}
	return vec;
}
int main()
{
	vector<int> vec;
	vec.push_back(7);
	vec.push_back(2);
	vec.push_back(8);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(5);
	vector<int> vec2;
	vec2 = runMed(vec);
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec2[i]<<" ";
	}
	return 0;
}
//	priorityQueueMin pq;
//	pq.push(10);
//	pq.push(12);
//	pq.push(11);
//	pq.push(0);
//	pq.push(2);
//	pq.push(100);
//	pq.push(28);
//	cout<<pq.top()<<"\n";
//	pq.pop();
//	cout<<pq.top()<<"\n";
//	pq.pop();
//	cout<<pq.top()<<"\n";
//	pq.pop();
//	cout<<pq.top()<<"\n";
//	pq.pop();
//	cout<<pq.top()<<"\n";
//	pq.pop();
//	cout<<pq.top()<<"\n";
//	pq.pop();
//	cout<<pq.top()<<"\n";
//	priorityQueueMax P;
//	P.push(10);
//	P.push(100);
//	P.push(50);
//	P.push(200);
//	P.push(300);
//	P.push(80);
//	cout<<"No. of elements = "<<P.size()<<"\n";
//	while(!P.empty())
//	{
//		cout<<"Removed element is : "<<P.top()<<"\n";
//		P.pop();
//	}
//  return 0;
//	pq.pop();
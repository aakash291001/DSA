#include<iostream>
#include<vector>
using namespace std; 
class priorityQueue{
	vector<int> pq;
	public:
		priorityQueue()
		{
			
		}
		void swap(int *p,int *q)
		{
			int a;
			a=*p;
			*p=*q;
			*q=a;
		}
		bool isEmpty()//return true if empty else if not empty than return false;
		{
			if(pq.size()==0)
			return true;
			else
			return false;
		}
		int getSize()//returns no. of elements present
		{
			return pq.size();
		}
		int getMin()
		{
			if(isEmpty())
			return -1; 
			return pq[0];
		}
		void insert(int ele)
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
				while(childIndex>0&&pq[parentIndex]>pq[childIndex])
				{
					swap(&pq[parentIndex],&pq[childIndex]);
					childIndex=parentIndex;
					parentIndex=(childIndex-1)/2;
				}
			}
		}
		int removeMin()
		{
			int s=pq.size();
			if(s==0)
			{
				return -1;
			}
			else
			{
				if(s==1)
				{
					int p;
					p=pq[0];
					pq.pop_back();
					return p;
				}
				else
				{
					int max = s-1;
					int m;
					m=pq[0];
					swap(&pq[s-1],&pq[0]);
					pq.pop_back();
					s--;
					int p;
					p=0;
					int rChild=(2*p)+2,lChild=(2*p)+1;
					int main;
					if(rChild<s&&lChild<s)
					{
						if(pq[rChild]<pq[lChild])
						main=rChild;
						else
						main=lChild;
					}
					else if(lChild<s)
					main = lChild;
					else if(rChild<s)
					main = rChild;
					while((pq[p]>pq[rChild]||pq[p]>pq[lChild])&&(lChild<max||rChild<max))
					{
						swap(&pq[main],&pq[p]);
						p=main;
						rChild=(2*p)+2;lChild=(2*p)+1;
						if(rChild<s&&lChild<s)
						{
							if(pq[rChild]<pq[lChild])
							main=rChild;
							else
							main=lChild;
						}
						else if(lChild<s)
						main = lChild;
						else if(rChild<s)
						main = rChild;
						else
						break;
					}
					return m;
				}
			}
		}
};
int main()
{
	priorityQueue pq;
//	P.insert(10);
//	P.insert(100);
//	P.insert(50);
//	P.insert(200);
//	P.insert(300);
//	P.insert(80);
	pq.insert(10);
	pq.insert(12);
	pq.insert(11);
	pq.insert(0);
	pq.insert(2);
	pq.insert(100);
	pq.insert(28);
	cout<<"No. of elements = "<<pq.getSize()<<"\n";
	while(!pq.isEmpty())
	{
		cout<<"Removed element is : "<<pq.removeMin()<<"\n";
		cout<<"No. of element left = "<<pq.getSize()<<"\n";
	}
	return 0;
}
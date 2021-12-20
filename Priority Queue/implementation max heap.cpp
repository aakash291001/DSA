#include<iostream>
#include<vector>
using namespace std;
class priorityQueue
{
  vector<int> pq;
  public:
  priorityQueue()
  {
    
  }
  void swap(int *a,int *b)
  {
    int c;
    c=*a;
    *a=*b;
    *b=c;
  }
  bool isEmpty()
  {
    if(pq.size()==0)
    return true;
    else
    return false;
  }
  int getSize()
  {
    return pq.size();
  }
  int getMax()
  {
    if(isEmpty())
    return -1;
    return pq[0];
  }
  void insert(int p)
  {
    pq.push_back(p);
    int s;
    s = getSize();
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
  int removeMax()
  {
    if(isEmpty())
    return -1;
    
    else
    {
      int s=getSize();
      if(s==1)
      {
        int p;
        p=pq[0];
        pq.pop_back();
        return p;
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
		return m;
		}
    }
  }
};
int main()
{
  priorityQueue P;
	P.insert(10);
	P.insert(100);
	P.insert(50);
	P.insert(200);
	P.insert(300);
	P.insert(80);
	cout<<"No. of elements = "<<P.getSize()<<"\n";
	while(!P.isEmpty())
	{
		cout<<"Removed element is : "<<P.removeMax()<<"\n";
		cout<<"No. of element left = "<<P.getSize()<<"\n";
	}
  return 0;
}
//        if(lchild<s&&rchild<s)
//        {
//          if(pq[lchild]>pq[rchild])
//          {
//            main=lchild;
//          }
//          else
//          {
//            main=rchild;
//          }
//        }
//        else if(rchild<s)
//        {
//          main=rchild;
//        }
//        else
//        {
//          main=lchild;
//        }
//        while((pq[p]<pq[lchild]||pq[p]<pq[rchild])&&(lchild<max||rchild<max))
//        {
//          swap(&pq[main],&pq[p]);
//          p = main;
//          lchild=2*p+1;
//          rchild = 2*p+2;
//          if(lchild<s&&rchild<s)
//          {
//             if(pq[lchild]>pq[rchild])
//             {
//                main=lchild;
//              }
//              else
//              {
//                main=rchild;
//              }
//            }
//            else if(rchild<s)
//        {
//          main=rchild;
//        }
//        else if(lchild<s)
//        {
//          main=lchild;
//        }
//           else
//           break;
//        }
//         return m;
//      }
#include<iostream>
#include<queue>
using namespace std;
using namespace std;
void sortK(int *arr,int k,int s)
{
  priority_queue<int> pq;
  int i=0,n=0;
  while(i<s)
  {
    while(pq.size()<=k&&n<s)
    {
      pq.push(arr[n]);
      n++;
    }
    arr[i]=pq.top();
    pq.pop();
    i++;
  }
}
int main() {
	//code
	int T;
	cout<<"Enter no. of test cases";
	cin>>T;
	for(int i=0;i<T;i++)
	{
	    pair<int,int> a;
	    cout<<"Enter no. elements for "<<i+1<<"th case\n";
	    cin>>a.first;//no. of elments
	    cout<<"Enter K value\n";
	    cin>>a.second;//k
	    int *kArr;
        kArr = new int[a.first];
        cout<<"Enter array elements in Reverse order\n";
        for(int i=a.first-1;i>=0;i--)
        cin>>kArr[i];
	    sortK(kArr,a.second,a.first);
	    cout<<"Sorted array is:\n";
        for(int i=a.first-1;i>=0;i--)
        {
            cout<<kArr[i]<<" ";
        }
        cout<<"\n";
	}
	return 0;
}
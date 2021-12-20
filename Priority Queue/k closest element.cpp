#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> printKClosest(int arr[], int n, int k, int x) {
        // code here
        // int n = arr.size();
        priority_queue<pair<int, int>>pq;
        int i;
        for(i=0;i<n;i++)
        {
            if(abs(x-arr[i])!=0)
            {
                pair<int,int> p;
                p.first=abs(x-arr[i]);
                p.second= arr[i];
                pq.push(p);
            if(pq.size()>k)
                pq.pop();
            }
            
        }
        vector<int> re;
        // priority_queue <int, vector<int>, greater<int> > pq2;
        for(int i=0;i<k;i++)
        {
            // re.push_back(pq.top().second);
            re.insert(re.begin(),pq.top().second);
            pq.pop();
        }
        // for(int i=0;i<k;i++)
        // {
        //     // re.insert(re.begin(),pq2.top());
        //     re.push_back(pq2.top());
        //     pq2.pop();
        // }
        
        return re;
    }
    int main()
    {
    	int arr[] = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
        int K = 4, X = 35,N = 13;
         vector<int> vec;
         vec = printKClosest(arr, N, K, X);
        for(int i=0;i<vec.size();i++)
        {
        	cout<<vec[i]<<" ";
		}
		return 0;
	}
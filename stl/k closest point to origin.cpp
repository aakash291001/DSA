#include<iostream>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<int>> kClosest(vector<vector<int>> A, int k) {
        unordered_map<int,tuple<int,int,int>> mp;
    for(int i=0;i<A.size();i++)
    {
        int sumI =0;
        for(int j=0;j<A[i].size();j++)
        {
            sumI+=A[i][j]*A[i][j];
        }
//        mp[sumI].first = A[i][0];
//        mp[sumI].second  = A[i][1];
			get<0>(mp[i]) = sumI;
			get<1>(mp[i]) = A[i][0];
			get<2>(mp[i]) = A[i][1];
    }
    priority_queue<tuple<int,int,int>> pq;
//    unordered_map<int,tuple<int,int,int>>::iterator it=mp.begin();
    for(auto x : mp)
    {
    	if(pq.size()<k)
    	pq.push(x.second);
    	else
    	{
    		pq.push(x.second);
        	pq.pop();
		}
	}
//    for(int i=0;i<k;i++)
//    {
//        pq.push((*it).second);
//        it++;
//    }
//    while(it!=mp.end())
//    {
//        pq.push((*it).second);
//        pq.pop();
//        it++;
//    }
    vector<vector<int>> vec;
//    priority_queue<tuple<int,int,int>>::iterator p=pq.begin();
    int i=0;
    while(pq.size()>=0)
    {
    	vec[i][0]=	get<1>(pq.top());
		vec[i][1]=	get<2>(pq.top());
		pq.pop();
		i++;
	}

    return vec;
        
    }
int main()
{
	vector<vector<int>> vec;
	int k=2;
	vec[0].push_back(3);
	vec[0].push_back(3);
	vec[1].push_back(5);
	vec[1].push_back(-1);
	vec[2].push_back(-2);
	vec[2].push_back(4);
	vector<vector<int>> vec2 = kClosest(vec,k);
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<2;j++)
		cout<<vec2[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}
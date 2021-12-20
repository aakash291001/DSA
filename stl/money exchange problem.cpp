#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
 bool comp(pair<int,int> a,pair<int,int> b)
    {
        if(a.first==b.first)
        {
        	if(a.second>b.second)
        	return true;
        	else
        	return false;
		}
        else 
		{
			if(b.first>a.first)
        		return true;
        	else
            return false;
		}
    }
    vector<int> frequencySort(vector<int>& arr) {
        int N = arr.size();
        unordered_map<int,int> map;
    for(int i=0;i<N;i++)
    {
        map[arr[i]]++;
    }
    // priority_queue<int> pq;
    // for(int i=0;i<N;i++)
    // {
    //     if(map1[arr[i]]>0)
    //     {
    //         pair<int,int> p;
    //     p.first = map1[arr[i]];
    //     p.second = arr[i];
    //     map1[arr[i]]=0;
    //     pq.push(p);
    //     }
    // }
        vector<pair<int,int>> vec;
        for(int i=0;i<N;i++)
        {
            if(map[arr[i]]>0)
            {
                pair<int,int> p;
                p.first = map[arr[i]];
                p.second = arr[i];
                map[arr[i]]=0;
                vec.push_back(p);
            }
        }
        sort(vec.begin(),vec.end(),comp);
    // priority_queue<pair<int,int>> pq;
    // for(int i=0;i<N;i++)
    // {
    //     if(map[arr[i]]>0)
    //     {
    //         pair<int,int> p;
    //     p.first = map[arr[i]];
    //     p.second = arr[i];
    //     map[arr[i]]=0;
    //     pq.push(p);
    //     }
    // }
        vector<int> ret;
    while(vec.size()>=1)
    {
        for(int i=0;i<vec[0].first;i++)
        {
            ret.insert(ret.begin(),vec[0].second);
        }
        vec.erase(vec.begin());
    }
        
        return ret;
    }
int main()
{
	//indian money change
//	int coins[]={1,2,5,10,20,50,100,200,500,2000};
//	int n = sizeof(coins)/sizeof(int);
//	int money = 168;
//	auto lb=lower_bound(coins,coins+n,money,compara);
//	cout<<"\nlower bound of 168 "<<coins[lb-coins];
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(2);
	vec.push_back(3);
	vector<int> vec2 = frequencySort(vec);
	for(int i=0;i<vec2.size();i++)
	{
		cout<<vec2[i]<<" ";
	}
	return 0;
}
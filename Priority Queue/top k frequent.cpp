#include<iostream>
#include<queue>
#inlcude<unordered_map>
using namespace std;
vector<int> topKFrequent(vector<int>& nums, int k) 
{
    unordered_map<int,int> mp;
    int s = nums.size();
    for(int i = 0;i<s;i++)
    {
        mp[nums[i]]++;
    }
    typedef pair<int,int> pi;
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    for(int i=0;i<s;i++)
    {
        if(mp[nums[i]]>0)
        {
		pi m;
        m.first = mp[nums[i]];
        m.second = nums[i];
        pq.push(m);
        mp[nums[i]]=0;
        if(pq.size()>k)
            pq.pop();}
    }
    vector<int> reu;
    for(int i=0;i<k;i++)
    {
        reu.push_back(pq.top().second);
        pq.pop();
    }
    return reu;
}
int main()
{
	int A
	return 0;
}
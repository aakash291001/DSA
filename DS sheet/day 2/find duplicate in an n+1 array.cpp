#include<bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int>& nums) {
        int f,s;
    f = nums[0];
    s = nums[0];
    do
    {
        f = nums[nums[f]];
        s = nums[s];
    }
    while(f!=s);
    f = nums[0];
    while(f!=s)
    {
        f = nums[f];
        s = nums[s];
    }
        return s;
    }
//    int findDuplicate(vector<int>& nums) {
//        int n = nums.size();
//    vector<int> vec(n,0);
//    for(int i=0;i<n;i++)
//    {
//        if(vec[nums[i]]==0)
//        vec[nums[i]]++;
//        else
//        return nums[i];
//    }
//    return 0;
//    }
int main()
{
    vector<int> vec{2,5,9,6,9,3,8,9,7,1};
    cout<<findDuplicate(vec);
    return 0;
}
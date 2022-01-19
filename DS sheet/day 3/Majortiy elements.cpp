#include<bits/stdc++.h>
using namespace std;
int freq(vector<int> vec)
{
    int n = vec.size();
    sort(vec.begin(),vec.end());
    return vec[n/2];
}
int freq2(vector<int> vec)
{
    int n = vec.size();
    int ans=vec[0];
    int count=1;
    for(int i=1;i<n;i++)
    {
        if(count==0)
        {
            ans = vec[i];
            count=1;
        }
        else if(vec[i]==ans)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return ans;
}
int main()
{
    vector<int> vec{4,4,2,4,3,4,4,3,2,4};
    cout<<freq2(vec);
    return 0;
}
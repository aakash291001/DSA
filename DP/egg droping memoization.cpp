#include<bits/stdc++.h>
using namespace std;
int maxi(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}
int min1(int a,int b)
{
    if(a>b)
    return b;
    else
    return a;
}
unordered_map<long long int,int> umap;
int solve(int e,int f)
{
    if(f==0||f==1)
    {
        return f;
    }
    if(e==1)
    return f;
    long long int l = e*1000+f;
    if(umap.find(l)!=umap.end())
    return umap[l];
    int mn = INT_MAX;
    for(int k = 1;k<=f;k++)
    {
//    	int ans1,ans2;
//    	if(umap.find((e*1000)+f-k)!=umap.end())
//    	ans1 = umap[(e*1000)+f-k];
//    	else
//        ans1 =umap[(e*1000)+f-k]= solve(e,f-k);
//        if(umap.find(((e-1)*1000)+k-1)!=umap.end())
//    	ans2 = umap[((e-1)*1000)+k-1];
//    	else
//        ans2=umap[((e-1)*1000)+k-1]= solve(e-1,k-1);
		int ans = 1+maxi(solve(e,f-k),solve(e-1,k-1));       
        mn = min1(mn,ans);
    }
    return umap[l] = mn;
}
int main()
{
    cout<<solve(3,7);
    return 0;
}
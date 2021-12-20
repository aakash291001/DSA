#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int dp[1002][1002];
int min(int a,int b)
{
    if(a<b)
    return a;
    else
    return b;
}
int adr(string s1,string s2)
{
    if(dp[s1.length()][s2.length()]!=-1)
    {
        return dp[s1.length()][s2.length()];
    }
    if(s1.length()==0&&s2.length()==0)
    {
        dp[s1.length()][s2.length()]=0;
        return 0;
    }
    else if(s1.length()==0)
    {
        dp[s1.length()][s2.length()] = s2.length();
        return s2.length();
    }
    else if(s2.length()==0)
    {
        dp[s1.length()][s2.length()] = s1.length();
        return s1.length();
    }
    else
    {
        if(s1[0]==s2[0])
        {
            dp[s1.length()][s2.length()] = adr(s1.substr(1),s2.substr(1));
            return dp[s1.length()][s2.length()];
        }
        else
        {
            int a = adr(s1.substr(1),s2);
            int d = adr(s1,s2.substr(1));
            int r = adr(s1.substr(1),s2.substr(1));
            dp[s1.length()][s2.length()] = min(a,min(d,r))+1;
            return  dp[s1.length()][s2.length()];
        }
    }
}
int adr2(string s1,string s2)
{
    int ans = adr(s1,s2);
    return dp[s1.length()][s2.length()];
}
int main()
{
    memset(dp,-1,sizeof(dp));
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int ans = adr2(s1,s2);
    cout<<ans;
    return 0;
}
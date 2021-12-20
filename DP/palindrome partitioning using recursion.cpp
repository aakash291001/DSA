#include<bits/stdc++.h>
using namespace std;
int ispallindrome(string str,int m,int n)
{
    int l = n-m+1;
    while(m<=n)
    {
        if(str[m]!=str[n])
        return 0;
        m++;
        n--;
    }
    return 1;
}
int solve(string str,int i,int j)
{
    if(i>=j)
    {
        return 0;
    }
    else if(ispallindrome(str,i,j)!=0)
    return 0;
    else
    {
        int mn = INT_MAX;
        for(int k = i;k<j;k++)
        {
            int temp = solve(str,i,k) + solve(str,k+1,j) + 1;
            if(mn>temp)
            mn= temp;
        }
        return mn;
    }
}
int main()
{
    string str;
    str = "aaabba";
    int l = str.length();
    cout<<solve(str,0,l-1);
    return 0;
}
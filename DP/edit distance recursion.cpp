#include<iostream>
#include<string>
using namespace std;
int min(int a,int b)
{
    if(a<b)
    return a;
    else
    return b;
}
int adr(string s1,string s2)
{
    if(s1.length()==0&&s2.length()==0)
    return 0;
    else if(s1.length()==0)
    {
        return s2.length();
    }
    else if(s2.length()==0)
    {
        return s1.length();
    }
    else
    {
        if(s1[0]==s2[0])
        {
            return adr(s1.substr(1),s2.substr(1));
        }
        else
        {
            int a = adr(s1.substr(1),s2);
            int d = adr(s1,s2.substr(1));
            int r = adr(s1.substr(1),s2.substr(1));
            return  min(a,min(d,r))+1;
        }
    }
}
int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int ans = adr(s1,s2);
    cout<<ans;
    return 0;
}
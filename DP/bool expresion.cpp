#include<bits/stdc++.h>
using namespace std;
int solve(string str,int i,int j,int value)
{
    if(i==j)
    {
        if(value==1)
        return str[i]=='T';
        else
        return str[i]=='F';
    }
    else
    {
    	int co=0;
        for(int k=i+1;k<=j-1;k+=2)
        {
            int lt = solve(str,i,k-1,1);
            int lf = solve(str,i,k-1,0);
            int rt = solve(str,k+1,j,1);
            int rf = solve(str,k+1,j,0);
            if(str[k]=='^')
            {
                if(value==true)
                co+= lt*rf+lf*rt;
                else
                co+= lt*rt+rf*lf;
            }
            else if(str[k]=='&')
            {
                if(value == true)
                {
                    co+= lt*rt;
                }
                else
                co+= lf*rt+lf*rf+lt*rf;
            }
            else if(str[k]=='|')
            {
                if(value == true)
                co+= (lf*rt+lt*rt+lt*rf);
                else
                co+= (lf*rf);
            }
        }
        return co;
    }
}
int main()
{
    string str = "T|T&F^T";
    cout<<solve(str,0,str.length()-1,1);
    return 0;
}
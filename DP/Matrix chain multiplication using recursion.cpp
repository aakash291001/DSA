#include<bits/stdc++.h>
using namespace std;
int solve(int A[],int i,int j)
{
    if(i>=j)
    return 0;
    else
    {
        int min = INT_MAX;
        for(int k = i;k<=j-1;k++)
        {
            int temp = solve(A,i,k)+solve(A,k+1,j)+A[i-1]*A[k]*A[j];
            if(min>temp)
            min = temp;
            
        }
        return min;
    }
}
int main()
{
    int A[]={40,20,30,10,10};
    cout<<solve(A,1,4);
    return 0;
}
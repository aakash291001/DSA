#include<iostream>
#include<limits.h>
using namespace std;
int min(int a,int b)
{
    if(a<b)
    return a;
    else
    return b;
}
int minStep(int n)
{
    if(n==2||n==3)
    return 1;
    else
    {
        int a,b,c;
        if(n%2==0)
        {
            a = minStep(n/2)+1;
        }
        else
        a = INT_MAX;
        if(n%3==0)
        {
            b = minStep(n/3)+1;
        }
        else
        b = INT_MAX;
        c = minStep(n-1)+1;
        return min(min(a,b),c);
    }
}
int minStep2(int n,int *A)
{
	if(A[n-2]!=-1)
	return A[n-2];
	else
	{
		int a,b,c;
        if(n%2==0)
        {
            a = minStep2(n/2,A)+1;
        }
        else
        a = INT_MAX;
        if(n%3==0)
        {
            b = minStep2(n/3,A)+1;
        }
        else
        b = INT_MAX;
        c = minStep2(n-1,A)+1;
        A[n-2]=min(min(a,b),c);
		return min(min(a,b),c);
	}
}
int minStep2(int n)
{
	int *A;
	A = new int[n-1];
	for(int i=0;i<n-1;i++)
	{
		A[i]=-1;
	}
	A[0]=1;//2
	A[1]=1;//3
	return minStep2(n,A);
}
int minStep3(int n)
{
		int *A;
	A = new int[n+1];
	for(int i=0;i<n+1;i++)
	{
		A[i]=-1;
	}
	A[0]=0;
	A[1]=0;
	A[2]=1;
	A[3]=1;
	for(int i=3;i<n+1;i++)
	{
		int a,b,c;
		if(i%2==0)
        {
            a = A[i/2]+1;
        }
        else
        a = INT_MAX;
        if(i%3==0)
        {
            b = A[i/3]+1;
        }
        else
        b = INT_MAX;
        c = A[i-1]+1;
        A[i] = min(min(a,b),c);
	}
	return A[n];
}
int main()
{
    int n;
    cin>>n;
    int ans = minStep3(n);
    cout<<ans;
    return 0;
}
#include<iostream>
using namespace std;
int t[1001][1001];

int max(int A,int B)
{
	if(A<B)
	return B;
	else if(A>=B)
	return A;
}
int knapsack(int *val,int *wt,int W,int n)
{
	
	if(n==0||W==0)
	{
		return 0;
	}
	if(t[n][W]!=-1)
	{
		return t[n][W];
	}
	else if(wt[n-1]<=W)
	{
		return t[n][W]=max(val[n-1]+knapsack(val,wt,W-wt[n-1],n-1),knapsack(val,wt,W,n-1));
	}
	else if(wt[n-1]>W)
	{
		return t[n][W]=knapsack(val,wt,W,n-1);
	}
	
}
int main()
{
	memset(t,-1,sizeof(t));
	cout<<"Enter the no. of elements\n";
	int n;
	cin>>n;
	int *val;
	val=(int*)malloc(n*sizeof(int));
	cout<<"Enter the values\n";
	for(int i =0;i<n;i++)
	{
		cin>>val[i];
		cout<<"\n";
	}
	int *wt;
	wt=(int*)malloc(n*sizeof(int));
	cout<<"Enter the wight\n";
	for(int i =0;i<n;i++)
	{
		cin>>wt[i];
		cout<<"\n";
	}
	cout<<"Enter maximum capacity\n";
	int W;
	cin>>W;
	int profit;
	profit = knapsack(val,wt,W,n);
	cout<<"\nProfit ="<<profit;
	return 0;
}
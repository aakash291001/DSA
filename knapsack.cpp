#include<iostream>
using namespace std;
int max(int A,int B)
{
	if(A>B)
	return A;
	else if(B>=A)
	return B;
}
int knapsack(int *val,int *wt,int W,int n)
{
	if(n==0||W==0)
	{
		return 0;
	}
	if(wt[n-1]<=W)
	{
		return max(knapsack(val,wt,W,n-1),val[n-1]+knapsack(val,wt,W-wt[n-1],n-1));
	}
	else if(wt[n-1]>W)
	{
		return knapsack(val,wt,W,n-1);
	}
}
int main()
{
	int *val;
	val=(int*)malloc(3*sizeof(int));
	int *wt;
	wt=(int*)malloc(3*sizeof(int));
	cout<<"\nEnter the value"<<"\n";
	for(int i = 0;i<3;i++)
	{
		cin>>val[i];
		cout<<"\n";
	}
	cout<<"\nEnter the weight\n";
	for(int i = 0;i<3;i++)
	{
		cin>>wt[i];
		cout<<"\n";
	}
	int n = 3;
	cout<<"Enter maximum weight\n";
	int W;
	cin>>W;
	int profit;
	profit=knapsack(val,wt,W,n);
	cout<<"\n"<<profit;
	return 0;
}
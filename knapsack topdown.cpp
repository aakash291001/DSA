#include<iostream>
using namespace std;
int max(int A,int B)
{
	if(A>=B)
	return A;
	else if(A<B)
	return B;
}
int knapsack(int *val,int *wt,int w,int n)
{
	int t[n+1][w+1];
	for(int i =0;i<n+1;i++)
	{
		for(int j=0;j<w+1;j++)
		{
			if(i==0||j==0)
			{
				t[i][j]=0;
			}
			else
			{
				if(j>=wt[i-1])
			{
				t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
			}
			else if(j<wt[i-1])
			{
				t[i][j]=t[i-1][j];
			}
			}
			
		}
	}
	return t[n][w];
}
int main()
{
	cout<<"Enter the no. of elements\n";
	int n;
	cin>>n;
	int *val;
	val=(int*)malloc(n*sizeof(int));
	cout<<"\nEnter the values\n";
	for(int i = 0;i<n;i++)
	{
		cin>>val[i];
	}
	int *wt;
	wt=(int*)malloc(n*sizeof(int));
	cout<<"\nEnter the weight\n";
	for(int i = 0;i<n;i++)
	{
		cin>>wt[i];
	}
	cout<<"\Enter the maximum capacity\n";
	int W;
	cin>>W;
	int profit;
	profit=knapsack(val,wt,W,n);
	cout<<"\nProfit = "<<profit;
	return 0;
}
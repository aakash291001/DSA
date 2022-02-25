#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	long long *maxsum;
	maxsum = new long long[n];
	for(int i =1;i<=n;i++)
	{
			long long *A;
			long long n1;
			cin>>n1;
			A = new long long[n1];
			long long k;
			cin>>k;
			long long *B;
			B = new long long[n*k];
			for(long long i=0;i<n1;i++)
			{
				cin>>A[i];
			}
			for(long long i =0;i<n1*k;i++)
			{
				for(long long j = 0;j<n;j++)
				B[i]=A[j];
			}
			int(long long p = 0;p<n1;p++)
			{
				if(A[p]>0)
				maxsum[i] = maxsum[i]+A[p];
			}
	}
	for(int i =0;i<n;i++)
	{
		cou<<maxsum[i];
	}
	return 0;
}

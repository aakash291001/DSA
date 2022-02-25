#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
	int k;
	k= (*a);
	(*a)=(*b);
	(*b)=k;
}
void display(int *arr,int n)
{
	for(int i = 0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}
void rotate(int *arr,int N)
{
	int a= arr[N-1];
	for(int i = N-2;i>=0;i--)
	{
		swap(&arr[i],&a);
	}
	arr[N-1]=a;
}
int main()
{
	int t;
	cin>>t;
	int i =t;
    while(i>0)
	{
		int N;
		int D;
		cin>>N;
		cin>>D;
		int *arr;
		arr = (int*)malloc(N*sizeof(int));
		int m=0;
		while(m<N)
		{
		    cin>>arr[m];
		    m++;
		}
		int p=0;
		while(p<D)
		{
		    rotate(arr,N);
		    p++;
		}
		display(arr,N);
		i--;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int countRev(int a[],int n)
{
	int count=0;
	for(int i=0;i<n;i++)
	{
		for(int j = i+1;j<n;j++)
		{
			if(a[i]>2*a[j])
			count++;
		}
	}
	return count;
}
void merge(int a[],int l,int m,int h,int &count)
{
	int n1 = m-l+1;
	int n2 = h-m;
	int left[n1],right[n2];
	for(int i=0;i<n1;i++)
	{
		left[i] = a[l+i];
	}
	for(int i=0;i<n2;i++)
	{
		right[i] = a[m+1+i];
	}
	int j=0;
    for(int i=0;i<n1;i++)
    {
    	while(j<n2&&left[i]>2*right[j])
    	j++;
    	count+=(j);
	}
	j=0;
	int i=0,k=l;
	while(i<n1&&j<n2)
	{
		if(left[i]<=right[j])
		{
			a[k]=left[i];
			i++;
			k++;
		}
		else
		{
			a[k]=right[j];
			j++;
			k++;
		}
	}
	while(i<n1)
	{
		a[k] = left[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k] = right[j];
		j++;
		k++;
	}
}
void mergeSort(int a[],int l,int h,int &count)
{
	if(l<h)
	{
		int m = (l+h)/2;
		mergeSort(a,l,m,count);
		mergeSort(a,m+1,h,count);
		merge(a,l,m,h,count);
	}
}
int main()
{
	int a[] = {3,2,1,4};
	int count=0;
	mergeSort(a,0,3,count);
	cout<<count;
	return 0;
}
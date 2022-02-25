#include<iostream>
using namespace std;
struct array
{
	int A[20];
	int length;
	int size;
};
void max_min(array arr)
{
	int max,min;
	max=min=0;
	for(int i=0,j=arr.length-1;i<j;i++,j--)
	{
		if(arr.A[i]>arr.A[j])
		{
			if(arr.A[i]>max)
			{
				max=arr.A[i];
			}
			if(arr.A[j]<min)
			{
				min=arr.A[j];
			}
		}
		else
		{
			if(arr.A[j]>max)
			{
				max=arr.A[j];
			}
			if(arr.A[i]<min)
			{
				min=arr.A[i];
			}
		}
	}
	cout<<"Max = "<<max<<"\n"<<"Min = "<<min;
}
max_min2(array arr)
{
	int max, min;
	max=min=0;
	for(int i=0;i<arr.length;i++)
	{
		if(arr.A[i]>max)
		max=arr.A[i];
		else if(arr.A[i]<min)
		min=arr.A[i];
	}
	cout<<"Max = "<<max<<"\n"<<"Min = "<<min;
}
int main()
{
	array arr{{5,8,3,9,6,3,10,7,-1,4},10,20};
	max_min2(arr);
	return 0;
}

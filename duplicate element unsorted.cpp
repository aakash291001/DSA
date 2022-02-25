#include<iostream>
using namespace std;
struct array 
{
	int A[20];
	int size;
	int length;
};
void duplicate(array arr)
{
	int i,j;
	for(i=0;i<arr.length-1;i++)
	{
	    int count=0;
		for(j=i+1;j<arr.length;j++)
		{
		    
			if(arr.A[i]==arr.A[j]&&arr.A[i]!=-1)
			{
			    count++;
				arr.A[j]=-1;
			}
		}
			if(count>0)
			cout<<"duplicate no. is "<<arr.A[i]<<"\n";
	}
}
int main()
{
	array arr{{8,3,6,4,6,5,6,8,2,7},20,10};
	duplicate(arr);
	return 0;
}

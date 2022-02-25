#include<iostream>
using namespace std;
void insert(int *arr,int n)
{
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
}
void display(int *arr,int n)
{
	for(int i =0;i<n;i++)
	{
		cout<<arr[i]<<"\n";
	}
}
 void smax(int arr,int *max,int j,int *p)
{
	if(arr>(*max))
	{
		(*max)=arr;
		(*p)=j;
	}
}
int minJumps(int arr[],int n)
{
    if(arr[0]==0)
    {
        return -1;
    }
    else if(n==0)
    {
        return 0;
    }
	int jump=0;
	for(int i = 0;i<n;)
	{
		if(arr[i]>1)
		{
			if((arr[i]+i)>=n-1)
			{
				jump++;
				return jump;
			}
			else
			{
				int max=0;int p =i+1;
				for(int j = i+1;j<=arr[i]+i;j++)
				{
					smax(arr[j],&max,j,&p);
				}
				i=p;
				jump++;
			}
		}
		else if(arr[i]==0)
		{
		    return -1;
		}
		else
		{
			jump++;
			i++;
		}
		
	}
}
int main()
{
	int n ;
	cout<<"Enter the size of array\n";
	cin>>n;
	cout<<"Enter the elements of array\n";
	int *arr;
	arr = (int*)malloc(n*sizeof(int));
	insert(arr,n);
	int jumps;
	jumps = minJumps(arr,n);
	cout<<"Minimum jumps are = "<<jumps;
	return 0;
}
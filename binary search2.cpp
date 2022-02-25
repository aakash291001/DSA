#include<iostream>
using namespace std;
struct array 
{
	int A[20];
	int size;
	int length;
};
int binary(array arr,int ele)
{
	int low,high,middle;
	low=0;
	high=arr.length-1;
	while(low<=high)
	{
		middle=(low+high)/2;
		if(arr.A[middle]==ele)
		return middle;
		else if(arr.A[middle]<ele)
		low=middle+1;
		else if(arr.A[middle]>ele)	
		high=middle-1;
	}
	return -1;
	
}
int binary(array arr,int ele)
{
	int low,high,middle;
	low=0;
	high=arr.length-1;
	while(low<=high)
	{
		middle=(low+high)/2;
		if(arr.A[middle]==ele)
		return middle;
		else if(arr.A[middle]<ele)
		low=middle+1;
		else if(arr.A[middle]>ele)	
		high=middle-1;
	}
	return -1;
	
}
int main()
{
	array arr{{2,5,7,8,9,10,12,13,17,19},20,10};
	int ele;
	cout<<"Enter The Element to be searched"<<"\n";
	cin>>ele;
	int pos;
	pos=binary(arr,ele);
	cout<<"\n"<<pos;
	return 0;	
}

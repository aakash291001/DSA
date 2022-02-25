#include<iostream>
using namespace std;
struct array
{
	int A[10];
	int size;
	int length;
};
int bsearch(array arr,int ele)
{
	int low,high,middle;
	low=0;
	high=arr.length-1;
	while(low<=high)
	{
		middle=(low+high)/2;
	if(arr.A[middle]==ele)
	return middle;
	else if(ele>arr.A[middle])
	low=middle+1;
	else if(ele<arr.A[middle])
	high=middle-1;
	}
	return -1;
}
int main()
{
	array arr{{2,4,7,10,20,31,45,60},10,8};
	cout<<"Enter the element to be searched"<<"\n";
	int ele;
	cin>>ele;
	int pos;
	pos=bsearch(arr,ele);
	cout<<"The position of the element is ="<<pos;
	return 0;
}

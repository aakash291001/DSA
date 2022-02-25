#include<iostream>
using namespace std;
struct array
{
	int A[100];
	int length;
	int size;
};
int lsearch(array arr,int ele)
{
	for(int i=0;i<arr.length;i++)
	{
		if(arr.A[i]==ele)
		return i;
	}
	return -1;
}
int main()
{
	array arr{{8,9,7,6,5,4,10,3,2,1},10,10};
	int ele,pos;
	cout<<"Enter the element to be searched"<<"\n";
	cin>>ele;
	pos=lsearch(arr,ele);
	if(pos==-1)
	cout<<"Element not found";
	else
	cout<<"Element foound"<<"\n"<<"position of element is "<<pos+1;
	return 0;
	
}

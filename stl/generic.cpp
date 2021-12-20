//Generic Programming using template
//1.Algorithm
//2.Container#inc
#include<iostream>
using namespace std;
template<typename T>
int search(T a[],int n,T key)
{
	for(int pos = 0;pos<n;pos++)
	{
		if(a[pos]==key)
		return pos;
	}
	return n;
}
int main()
{
	int  a[]={1,2,3,4,10,12};
	int key = 10;
	cout<<"Position of key :"<<search(a,6,key)<<"\n";
	float t[]={10.1,20.2,30.3};
	float key2 =20.2;
	cout<<"Position of key :"<<search(t,6,key2);
	return 0;
}
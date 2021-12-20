#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int arr[] = {1,10,100,11,9};
	int n = sizeof(arr)/sizeof(int);
	int key;
	cin>>key;
	auto it = find(arr,arr+n,key);
	cout<<it-arr;
	return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int arr[]={20,30,50,100,1100};
	int n = sizeof(arr)/sizeof(int);
	int key;
	cin>>key;
	bool pres = binary_search(arr,arr+n,key);
	if(pres)
	{
		cout<<"Element is present\n";
	}
	else
	cout<<"Not present";
	auto lb = lower_bound(arr,arr+n,40);
	cout<<"\nLower bound of 40 "<<(lb-arr);
	auto up = upper_bound(arr,arr+n,40);
	cout<<"\nUpper bound of 40 "<<(up-arr);
	
	cout<<"\nNo. of occurances "<<(up-lb);
	return 0;
}
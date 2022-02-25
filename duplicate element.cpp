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
	int last_dup=0;
	for(int i=0;i<arr.length;i++)
	{
		if(arr.A[i]==arr.A[i+1]&&last_dup!=arr.A[i+1])
		{
			last_dup=arr.A[i];
			cout<<"Duplicate Element is="<<last_dup<<"\n";
		}
	}
}
int main()
{
	array arr{{3,6,8,8,10,12,15,15,15,20},20,10};
	duplicate(arr);
	return 0;
}

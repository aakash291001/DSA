#include<iostream>
using namespace std;
struct array
{
	int A[10];
	int size;
	int length;
};
int lsearch(array *arr,int ele)
{
	for(int i=0;i<arr->length;i++)
	{
		if(arr->A[0]==ele)
		{
			return 0;
		}
		if(ele==arr->A[i])
		{
			int temp;
			temp=arr->A[i];
			arr->A[i]=arr->A[i-1];
			arr->A[i-1]=temp;
			return i;
		}
		
	} 		return -1;
}
int main()
{
	array arr{{4,2,3,6,7},10,5};
	cout<<"Enter the no. you want to search"<<"\n";
	int ele;
	cin>>ele;
	int pos;
	pos=lsearch(&arr,ele);
	cout<<"Position of the element is ="<<pos<<"\n"<<"Array =";
	for(int i=0;i<arr.length;i++)
	{
		cout<<arr.A[i]<<" ";
	}
	return 0;

}

#include<iostream>
#include<limits.h>
using namespace std;
int max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}
int theif(int a[],int size)
{
    if(size==1)
	return a[0];
	if(size==2)
	return max(a[0],a[1]);
    else
    {   
        return max(theif(a,size-2)+a[size-1],theif(a,size-1));
    }
}
int main()
{
    int A[] = {97,22,349,200,169,485,282,235,54,500,419,439,401,289,128,468,229,394,149,484,308};
    cout<<theif(A,21);
    return 0;
}
////
//if(size==1)
//return arr[0];
//if(size==2)
//return max(arr[0],arr[1])
//return max(theif(a,size-2)+a[size-1],theif(size-1));
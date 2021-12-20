#include<iostream>
#include<math.h>
using namespace std;
float geop(int k)
{
	if(k==0)
	{
		return 1;
	}
	float sum = geop(k-1);
	return 1/(pow(2,k))+sum;
}
int main()
{
	cout<<"Enter value of k\n";
	int k;
	cin>>k;
	float gp;
	gp = geop(k);
	cout<<"Answer = "<<gp;
	return 0;
}
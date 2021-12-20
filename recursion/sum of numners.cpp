#include<iostream>
using namespace std;
int sumn(int A)
{
	if(A<10)
	{
		return A;
	}
	int sum = sumn(A/10);
	return A%10 +sum;
}
int main()
{
	int A;
	cout<<"Enter a Numer\n";
	cin>>A;
	int sum = sumn(A);
	cout<<"Sum = "<<sum;
	return 0;
}
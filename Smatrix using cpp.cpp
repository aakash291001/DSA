#include<iostream>
using namespace std;
class Smatrix
{
	private:
		int *A;
		int n;
	public: 
	Smatrix(int m)
	{
		n=m;
		A=new int[n];
	 } 
	void set();
	void disp();
};
void Smatrix::set()
{
	for(int i=0;i<5;i++)
	{
		int x;
		cout<<"take input ";
		cin>>x;
		A[i]=x;
	}
}
void Smatrix::disp()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i<=j)
			cout<<A[i];
			else
			cout<<A[j];
		}
		cout<<endl;
	}
}
int main()
{
	Smatrix s(5);
	s.set();
	s.disp();
	return 0;
}

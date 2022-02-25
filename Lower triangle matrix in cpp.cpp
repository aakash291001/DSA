#include<iostream>
using namespace std;
class Ltriangle
{
	private: 
	int *A;
	int n;
	public: 
	Ltriangle(int m)
	{
		n=m;
		A = new int[n];
	}
	void set(int r);
	void display();
	~Ltriangle()
	{
		delete []A;
	}
};
void Ltriangle::set(int r)
{
	for(int i=0;i<=r;i++)
		{
			int x;
			cout<<"Take input";
			cin>>x;
			A[r*(r+1)/2 + i]=x;
		}
}
void Ltriangle::display()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j<=i)
			{
				cout<<A[i*(i+1)/2 + j];
			}
			else 
			cout<<0;
		}
		cout<<"\n";
	}
}
int main()
{
	Ltriangle(5);
	return 0;
}

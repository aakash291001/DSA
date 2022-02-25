#include<iostream>
using namespace std;
class daigonal
{
	private :
		int n;
		int *A;
	public :
		daigonal(int m)
		{
		n=m;
		A = new int[m];
		}
	void set(int i,int j,int x);
	void disp();
	~daigonal()
	{
		delete []A;
	}
};
void daigonal::set(int i,int j,int x)
{
	if(i==j)
	{
		A[i]=x;
	}
}
void daigonal::disp()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
			{
				cout<<A[i];
			}
			else
			cout<<0;
		}
		cout<<"\n";
	}
}
int main()
{
	daigonal M(4);
	M.set(0,0,5);
	M.set(1,1,5);
	M.set(2,2,5);
	M.set(3,3,5);
	M.set(4,4,5);
	M.disp();
	return 0;
}

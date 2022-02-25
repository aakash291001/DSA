#include<iostream>
using namespace std;
struct array {
	int A[20];
	int size;
	int length;
};
void missele(array arr)
{
	int diff;
	diff=arr.A[0];
	int n=0;
	for(int i=0;i<arr.length;i++)
	{
		while(arr.A[i]-i!=diff)
		{
			int missele;
			missele=i+diff;
			cout<<"Missing Element"<<++n<<" "<<missele<<"\n";
			diff++;
		}
	}
}
int main()
{
	array arr{{6,7,8,9,11,12,15,16,17,18,19},20,11};
	missele(arr);
	return 0;
}

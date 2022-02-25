#include<iostream>
using namespace std;
int main()
    {
        int A[100000],n,d;
        cin>>n;
        
        cin>>d;
        for(int i=0;i<n;i++)
        {
            A[i]=i+1;
        }
        for(int i=1;i<=d;i++)
        {
            int temp;
            temp=A[0];
            for(int j=0;j<n;j++)
            {
                A[j]=A[j+1];
            }
            A[n-1]=temp;
        }
        cout<<"\n";
        for(int i=0;i<n;i++)
        {
            cout<<A[i]<<" ";
        }
        return 0;
    }

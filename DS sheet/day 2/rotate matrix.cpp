#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void rotate(vector<vector<int>>& A) {
    int n = A.size(); 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            swap(A[i][j],A[j][i]);
        }
    }
    for(int i=0;i<(n);i++)
    {
        for(int j=0;j<(n/2);j++)
        {
            swap(A[i][n-1-j],A[i][j]);
        }
    }
}
void rotate2(vector<vector<int>>& A) {
    int n = A.size(); 
    int B[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            B[j][n-1-i] = A[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            A[i][j]=B[i][j];
        }
    }
}
int main()
{
    vector<vector<int>> matrix{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    rotate(matrix);
    int n = matrix.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
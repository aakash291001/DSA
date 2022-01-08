#include<bits/stdc++.h>
using namespace std;
void kadane(int A[],int n)
{
    int overSum=A[0];
    vector<int> overV;
    overV.push_back(A[0]);
    vector<int> currV;
    currV.push_back(A[0]);
    int currSum=A[0];
    for(int i=1;i<n;i++)
    {
        if(currSum+A[i]>A[i])
        {
            currSum+=A[i];
            currV.push_back(A[i]);
        }
        else
        {
            vector<int> temp;
            temp.push_back(A[i]);
            currV = temp;
            currSum = A[i];
        }
        if(overSum<currSum)
        {
            overSum = currSum;
            overV = currV;
        }
    }
    for(auto it:overV)
    {
        cout<<it<<" ";
    }
}
int main()
{
    int A[] = {4,3,-2,6,-14,7,-1,4,5,7,-10,2,9,-10,2,9,-10,-5,-9,6,1};
    kadane(A,18);
    return 0;
}
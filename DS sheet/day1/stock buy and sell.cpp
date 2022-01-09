#include<bits/stdc++.h>
using namespace std;
//int stock(int A[],int n)
//{
//    int maxProfit=INT_MIN;
//    for(int i=0;i<n-1;i++)
//    {
//        for(int j=i+1;j<n;j++)
//        {
//            int temp = A[j]-A[i];
//            if(maxProfit<temp)
//            {
//                maxProfit=temp;
//            }
//        }
//    }
//    return maxProfit;
//}
void stock(int A[],int n)
{
    int maxProfit = 0;
    int min = 0;
    vector<pair<int,int>> vec;
    for(int i=1;i<n;i++)
    {
        int temp = A[i]-A[min];
        if(maxProfit<temp)
        {
            maxProfit = temp;
        }
        else
        {
            if(maxProfit==0)
            {
                min=i;
            }
            else
            {
                vec.push_back(make_pair(min,i-1));
                min = i;
                maxProfit = INT_MIN;
            }
        }
    }
    if(maxProfit>0)
    vec.push_back(make_pair(min,n-1));
    if(vec.size()==0)
    cout<<"No Profit";
    else
    {
        for(auto it:vec)
        {
            cout<<"("<<it.first<<" "<<it.second<<")"<<" ";
        }
    }
}
int main()
{
    int A[] = {7,1,5,3,6,4};
    cout<<stock(A,6);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
void merge(vector<vector<int>> A)
{
    sort(A.begin(),A.end());
    int n = A.size();
    int j=0;
    vector<vector<int>> ans;
    ans.push_back(A[0]);
    for(int i=1;i<n;i++)
    {
        if(A[i][0]<=ans[j][1])
        {
            if(A[i][1]>ans[j][1])
            {
                ans[j][1] = A[i][1];
            }
        }
        else
        {
            ans.push_back(A[i]);
            j++;
        }
    }
    for(auto it:ans)
    {
        cout<<it[0]<<" "<<it[1]<<"\n";
    }
    
}
int main()
{
    vector<vector<int>> vec{{1,3},{2,6},{8,10},{8,9},{9,11},{15,18},{2,4},{16,17}};
    merge(vec);
    return 0;
}
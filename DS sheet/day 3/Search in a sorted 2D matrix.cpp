#include<bits/stdc++.h>
using namespace std;
void find2d(vector<vector<int>> A,int ele)
{
    int nr,nc;
    nr = A.size();
    nc =A[0].size();
    int mark=-1;
    for(int i=0;i<nr;i++)
    {
        if(A[i][0]<=ele&&ele<=A[i][nc-1])
        {    
            mark = i;
            break;
        }
    }
    if(mark==-1)
    return;
    else
    {
        int l = 0;
        int h = nc-1;
        int m;
        while(l<=h)
        {
            m = (l+h)/2;
            if(A[mark][m]==ele)
            {
                cout<<A[mark][m]<<" position "<<mark<<" "<<m;
                return;
            }
            else if(ele<A[mark][m])
            {
                h = m-1;
            }
            else
            {
                l = m+1;
            }
        }
    }
}
int main()
{
    vector<vector<int>> vec{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    find2d(vec,13);
    return 0;
}
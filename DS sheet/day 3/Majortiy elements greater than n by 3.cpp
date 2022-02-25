#include<bits/stdc++.h>
using namespace std;
vector<int> maj(vector<int> vec)
{
    int num1,num2,c1,c2;
    c1 = c2 = 0;
    num1 = num2 = INT_MIN;
    int n = vec.size();
    for(int i=0;i<n;i++)
    {
    	if(num1==vec[i])
        {
            c1++;
        }
        else if(num2==vec[i])
        {
            c2++;
        }
        else if(c1==0)
        {
            c1 = 1;
            num1 = vec[i];
        }
        else if(c2==0)
        {
            c2 = 1;
            num2 = vec[i];
        }
        else
        {
            c1--;
            c2--;
        }
    }
    for(int i=0;i<n;i++)
    {
    	if(vec[i]==num1)
    	c1++;
    	if(vec[i]==num2)
    	c2++;
	}
    vector<int> ans{};
    if(c1>n/3)
    ans.push_back(num1);
    if(c2>n/3)
    ans.push_back(num2);
    return ans;
}
int main()
{
    vector<int> v{1,2,2,3,2};
    vector<int> vec = maj(v);
    for(auto it:vec)
    {
        cout<<it<<" ";
        
    }
    return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//vector<int> maj(vector<int> vec)
//{
//    sort(vec.begin(),vec.end());
//    vector<int> ans{};
//    int n = vec.size();
//    int j,i = n/3;
//    j = i;
//    for(i;i<n;i++)
//    {
//        if(vec[i-j]==vec[i])
//        {
//            if(ans.size()!=0)
//            {
//                if(ans.back()!=vec[i])
//                ans.push_back(vec[i]);
//            }
//            else
//            ans.push_back(vec[i]);
//        }
//    }
//    return ans;
//}
//int main()
//{
//    vector<int> v{3,2,3};
//    vector<int> vec = maj(v);
//    for(auto it:vec)
//    {
//        cout<<it<<" ";
//        
//    }
//    return 0;
//}
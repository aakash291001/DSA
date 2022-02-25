#include<iostream>
#include<string>
using namespace std;
class st
{
    public:
    int t;
    char a[256];
    st() { t = -1; }
    int push(char x)
	{
    	if (t >= (1000 - 1))
    	{
    	    cout << "st IS FULL";
    	    return 0;
    	}
    	else
    	{
    	    a[++t] = x;
    	    return 1;
    	}
	}
	char peek()
	{
	    if (t < 0)
	    {
	        cout << "Empty";
	        return 0;
	    }
 	   else
	    {
 	       char x = a[t];
	       return x;
    	}
	}
    void pop()
	{
	    if (t < 0)
    	{
    	    cout << "NO ELEMENTS IN THE st";
    	}
    	else
    	{
    	    t--;
    	}
	}
    int Isempty()
	{
		if(t<0)
		return 1;
		else
		return 0;
	}
};
int main()
{
    st s;
    string str;
    cout << "Enter the string\n";
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        s.push(str[i]);
    }
    int cA = 0, cB = 0;
    while (!s.Isempty())
    {
        char c = s.peek();
        s.pop();
        if (c == 'a')
            cA++;
        else if (c == 'b')
            cB++;
    }
    if (cA == cB)
    {
        cout << "Equal";
    }
    else
    {
        cout << "Not Equal";
    }
    return 0;
}
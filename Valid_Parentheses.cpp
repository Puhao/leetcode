#include <iostream>
#include <stack>

using namespace std;

    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> sta;
        for(auto i:s)
        {
        	if (i == '[')
        	{
        		sta.push(i);
        	}
        	if (i == ']')
        	{
        		if (sta.size() == 0 ||  sta.top() != '[')
        			return false;
        		else
        			sta.pop();
        	}
        	if (i == '(')
        	{
        		sta.push(i);
        	}
        	if (i == ')')
        	{
        		if (sta.size() == 0 || sta.top() != '(')
        			return false;
        		else
        			sta.pop();
        	}
        	if (i == '{')
        	{
        		sta.push(i);
        	}
        	if (i == '}')
        	{
        		if (sta.size() == 0 || sta.top() != '{')
        			return false;
        		else
        			sta.pop();
        	}
        }
        return sta.size() == 0;
    }


int main()
{
	string s = "[]{}";
	cout << isValid(s) << endl;
	return 0;
}

#include <iostream>
#include <stack>

using namespace std;

struct node
{
	char val;
	int index;
	node(int v,int i):val(v),index(i){}
	/* data */
};

    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxlen = 0;
        if (s.size() <= 1)
        	return 0;
        stack<node> S;
        S.push(node(')',-1));
        for(int i=0;i<s.size();i++)
        {
        	if (s[i] == '(')
        	{
        		S.push(node(s[i],i));
        	}
        	if (s[i] == ')')
        	{
        		if (S.top().val == '(')
        		{
        			S.pop();
        			maxlen = max(maxlen,i - S.top().index);
        		}
        		else
        		{
        			S.push(node(')',i));
        		}
        	}
        }
        return maxlen;
    }


int main()
{
	string s = ")()(((())))(";
	cout << longestValidParentheses(s) << endl;
	return 0;
}
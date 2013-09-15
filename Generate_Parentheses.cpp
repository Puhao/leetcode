#include <iostream>
#include <vector>

using namespace std;

void DfsParent(string s,int left,int right,vector<string> &v)
{
	if (left <= 0 && right <= 0)
	{
		v.push_back(s);
		return;
	}
	if (left > 0)
	{
		DfsParent(s+'(',left-1,right,v);
	}
	if (right > left)
	{
		DfsParent(s+')',left,right-1,v);
	}
	return;
}


    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> v;
        string s;
        DfsParent(s,n,n,v);
        return v;
    }

int main()
{
	int n = 3;
	vector<string> v;
	v = generateParenthesis(n);
	for(auto i:v)
	{
		cout << i << ' ';
	}
	cout << endl;
	return 0;
}
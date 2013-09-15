#include <iostream>
#include <vector>

using namespace std;

void dfs(string digits,string ret,int depth,vector<string> &v,vector<string> &StrV)
{
	if (depth >= digits.size())
	{
		v.push_back(ret);
		return;
	}
	char tmp = digits[depth];
	string vtmp = StrV[tmp - '2'];
	for(int i=0;i<vtmp.size();i++)
	{
		ret.push_back(vtmp[i]);
		dfs(digits,ret,depth+1,v,StrV);
		ret.pop_back();
	}
	return;
}

    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    vector<string>  StrV = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> v;
    string ret;
    dfs(digits,ret,0,v,StrV);
    return v;
}

int main()
{
	string digits = "234";
	vector<string> v;
	v = letterCombinations(digits);
	for(auto i:v)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}



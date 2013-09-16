#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_map<string,int> Words,StrMatch;
        for (auto i:L)
        {
        	Words[i]++;
        }
        vector<int> v;
        int n = L.size();
        if (n == 0)
        	return v;
        int m = L.begin()->size();
        for(int i=0;i <= (int(S.size()) - n*m);i++)
        {
        	StrMatch.clear();
        	int j;
        	for(j=0;j<n;j++)
        	{
        		string tmp = S.substr(i+m*j,m);
        		if (Words.find(tmp) == Words.end())
        			break;
        		StrMatch[tmp]++;
        		if (StrMatch[tmp] > Words[tmp])
        			break;
        	}
        	if ( j == n)
        		v.push_back(i);
        }
        return v;
    }

int main()
{
	vector<string> L = {"a","a"};
	string S = "a";
	vector<int> v;
	v = findSubstring(S,L);
	for (auto i:v)
		cout << i << " ";
	return 0;
}


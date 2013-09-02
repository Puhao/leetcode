#include <iostream>
#include <string>
#include <set>

using namespace std;

int LongestSubString(int pos,string &s)
{
	if (pos < 0)
		return 0;
	if (pos == 0)
		return 1;
	set<char> set;
	for(int i=pos;i >= 0;i--)
	{
		if (set.count(s[i]))
			return max(pos - i,LongestSubString(pos-1,s));
		else
			set.insert(s[i]);
	}
	return pos+1;
}

int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return LongestSubString(s.size()-1,s);
    }


int main()
{
	string s = "bbbbb";
	cout << lengthOfLongestSubstring(s) << endl;
	return 0;
}
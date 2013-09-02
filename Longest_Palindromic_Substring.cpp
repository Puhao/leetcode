#include <iostream>

using namespace std;

string Palindrom(int pos,string s)
{
	if (pos < 0)
		return NULL;
	if (pos == 0)
	{
		string tmp(s,0,1);
		return tmp;
	}
	string sub = Palindrom(pos-1,s);
	for(int i=0;i<pos;i++)
	{
		int j = i;
		int k = pos;
		while(j < k)
		{
			if(s[j] != s[k])
				break;
			else
			{
				j++;
				k--;
			}
		}
		if (j >= k)	//find longest Palindrom
		{
			string pal(s,i,pos-i+1);
			
			if (pal.size() > sub.size())
				return pal;
			else
				return sub;
		}
	}
	return sub;
}

string longestPalindrome(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    return Palindrom(s.size()-1,s);
    
}

int main()
{
	string s = "fjaojfoejajfeafawwe";
	cout << longestPalindrome(s) << endl;
	return 0;
}


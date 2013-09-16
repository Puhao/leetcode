#include <iostream>
#include <vector>

using namespace std;

vector<int> GetNext(char *pattern)
{
	vector<int> v(strlen(pattern),-1);
	int j;
	for(int i=1;i<strlen(pattern);i++)
	{
		for(j=v[i-1];j>=0&&pattern[i] != pattern[j+1];j = v[j]);

		if(pattern[j+1] == pattern[i])
			v[i] = j+1;
	}
	return v;
}

//KMP
char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	vector<int> next = GetNext(needle);
	int i=0,j=0;
	while(haystack[i] && needle[j])
	{
		if (haystack[i] == needle[j])
		{
			i++;
			j++;
		}
		else
		{
			if (j==0)
				i++;
			else
				j = next[j-1] + 1;
		}

	}
	if (needle[j])
		return NULL;
	return haystack + i - j;
}

int main()
{
	char h[] = "missi";
	char n[] = "ss";
	cout << *strStr(h,n) << endl;
	return 0;
}
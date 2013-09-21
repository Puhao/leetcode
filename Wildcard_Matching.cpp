#include <iostream>

using namespace std;


bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	if (*p == 0)
		return *s == 0;
	if (*p == '?')
	{
		if (strlen(s) < 1)
			return false;
		else
			return isMatch(s+1,p+1);
	}
	if (*p == '*')
	{
		for (int i=0;i<strlen(s)+1;i++)
		{
			if (isMatch(s+i,p+1))
				return true;
		}
		return false;
	}
	if (*p == *s)
		return isMatch(s+1,p+1);
	return false;

}


int main()
{
	char s1[] = "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba";
	char s2[] = "a*******b";
	cout << isMatch(s1,s2) << endl;
	return 0;
}
#include <iostream>


using namespace std;


bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	if (s1.size() != s2.size())
		return false;
	int n = s1.size();
	bool isOk[n+1][n][n];
	memset(isOk,false,sizeof(isOk));
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			isOk[1][i][j] = (s1[i] == s2[j]);
	}
	for(int len=2;len < n+1; len++)
	{
		for(int i=0; i<n+1-len; i++)
		{
			for(int j=0; j<n+1-len; j++)
			{
				bool ret = false;
				if (s1.substr(i,len) == s2.substr(j,len))
					isOk[len][i][j] = true;
				else
				{
					for(int k=1;k<len;k++)
					{
						if ((isOk[k][i][j+len-k] && isOk[len-k][i+k][j]) || (isOk[k][i][j] && isOk[len-k][i+k][j+k]) )
						{
							ret = true;
							break;
						}
					}
					isOk[len][i][j] = ret;
				}
			}
		}
	}
	return isOk[n][0][0];
        
}

int main()
{
	string s1 = "abcd";
	string s2 = "adbc";
	cout << isScramble(s1,s2) << endl;
	return 0;
}
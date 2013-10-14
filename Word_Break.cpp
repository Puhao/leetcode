#include <iostream>
#include <unordered_set>

using namespace std;
bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
	int len = s.size();
	bool Ret[len][len];
	memset(Ret,false,sizeof(Ret)/sizeof(Ret[0][0]));
	for(int i=1;i<=len;i++)
	{
		for(int j=0;j<len+1-i;j++)
		{
			if (dict.find(s.substr(j,i)) != dict.end())
				Ret[j][j+i-1] = true;
			else
			{
				for(int k=j;k<j+i-1;k++)
				{
					if(Ret[j][k] && Ret[k+1][j+i-1])
					{
						Ret[j][j+i-1] = true;
						break;
					}
				}
			}
		}
	}
	return Ret[0][len-1];
}

int main()
{
	string s = "leetcode";
	unordered_set<string> dict = {"leet","code"};
	cout << wordBreak(s,dict) << endl;
	return 0;
}
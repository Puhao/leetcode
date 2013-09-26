#include <iostream>

using namespace std;

int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	int l1 = word1.size();
	int l2 = word2.size();
	int Ret[l1+1][l2+1];
	memset(Ret,-1,sizeof(Ret)/sizeof(Ret[0][0]));
	for(int i=0;i<l1+1;i++)
		Ret[i][0] = i;
	for(int j=0;j<l2+1;j++)
		Ret[0][j] = j;
	for(int i=1;i<=word1.size();i++)
	{
		for(int j=1;j<=word2.size();j++)
		{
			if (word1[word1.size()-i] == word2[word2.size()-j])
				Ret[i][j] = Ret[i-1][j-1];
			else
			{
				Ret[i][j] = min(min(Ret[i][j-1],Ret[i-1][j]),Ret[i-1][j-1])+1;
			}
		}
	}
	return Ret[l1][l2];
        
}

int main()
{
	string a = "abcd";
	string b = "ace";
	cout << minDistance(a,b) << endl;
	return 0;
}
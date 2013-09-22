#include <iostream>

using namespace std;

int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	int l1 = word1.size();
	int l2 = word2.size();
	int Ret[1000][1000];
	memset(Ret,-1,sizeof(Ret)/sizeof(Ret[0][0]));
	for(int i=0;i<l1+1;i++)
		Ret[i][l2] = l1 -i;
	for(int j=0;j<l2+1;j++)
		Ret[l1][j] = l2 -j;
	return dst(word1,0,word2,0,Ret);
        
}

int main()
{
	string a = "abcd";
	string b = "ace";
	cout << minDistance(a,b) << endl;
	return 0;
}
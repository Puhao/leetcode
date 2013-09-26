#include <iostream>

using namespace std;

int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	int l1 = S.size();
	int l2 = T.size();
	if (l1 == 0)
		return 0;
	int num[l1][l2];
	if (S[0] == T[0])
		num[0][0] = 1;
	else
		num[0][0] = 0;
	for (int i=1;i<l1;i++)
	{
		if (S[i] == T[0])
		{
			num[i][0] = 1 + num[i-1][0];
		}
		else
		{
			num[i][0] = num[i-1][0];
		}
	}
	for (int j=1;j<l2;j++)
	{
		num[0][j] = 0;
	}
	for(int i=1;i<l1;i++)
	{
		for(int j=1;j<l2;j++)
		{
			if (S[i] == T[j])
			{
				num[i][j] = num[i-1][j-1] + num[i-1][j];
			}
			else
			{
				num[i][j] = num[i-1][j];
			}
		}
	}
	return num[l1-1][l2-1];
        
}



int main()
{
	string S = "rabbbit";
	string T = "rabbit";
	cout << numDistinct(S,T) << endl;
	return 0;
}
#include <iostream>

using namespace std;


bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	int l1 = strlen(s);
	int l2 = strlen(p);
	bool Ret[l1+1][l2+1];
	memset(Ret,false,sizeof(Ret)/sizeof(Ret[0][0]));
	Ret[0][0] = true;
	for(int j=1;j<l2+1;j++)
	{
		if(*(p+l2-j) == '*')
			Ret[0][j] = Ret[0][j-1];
	}
	for(int i=1;i<l1+1;i++)
	{
		for(int j=1;j<l2+1;j++)
		{
			if (*(p+l2-j) == '?')
			{
				Ret[i][j] = Ret[i-1][j-1];
			}
			else if (*(p+l2-j) == '*')
			{
				for(int k=0;k<=i;k++)
				{
					if(Ret[k][j-1] == true)
					{
						Ret[i][j] = true;
						break;
					}
				}
			}
			else if (*(p+l2-j) == *(s+l1-i))
				Ret[i][j] = Ret[i-1][j-1];
		}
	}
	return Ret[l1][l2];
}


int main()
{
	char s1[] = "fafjlajfljfoaaafldef";
	char s2[] = "f*aa*def";
	cout << isMatch(s1,s2) << endl;
	return 0;
}
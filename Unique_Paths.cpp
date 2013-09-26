#include <iostream>
#include <vector>
#include <array>
using namespace std;

    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    if (m==1 && n==1)
    	return 1;
    int t[101][101];
    t[0][0] = 0;
    for(int i=1;i<n;i++)
    {
    	t[i][0] = 1;
    }
    for(int i=1;i<m;i++)
    	t[0][i] = 1;
    for(int i =1;i<n;i++)
    {
    	for(int j=1;j<m;j++)
    		t[i][j] = t[i-1][j]+t[i][j-1];
    }
    return t[n-1][m-1];

}

int main()
{
	int m = 3;
	int n = 7;
	cout << uniquePaths(m,n) << endl;
	return 0;
}
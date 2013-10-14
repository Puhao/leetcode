#include <iostream>
#include <array>

using namespace std;

int numTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
	array<int, 1000> res;
	memset(&res,0,sizeof(res)/sizeof(res[0]));
	if (n <= 2)
		return n;
	res[0] = 1;
	res[1] = 1;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			res[i] += res[j]*res[i-1-j];
		}
	}
	return res[n];
}

int main()
{
	cout << numTrees(3) << endl;
	return 0;
}
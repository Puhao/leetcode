#include <iostream>
#include <array>
#include <vector>

using namespace std;

int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	if (n <= 1)
		return 0;
	int start = 0;
	int end = 0;
	int step = 0;
	while(start<=end)
	{	
		step++;
		int NextStart = end + 1;
		int NextEnd = end;
		for(int i=start;i<=end;i++)
		{
			int dst = i + A[i];
			if (dst >= n-1)
				return step;
			else if (dst > NextEnd)
				NextEnd = dst;
		}
		start = NextStart;
		end = NextEnd;
	}
	return 0;
}

int main()
{
	int a[] = {2,3,1,1,4};
	cout << jump(a,sizeof(a)/sizeof(a[0])) << endl;
	return 0;
}
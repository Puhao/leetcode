#include <iostream>

using namespace std;

int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	int left = 0;
	int right = n-1;
	while(left<=right)
	{
		int middle = left + (right - left) /2;
		if (target == A[middle])
			return middle;
		if (target > A[middle])
			left = middle + 1;
		else
			right = middle - 1;
	}
	return left;
}

int main()
{
	int a[] = {1,3,5,6};
	cout << searchInsert(a,sizeof(a)/sizeof(a[0]),4) << endl;
	return 0;
}